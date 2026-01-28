#!/bin/bash

# Script to create a new raw note file for a class
# Usage: ./new-note.sh [course_code]
# Example: ./new-note.sh 381

if [ -z "$1" ]; then
    echo "Usage: ./new-note.sh [course_code]"
    echo "Example: ./new-note.sh 381"
    exit 1
fi

COURSE_CODE="$1"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COURSE_DIR="${SCRIPT_DIR}/cecs${COURSE_CODE}"
DATE=$(date +"%m-%d-%Y")
RAW_FILE="${COURSE_DIR}/raw-${DATE}.md"

# Create course directory if it doesn't exist
mkdir -p "$COURSE_DIR"

# Check if file already exists
if [ -f "$RAW_FILE" ]; then
    echo "File already exists: $RAW_FILE"
    exit 0
fi

# Create the raw note file
touch "$RAW_FILE"

echo "Created new raw note file: $RAW_FILE"
