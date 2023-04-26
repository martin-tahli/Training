names = ("georgi", "tosho", "pesho")
print(names[0])
print(id(names))
# names = names + ("misho", "ivan")
print(id(names))
print(names)
print(names.count("georgi"))

strange_tuple = ("Pesho", 32, [])
strange_tuple[-1].append(1)
print(strange_tuple, len(strange_tuple))

# This won't work
# strange_tuple[1] = 44
# print(strange_tuple)

tuple_of_single_element = (1,)


tuple_of_different_elements = ((8, 3), [1, 2], {4, 5})
print(tuple_of_different_elements)
