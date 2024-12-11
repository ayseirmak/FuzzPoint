import os
import sys
from time import time
from shlex import quote
import random
import datetime

from Parser import Parser


from openai import OpenAI
from dotenv import load_dotenv


def generate_filename(selected_file: str) -> str:
    return f"test_input_{selected_file}"


def write_to_file(file: str, content: str):
    with open(file, "w") as f:
        f.write(content)

def get_random_program(program_folder_path: str):
    c_files = [f for f in os.listdir(program_folder_path) if f.endswith('.c')]
    selected_file = random.choice(c_files)
    selected_file_path = os.path.join(program_folder_path, selected_file)
    # Read the content of the selected file
    with open(selected_file_path, 'r') as file:
        content = file.read()
    return selected_file, content

def get_program(program_path: str):
    
    selected_file_path = os.path.abspath(os.path.join(".", program_path))
    selected_file = os.path.basename(selected_file_path)
    # Read the content of the selected file
    with open(selected_file_path, 'r') as file:
        content = file.read()
    return selected_file, content
    
class GPTProgramGenerator:
    def __init__(self, client: OpenAI):
        self.client = client
        self.system_prompt = """
        Your task is to convert given **floating point C programs** to **floating point normal programs** and meet specific requirements. All programs must adhere strictly to the following guidelines:
        1. **ARM Compatibility**: Ensure the code can run on ARM architecture without any architecture-specific incompatibilities.
        2. **No Reading Operations**: Exclude any code that uses functions like `scanf`, file I/O, command line arguments or similar input mechanisms.
        3. **No Time Functions or Randomness**: Avoid using time-based functions (e.g., `time()`, `gettimeofday()`) or randomness (`rand()`, `srand()`). Outputs must not rely on any non-deterministic behavior.
        4. **No Uninitialized or Undeclared Variables**: Initialize and declare all variables explicitly before use, ensure the fixed values preserve the intent and logic of the original program and if they affects floating-point operations the initialization values should be chosen to reflect typical use cases or edge cases relevant to the computation.
        5. **Standard Compliance**: Replace custom verifier functions or non-standard libraries with standard C constructs (e.g., assertions, logging with `printf`).
        6. **Return Value 0 **:The program should include return 0; statement at the end of main function. Return 0 to indicate successful execution or a condition passed.
        Your output must maintain functional equivalence and float opeartions to the original program within the specified constraints. It should be correctly compilable without syntax errors.
        """
        self.history = []
        
    def add_to_history(self, prompt: str, response: str):
        if len(self.history) > 5:
            self.history.pop(0)
        self.history.append({
            'role': 'user', 'content': prompt
        })
        self.history.append({
            'role': 'assistant', 'content': response
        })

    def prompt(self, prompt_text: str) -> str:
        try:
            result = self.client.chat.completions.create(
                model="gpt-4o",
                messages=[
                    {
                        'role': 'system', 'content': self.system_prompt
                    },
                    *self.history,
                    {
                        'role': 'user', 'content': prompt_text
                    }
                ]
            )

            #self.add_to_history(prompt_text, result.choices[0].message.content)

            return result.choices[0].message.content
        except Exception as e:
            print(f"Error: {e}")
            return ""

    def generate_program(self, selected_file: str, query: str, ):
        print(f"Prompting")
        result = self.prompt(query)
        print(f"Received response: {result}")
        try:
            pr =  Parser()
            transformed_program = pr.get_c_program(result)
            #print(f"Transformed Program: \n{transformed_program}")

            file_name = generate_filename(selected_file)
        except ValueError as e:
            print(e)
        return file_name, transformed_program
       
    def run(self, program_path: str = None):

        try:
            selected_file, program_content = get_program(program_path)
            #print(f"Selected C Program: {selected_file}")
            #print("Program Content:\n")
            #print(program_content)
            
            query = """
            Can you covert this program to the normal program and add necessary includes.  
            Here is the code :
            """
            prompt = f"{query}\n\n{program_content}"
            
            return self.generate_program(selected_file, prompt)
        except ValueError as e:
            print(e)
        

                




if __name__ == "__main__":    
    load_dotenv(dotenv_path = "/Users/k24057520/PHD/ProgramCollection/.env")
    key = os.getenv("OPENAI_API_KEY")
    print("Key: ", key)

    if not key:
        print("Error: No OpenAI API key found")
        print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
        sys.exit(1)
        
