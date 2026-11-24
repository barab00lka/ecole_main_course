#!/usr/bin/env bash
set -eo pipefail
choice="$1"
# 1-  All entries sorted by response code;
# 2-  All unique IPs found in the entries;
# 3-  All requests with errors (response code — 4xx or 5xxx);
# 4-  All unique IPs found among the erroneous requests.

logs="../04/access*.log"

#tmpfile=$(mktemp)
## Удалим временный файл при выходе (на случай прерывания)
#trap 'rm -f "$tmpfile"' EXIT
#cat ../04/access*.log >> "$tmpfile"

if [[ $choice -eq 1 ]]; then 
	cat $logs | sort -k9,9n

elif [[ $choice -eq 2 ]]; then
	cat $logs | cut -d' ' -f1 | sort -u

elif [[ $choice -eq 3 ]]; then
	cat $logs | awk '$9 >= 400'

elif [[ $choice -eq 4 ]]; then
	cat $logs | awk '$9 >= 400' | cut -d' ' -f1 | sort -u

else
	echo -e "Usage: ./main.sh [PARAMETER]\nAvailable parameters:\n1 - All entries sorted by response code;\n2 - All unique IPs found in the entries;\n3 - All requests with errors (response code — 4xx or 5xxx);\n4 - All unique IPs found among the erroneous requests."
fi
