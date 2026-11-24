#!/bin/bash

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


  echo "HOSTNAME = $HOSTNAME"
  echo "TIMEZONE = $TIMEZONE"
  echo "USER = $USER"
  echo "OS = $OS_NAME $OS_VERSION $(uname -m)"
  echo "DATE = $DATE"
  echo "UPTIME = $UPTIME"
  echo "UPTIME_SEC = $UPTIME_SEC"
  echo "IP = $IP_ADDR4"
  echo "MASK = $NETMASK"
  echo "GATEWAY = $GATEWAY" 
  echo "RAM_TOTAL = $RAM_TOTAL GB"
  echo "RAM_USED = $RAM_USED GB"
  echo "RAM_FREE = $RAM_FREE GB"
  echo "SPACE_ROOT = $SPACE_ROOT"
  echo "SPACE_ROOT_USED = $SPACE_ROOT_USED"
  echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE"
)
saveOutput(){
		FILENAME=$(date +"%d_%m_%y_%H_%M_%S").status
		echo "$output" > "$FILENAME"
		echo -e "\nFile is saved as $FILENAME"
	}

userPrompt(){       
	answer=0
	echo -e "\nDo you want to write the output to a file? Name will be: 'DD_MM_YY_HH_MM_SS.status'"
	echo -e "\nPress Y to accept, or any other key to decline"
	read -n 1 -r answer
        
        # Check the user's response
        if [[ "$answer" == "y" || "$answer" == "Y" ]]; then
	saveOutput
        else
            echo -e "\nFile not saved. Exiting..."
        fi
}


echo "$output"
sleep 1
userPrompt
