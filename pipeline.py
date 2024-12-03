import os
import subprocess
import shutil
import re

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
SANITIZERS = "-fsanitize=address -fsanitize=undefined"
COMP_ERR_log = "compilation_error.log"
SAN_ERR_log = "sanitizer_error.log"

# Step 1: Clone Git repository
def clone_repository(repo_url, clone_dir):
    if os.path.exists(clone_dir):
        shutil.rmtree(clone_dir)
    subprocess.run(["git", "clone", repo_url, clone_dir], check=True)
    print(f"Cloned repository into {clone_dir}")

# Step 2: Extract C files with floating-point operations
def extract_c_files_with_floats(clone_dir):
    file_text_path = "c_files_list.txt"
    pattern = re.compile(r'\b(float|double|long double)\b\s+\w+\s*(=\s*[^;]*)?;')
    c_files = []
    
    for root, _, files in os.walk(clone_dir):
        for file in files:
            if file.endswith(".c"):
                file_path = os.path.join('./',root, file)
                # Check for floating-point operations
                with open(file_path, "r") as f:
                    content = f.read()
                if  pattern.search(content):
                    if "int main()" in content:
                        c_files.append(file_path)
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
def detect_sanitizer_type(stderr_output):
    """
    Detect the type(s) of sanitizer errors from the stderr output.
    """
    sanitizer_patterns = {
        "AddressSanitizer": re.compile(r"AddressSanitizer"),
        "MemorySanitizer": re.compile(r"MemorySanitizer"),
        "UndefinedBehaviorSanitizer": re.compile(r"Undefined"),
    }
    detected_sanitizers = []
    for sanitizer, pattern in sanitizer_patterns.items():
        if pattern.search(stderr_output):
            detected_sanitizers.append(sanitizer)
    return ", ".join(detected_sanitizers) if detected_sanitizers else False

# Step 4: Compile and test with sanitizers
def compile_and_test(file_path):
    binary_path = file_path.replace(".c", "")
    compile_cmd = f"gcc {SANITIZERS} -o {binary_path} {file_path}"

    try:
        subprocess.run(compile_cmd.split(), check=True, stderr=subprocess.PIPE)
        print(f"Compiled {file_path} successfully.")
        with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nCompiled successfully\n\n")
        # Run the binary and capture sanitizer output
       
        san_result = subprocess.run([binary_path], stderr=subprocess.PIPE, check=True)
        sanitizer_error = detect_sanitizer_type(san_result.stderr.decode())
        
        if sanitizer_error:
            with open(SAN_ERR_log, "a") as san_error_file:
                san_error_file.write(f"Program: {file_path}\nRuntime Error: {sanitizer_error}\n\n")
            print(f"Sanitizer error logged for {file_path}: {sanitizer_error}")
            return False, None

        print(f"Test passed for {file_path}.")
        return True, sanitizer_error
    
    except subprocess.CalledProcessError as e:
        if e.cmd[0] == "gcc" or "clang" in e.cmd[0]:  # Check if the error is during compilation
            # Log compilation errors
            with open(COMP_ERR_log, "a") as comp_error_file:
                comp_error_file.write(f"Program: {file_path}\nError: {e.stderr}\n\n")
            print(f"Compilation error logged for {file_path}.")
            return False, None
        else:
            sanitizer_error = detect_sanitizer_type(e.stderr.decode())
            # Log sanitizer errors
            with open(SAN_ERR_log, "a") as sanitizer_error_file:
                sanitizer_error_file.write(f"Program: {file_path}\n")
                sanitizer_error_file.write(f"Error: {sanitizer_error} \n\n")
            print(f"Sanitizer exception logged for {file_path}.")
            return False, None
"""
# Step 5: Save results
def save_results(file_path, valid):
    target_dir = VALID_DIR if valid else INVALID_DIR
    os.makedirs(target_dir, exist_ok=True)
    shutil.move(file_path, os.path.join(target_dir, os.path.basename(file_path)))
    print(f"Saved {file_path} to {target_dir}")
"""

# Main pipeline
def main():
    # Clone repository
    #clone_repository(REPO_URL, CLONE_DIR)
    
    # Extract and process C files
    #c_files = extract_c_files_with_floats(CLONE_DIR)
    
    with open('c_files_list.txt', 'r') as file:
        c_files = file.readlines()
    c_files = [line.strip() for line in c_files]
    
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    
    # Reshaping with gpt
    load_dotenv(dotenv_path = ".env")
    key = "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"
    print("Key: ", key)
    if not key:
        print("Error: No OpenAI API key found")
        print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
        sys.exit(1)
    
    gpt = GPTProgramGenerator(OpenAI(api_key=key))
    
    for c_file in c_files[:10]:
        reshaped_file = reshape_file(gpt, c_file, OUTPUT_DIR)
        print(f"Reshaped file saved to {reshaped_file}")
        valid, report_path = compile_and_test(reshaped_file)
        print(valid)
        #save_results(reshaped_file, valid)
        #if not valid:
        #    print(f"Sanitizer report saved to {report_path}")

if __name__ == "__main__":
    main()
