#!/usr/bin/env python3

from socketserver import BaseRequestHandler, TCPServer


class TCPHandler(BaseRequestHandler):

    def handle(self):
        self.data = self.request.recv(1024).strip()
        print(self.data)
        self.request.sendall(self.data.upper())


if __name__ == '__main__':
    HOST, PORT = 'localhost', 8080

    with TCPServer((HOST,PORT), TCPHandler) as server:
        server.serve_forever()

