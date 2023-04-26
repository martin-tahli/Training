import random
from collections import Counter, defaultdict

fruits_colors = {
    "green_apple": "green",
    "banana": "yellow",
    "peach": "orange",
}

print(fruits_colors["green_apple"])
print(fruits_colors.get(0, "NOT FOUND"))

fruits_colors["orange"] = "ohra"
print(fruits_colors)

print(fruits_colors.setdefault("orange", "pink"))
print(fruits_colors)

fruits_colors["banana"] = "green"
print(fruits_colors)

# fruits_colors.update(banana="yellow")
# fruits_colors.update({"banana": "yellow"})
# print(fruits_colors)

print(len(fruits_colors))

# Iterate by using iteration on keys and Key look up
for key in fruits_colors:
    print(key, fruits_colors[key])

# print(fruits_colors.keys())
# print(fruits_colors.values())
# print(fruits_colors.items())
#
# for key in fruits_colors.keys():
#     print(key)
#
# for value in fruits_colors.values():
#     print(value)
#
# for key, value in fruits_colors.items():
#     print(key, value)

orange = fruits_colors.pop("orange", "NO SUCH FRUIT")
print(orange)
print(fruits_colors)

popped_item = fruits_colors.popitem()

del fruits_colors["green_apple"]
# del fruits_colors["bumba"]  # What here?
del fruits_colors


words_counter = Counter('gallahad')
print(words_counter)

c = Counter({'red': 4, 'blue': 2})
print(c)
c2 = Counter(cats=4, dogs=8)
print(c2)

print(c["black"])

c3 = Counter(dict([(10, 4), (0, 9)]))
print(c3.most_common(1))
# print(c3.total())

c3.subtract(c2)
print(c3)

example_default_dict = defaultdict(list)  # {}
example_default_dict_str = defaultdict(str)  # {}
example_default_dict_int = defaultdict(int)  # {}
example_default_dict_float = defaultdict(float)  # {}
example_default_dict_custom_dict = defaultdict(lambda: {"grades": []})  # {}
for name in ["N1", "N2", "N3", "N4"]:
    example_default_dict[name].append(random.choice(range(100)))
    example_default_dict_custom_dict[name]["grades"].extend(["C", "Linux"])
# print(example_default_dict)
# print(example_default_dict["N9"])
# print(example_default_dict_custom_dict)

dict_comprehension = {(value + 1) ** 2: value for value in range(10)}
print(dict_comprehension)
