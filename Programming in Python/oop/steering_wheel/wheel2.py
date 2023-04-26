class Wheel:
    def __init__(self, diameter, material):
        self.diameter = diameter
        self.material = material
        print(f"A wheel with diameter {self.diameter} and material {self.material} is created.")

    def rotate(self):
        print("The wheel is rotating.")
