import os

# Paths
text_file_path = '/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/compilation_error.log'
folder_x_path = '/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/clear_programs'

# Read the text file
with open(text_file_path, 'r') as file:
    lines = file.readlines()

# Extract program names that cause errors
error_programs = []
for line in lines:
    if "Error:" in line:
        prev_line_index = lines.index(line) - 1
        program_line = lines[prev_line_index].strip()
        if program_line.startswith("Program:"):
            program_path = program_line.split("Program:")[1].strip()
            program_name = os.path.basename(program_path)
            error_programs.append(program_name)

# Check if these programs exist in folder X
found_programs = []
for program in error_programs:
    if os.path.exists(os.path.join(folder_x_path, program)):
        found_programs.append(program)

print(found_programs)
print(len(found_programs))

# List all files in the directory
folder_path = "/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/clear_programs"
folder_path2 = "/users/a_irmak/FloatingPoint_and_CompilerTesting/ProgramCollection/reshaped_programs"
num_files = len([f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))])

print(f"Number of files: {num_files}")

# List all files in the directory
num_files = len([f for f in os.listdir(folder_path2) if os.path.isfile(os.path.join(folder_path2, f))])

print(f"Number of files: {num_files}")