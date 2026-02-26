import socket

HOST = "0.0.0.0"
PORT = 3000

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.bind((HOST, PORT))
    print(f"listening on {HOST}:{PORT}")

    while True:
        data, addr = s.recvfrom(1024)
        message = data.decode()
        print(f"received from {addr}: {message}")
