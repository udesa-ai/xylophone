#/usr/bin/env python

from xylophone.client import XyloClient
from xylophone.xylo import XyloNote


if __name__ == '__main__':
    adapter = XyloClient(host='localhost', port=8080)
    note = XyloNote('A4', '0.5', 90)
    adapter.send(note)
