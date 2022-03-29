import serial
import time


arduino1 = serial.Serial(port='/dev/ttyUSB0', baudrate=115200, timeout=.1)
#arduino2 = serial.Serial(port='/dev/ttyUSB1', baudrate=115200, timeout=.1)
time.sleep(2)

def write1(x):
    arduino1.write(bytes(x, 'utf-8'))

#def write2(x):
#    arduino2.write(bytes(x, 'utf-8'))

delays = 0.5

write1('18050')
write1('01050')

