import socket
import time
import os

SERVER_HOST = "server"
SERVER_PORT = 3000

time.sleep(2)  # wait for server to be ready

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    for i in range(3):
        message = f"hello from client"
        s.sendto(message.encode(), (SERVER_HOST, SERVER_PORT))

        time.sleep(1)
