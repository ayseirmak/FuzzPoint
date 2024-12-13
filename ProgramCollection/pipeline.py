import os
import subprocess
import shutil
import re
import chardet

from reshaper import GPTProgramGenerator
from openai import OpenAI
from dotenv import load_dotenv
import sys

# Paths and configurations
REPO_URL = "https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks.git"  # Replace with actual repository URL
CLONE_DIR = "SV-Comp2"
OUTPUT_DIR = "reshaped_programs"
VALID_DIR = os.path.join(OUTPUT_DIR, "valid")
INVALID_DIR = os.path.join(OUTPUT_DIR, "invalid")
SANITIZER_AD = "-fsanitize=address"
SANITIZER_UB = "-fsanitize=undefined" 
SANITIZER_MEM = "-fsanitize=memory"
COMP_ERR_log = "compilation_error.log"
SAN_ERR_log = "sanitizer_error.log"
DET_ERR_log = "detail_error.log"

CLEAR_DIR = "clear_programs"
PROBLEM_DIR = "problem_programs"
EXECUTION_TIMEOUT = 10


SANITIZERS = [
        (SANITIZER_AD, "Address Sanitizer"),
        (SANITIZER_MEM, "Memory Sanitizer"),
        (SANITIZER_UB, "Undefined Behavior Sanitizer"),
        ]

# Step 1: Clone Git repository
def clone_repository(repo_url, clone_dir):
    if os.path.exists(clone_dir):
        shutil.rmtree(clone_dir)
    subprocess.run(["git", "clone", repo_url, clone_dir], check=True)
    print(f"Cloned repository into {clone_dir}")

# Step 2: Extract C files with floating-point operations
def extract_c_files_with_floats(clone_dir):
    file_text_path = "c_files_list.txt"
    pattern = re.compile(r'\b(float|double|long double)\b\s')
    c_files = []
    for root, _, files in os.walk(clone_dir):
        for file in files:
            if file.endswith(".c"):
                file_path = os.path.join('./',root, file)
                # Check for floating-point operations
                try:
                    with open(file_path, "rb") as f:
                        raw_data = f.read()
                        result = chardet.detect(raw_data)
                        encoding = result['encoding']
                        print(encoding)
                    with open(file_path, "r",encoding=encoding) as f:
                        content = f.read()
                    if  pattern.search(content):
                        print(file_path)
                        print("pattern match")
                        if re.search(r'\bint\s+main\s*\(', content, re.DOTALL):
                            print("int match")
                            c_files.append(file_path)
                except UnicodeDecodeError as e:
                    print(e)
    print(f"Found {len(c_files)} C files with floating-point operations.")
    
    with open(file_text_path, "w") as f:
        for path in c_files:
            f.write(path + "\n")
    print(f"Saved list of C files to {file_text_path}")
    
    return c_files


# Step 3: Reshape files (simulated LLM processing)
def reshape_file(gpt, file_path, output_dir):
    file_name, transformed_program = gpt.run(file_path)
    reshaped_file_path = os.path.join(output_dir, file_name)
    with open(reshaped_file_path, "w") as f:
        f.write(transformed_program)
    return reshaped_file_path

# This function used to detect type of senitizers 
# Also catch the waninig and errors that don't throw exception
# Step 4.2: Compile and test with sanitizers
def detect_sanitizer(stderr_output, name):
    """
    Detect the type(s) of sanitizer errors from the stderr output.
    """
    if name == "Address Sanitizer":
        pattern = re.compile(r"AddressSanitizer")
    elif name == "Memory Sanitizer":
        pattern = re.compile(r"MemorySanitizer")
    elif name == "Undefined Behavior Sanitizer":
        pattern = re.compile(r"Undefined")
    if pattern.search(stderr_output):
        return True
    else:
        return False

def check_summary(stderr_output):
    """
    Check if the stderr output contains a SUMMARY line.
    """
    if "SUMMARY:" in stderr_output:
        return True
    else:
        return False

