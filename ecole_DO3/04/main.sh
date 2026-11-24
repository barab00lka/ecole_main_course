#!/bin/bash


DEFAULTFLAG=0

setColorsFromFile(){
	source ./main.conf
	## if one or more colors are not specified within allowed values (1-6)
	if ! [[ "$column1_font_color" =~ ^[1-6]$ && "$column1_background" =~ ^[1-6]$ && "$column2_font_color" =~ ^[1-6]$ && "$column2_background" =~ ^[1-6]$ ]]; then
		column1_background=1
		column1_font_color=6
		column2_background=6
		column2_font_color=3
		DEFAULTFLAG=1
	fi
}

# function to check that bg and fg colors are not the same 
checkColors() {
	if [[ "$column1_background" == "$column1_font_color" || "$column2_background" == "$column2_font_color" ]]; then
		echo "Please enter different colors for background and text."
		return 1
	else 
		return 0
	fi
}

## Function for colorized outputs
colorized_echo() {
    local color=$1
    local text=$2
    local background=$3  

    # Map background names to ANSI codes
    local background_code=""
    case $background in
        "1") background_code="\e[47m";; ## white
        "2") background_code="\e[41m";; ## red
        "3") background_code="\e[102m";; ## green
        "4") background_code="\e[44m";; ## blue
        "5") background_code="\e[45m";; ## purple
        "6") background_code="\e[40m";; ## black
        *) background_code="";; ## no bg color
    esac

    case $color in
        "1")
            printf "\e[37m${background_code}${text}\e[0m";; ## white
        "2")
            printf "\e[31m${background_code}${text}\e[0m";; ## red
        "3")
            printf "\e[32m${background_code}${text}\e[0m";; ## green
        "4")
            printf "\e[34m${background_code}${text}\e[0m";; ## blue
        "5")
            printf "\e[35m${background_code}${text}\e[0m";; ## purple 
        "6")
            printf "\e[30m${background_code}${text}\e[0m";; ## black
        *)
            echo "${text}" ## no foreground color
        ;;
    esac
}

setColorsFromFile

setColorHeader(){
	if [[ "$1" == 1 ]]; then
		echo "(white)"
	elif [[ "$1" == 2 ]]; then
		echo "(red)"
	elif [[ "$1" == 3 ]]; then
		echo "(green)"
	elif [[ "$1" == 4 ]]; then
		echo "(blue)"
	elif [[ "$1" == 5 ]]; then
		echo "(purple)"
	elif [[ "$1" == 6 ]]; then
		echo "(black)"
	fi
}

COLORSCHEME=$(
	if [[ "$DEFAULTFLAG" == 0 ]]; then
		echo "Column 1 background = $column1_background $(setColorHeader "$column1_background")"
		echo "Column 1 font color = $column1_font_color $(setColorHeader "$column1_font_color")"
		echo "Column 2 background = $column2_background $(setColorHeader "$column2_background")"
		echo "Column 2 font color = $column2_font_color $(setColorHeader "$column2_font_color")"
	else 
		echo "Column 1 background = default $(setColorHeader "$column1_background")"
		echo "Column 1 font color = default $(setColorHeader "$column1_font_color")"
		echo "Column 2 background = default $(setColorHeader "$column2_background")"
		echo "Column 2 font color = default $(setColorHeader "$column2_font_color")"
	fi
)

