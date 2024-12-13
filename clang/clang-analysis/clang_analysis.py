import os

# Define the paths related to BACKEND and MIDDLE-END
backend_paths = [
    "clang/lib/CodeGen",
    "llvm/lib/AsmParser",
    "llvm/lib/Bitcode",
    "llvm/lib/CodeGen",
    "llvm/lib/DebugInfo",
    "llvm/lib/ExecutionEngine",
    "llvm/lib/Linker",
    "llvm/lib/LTO",
    "llvm/lib/MC",
    "llvm/lib/MCA",
    "llvm/lib/Support",
    "llvm/lib/Target",
    "llvm/utils/TableGen",
]

middle_end_paths = [
    "clang/lib/Analysis",
    "llvm/lib/Analysis",
    "llvm/lib/BinaryFormat",
    "llvm/lib/DebugInfo",
    "llvm/lib/IR",
    "llvm/lib/IRReader",
    "llvm/lib/Object",
    "llvm/lib/ObjectYAML",
    "llvm/lib/Passes",
    "llvm/lib/Support",
    "llvm/lib/Transforms",
]

# Keywords related to optimization
keywords = ["optimization", "optimize", "optimizer"]
keywords_enh = ["optimization", "optimize", "optimizer", "pass", "transform", "inline", "unroll"]
# Output log file
log_file_path = "optimization_files.log"
pth = "/users/a_irmak/llvm-project"
def find_optimization_files(paths, keywords, log_file):
    matched_files = []   
    for path2 in paths:
        path = os.path.join(pth,path2)
        for root, dirs, files in os.walk(path):
            for file in files:
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        # Check if any keyword exists in the file content
                        if any(keyword.lower() in content.lower() for keyword in keywords):
                            matched_files.append(file_path)
                            print(f"Found: {file_path}")
                            print(f"Found: {file_path}")
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")

    # Save matched file paths to the log file
    with open(log_file, "w") as log:
        for file_path in matched_files:
            log.write(file_path + "\n")
    
    print(f"\nLog saved to {log_file}")

# Run the function
find_optimization_files(middle_end_paths, keywords, log_file_path)