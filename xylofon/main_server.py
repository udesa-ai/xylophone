#!/usr/bin/env python

from socketserver import TCPServer
from server import TCPHandler, MockTCPHandler


if __name__ == '__main__':
    HOST, PORT = 'localhost', 8080

    with TCPServer((HOST,PORT), MockTCPHandler) as server:
        server.serve_forever()