output=$(
  HOSTNAME=$(hostname)
  ZONE_NAME=$(readlink /etc/localtime | sed 's|.*/zoneinfo/||')
  UTC_OFFSET=$(date +'%:z')  # ±HH:MM
  TIMEZONE="$ZONE_NAME UTC $UTC_OFFSET"
  USER=$(whoami)
  OS_NAME=$(cat /etc/os-release | grep -w NAME | cut -d= -f2 | tr -d '"')
  OS_VERSION=$(cat /etc/os-release | grep -w VERSION | cut -d= -f2 | tr -d '"')
  DATE=$(date +"%d %b %Y %H:%M:%S")
  UPTIME=$(uptime -p)
  UPTIME_SEC=$(awk '{print $1}' /proc/uptime)
  IP_ADDR4=$(ip a | grep -w inet | awk '{print $2}' | head -n 2 | tail -n 1 | cut -d'/' -f 1)
  NETMASK=$(ifconfig | grep -w netmask | awk '{print $4}' | head -n 1)
  GATEWAY=$(ip r | grep default | awk '{print $3}')
  RAM_TOTAL=$(free -b | awk '/Mem:/ {printf "%.3f\n", $2/1024/1024/1024}')
  RAM_USED=$(free -b | awk '/Mem:/ {printf "%.3f\n", $3/1024/1024/1024}')
  RAM_FREE=$(free -b | awk '/Mem:/ {printf "%.3f\n", $4/1024/1024/1024}')
  SPACE_ROOT=$(df -B1 / | awk 'NR==2{printf "%.2f MB\n", $2/1024/1024}')
  SPACE_ROOT_USED=$(df -B1 / | awk 'NR==2{printf "%.2f MB\n", $3/1024/1024}')
  SPACE_ROOT_FREE=$(df -B1 / | awk 'NR==2{printf "%.2f MB\n", $4/1024/1024}')

  colorized_echo $column1_font_color "HOSTNAME =" $column1_background
  colorized_echo $column2_font_color " $HOSTNAME\n" $column2_background
  colorized_echo $column1_font_color "TIMEZONE =" $column1_background 
  colorized_echo $column2_font_color " $TIMEZONE\n" $column2_background 
  colorized_echo $column1_font_color "USER =" $column1_background 
  colorized_echo $column2_font_color " $USER\n" $column2_background
  colorized_echo $column1_font_color "OS =" $column1_background 
  colorized_echo $column2_font_color " $OS_NAME $OS_VERSION $(uname -m)\n" $column2_background
  colorized_echo $column1_font_color "DATE =" $column1_background 
  colorized_echo $column2_font_color " $DATE\n" $column2_background
  colorized_echo $column1_font_color "UPTIME =" $column1_background 
  colorized_echo $column2_font_color " $UPTIME\n" $column2_background
  colorized_echo $column1_font_color "UPTIME_SEC =" $column1_background 
  colorized_echo $column2_font_color " $UPTIME_SEC\n" $column2_background
  colorized_echo $column1_font_color "IP =" $column1_background 
  colorized_echo $column2_font_color " $IP_ADDR4\n" $column2_background
  colorized_echo $column1_font_color "MASK =" $column1_background 
  colorized_echo $column2_font_color " $NETMASK\n" $column2_background
  colorized_echo $column1_font_color "GATEWAY =" $column1_background  
  colorized_echo $column2_font_color " $GATEWAY\n" $column2_background
  colorized_echo $column1_font_color "RAM_TOTAL =" $column1_background 
  colorized_echo $column2_font_color " $RAM_TOTAL GB\n" $column2_background
  colorized_echo $column1_font_color "RAM_USED =" $column1_background 
  colorized_echo $column2_font_color " $RAM_USED GB\n" $column2_background
  colorized_echo $column1_font_color "RAM_FREE =" $column1_background 
  colorized_echo $column2_font_color " $RAM_FREE GB\n" $column2_background
  colorized_echo $column1_font_color "SPACE_ROOT =" $column1_background 
  colorized_echo $column2_font_color " $SPACE_ROOT\n" $column2_background
  colorized_echo $column1_font_color "SPACE_ROOT_USED =" $column1_background 
  colorized_echo $column2_font_color " $SPACE_ROOT_USED\n" $column2_background
  colorized_echo $column1_font_color "SPACE_ROOT_FREE =" $column1_background 
  colorized_echo $column2_font_color " $SPACE_ROOT_FREE" $column2_background
)

if checkColors "$1" "$2" "$3" "$4"; then 
	echo "$output"
	echo -e "\n$COLORSCHEME"
else 
	exit 0
fi
