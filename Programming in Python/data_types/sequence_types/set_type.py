a = {2, 3, 4}
b = {2, 5, 6}

print(a & b, "a & b")  # intersection of a and b
print(a | b, "a | b")  # the union of a and b
print(a ^ b, "a ^ b")  # the set of elements in precisely one of a or b
print(a - b, "a - b")  # the set of elements in a but not b
print(a == b, "a == b")  # a is equivalent to b
print(a != b, "a != b")  # a is not equivalent to b
print(a <= b, "a <= b")  # a is subset of b
print(a < b, "a < b")  # a is proper subset of b
print(a > b, "a > b")  # a is proper superset of b
print(a >= b, "a >= b")  # a is superset of b

print("symetric difference between 'a' and 'b'", a.symmetric_difference(b))


# set_of_different_elements = {2, [1, 2], (8, 3), ((8, 3), [1, 2], {4, 5})}
# print(set_of_different_elements)
