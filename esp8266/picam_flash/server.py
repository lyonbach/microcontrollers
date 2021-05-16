"""
Module to run on esp8266
Does the following:
    * Starts a TCP server and listents to specific commands, does not respond to unknown stuff.
    * Interprets the data and runs the relevant command.
"""

import socket
import time
import machine 
import constants

def start_server():
    
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((constants.HOST, constants.PORT))
    server_socket.listen(5)
    return server_socket

def receive_data(connection):

    while True:
        data = connection.recv(24)
        if data:
            return data
