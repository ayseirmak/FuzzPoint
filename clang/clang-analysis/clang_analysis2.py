import os
import re

# Backend and Middle-End directories
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

# Keywords for each category
keywords = {
    "number": [
        r"APInt", r"APFloat", r"ConstantInt", r"ConstantFP", r"\bfloat\b", r"\binteger\b", r"\bdouble\b",
        r"\badd\b", r"\bsub\b", r"\bmul\b", r"\bdiv\b", r"\bround\b", r"\brem\b", r"\bmod\b", r"\bpow\b", r"\bsqrt\b",
        r"\bround\b", r"\bfloor\b", r"\bceil\b", r"\btrunc\b", r"\bfabs\b", r"\bfmod\b", r"\blog\b", r"\bexp\b",
        r"\bNaN\b", r"\bINF\b", r"\bdenormal\b", r"\bFPClass\b", r"\bisnan\b", r"\bisinf\b"
    ],

    "type": [r"\bType\b", r"QualType", r"BuiltinType", r"IntType", r"FloatType",
             r"ASTContext", r"ASTNode", r"TypeInfo", r"TypeDecl", 
             r"\bstruct\b", r"\bunion\b", r"\benum\b", r"typeCheck",r"checkType", r"typeCast", r"getType"],

    "optimization": [r"Pass", r"optimize",r"optimization", r"Transform", r"inline", r"unroll", 
                     r"InstCombine",r"InstSimplify",r"SCCP", r"GVN", r"LICM" , r"CodeGenPass",r"Emit", r"InlineFunction"]
}

# Function to scan files for keywords
def scan_files(directories, keywords, category_name):
    results = {category: [] for category in keywords}
    pth = "/users/a_irmak/llvm-project"
    for drt in directories:
        directory = os.path.join(pth,drt)
        if os.path.exists(directory):
            for root, _, files in os.walk(directory):
                for file in files:
                    if file.endswith(".cpp") or file.endswith(".h"):
                        file_path = os.path.join(root, file)
                        try:
                            with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                                content = f.read()
                                for category, patterns in keywords.items():
                                    if any(re.search(pattern, content, re.IGNORECASE) for pattern in patterns):
                                        results[category].append(file_path)
                        except Exception as e:
                            print(f"Error reading {file_path}: {e}")
        else:
            print(f"Directory not found: {directory}")
    
    # Write results to log files
    for category, files in results.items():
        log_filename = f"{category_name}_{category.lower()}_files.log"
        with open(log_filename, "w", encoding="utf-8") as log_file:
            log_file.write(f"{'='*20} {category} Related Files {'='*30}\n")
            for file in sorted(set(files)):
                log_file.write(file + "\n")
        print(f"Results saved to: {log_filename}")

# Run scans for backend and middle-end paths
scan_files(backend_paths, keywords, "backend")
scan_files(middle_end_paths, keywords, "middleend")