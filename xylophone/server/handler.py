from socketserver import BaseRequestHandler


class TCPHandler(BaseRequestHandler):

    def handle(self):
        print(self.server.xylo)

        self.data = self.request.recv(1024).strip()
        # TODO: use real Xylophone
        self.request.sendall(self.data.upper())

