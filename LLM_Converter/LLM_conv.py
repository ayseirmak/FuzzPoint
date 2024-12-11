
import os
import subprocess
import shutil
import re
import chardet

from reshaper import GPTProgramGenerator
from openai import OpenAI
from dotenv import load_dotenv
import sys
from reshaper import GPTProgramGenerator
from openai import OpenAI


def reshape_file(gpt, file_path, output_dir):
    file_name, transformed_program = gpt.run(file_path)
    file_idx = len(os.listdir(output_dir)) + 1
    file_name = f"{file_idx}_{file_name}"
    reshaped_file_path = os.path.join(output_dir, file_name)
    with open(reshaped_file_path, "w") as f:
        f.write(transformed_program)
    return reshaped_file_path

key = "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"
#key = os.getenv("OPENAI_API_KEY")
print("Key: ", key)
if not key:
    print("Error: No OpenAI API key found")
    print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
    sys.exit(1)

gpt = GPTProgramGenerator(OpenAI(api_key=key))

current_directory = os.path.dirname(os.path.abspath(__file__))
c_file = "c_file.c"
# Create the full path of the file
file_path = os.path.join(current_directory, c_file)
OUTPUT_DIR = "converted_programs"


reshaped_file = reshape_file(gpt, file_path, OUTPUT_DIR)
print(f"Converted file saved to {reshaped_file}")