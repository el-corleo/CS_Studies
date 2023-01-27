#! /usr/bin/python3
'''
Script of TCP server copied from Linux Basics for Hackers
'''


import socket

TCP_IP = "172.26.142.32"
TCP_PORT = 6996
BUFFER_SIZE = 100

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()

print(f"Connection address: {addr}")

while 1:
    data = conn.recv(BUFFER_SIZE)
    if not data: break
    print(f"Received data: {data}")
    conn.send(data)

conn.close()
