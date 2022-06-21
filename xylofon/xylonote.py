import json

class XyloNote:
    def __init__(self, note, start_time, velocity):
        self.note = note
        self.start_time = start_time
        self.velocity = velocity
    
    @staticmethod
    def from_json(json_dct):
        return XyloNote(
                json_dct['note'],
                json_dct['start_time'],
                json_dct['velocity'],
            )
    
    def to_json(self): 
        return json.dumps(self, default=lambda o: o.__dict__)


    def __str__(self):
        return f'Note: {self.note} | Start time: {self.start_time} | Velocity: {self.velocity}'
    

    def __repr__(self):
        return f'{self.__class__}(note={self.note},start_time={self.start_time},velocity={self.velocity}'

