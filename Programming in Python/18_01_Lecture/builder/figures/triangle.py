class Side:
    def __init__(self, length):
        self.length = length


class Triangle:
    def __init__(self, side1, side2, side3):
        self.side1 = Side(side1)
        self.side2 = Side(side2)
        self.side3 = Side(side3)

    def check_area(self):
        s = (self.side1.length + self.side2.length + self.side3.length) / 2
        area = (s * (s - self.side1.length) * (s - self.side2.length) * (s - self.side3.length)) ** 0.5
        return area

    def determine_kind(self):
        if self.side1.length == self.side2.length == self.side3.length:
            return "equilateral"
        elif self.side1.length == self.side2.length or self.side2.length == self.side3.length or self.side1.length == self.side3.length:
            return "isosceles"
        else:
            return "scalene"
