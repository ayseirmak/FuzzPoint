import os
import re

# Lists of directories
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

# Keywords for classification
keywords = {
    "number": [r"\bAPFloat\b", r"\bAPInt\b", r"\bfloat\b", r"\bdouble\b", r"\bConstantFP\b", r"\bConstantInt\b"],
    "type": [r"\bType\b", r"\bQualType\b", r"\bASTContext\b", r"\bBuiltinType\b", r"\bstruct\b", r"\bunion\b"],
    "optimization": [r"\bPass\b", r"\boptimize\b", r"\bTransform\b", r"\bInstCombine\b", r"\bLoopUnroll\b"],
}

# Function to classify files based on keywords
def classify_files(paths):
    results = {"number": [], "type": [], "optimization": []}

    for path in paths:
        for root, _, files in os.walk(path):
            for file in files:
                if file.endswith((".cpp", ".h", ".td")):
                    file_path = os.path.join(root, file)
                    try:
                        with open(file_path, "r", errors="ignore") as f:
                            content = f.read()
                            for category, patterns in keywords.items():
                                if any(re.search(pattern, content) for pattern in patterns):
                                    results[category].append(file_path)
                    except Exception as e:
                        print(f"Error reading {file_path}: {e}")

    return results

# Combine both lists
all_paths = backend_paths + middle_end_paths

# Run the classification
results = classify_files(all_paths)

# Print the results
for category, files in results.items():
    print(f"\nFiles related to {category.upper()}:")
    for file in files:
        print(f"  - {file}")