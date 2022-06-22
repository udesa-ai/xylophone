#!/usr/bin/env python3

import socket

from ..xylo.note import XyloNote
from ..util.logger import logger


class XyloClient:
    def __init__(self, host: str='localhost', port: int=8080):
        self.host = host
        self.port = port
    

    def send(self, note: XyloNote):
        if not isinstance(note, XyloNote):
            raise ValueError("note is not a XyloNote")
        
        data = note.to_json()
        self._socket_send(data)


    def _socket_send(self, data):
        # Create a socket (SOCK_STREAM means a TCP socket)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            # Connect to server and send data
            s.connect((self.host, self.port))
            s.sendall(bytes(data + "\n", "utf-8"))

            # Receive data from the server and shut down
            received = str(s.recv(1024), "utf-8")
            
            logger.debug(received)

