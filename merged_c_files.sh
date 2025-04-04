#!/bin/bash
destination="C-programset"
mkdir -p "$destination"

directories=(
    "ProgramCollection/SoSy-lab-2024/clear_programs"
    "ProgramCollection/SearhGem5/clear_programs"
    "ProgramCollection/LLM_Generated/clear_programs2"
    "ProgramCollection/Klee-float/clear_programs"
    "ProgramCollection/GrayC/10-sets-of-test-programs-Clang-FuzzerU/clear_programs"
    "ProgramCollection/GrayC/10-sets-of-test-programs-GrayC-No-Coverage-GuidanceU/clear_programs"
    "ProgramCollection/GrayC/10-sets-of-test-programs-GrayC-aggressive/clear_programs"
    "ProgramCollection/GrayC/GrayC-Conservative/clear_programs"
)

for dir in "${directories[@]}"; do
    if [ ! -d "$dir" ]; then
        echo "Directory $dir not found, skipping."
        continue
    fi

    # Dizin yolunun kısa bir hash'ini oluştur (ilk 6 karakter)
    dir_hash=$(echo -n "$dir" | md5sum | cut -c1-6)
    
    for file in "$dir"/*.c; do
        [ -e "$file" ] || continue
        
        base=$(basename "$file")
        newname="${dir_hash}-${base}"
        count=1
        finalname="$destination/$newname"
        while [ -e "$finalname" ]; do
            finalname="$destination/${dir_hash}-${count}-${base}"
            count=$((count+1))
        done
        cp "$file" "$finalname"
        echo "Copied $file to $finalname"
    done
done

