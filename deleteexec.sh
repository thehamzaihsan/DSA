#!/bin/bash

# Call the function with the target directory
delete_executables() {
    for file in "$1"/*; do
        if [[ -d "$file" ]]; then
            delete_executables "$file"  # Recursively call the function for subdirectories
        elif [[ -x "$file" && "$file" != "deleteexec" ]]; then  # Skip the script file itself
            echo "Deleting file: $file"  # Print the name of the file being deleted
            rm "$file"  # Delete the executable file
        fi
    done
}

delete_executables "/media/hamzaihsan/New Volume/projects/DSA"