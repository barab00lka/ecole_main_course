#!/bin/bash
start=$(date +%s)
DIR=$1
if ! [[ "$DIR" ]]; then 
	echo "Usage: main.sh [DIRECTORY]"
	exit 1
fi
echo "Loading..."

TOTAL_DIR=$(find $DIR -type d | wc -l)

TOP5_WEIGHT(){
du -h "$DIR" | sort -hr | tail -n +2 | head -n 5 | nl -w1 -s" - " | while IFS= read -r line; do
    # Extract number and rest using the first ' - ' as separator
    num="${line%% - *}"
    rest="${line#* - }"

    # Extract size (first word) and path (rest)
    size="${rest%%[[:space:]]*}"
    path="${rest#*$size}"
    path=$(echo "$path" | xargs)   # trim leading spaces

    # Print formatted output
    echo "$num - $path/, $size"
done
}

FILES_TOTAL=$(find $DIR -type f | wc -l)

CONFS_TOTAL=$(find $DIR -type f -name "*.conf" | wc -l) 

TEXTFILES_TOTAL=$(find $DIR -type f -exec file --mime-type {} + | grep 'text/' | wc -l)

EXECUTABLES_TOTAL=$(find "$DIR" -type f -exec file -b {} + \
  | grep -E 'executable|PE32' \
  | wc -l)

LOGFILES_TOTAL=$(find $DIR -type f -name "*.log" | wc -l)

ARCHIVE_TOTAL=$(find $DIR -type f -exec file --mime-type -b {} + | grep -E 'application/(zip|x-tar|gzip|x-gzip|x-bzip2|x-xz|x-7z-compressed|vnd.rar|x-rar|x-arc|x-arj|x-lzh|x-lzip|x-lzma|x-compress|x-apple-diskimage|vnd.android.package-archive|x-cpio|x-iso9660-image|zstd)' | wc -l)

SYMLINKS_TOTAL=$(find $DIR -type l | wc -l)

TOP10_MAX_SIZE(){
find "$DIR" -type f -exec du -h {} + 2>/dev/null \
  | sort -hr \
  | head -n 10 \
  | while IFS=$'\t' read -r size path; do
      type=$(file -b --mime-type "$path")
      [[ "$type" == "application/x-executable" ]] && type="exe"
      echo "$path|$size|$type"
  done | nl -w1 -s' - ' | awk -F'|' '{print $1 " - " $2 ", " $3 " " $4}'
}

TOP10_EXEC_MD5(){
find "$DIR" -type f 2>/dev/null \
  | while IFS= read -r file_path; do
      # Only process executables
      if file -b "$file_path" | grep -q -E "executable|PE32|script"; then
          du -h "$file_path"
      fi
  done \
  | sort -hr \
  | head -n 10 \
  | while IFS=$'\t' read -r size path; do
      md5=$(md5sum "$path" | cut -d' ' -f1)
      echo "$path|$size|$md5"
  done | nl -w1 -s' - ' | awk -F'|' '{print $1 " - " $2 ", " $3 " " $4}'
}

output=$(
	echo "Total number of folders (including all nested ones) = $TOTAL_DIR"
	echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
	TOP5_WEIGHT
	echo "Total number of files = $FILES_TOTAL"
	echo "Number of:"
	echo "Configuration files (with the .conf extension) = $CONFS_TOTAL" 
	echo "Text files = $TEXTFILES_TOTAL"
	echo "Executable files = $EXECUTABLES_TOTAL"
	echo "Log files (with the extension .log) = $LOGFILES_TOTAL"
	echo "Archive files = $ARCHIVE_TOTAL"
	echo "Symbolic links = $SYMLINKS_TOTAL"
	echo "------------------------------------------------------"
	echo "TOP 10 files of maximum size arranged in descending order (path, size and type):" 
	TOP10_MAX_SIZE
	echo "------------------------------------------------------"
	echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
	TOP10_EXEC_MD5
)

echo "$output"
end=$(date +%s)
runtime=$((end - start))
echo "Script execution time (in seconds) = $runtime"
