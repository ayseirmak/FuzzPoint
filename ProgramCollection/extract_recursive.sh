#!/bin/bash

# Extract the main ZIP file
7z x "$1" -o"${1%.zip}"

# Function to extract nested ZIP files
extract_nested_zips() {
    find "$1" -type f -name "*.zip" | while read -r nested_zip; do
        echo "Extracting $nested_zip"
        nested_dir="${nested_zip%.zip}"
        7z x "$nested_zip" -o"$nested_dir"
        rm "$nested_zip"  # Optional: delete the nested ZIP after extraction
        extract_nested_zips "$nested_dir"  # Recursively extract further nested ZIPs
    done
}

# Call the function on the output directory
extract_nested_zips "${1%.zip}"