# Step 4: Compile and test with sanitizers
def compile_and_test(file_path):
    results = {"comp": 0, "Address Sanitizer": 0, "Undefined Behavior Sanitizer": 0, "Memory Sanitizer": 0}
    errors = []

    for sanitizer, name in SANITIZERS:
        binary_path = file_path.replace(".c", "")
        compile_cmd = f"clang {sanitizer} -o {binary_path} {file_path}"


        try:
            comp_res = subprocess.run(compile_cmd.split(), check=True, stderr=subprocess.PIPE,timeout=EXECUTION_TIMEOUT)
            if comp_res.stderr:
                err = comp_res.stderr.decode('utf-8', errors='replace')
                err = err.replace(file_path, "")
                if "error:" in err:
                    print(f"Compiler Error: {comp_res.stderr}")
                    with open(COMP_ERR_log, "a") as comp_error_file:
                        comp_error_file.write(f"Program: {file_path}\nError: {err}\n")
                    return False
                else:
                    results["comp"] += 1
                    print(f"Compiled {file_path} successfully with warning. Warning:{err}")
            else:
                results["comp"] += 1
                print(f"Compiled {file_path} successfully.")            
        except subprocess.CalledProcessError as e:
            print(f"Compiler Error: {e.stderr}")
            err = e.stderr.decode('utf-8', errors='replace')
            err = err.replace(file_path, "")
            with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nError: {err}\n")
            return False
            

        try:    
            san_result = subprocess.run([binary_path], stderr=subprocess.PIPE, check=True)

            if san_result.stderr:
                err = san_result.stderr.decode('utf-8', errors='replace')  
                err = err.replace(file_path, "") 
                if detect_sanitizer(san_result.stderr.decode('utf-8', errors='replace'), name):
                        results[name] += 1
                        if "SUMMARY:" in err:
                            lines = err.splitlines()
                            for line in lines:
                                if "SUMMARY:" in line:
                                    sanitizer_summary = line.strip()  # Extract the SUMMARY part
                                    errors.append(sanitizer_summary)
                                    break
                        else:
                            errors.append(name + " Error: " + err)
                else:        
                    if err not in errors:
                        errors.append(err)
        except subprocess.TimeoutExpired:
            err = "Error: Compilation timed out after 10 seconds."
            if err not in errors:
                    errors.append(err)
        except subprocess.CalledProcessError as e:
            err = e.stderr.decode('utf-8', errors='replace')
            err = err.replace(file_path, "")
            if detect_sanitizer(e.stderr.decode('utf-8', errors='replace'), name):
                results[name] += 1
                if "SUMMARY:" in err:
                    lines = err.splitlines()
                    for line in lines:
                        if "SUMMARY:" in line:
                            sanitizer_summary = line.strip()  # Extract the SUMMARY part
                            errors.append(sanitizer_summary)
                            break
                else:
                    errors.append(name + " Error: " + err)

            else:
                if err not in errors:
                    errors.append(err)
    if errors:
        with open(DET_ERR_log, "a") as detail_error_file:
            detail_error_file.write(f"Program: {file_path}\n")
            detail_error_file.write(f"Error: {', '.join(errors)} \n")
    if results["comp"] == 3:
        with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nCompiled successfully\n")
    
    snt = {key: value for key, value in results.items() if key != "comp"}
    # Check if all sanitizers have a value of 0
    if all(value == 0 for value in snt.values()):
        print(f"{file_path} passed all sanitizers.")
        if not errors:
            return True
        
    # Find sanitizers that caused errors (value == 1)
    failed_sanitizers = [key for key, value in snt.items() if value == 1]
    # Format the error message
    if failed_sanitizers:
        with open(SAN_ERR_log, "a") as sanitizer_error_file:
                sanitizer_error_file.write(f"Program: {file_path}\n")
                sanitizer_error_file.write(f"Error: {', '.join(failed_sanitizers)} \n")
        print(f"{file_path} failed due to: {', '.join(failed_sanitizers)}")
    return False
            
