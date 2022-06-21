#!/usr/bin/env python

import json

from socketserver import BaseRequestHandler
from xylofon import MockXylo
from xylonote import XyloNote


class MockTCPHandler(BaseRequestHandler):
    xylo = MockXylo()

    def handle(self):
        self.data = self.request.recv(1024).strip()
        note = json.loads(self.data, object_hook=XyloNote.from_json)
        self.xylo.send(note)
        self.request.sendall(self.data.upper())


class TCPHandler(BaseRequestHandler):

    def handle(self):
        self.data = self.request.recv(1024).strip()
        print(self.data)     
        self.request.sendall(self.data.upper())

