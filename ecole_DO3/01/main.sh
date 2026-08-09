#!/bin/bash
text=$1
if [ $# != 1 ]; then
	echo "Usage: bash main.sh [TEXT STRING]"
	exit 1
elif [[ $1 =~ ^-?[0-9]+(\.[0-9]+)?$ ]]; then
	echo "Invalid input. You've entered a number"
	exit 1
else
	echo $text
fi
