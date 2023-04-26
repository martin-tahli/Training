import random
import string
import sys
from contextlib import contextmanager
from datetime import datetime
from itertools import tee


def first_n(n):
    num = 0
    while num < n:
        yield num
        num += 1


# Generator comprehension
ascii_leters_generator = (char for char in string.ascii_letters)
# print(type(first_n))
#
# for number in first_n(5):
#     print(number)


# class FirstN:
#     def __init__(self, n):
#         self.n = n
#         self.num = 0
#
#     def __iter__(self):
#         return self
#
#     def __next__(self):
#         if self.num < self.n:
#             current, self.num = self.num, self.num + 1
#             return current
#         raise StopIteration()


def generate_students_info():
    for e in range(1, 110):
        for s in range(1, 280000):
            yield f"Student {s}", {
                "student_name": f"Student {s}",
                "exam": e,
                "points": random.randint(random.choice([30, 40, 50]), 100),
            }


def generate_students_info_list():
    return [
        (
            f"Student {s}", {
                "student_name": f"Student {s}",
                "exam": e,
                "points": random.randint(random.choice([30, 40, 50]), 100),
            }
        )
        for s in range(1, 280000)
        for e in range(1, 110)
    ]


# now = datetime.now()
# print(now)


# students_info_list = generate_students_info_list()
# students_info_generator = generate_students_info()

# print(sys.getsizeof(students_info_list))
# print(sys.getsizeof(students_info_generator))

# for student_name, student_info in students_info_generator:
#     continue

# after_generator_loop = datetime.now()
# print(after_generator_loop)
# print((after_generator_loop - now).total_seconds())


def nested_generator_example():
    for x in range(100):
        if 10 < x < (50 - 3) * 1.5:
            for y in range(x):
                if y % 2 != 0:
                    for z in range(y):
                        yield z // 2


gen1, gen2, gen3 = tee(nested_generator_example(), 3)
# print(gen1, id(gen1))
# print(gen2, id(gen2))
# print(gen3, id(gen3))


nested_generator_expression_example = (
    z // 2
    for x in range(100)
    if 10 < x < (50 - 3) * 1.5
    for y in range(x)
    if y % 2 != 0
    for z in range(y)
)


def generator_with_multiple_yield():
    for x in range(1, 8):
        yield
        yield "Before first operation"
        yield x ** 2
        yield "After second operation"
        yield x ** 3


# for x in generator_with_multiple_yield():
#     print(x)


@contextmanager
def bold_tag(text):
    yield f"<b>{text}</b>"


with bold_tag("GENERATOR") as debug_name:
    print(debug_name)


def fibonacci_of(n):
    if n in (0, 1):  # Base case
        return n
    return fibonacci_of(n - 1) + fibonacci_of(n - 2)


def fibonacci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


print(datetime.now())
fib_gen = fibonacci()
for x in range(10):
    print(next(fib_gen))
print(datetime.now())

# Called with recursive fn
print(datetime.now())
for x in range(10):
    print(fibonacci_of(x))
print(datetime.now())
