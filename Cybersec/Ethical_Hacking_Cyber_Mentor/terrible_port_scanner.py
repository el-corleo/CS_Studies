#!/bin/python3

from datetime import datetime
import socket
import sys


def scan_target(target: str) -> None:
    start = datetime.now()
    print('-' * 50)
    print(f"Scanning {target}")
    print(f"Start: {start}")
    print('-' * 50)

    for port in range(0,1000):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket.setdefaulttimeout(1)
        if s.connect_ex((target, port)) == 0:
            print(f"Port {port} is open.")
        s.close()

    print('-' * 50)
    print(f"Finish: {datetime.now()}")
    print(f"Time elapsed: {datetime.now() - start}")
    print('-' * 50)



# Define target
if len(sys.argv) == 2:
    target = socket.gethostbyname(sys.argv[1]) # translate host name to IPv4
    try:
        scan_target(target)
    except KeyboardInterrupt:
        print("\nExiting program...")
        sys.exit()
    except socket.gaierror:
        print("Hostname could not be resolved.")
        sys.exit()
    except socket.error:
        print("Could not connect to server.")
        sys.exit()
else:
    print("Invalid number of args.")
    print("Usage: terrible_port_scanner.py <IP addr>")
