#!/usr/bin/env bash
set -eo pipefail
#start time
start=$(date +%s)
time_of_start=$(date +%Y-%m-%d_%H:%M:%S)

# check that all arguments are passed by the user
if (( $# < 3 )); then
    echo "Usage: ./main.sh [LETTERS FOR DIR NAME] [LETTERS FOR FILE 'BASENAME.EXTENSION'] [FILESIZE in MB]"
    exit 1
fi

#initialize LOG file
LOGFILE="02.log"

letters_dir=$1 # разрешенные латинские буквы - только a-z, максимум 7
letter_w_extension=$2 # разрешенные латинские буквы для названия и через точку для расширения. (a-z).(a-z) не больше 7 для названия и не больше 3 для расширения
filesize_mb=$3 #не больше 100


basename="${letter_w_extension%%.*}"
extension="${letter_w_extension#*.}"

check_free_space() {
    local path="$1"      # Directory or mount point
    local min_gb="$2"    # Minimum required GB
    local free_kb free_gb

    # Get available space in kilobytes (always numeric)
    free_kb=$(df -k --output=avail "$path" | tail -n 1)
    # Convert minimum GB to KB
    local min_kb=$((min_gb * 1024 * 1024))

    if (( free_kb < min_kb )); then
        echo "Free space on $path below threshold (${min_gb}GB). Stopping script..."
        return 1
    else
        return 0
    fi
}

check_arguments(){
	local flag=0 

	if (( ${#letters_dir} > 7 || ${#letters_dir} < 1 )); then
		((flag++))
		echo "Argument 1 not accepted. Letters for directory: min 1, max 7. Please try again."
	fi

	if [[ "$letters_dir" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 1 not accepted. Letters for directory: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if [[ "$basename" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 2 not accepted. Letters for basename: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if (( ${#basename} > 7 || ${#basename} < 1 )); then
		((flag++))
		echo "Argument 2 not accepted. Letters for basename: min 1, max 7. Please try again."
	fi

	if [[ "$extension" =~ [^a-zA-Z] ]]; then
		((flag++))
		echo "Argument 2 not accepted. Letters for extension: can only be ASCII a-z/A-Z letters. Please try again."
	fi

	if (( ${#extension} > 3 || ${#extension} < 1 )); then
		((flag++))
		echo "Argument 2 not accepted. Letters for extension: min 1, max 3. Please try again."
	fi

	if (( $filesize_mb > 100 || $filesize_mb == 0 )); then 
		((flag++))
		echo "Argument 3 not accepted. Filesize must be 1-100 (Megabytes). Please try again."
	fi

	return $flag
}


generate_names() {
  local base="$1"
  local total="$2"   # how many names to emit (including the base).
  local len=${#base}
  if (( len == 0 )); then
	  return
  elif (( len < 5 )); then
	  local last_char="${base: -1}"            
	  while (( ${#base} < 5 )); do
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
	local abs_path="$1"
	local subdirs_max=100

	generate_names "$letters_dir" "$subdirs_max"
	local dir_list=()
	local date=$(date +"%d%m%y")
	#create directories
	for (( i=0; i<subdirs_max; i++ )); do
		dir_list+=("$abs_path/${emitted_names[i]}_$date")
       	        # Check free space before creating each file
	        if check_free_space "/" "1"; then
			# create directory on fs
			mkdir -p "${dir_list[i]}"
			# Log directory
			echo "DIR | ${dir_list[i]} | Created: $(date +"%Y-%m-%d_%H:%M:%S")" >> "$LOGFILE"
		else
			return 1
		fi
	done

    # Generate file names
    generate_names "$basename" "50"
    local file_names=("${emitted_names[@]}")  # save file names

    # Create files and write files to disk
    local fn_list=()
    local threshold=0
    for (( i=0; i<subdirs_max; i++ )); do
	    for (( j=0; j<RANDOM % 50 + 1; j++ )); do
            filename="${dir_list[i]}/${file_names[j]}_$date.$extension"
            fn_list+=("$filename")
	        if check_free_space "/" "1"; then
	    		#fill files with zeroes and append information on creation to logfile
	    		dd if=/dev/zero of="$filename" bs=1M count="$filesize_mb" status=none
	    		echo "FILE | $filename | Created: $(date +"%Y-%m-%d_%H:%M:%S") | Size: ${filesize_mb}MB" >> "$LOGFILE"
		else
			return 1
		fi
        done
    done
}

fs_clogging(){
	local path="$1"
	create_files "$path"
}

find_dirs_to_clog(){
 # Precompute array of writable top-level directories 
 writable_dirs=($(find / -maxdepth 1 -type d ! -name "bin" ! -name "sbin" ! -name "proc" ! -name "sys" ! -name "dev" ! -name "boot" -writable 2>/dev/null))
 # Safety check: exit if no writable directories found
 if (( ${#writable_dirs[@]} == 0 )); then
     echo "Error: No writable directories found on root filesystem."
     return 1
 fi
}

## SCRIPT FUNCTIONS CALL FLOW
if check_arguments && find_dirs_to_clog; then
	# Loop while there is at least 1 GB free
	echo "Started fs clogging. Kill the process yourself or wait until there is 1GB left on /"
	key=""
	while check_free_space "/" "1" && [[ ! "$key" =~ [qQ] ]]; do
	    wr_dir="${writable_dirs[RANDOM % ${#writable_dirs[@]}]}"
		    # stops the loop if fs_clogging returns 1 (in case free space check inside fs_clogging returns flag)
	    fs_clogging "$wr_dir" || break
	    read -r -n 1 key 2>/dev/null
	    sleep 1
	done
	echo "FS clogging is done! Check log '02.log'."
else
	echo "Invalid arguments, exiting.."
	exit 1
fi

# Display start time end time and total running time of the script and append it to logfile as well
end=$(date +%s)
time_of_end=$(date +%Y-%m-%d_%H:%M:%S)
runtime=$((end - start ))
## Echo final script stats on stdout and append to logfile also

{
    echo "Start time = $time_of_start"
    echo "End time = $time_of_end"
    echo "Script execution time (in seconds) = $runtime"
} | tee -a "$LOGFILE"
