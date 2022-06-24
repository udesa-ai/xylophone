# Xylophone

This repository is contains a litle Python package that can communicate with real xylophone.

## Installation

In order to use this library in another project it must be installed.
This is fairly straightforward as it can be installed with pip.
Execute the following steps:

1. Clone the repository.

```shell
$ git clone https://github.com/udesa-ai/xylophone.git
```

1. Get in the local repository.

```shell
$ cd /path/to/xylophone
```

1. Install it with pip

```shell
$ pip install -r requirements.txt
$ pip install .
```

## Usage

The usage is also quite easy as it requires to interact with just a few classes.
First we'll show you how to write a xylophone client that can send commands to the xylophone server.

### Client

```python
# Import the client and the class that represents a note.
from xylophone.client import XyloClient
from xylophone.xylo import XyloNote


if __name__ == '__main__':
    # Instantiate a client based on XyloClient.
    # Specify the host or IP address of the server and the port in which it's listening.
    # By default, the XyloClient will connect to localhost:8080
    client = XyloClient(host='localhost', port=8080)
    
    # Create a note object. In this case we're instantiating a A$ with 0.5 start time and 90 velocity.
    note = XyloNote('A4', 0.5, 90)

    # Tell the client to send the note.
    client.send(note)
```

You can use the example in [here](examples/xilo_client.py).

### Server

This tiny library provides two servers:

- A server that connects to a real xylophone by USB.
- A mock server that has the same interface as the real one but just acknowledges the sent message.

#### Mock server

To instantiate a mock server it's also very easy as it requires to import only one class from this library.

```python
# Import the mock server
from xylophone.server.server import MockXyloServer

# Instantiate the mock server and specify the IP/host and port that it's going to be using.
server = MockXyloServer(host='localhost', port=8080)

# Just start the server
server.start()
```

#### Real server

It's the same but it must be connected to a real robotic xylophone by USB.

```python
# Import the xylo server
from xylophone.server.server import XyloServer

# Instantiate the xylo server and specify the IP/host and port that it's going to be using.
server = XyloServer(host='localhost', port=8080)

# Just start the server
server.start()
```

> Note: Keep in mind that these scripts won't terminate unless you do it.

