#!/bin/bash

# function to check that bg and fg colors are not the same 
checkColors() {
	if [[ "$1" == "$2" || "$3" == "$4" ]]; then
		echo "Please enter different colors for background and text e.g., 'main.sh 1 2 4 5'"
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
        "3") background_code="\e[42m";; ## green
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

  colorized_echo $2 "HOSTNAME =" $1
  colorized_echo $4 " $HOSTNAME\n" $3
  colorized_echo $2 "TIMEZONE =" $1 
  colorized_echo $4 " $TIMEZONE\n" $3 
  colorized_echo $2 "USER =" $1 
  colorized_echo $4 " $USER\n" $3
  colorized_echo $2 "OS =" $1 
  colorized_echo $4 " $OS_NAME $OS_VERSION $(uname -m)\n" $3
  colorized_echo $2 "DATE =" $1 
  colorized_echo $4 " $DATE\n" $3
  colorized_echo $2 "UPTIME =" $1 
  colorized_echo $4 " $UPTIME\n" $3
  colorized_echo $2 "UPTIME_SEC =" $1 
  colorized_echo $4 " $UPTIME_SEC\n" $3
  colorized_echo $2 "IP =" $1 
  colorized_echo $4 " $IP_ADDR4\n" $3
  colorized_echo $2 "MASK =" $1 
  colorized_echo $4 " $NETMASK\n" $3
  colorized_echo $2 "GATEWAY =" $1  
  colorized_echo $4 " $GATEWAY\n" $3
  colorized_echo $2 "RAM_TOTAL =" $1 
  colorized_echo $4 " $RAM_TOTAL GB\n" $3
  colorized_echo $2 "RAM_USED =" $1 
  colorized_echo $4 " $RAM_USED GB\n" $3
  colorized_echo $2 "RAM_FREE =" $1 
  colorized_echo $4 " $RAM_FREE GB\n" $3
  colorized_echo $2 "SPACE_ROOT =" $1 
  colorized_echo $4 " $SPACE_ROOT\n" $3
  colorized_echo $2 "SPACE_ROOT_USED =" $1 
  colorized_echo $4 " $SPACE_ROOT_USED\n" $3
  colorized_echo $2 "SPACE_ROOT_FREE =" $1 
  colorized_echo $4 " $SPACE_ROOT_FREE" $3
)

if checkColors "$1" "$2" "$3" "$4"; then 
	echo "$output"
else 
	exit 0
fi
