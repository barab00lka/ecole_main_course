#!/usr/bin/env bash
set -eo pipefail

mode="$1"
#modes:
#1 by log file
#2 by cretion date and time (start time - end time [year-month-day_hour:minute] )
#3 by name mask of folder (i.e. [abcd_DayMonthYear])

clear_by_log(){
	local log_path="$1"
	count=$(grep 'DIR |' $LOG_PATH | cut -d' ' -f3 | wc -l)
	grep 'DIR |' "$log_path" | cut -d' ' -f3 | while read -r dir; do
		rm -rfv "$dir"
	done
}

clear_by_date(){
	local cr_date_start="${1//_/ }"
	local cr_date_end="${2//_/ }"
	dirs=( $(find / -type d -newermt "$cr_date_start" ! -newermt "$cr_date_end" -not -path "*/bin/*" 2>/dev/null) )
	for dir in "${dirs[@]}"; do
		echo "Delete "$dir"? (y)es | (n)o"
		read -n 1 -r answer
		echo
		case "$answer" in 
		[yY]) rm -rfv "$dir"
			;;
		[nN]) echo "Skipped '$dir'"
			;;
		*) echo "Invalid choice, exiting..."
		return 1
			;;
		esac
	done
}

clear_by_name(){
	local name_mask="$1"
	echo "$name_mask"
	files=( $(find / -type f -iname "$name_mask*" 2>/dev/null) )	
	for file in "${files[@]}"; do
		echo "Delete "$file"? (y)es | (n)o"
		read -n 1 -r answer
		echo
		case "$answer" in 
		[yY]) rm -fv "$file"
			;;
		[nN]) echo "Skipped '$file'"
			;;
		*) echo "Invalid choice, exiting..."
		return 1
			;;
		esac
	done
}

if [[ $mode -eq 1 ]]; then
	if [[ -n "$2" ]]; then
		LOG_PATH="$2"
	else 
		echo "Please provide full path to the logfile (user home directory should be written explicitly without using '~')"
		read -r LOG_PATH
	fi
	clear_by_log "$LOG_PATH"
elif [[ $mode -eq 2 ]] then 
	if [[ -n "$2" && -n "$3" ]]; then
		CR_DATE_START="$2"
		CR_DATE_END="$3"
		clear_by_date "$CR_DATE_START" "$CR_DATE_END"
	else 
		echo "Please provide creation date and time interval for the files that need to be deleted. Format: [yyyy-mm-dd_HH:MM] [yyyy-mm-dd_HH:MM]"
		read -r CR_DATE_START CR_DATE_END
		clear_by_date "$CR_DATE_START" "$CR_DATE_END"
	fi

elif [[ $mode -eq 3 ]] then 
	if [[ -n "$2" ]]; then 
		NAMEMASK="$2"
		clear_by_name "$NAMEMASK"
	else 
		echo "Please provide name mask (i.e. characters, underlining and date). Format: [xxxxx_000000]:" 
		read -r NAMEMASK
		clear_by_name "$NAMEMASK"
	fi
else 
	echo -e "Usage: ./main.sh [PARAMETER] ...\nAvailable parameters:\n1 - By log file: [1] [FULL PATH TO LOGFILE];\n2 - By creation date and time interval: ./main.sh [2] [yyyy-mm-dd_HH:MM] [yyyy-mm-dd_HH:MM];\n3 - By name mask (i.e. characters, underlining and date): ./main.sh [3] [xxxxx_000000];"
fi

