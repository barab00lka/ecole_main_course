#!/bin/sh

scp src/cat/my_cat root@192.168.100.252:/usr/local/bin/my_cat && scp src/grep/my_grep root@192.168.100.252:/usr/local/bin/my_grep && echo "Binaries transfered successfully!"

