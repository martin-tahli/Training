class RadioConnector:
    def __init__(self, audio_input, audio_output):
        self.audio_input = audio_input
        self.audio_output = audio_output
        print(f"A radio connector with {self.audio_input} audio input and {self.audio_output} audio output is created.")

    def connect(self):
        print("The radio is connected.")
