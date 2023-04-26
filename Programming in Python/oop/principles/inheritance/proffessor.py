from oop.principles.inheritance.student import Student


class Professor(Student):
    TITLE = "Professor"

    def __init__(self, faculty, experience_ages, disciplines, *args, create_student=False):
        super().__init__(*args, validate_age=False, create_student=create_student)
        self.__disciplines = disciplines
        self.faculty = faculty
        self.experience_ages = experience_ages

    def __contains__(self, discipline):
        return self.disciplines.index(discipline) != -1

    def __repr__(self):
        return f"<Professor {self.name}, aged: {self.age}>"

    def __str__(self):
        return f"Professor {self.name}"

    @property
    def disciplines(self):
        return self.__disciplines

    @disciplines.setter
    def disciplines(self, disciplines):
        # raise TypeError("Disciplines are unchangable")
        self.__disciplines = disciplines

    def add_discipline(self, discipline):
        if discipline in self.__disciplines:
            return "I already have this one in my list"
        self.__disciplines.append(discipline)
        return "Oh, another one for me..."

    def study(self, discipline):
        print(f"{self.name} is mastering {discipline}")

    def read_books(self):
        student_result = super().read_books()
        return student_result * 100


prof = Professor(
    "FMI",
    25,
    ["Math", "Advanced Math 1"],
    None,
    None,
    "Poli",
    23,
    "f",
    155,
)
result = "Math" in prof
print(result)
# prof.study("Astro physics")
# print(f"Professor {prof.name} read {prof.read_books()}")

