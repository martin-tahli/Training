class Square:
    def __init__(self):
        self.area = 16
        self.filled = False

    def check_area(self):
        return self.area

    def can_hold_triangle(self, triangle_area):
        if triangle_area > self.area:
            return False
        else:
            return True

    def place_triangle(self, triangle_area):
        if not self.can_hold_triangle(triangle_area):
            print("Builder: There is no space left in the Square for the triangle.")
            return
        self.area -= triangle_area
        if self.area == 0:
            self.filled = True
            print("Builder: The square is filled.")

