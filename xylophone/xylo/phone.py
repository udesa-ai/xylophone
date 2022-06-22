from serial import Serial
from ..util.logger import logger

class BaseXylo:
    WHITE_MAPPING = {
        'G4':'18', 'A4':'17', 'B4':'16',
        'C5':'15', 'D5':'14', 'E5':'13',
        'F5':'12', 'G5':'11', 'A5':'10',
        'B5':'09', 'C6':'08', 'D6':'07',
        'E6':'06', 'F6':'05', 'G6':'04',
        'A6':'03', 'B6':'02', 'C7':'01'}

    BLACK_MAPPING = {
        'G#4': '01', 'A#4': '02', 'C#5': '03',
        'D#5': '04', 'F#6': '05', 'G#5': '06',
        'A#5': '07', 'C#6': '08', 'D#6': '09',
        'F#6': '10', 'G#6': '11', 'A#6': '12',
    }
    
    def _format_velocity(self, velocity: int) -> str:
        return '0' + str(velocity) if velocity < 100 else str(velocity)


class MockXylo(BaseXylo):
    def write(self, message):
        logger.debug(f'Message was sent: {message}')
    
    def send(self, note):
        print(f'Note received: {note}')
        if note.value in self.WHITE_MAPPING or note.value in self.BLACK_MAPPING:
            self.write(self.WHITE_MAPPING[note.value] +
                    self._format_velocity(note.velocity))
        elif note.value in self.BLACK_MAPPING:
            self.write(self.BLACK_MAPPING[note.value] +
                    self._format_velocity(note.velocity))
        else:
            raise ValueError('Specified note is not supported')


class Xylo(BaseXylo):
    def __init__(self, first_port='/dev/ttyUSB0', second_port='/dev/ttyUSB1', baudrate=115200, timeout=0.1):
        self.first_device = Serial(port=first_port, baudrate=baudrate, timeout=timeout)
        self.second_device = Serial(port=second_port, baudrate=baudrate, timeout=timeout)

    def write_first(self, message):
        self.first_device.write(bytes(message, 'UTF-8'))
    
    def write_second(self, message):
        self.second_device.write(bytes(message, 'UTF-8'))
    
    def send(self, note):
        if note.value in self.WHITE_MAPPING:
            self.write_first(self.WHITE_MAPPING[note.value] +
                    self._format_velocity(note.velocity))
        elif note.value in self.BLACK_MAPPING:
            self.write_second(self.BLACK_MAPPING[note.value] +
                    self._format_velocity(note.velocity))
        else:
            raise ValueError('Specified note is not supported')


