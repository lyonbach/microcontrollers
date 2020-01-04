import socket

HOST = '192.168.0.22'
PORT = 2062


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello Cheese!')
    data = s.recv(1024)

print('Received', repr(data))
