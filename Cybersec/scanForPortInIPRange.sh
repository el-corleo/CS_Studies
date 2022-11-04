#!/bin/bash

echo "Enter first IP address in range: "
read firstIPAdd

echo "Enter final octect of range: "
read finalOctect

echo "Enter target port number: "
read targetPort

nmap -sT $firstIPAdd-$finalOctect -p $targetPort >/dev/null -oG scanResultsTmp

cat scanResultsTmp | grep open > scanResults

cat scanResults
