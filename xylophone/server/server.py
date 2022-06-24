#!/usr/bin/env python

from socketserver import TCPServer

from .mock_handler import MockTCPHandler
from .handler import TCPHandler
from ..xylo.phone import Xylo, MockXylo


class CustomTCPServer(TCPServer):
    def __init__(self, host_port, handler, xylo):
        super().__init__(host_port, handler)
        self.xylo = xylo


class BaseXyloServer:
    def __init__(self, host, port):
        if not isinstance(port, int):
            raise TypeError("Port must be an integer")
        self.host = host
        self.port = port

    def _start(self, handler, xylo):
        with CustomTCPServer((self.host,self.port), handler, xylo) as server:
            server.serve_forever()


class MockXyloServer(BaseXyloServer):

    def __init__(self, host='localhost', port=8080):
        super().__init__(host=host, port=port)


    def start(self):
        self._start(MockTCPHandler, MockXylo())


class XyloServer(BaseXyloServer):
    def __init__(self, host='localhost', port=8080):
        super().__init__(host=host, port=port)


    def start(self):
        self._start(TCPHandler, Xylo())

