#/usr/bin/env python

from client import XyloAdapter
from xylonote import XyloNote


if __name__ == '__main__':
    adapter = XyloAdapter()
    note = XyloNote('A4', '0.5', 90)
    adapter.send(note)

