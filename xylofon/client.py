#!/usr/bin/env python3

import json
import socket
import logging

logging.basicConfig(format='%(levelname)s: %(asctime)s - %(message)s')
logger = logging.getLogger('logger')
logger.setLevel(logging.INFO)

class XyloNote:
    def __init__(self, note, start_time, velocity):
        self.note = note
        self.start_time = start_time
        self.velocity = velocity
    
    def __str__(self):
        return f'Note: {self.note} | Start time: {self.start_time} | Velocity: {self.velocity}'
    

    def __repr__(self):
        return f'{self.__class__}(note={self.note},start_time={self.start_time},velocity={self.velocity}'



class XyloAdapter:
    def __init__(self, host: str='localhost', port: int=8080):
        self.host = host
        self.port = port
    

    def to_json(self):
        return json.dumps(note, default=lambda o: o.__dict__)


    def send(self, note: XyloNote):
        if not isinstance(note, XyloNote):
            raise ValueError("note is not a Note")
        
        data = self.to_json()
        self._socket_send(data)


    def _socket_send(self, data):
        # Create a socket (SOCK_STREAM means a TCP socket)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            # Connect to server and send data
            s.connect((self.host, self.port))
            s.sendall(bytes(data + "\n", "utf-8"))

            # Receive data from the server and shut down
            received = str(s.recv(1024), "utf-8")
            
            logger.info(received)


if __name__ == '__main__':
    adapter = XyloAdapter()
    note = XyloNote('A4', '0', '95')
    adapter.send(note)

