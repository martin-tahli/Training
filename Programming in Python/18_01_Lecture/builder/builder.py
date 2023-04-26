import math

from figures.square import Square
from figures.triangle import Triangle


class Builder:
    def __init__(self):
        self.square = Square()
        #self.triangle=Triangle()
        self.triangle_count = 0

    def check_square_state(self):
        return self.square.filled

    def process_triangle(self, triangle):
        if self.triangle_count >= 10:
            print("Builder: Cannot build more than 10 triangles.")
            return
        if not self.square.can_hold_triangle(Triangle.check_area(triangle)):
            print("Builder: The triangle does not fit in the square.")
            return
        self.triangle_count += 1
        self.square.place_triangle(Triangle.check_area(triangle))
        print("Builder: Successfully placed a {} triangle in the square.".format(Triangle.determine_kind(triangle)))

    def receive_square_signal(self, signal):
        if self.square.filled:
            print("Builder: The square is filled. Stop building.")

############################################
build = Builder()
sq = Square()
trian = Triangle(2, 2, math.sqrt(8))

print(trian.check_area())
build.process_triangle(trian)
########################################
triangle2 = Triangle(8, 7, 4)
print(triangle2.check_area())
build.process_triangle(triangle2)

print(sq.check_area())
#####################################
triangle3 = Triangle(1, 1, 1)
print(triangle3.check_area())
build.process_triangle(triangle3)
build.receive_square_signal(build.check_square_state())




