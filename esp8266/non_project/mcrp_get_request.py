# Http get request script for micropython board. Do not run the
# file directly, instead this file is a placeholder for the code which
# would be put in boot.py or some other script. If you want to test the file
# simply open, read and exec.

import socket

def http_get(url):
    _, _, host, path = url.split('/', 3)
    addr = socket.getaddrinfo(host, 80)[0][-1]
    s = socket.socket()
    s.connect(addr)
#    s.send(bytes('GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n' % (path, host), 'utf8'))
    s.send(bytes('GET /{} HTTP/1.0\r\nHost: {}\r\n\r\n'.format(path, host), 'utf8'))
    while True:
        data = s.recv(100)
        if data:
            print(str(data, 'utf8'), end='')
        else:
            break
    s.close()

