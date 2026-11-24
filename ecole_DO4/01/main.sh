#!/usr/bin/env bash
set -euo pipefail

# check that all arguments are passed by the user
if (( $# < 6 )); then
    echo "Usage: ./main.sh [PATH] [DIR MAX] [LETTERS FOR DIR NAME] [FILES MAX] [LETTERS FOR FILE 'BASENAME.EXTENSION'] [FILESIZE in KB]"
    exit 1
fi

abs_path=$1 #строка (абсолютный путь) (должна быть без пробелов по идее)

#initialize LOG file
LOGFILE="$abs_path/01.log"

dirs_max=$2 #количество сабдиректорий
letters_dir=$3 # разрешенные латинские буквы - только a-z, максимум 7
files_max=$4 #макс кол-во файлов в одной созданной сабдиректории
letter_w_extension=$5 # разрешенные латинские буквы для названия и через точку для расширения. (a-z).(a-z) не больше 7 для названия и не больше 3 для расширения
filesize_kb=$6 #не больше 100


basename="${letter_w_extension%%.*}"
extension="${letter_w_extension#*.}"

check_free_space() {
    local path="$1"           # Directory or mount point to check
    local min_gb="$2"         # Minimum required free space in GB
    local free_gb

    # Get available space in human-readable format (e.g., 1G, 500M)
    free_gb=$(df -h "$path" --output=avail | tail -n 1 | sed 's/[A-Za-z]*//g')

    # Convert free space to GB (if it's in MB, KB, etc.)
    if [[ "$free_gb" == *G ]]; then
        free_gb="${free_gb%G}"
    elif [[ "$free_gb" == *M ]]; then
        free_gb=$(echo "$free_gb" | sed 's/M//g')
        free_gb=$(awk "BEGIN {print $free_gb/1024}")
    elif [[ "$free_gb" == *K ]]; then
        free_gb=$(echo "$free_gb" | sed 's/K//g')
        free_gb=$(awk "BEGIN {print $free_gb/1048576}")
    fi

    # Compare free space with the minimum required
    if (( $(echo "$free_gb < $min_gb" | bc -l) )); then
        echo "Free space on $path below threshold ($min_gb GB). Stopping script."
        return 1
    else 
	return 0
    fi
}

check_arguments(){
	local flag=0 
	if [[ "$abs_path" == *" "* ]]; then 
		((flag++))
		echo "Argument 1 not accepted. [PATH] cannot contain spaces. Please try again."
	fi

	if (( ${#letters_dir} > 7|| ${#letters_dir} < 1 )); then
		((flag++))
		echo "Argument 3 not accepted. Letters for directory: min 1, max 7. Please try again."
	fi

	if [[ "$letters_dir" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 3 not accepted. Letters for directory: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if [[ "$basename" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 5 not accepted. Letters for basename: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if (( ${#basename} > 7 || ${#basename} < 1 )); then
		((flag++))
		echo "Argument 5 not accepted. Letters for basename: min 1, max 7. Please try again."
	fi

	if [[ "$extension" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 5 not accepted. Letters for extension: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if (( ${#extension} > 3 || ${#extension} < 1 )); then
		((flag++))
		echo "Argument 5 not accepted. Letters for extension: min 1, max 3. Please try again."
	fi

	if (( $filesize_kb > 100 || $filesize_kb == 0 )); then 
		((flag++))
		echo "Argument 6 not accepted. Filesize must be 1-100 (Kilobytes). Please try again."
	fi

	return $flag
}


generate_names() {
  local base="$1"
  local total="$2"   # how many names to emit (including the base).
  local len=${#base}
  if (( len == 0 )); then
	  return
  elif (( len < 4 )); then
	  local last_char="${base: -1}"            
	  while (( ${#base} < 4 )); do
	  	base+="$last_char"
	  done
	  len=${#base}
  fi

  # init counts (each letter appears at least once)
  local -a counts
  for ((i=0;i<len;i++)); do counts[i]=1; done

  emitted_names=() # declare a blank globally acessible indexed array 

  local emitted=0
  for (( ; emitted < total; emitted++ )); do
    # build current name from counts
    local name=""
    for ((i=0;i<len;i++)); do
      local ch="${base:i:1}"
      local rep=${counts[i]}
      for ((r=0;r<rep;r++)); do
        name+="$ch"
      done
    done
    # put emitted name in a hash table used_names
    emitted_names+=("$name")

    # choose which letter to increment next: left-to-right round-robin
    local idx=$(( (emitted-1) % len ))   # after emitting the base (emitted==1) -> idx=0
    counts[idx]=$(( counts[idx] + 1 ))
  done
}

create_files(){
	generate_names "$letters_dir" "$dirs_max"
	local dir_list=()
	local date=$(date +"%d%m%y")
	#create directories
	for (( i=0; i<dirs_max; i++ )); do
		dir_list+=("$abs_path/${emitted_names[i]}_$date")
       	        # Check free space before creating each file
	        if check_free_space "/" "1"; then
			# create directory on fs
			mkdir -p "${dir_list[i]}"
			# Log directory
			echo "DIR | ${dir_list[i]} | Created: $(date "+%Y-%m-%d_%H:%M:%S")" >> "$LOGFILE"
		else
			return 1
		fi
	done

	# Generate file names
	generate_names "$basename" "$files_max"
	local file_names=("${emitted_names[@]}")  # save file names
	
	# Create files and write files to disk
	local fn_list=()
	local threshold=0
	for (( i=0; i<dirs_max; i++ )); do
	    for (( j=0; j<files_max; j++ )); do
	        filename="${dir_list[i]}/${file_names[j]}_$date.$extension"
	        fn_list+=("$filename")
	
	   	    # Check free space before creating each file
	        if check_free_space "/" "1"; then 
		       	#fill files with zeroes and append information on creation to logfile
			dd if=/dev/zero of="$filename" bs=1K count="$filesize_kb" status=none
			echo "FILE | $filename | Created: $(date +"%Y-%m-%d_%H:%M:%S") | Size: ${filesize_kb}K" >> "$LOGFILE"
		else 
			return 1
		fi
	    done
	done
}

## SCRIPT FUNCTIONS CALL FLOW
if check_arguments; then
	create_files
else
	echo "Invalid arguments, exiting.."
	exit 1
fi
