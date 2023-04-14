import socket

HOST = "127.0.0.1"
PORT = 7777

# AF_INET is for IPv4; SOCK_STREAM is a port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT)) # note this takes a tuple as a parameter
