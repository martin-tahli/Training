from wheel2 import Wheel
from radio_connector import RadioConnector
from airbag import Airbag


class SteeringWheel:
    def __init__(self, diameter, material, audio_input, audio_output, inflation_pressure):
        self.wheel = Wheel(diameter, material)
        self.radio_connector = RadioConnector(audio_input, audio_output)
        self.airbag = Airbag(inflation_pressure)
        print("A steering wheel with a wheel, a radio connector, and an airbag is created.")

    def rotate_wheel(self):
        self.wheel.rotate()

    def connect_radio(self):
        self.radio_connector.connect()

    def deploy_airbag(self):
        self.airbag.deploy()

    def get_properties(self):
        print(f"Diameter: {self.wheel.diameter}, Material: {self.wheel.material}")
        print(f"Audio Input: {self.radio_connector.audio_input}, Audio Output: {self.radio_connector.audio_output}")
        print(f"Inflation Pressure: {self.airbag.inflation_pressure}")


# Create an example steering wheel
example_wheel = SteeringWheel(15, "Leather", "Aux", "Speakers", 20)

# Print the properties of the example steering wheel
example_wheel.get_properties()
