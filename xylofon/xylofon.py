from serial import Serial


class Xylofon:
    MAPPING = {
        'G4':'18', 'A4':'17', 'B4':'16',
        'C5':'15', 'D5':'14', 'E5':'13',
        'F5':'12', 'G5':'11', 'A5':'10',
        'B5':'09', 'C6':'08', 'D6':'07',
        'E6':'06', 'F6':'05', 'G6':'04',
        'A6':'03', 'B6':'02', 'C7':'01',
        'G#4': '01', 'A#4': '02', 'C#5': '03',
        'D#5': '04', 'F#6': '05', 'G#5': '06',
        'A#5': '07', 'C#6': '08', 'D#6': '09',
        'F#6': '10', 'G#6': '11', 'A#6': '12',
    }


    def __init__(self, port='/dev/ttyUSB0', baudrate=115200, timeout=0.1):
        self.device = Serial(port=port, baudrate=baudrate, timeout=timeout)


    def _format_velocity(self, velocity: int) -> str:
        return '0' + str(velocity) if velocity < 100 else str(velocity)


    def write(self, message):
        self.device.write(bytes(message, 'UTF-8'))


    def send(self, note, velocity):
        message = self.MAPPING[note] + self._format_velocity(velocity)
        self.write(message)

