#!/bin/sh

echo $(dpkg-query -f '${binary:Package}\n' -W | wc -l; echo packages installed); echo $(echo uptime; uptime | awk '{print $3,$4}' | rev | cut -c 2- | rev); uname -a | awk '{print $3}'; echo $(echo 'mem: '; free -m | awk 'NR >= 2 && NR <= 2' | awk '{print $3}'; echo /; free -m | awk 'NR >= 2 && NR <= 2' | awk '{print $2}'; echo MB); df -h | grep nvme1n1p3; df /media/aleister -h | grep nvme0n1p1