def main():
    # Clone repository
    #clone_repository(REPO_URL, CLONE_DIR)
    
    # Extract and process C files
    #c_files = extract_c_files_with_floats(CLONE_DIR)
    
    with open('c_files_list.txt', 'r') as file:
        c_files = file.readlines()
    c_files = [line.strip() for line in c_files]
    
    #os.makedirs(OUTPUT_DIR, exist_ok=True)
    #os.makedirs(CLEAR_DIR, exist_ok=True)

    
    # Reshaping with gpt
    # load_dotenv(dotenv_path = ".env")
    key = "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"
    #key = os.getenv("OPENAI_API_KEY")
    print("Key: ", key)
    if not key:
        print("Error: No OpenAI API key found")
        print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
        sys.exit(1)
    
    gpt = GPTProgramGenerator(OpenAI(api_key=key))
    
    for c_file in c_files[0:5]:
        reshaped_file = reshape_file(gpt, c_file, OUTPUT_DIR)
        print(f"Reshaped file saved to {reshaped_file}")
        if compile_and_test(reshaped_file):
            print(f"{reshaped_file} passed all sanitizers.")
            pth = CLEAR_DIR
            try:
                shutil.copy(reshaped_file, pth)
                print(f"File copied successfully from {reshaped_file} to {pth}")
            except FileNotFoundError as e:
                print(f"Error: {e}")
            except PermissionError as e:
                print(f"Permission Error: {e}")
            except Exception as e:
                print(f"Unexpected Error: {e}")
        

        #save_results(reshaped_file, valid)
        #if not valid:
        #    print(f"Sanitizer report saved to {report_path}")
def compile_and_test2(file_path):
    results = {"comp": 0, "Address Sanitizer": 0, "Undefined Behavior Sanitizer": 0, "Memory Sanitizer": 0}
    errors = []

    for sanitizer, name in SANITIZERS:
        binary_path = file_path.replace(".c", "")
        compile_cmd = f"clang {sanitizer} -o {binary_path} {file_path}"
       
       #Compile the program 
        try:
            comp_res = subprocess.run(compile_cmd.split(), check=True, stderr=subprocess.PIPE)
            # if it give runtime error not exception catch it
            if comp_res.stderr:
                err = comp_res.stderr.decode('utf-8', errors='replace')
                err = err.replace(file_path, "")
                #if it only give warning just okay with it
                if "error:" in err:
                    print(f"Compiler Error: {comp_res.stderr}")
                    with open(COMP_ERR_log, "a") as comp_error_file:
                        comp_error_file.write(f"Program: {file_path}\nError: {comp_res.stderr}\n")
                    return False
                else:
                    results["comp"] += 1
                    print(f"Program: {file_path} successfully compiled with warning.")
            else:
                results["comp"] += 1
                print(f"Program: {file_path} compiled successfully - {name}.")            
        except subprocess.CalledProcessError as e:
            err = e.stderr.decode('utf-8', errors='replace')
            err = err.replace(file_path, "")
            print(f"Compiler Error: {e.stderr}")
            with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nError: {e.stderr}\n")
            return False
            
        # execute binaries with sanitizers
        try:    
            san_result = subprocess.run([binary_path], stderr=subprocess.PIPE, check=True, timeout=EXECUTION_TIMEOUT)
            if san_result.stderr:
                err = san_result.stderr.decode('utf-8', errors='replace')  
                err = err.replace(file_path, "") 
                if detect_sanitizer(san_result.stderr.decode('utf-8', errors='replace'), name):
                        results[name] += 1
                        if "SUMMARY:" in err:
                            lines = err.splitlines()
                            for line in lines:
                                if "SUMMARY:" in line:
                                    sanitizer_summary = line.strip()  # Extract the SUMMARY part
                                    errors.append(sanitizer_summary)
                                    break
                        else:
                            errors.append(name + " Error: " + err)
                else:        
                    if err not in errors:
                        errors.append(err)
        except subprocess.TimeoutExpired:
            err = "Error: Compilation timed out after 10 seconds."
            if err not in errors:
                    errors.append(err)
        except subprocess.CalledProcessError as e:
            err = e.stderr.decode('utf-8', errors='replace')
            err = err.replace(file_path, "")
            if detect_sanitizer(e.stderr.decode('utf-8', errors='replace'), name):
                results[name] += 1
                if "SUMMARY:" in err:
                    lines = err.splitlines()
                    for line in lines:
                        if "SUMMARY:" in line:
                            sanitizer_summary = line.strip()  # Extract the SUMMARY part
                            errors.append(sanitizer_summary)
                            break
                else:
                    errors.append(name + " Error: " + err)

            else:
                if err not in errors:
                    errors.append(err)
    if errors:
        with open(DET_ERR_log, "a") as detail_error_file:
            detail_error_file.write(f"Program: {file_path}\n")
            detail_error_file.write(f"Error: {', '.join(errors)} \n")
    if results["comp"] == 3:
        with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nCompiled successfully\n")
    
    snt = {key: value for key, value in results.items() if key != "comp"}
    # Check if all sanitizers have a value of 0
    if all(value == 0 for value in snt.values()):
        print(f"{file_path} passed all sanitizers.")
        if not errors:
            return True
        
    # Find sanitizers that caused errors (value == 1)
    failed_sanitizers = [key for key, value in snt.items() if value == 1]
    # Format the error message
    if failed_sanitizers:
        with open(SAN_ERR_log, "a") as sanitizer_error_file:
                sanitizer_error_file.write(f"Program: {file_path}\n")
                sanitizer_error_file.write(f"Error: {', '.join(failed_sanitizers)} \n")
        print(f"{file_path} failed due to: {', '.join(failed_sanitizers)}")
    return False

