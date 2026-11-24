#!/usr/bin/env bash

LC_NUMERIC=C

# CPU usage metric
cpu_usage_metrics(){
	local flag=0
	CPU_US=$(top -bn1 | grep '%Cpu' | awk '{print (100 - $8) / 100}') 
	echo "# HELP node_cpu_total_usage_ratio fraction of total CPU time used ((100 - idle) / 100)"
	echo "# TYPE node_cpu_total_usage_ratio gauge"
	# Error checking
	[[ -z "$CPU_US" ]] && ((flag++))
	echo "node_cpu_total_usage $CPU_US"
	return $flag
}

#memory in bytes
memory_usage_metrics(){
	local flag=0
	RAM_AVAIL="$(free --bytes | grep 'Mem' | awk '{print $7}')"
	RAM_USED=$(free --bytes| grep 'Mem' | awk '{print $3}')
	# Error checking
	[[ -z "$RAM_USED" || -z "$RAM_AVAIL" ]] && ((flag+=4))	
	echo "# HELP node_memory_used_bytes Memory in use"
	echo "# TYPE node_memory_used_bytes gauge"
	echo "node_memory_used_bytes $RAM_USED"
	echo "# HELP node_memory_available_bytes Memory available"
	echo "# TYPE node_memory_available_bytes gauge"
	echo "node_memory_available_bytes $RAM_AVAIL"

#	SWAP_FREE=$(free --bytes | grep 'Swap' | awk '{print $4}')
#	SWAP_USED=$(free --bytes | grep 'Swap' | awk '{print $3}')
 	return $flag
}	


# Disk space metrics
disk_space_metrics(){
local flag=0

persistent_fstypes="--type=adfs --type=ext2 --type=ext3 --type=ext4 --type=btrfs --type=exfat --type=fuse --type=fuseblk --type=fusectl --type=hpfs --type=hfs --type=minix --type=ntfs --type=ntfs3 --type=overlay --type=qnx4 --type=reiserfs --type=romfs --type=squashfs --type=ufs --type=udf --type=vfat --type=vxfs --type=xfs --type=xiafs"
readarray -t fs < <(df -B1 --output=source $persistent_fstypes | tail -n +2)
readarray -t fstype < <(df -B1 --output=fstype $persistent_fstypes | tail -n +2)
readarray -t size < <(df -B1 --output=size $persistent_fstypes | tail -n +2 | tr -d ' ')
readarray -t used < <(df -B1 --output=used $persistent_fstypes | tail -n +2 | tr -d ' ')
readarray -t mounts < <(df -B1 --output=target $persistent_fstypes | tail -n +2)

# Error checking
[[ -z "$fs" || -z "$fstype" || -z "$size" || -z "$used" || -z "$mounts" ]] && ((flag+=3))

#OUTPUT
echo "# HELP filesystem_total_bytes Total system disk space"
echo "# TYPE filesystem_total_bytes gauge"
for i in "${!fs[@]}"; do
	echo "filesystem_total_bytes{fstype=\"${fstype[$i]}\", device=\"${fs[$i]}\", mountpoint=\"${mounts[$i]}\"} ${size[$i]}"
	
done
echo "# HELP filesystem_used_bytes Used system disk space"
echo "# TYPE filesystem_used_bytes gauge"
for i in "${!fs[@]}"; do
	echo "filesystem_used_bytes{fstype=\"${fstype[$i]}\", device=\"${fs[$i]}\", mountpoint=\"${mounts[$i]}\"} ${used[$i]}"
done

return $flag
}

output_metrics_with_errorcount(){
	local error_flag=0
	cpu_usage_metrics || ((error_flag++))
        memory_usage_metrics || ((error_flag++))
	disk_space_metrics || ((error_flag++))
	echo "# HELP exporter_last_scrape_error How many errors were captured in last scrape"
	echo "# TYPE exporter_last_scrape_error counter"
	echo "exporter_last_scrape_error $error_flag"
}

export_to_nginx(){
	while true; do
		output_metrics_with_errorcount > ./nginx/html/metrics.txt
		sleep 5
	done
}

export_to_nginx
