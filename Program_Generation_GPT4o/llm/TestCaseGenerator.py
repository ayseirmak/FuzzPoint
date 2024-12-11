import os
import sys
from time import time
from shlex import quote

from openai import OpenAI
from dotenv import load_dotenv

def query_jar(jar_file: str, type_of_query: str, query: str | None = None) -> str:
    """
    This function will query the class file with the given query and return the result
    """
    if query is None:
        # We are querying for a type of query
        print(f"java -jar {jar_file} QueryGenerator {type_of_query}")
        result = os.popen(f"java -jar {jar_file} QueryGenerator {type_of_query}").read()
    else:
        # We are querying for a specific query
        print(f"java -jar {jar_file} QueryGenerator {type_of_query} {quote(query)}")
        result = os.popen(f"java -jar {jar_file} QueryGenerator {type_of_query} {quote(query)}").read()
    return result


def generate_filename() -> str:
    return "test_input_" + str(int(time())) + ".c"


def write_to_file(file: str, content: str):
    with open(file, "w") as f:
        f.write(content)

def save_results(program: str, call_line: str, args_type: str, prompt_type: str):
    try:
        file_name_c = generate_filename()
        file_path = os.path.join(os.getcwd(), file_name_c)
        if (prompt_type == "1"):
            file_path = os.path.join(os.getcwd(), "Custom_Programs/", file_name_c)
        elif (prompt_type == "2"):
            file_path = os.path.join(os.getcwd(), "EdgeCase_Programs/", file_name_c)
        elif (prompt_type == "4"):  
            file_path = os.path.join(os.getcwd(), "Random_Programs/", file_name_c)
        write_to_file(file_path, program)
    except Exception as e:
        print(f"Error: {e}")

class GPTProgramGenerator:
    def __init__(self, file: str, client: OpenAI, sys_prompt: str = "0" or "3"):
        self.jar_path = file
        self.client = client
        self.system_prompt = query_jar(file, sys_prompt)
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

            self.add_to_history(prompt_text, result.choices[0].message.content)

            return result.choices[0].message.content
        except Exception as e:
            print(f"Error: {e}")
            return ""

    def generate_program(self,prompt_type: str = "1" or "2" or "4"):
        query = query_jar(self.jar_path, prompt_type)
        print(f"Prompting GPT-4o with: \n{query}")
        result = self.prompt(query)
        print(f"Received response: {result}")
        result = query_jar(self.jar_path, "5", result)

        try:
            types = result.split("\n")[0]
            call_line = result.split("\n")[1]
            program = "\n".join(result.split("\n")[2:])

            print(f"Generated program: \n{program}")
            print(f"Types: {types}")
            print(f"Call line: {call_line}")

            save_results(program, call_line, types, prompt_type)
        except IndexError:
            print("Error: failed to parse response")
            return

    def run(self):
            start = time()

            time_to_run = 375
            while True:
                self.generate_program("4")
                if time() - start > time_to_run:
                    print(f"Time limit reached ({time() - start} seconds)")
                    break




if __name__ == "__main__":
    args = sys.argv

    # We expect a jar file location (default to ./QueryGenerator.jar)
    if len(args) < 2:
        # Check if the jar file exists
        if not os.path.exists("./QueryGenerator.jar"):
            print("Error: No jar file found at ./QueryGenerator.jar")
            print("Usage: python3 TestCaseGenerator.py <path_to_jar_file>")
            sys.exit(1)
        else:
            jar = "./QueryGenerator.jar"
    else:
        jar = args[1]
    key = "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"
    print("Key: ", key)

    if not key:
        print("Error: No OpenAI API key found")
        print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
        sys.exit(1)

    gpt = GPTProgramGenerator(jar, OpenAI(api_key=key),"3")

    gpt.run() 


    
# Load environment variables
# load_dotenv()
# client = OpenAI(os.getenv('OPENAI_API_KEY'))

############################################################
#javac prompt/*.java                                       #
#jar cfm QueryGenerator.jar MANIFEST.MF -C . prompt        #
############################################################

#*/