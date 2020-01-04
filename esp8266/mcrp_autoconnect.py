# Auto connection script for micropython board. do not run the
# file , instead this file is a placeholder for the code which
# would be put in boot.py or some other script if an auto-connection
# is desired.

import network
import socket

passwd = input('Provide the password for the connection:\n')

def connect():
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect('UPC1625583', str(passwd))
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())

def connection_test():
    HOST = "192.168.0.31"
    PORT = 2062
    s=socket.socket()
    s.connect((HOST, PORT))
    s.sendall(b"CHEESE!\n")

connect()
connection_test()
