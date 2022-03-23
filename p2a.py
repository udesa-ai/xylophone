import serial
import time


arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=57600, timeout=.1)
time.sleep(2)
def write(x):
    arduino.write(bytes(x, 'utf-8'))

delays = 0.5

write('15')
time.sleep(delays)
write('15')
time.sleep(delays)
write('11')
time.sleep(delays)
write('11')
time.sleep(delays)
write('10')
time.sleep(delays)
write('10')
time.sleep(delays)
write('11')
time.sleep(delays*2)
write('12')
time.sleep(delays)
write('12')
time.sleep(delays)
write('13')
time.sleep(delays)
write('13')
time.sleep(delays)
write('14')
time.sleep(delays)
write('14')
time.sleep(delays)
write('15')
time.sleep(delays)

delays = 0.25

write('15')
time.sleep(delays)
write('15')
time.sleep(delays)
write('11')
time.sleep(delays)
write('11')
time.sleep(delays)
write('10')
time.sleep(delays)
write('10')
time.sleep(delays)
write('11')
time.sleep(delays*2)
write('12')
time.sleep(delays)
write('12')
time.sleep(delays)
write('13')
time.sleep(delays)
write('13')
time.sleep(delays)
write('14')
time.sleep(delays)
write('14')
time.sleep(delays)
write('15')
time.sleep(delays)


delays = 0.15

write('15')
time.sleep(delays)
write('15')
time.sleep(delays)
write('11')
time.sleep(delays)
write('11')
time.sleep(delays)
write('10')
time.sleep(delays)
write('10')
time.sleep(delays)
write('11')
time.sleep(delays*2)
write('12')
time.sleep(delays)
write('12')
time.sleep(delays)
write('13')
time.sleep(delays)
write('13')
time.sleep(delays)
write('14')
time.sleep(delays)
write('14')
time.sleep(delays)
write('15')
time.sleep(delays)