def main2(c_path):
    with open(c_path, 'r') as file:
        c_files = file.readlines()
    c_files = [line.strip() for line in c_files]
    print(len(c_files))
    CLEAR_DIR2 = "clear_programs2"
    #os.makedirs(CLEAR_DIR2, exist_ok=True)

    for c_file in c_files[1210:]:
        print(c_files.index(c_file))
        if compile_and_test2(c_file):
            print(f"{c_file} passed all sanitizers.")
            pth = CLEAR_DIR2
            try:
                shutil.copy(c_file, pth)
                print(f"File copied successfully from {c_file} to {pth}")
            except FileNotFoundError as e:
                print(f"Error: {e}")
            except PermissionError as e:
                print(f"Permission Error: {e}")
            except Exception as e:
                print(f"Unexpected Error: {e}")

if __name__ == "__main__":
    #path = '/home/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/reshaped_programs/test_input_double_req_bl_1252b.c'
    #compile_and_test(path)
    
    #CLONE_DIR = "/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/GRAYC-CONSERVATIVE"
    #c_files = extract_c_files_with_floats(CLONE_DIR)
   
    #main()
    main2("/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/c_files_list.txt")

    '''
    with open('c_files_list.txt', 'r') as file:
        c_files = file.readlines()

    c_files = [line.strip() for line in c_files]

    for c_file in c_files[0:5]:
        #p = "/home/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/mem_den.c"
        if compile_and_test(c_file):
            print(f"{c_file} passed all sanitizers.")
            pth = CLEAR_DIR
        else:
            pth = PROBLEM_DIR
            # Copy the file
        try:
            shutil.copy(c_file, pth)
            print(f"File copied successfully from {c_file} to {pth}")
        except FileNotFoundError as e:
            print(f"Error: {e}")
        except PermissionError as e:
            print(f"Permission Error: {e}")
        except Exception as e:
            print(f"Unexpected Error: {e}")
'''
