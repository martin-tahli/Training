from datetime import date
from faker import Faker
import random


def print_student_sentence(name, age, today):
    print(name, "is aged ", age, "He is a passionate learner, and he started a JD program just ", today)

    # Write code that prints out a sentence like
    # <name> is aged <age>. He is a passionate learner, and he started a JD program just <today>


fake = Faker((['bg_BG']))
print_student_sentence(fake.name(), random.randint(12, 99), date.today())
