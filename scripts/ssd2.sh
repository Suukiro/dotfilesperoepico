#!/bin/sh
echo $(echo "/:"; df -h | grep nvme1n1p3 | awk '{print $4}')
