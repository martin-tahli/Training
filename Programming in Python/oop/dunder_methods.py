class ClassRoom:
    def __init__(self):
        self._start_seat = 0
        self.seats = range(24)

    def __iter__(self):
        yield from self.seats


class ClassRoom2:
    def __init__(self):
        self._start_seat = 0
        self.seats = list(range(1, 25))

    def __iter__(self):
        yield from self.seats

    def __getitem__(self, item):
        try:
            return self.seats[item]
        except IndexError:
            return None


class_room = ClassRoom2()
# for ss in class_room:
#     print(ss)

print(class_room[0])
print(class_room[25])
