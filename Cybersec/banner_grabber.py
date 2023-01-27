#! /usr/bin/python3

import socket

IP_ADDRESS = input("Enter IP address: ")
BUFFER_SIZE = 1024

ports = [21,22,3306]

for i in range(len(ports)):
    port = ports[i]
    s = socket.socket()
    
    try:
        s.connect((IP_ADDRESS, port))
    except:
        print(f"Failed to connect to port {port}.")
        continue

    banner = s.recv(BUFFER_SIZE)

    print(f"Banner for port {port}:\n{banner}")

    s.close()

