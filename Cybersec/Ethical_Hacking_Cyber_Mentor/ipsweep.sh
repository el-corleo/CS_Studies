#!/bin/bash

IP_BLOCK=$1

if [ "$IP_BLOCK" == "" ]
then
  echo "Must include IP block"
  echo "e.g., $ ./ipsweep.sh 192.168.8"
else
for host in `seq 1 254`; do
  ping -c 1 $IP_BLOCK.$host | grep "64 bytes" | cut -d " " -f 4 | tr -d ":" &
done
fi
