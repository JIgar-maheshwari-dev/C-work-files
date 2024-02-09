#!/bin/bash

# Define the source and target paths
source_file_1="./book_files/book_records.txt"
target_file_1="/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/book_records.txt"

source_file_2="./book_files/count.txt"
target_file_2="/home/jigar/Downloads/training/jigar_maheshwari_idp/mega/book_files/count.txt"

# Define the directory path
directory="srs"

# Loop through all files in the specified directory
for file in "./src"/*; do
    # Check if the file is a regular file
    if [ -f "$file" ]; then
        # Replace occurrences of source_file_1 with target_file_1
        sed -i "s|$source_file_1|$target_file_1|g" "$file"
        
        # Replace occurrences of source_file_2 with target_file_2
        sed -i "s|$source_file_2|$target_file_2|g" "$file"
        
        echo "Replaced occurrences in $file"
    fi
done

echo "Replacement complete!"

