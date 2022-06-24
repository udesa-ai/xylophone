import json

class XyloNote:
    def __init__(self, value, start_time, velocity):
        try:
            start_time = float(start_time)
        except (TypeError, ValueError):
            raise ValueError('The start_time must be convertible to float')

        if not isinstance(velocity, int):
            raise ValueError('Velocity must be an integer')

        if velocity < 0:
            raise ValueError('Please use a velocity above or equal to 0')

        if velocity >= 100:
            raise ValueError('Please use a velocity below 100')

        self.value = value
        self.start_time = start_time
        self.velocity = velocity


    @staticmethod
    def from_json(json_dct):
        return XyloNote(
                json_dct['value'],
                json_dct['start_time'],
                json_dct['velocity'],
            )

    def to_json(self):
        return json.dumps(self, default=lambda o: o.__dict__)


    def __str__(self):
        return f'Note: {self.value} | Start time: {self.start_time} | Velocity: {self.velocity}'


    def __repr__(self):
        return f'{self.__class__}(note={self.value},start_time={self.start_time},velocity={self.velocity}'

