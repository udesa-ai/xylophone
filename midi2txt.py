from mido import MidiFile
from sys import argv
import time
import serial

m2a = {55:'18', 57:'17', 59:'16',
       60:'15', 62:'14', 64:'13',
       65:'12', 67:'11', 69:'10',
       71:'09', 72:'08', 74:'07',
       76:'06', 77:'05', 79:'04',
       81:'03', 83:'02', 84:'01'}

m2a2 = {56: '01', 58: '02', 61: '03',
        63: '04', 66: '05', 68: '06',
        70: '07', 73: '08', 75: '09',
        78: '10', 80: '11', 82: '12'}


arduino1 = serial.Serial(port='/dev/ttyUSB0', baudrate=57600, timeout=.1)
arduino2 = serial.Serial(port='/dev/ttyUSB1', baudrate=57600, timeout=.1)
time.sleep(2)


def write1(x):
    arduino1.write(bytes(x, 'utf-8'))

def write2(x):
    arduino2.write(bytes(x, 'utf-8'))

def parse(file):
    mid = MidiFile(file)
    for msg in mid.play():
        if msg.type == 'note_on':
            if msg.note in m2a:
                write1(m2a[msg.note])
            elif msg.note in m2a2:
                write2(m2a2[msg.note])






parse(argv[1])
