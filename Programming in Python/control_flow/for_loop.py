from collections import Iterable


int_raw = range(10, 21)
print(type(int_raw))

name = "Pesho"

# for x in int_raw:
#     if isinstance(x, Iterable):
#         for xx in x:
#             print(xx)
#     else:
#         print(f"{x} does not support iteration")
#
#     if x < 16:
#         print("age is under 16")
#         if len(name) < 6:
#             print(f"{name} is too short for given age {x}")
#     elif x == 16:
#         print("age is exactly 16")
#     else:
#         print("age is over 16")
#
#     print("Where do I come from?")


# string
# list

students_data = [
    ("Pesho", 32, ["Python", "Web", "Caching"]),
    ("Gosho", 29, ["JS", "Web", "DB"]),
    ("Tosho", 38, ["Jenkins", "AI"]),
    ("Mihaela", 25, ["HTML", "SCSS", "Vue"]),
]
# for name, age, courses in students_data:
#     print(name)
#     for course in courses:
#         print(f"{course}, ", end="")
#     print()

# dict
dict_comprehension = {x: str(x) for x in range(500) if x % 3 != 0}

# print("Print dict keys with native loop")
# for x in dict_comprehension:
#     print(x)
#
# print("Print dict keys")
# for key in dict_comprehension.keys():
#     print(key)
#
# print("Print dict values")
# for value in dict_comprehension.values():
#     print(value)

# print("Print dict items")
# for key, value in dict_comprehension.items():
#     print(key, value)
    # del dict_comprehension[key]  Throws RuntimeError: dictionary changed size during iteration
    # dict_comprehension[key * 1000] = "custom added key within iteration"
    # Throws RuntimeError: dictionary changed size during iteration

# set
# ages = {25, 15, 16, 18, 20}
# print("Print set ages elements")
# for age in ages:
#     print(age)

# tuple - same as lists
# generators


# For loop ending with normal end and else
for char in "CodeAcademyBG":
    continue
    print(char, ord(char))
    break
else:
    print("For loop ended successfully")
