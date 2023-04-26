class Airbag:
    def __init__(self, inflation_pressure):
        self.inflation_pressure = inflation_pressure
        print(f"An airbag with {self.inflation_pressure} inflation pressure is created.")

    def deploy(self):
        print("The airbag is deploying.")
