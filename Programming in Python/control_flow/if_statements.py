age = 15
name = "Pesho"

if age < 16:
    print("age is under 16")
    if len(name) < 6:
        print(f"{name} is too short for given age {age}")
elif age == 16:
    print("age is exactly 16")
else:
    print("age is over 16")

print("Where do I come from?")

# ages_list = Define ages_list using list comprehension. Make sure you generate such list holding
# duplicated ages. You would then use a set to get unique values. You can construct if statement
# using the count of ages in the original list vs the ages remained in the ages set.

list_comprehensions = [x for x in range(500) if x % 3 != 0]
set_comprehensions = {x for x in range(500) if x % 3 != 0}
dict_comprehensions = {x: str(x) for x in range(500) if x % 3 != 0}

range(2000, 3201)
print(list_comprehensions)
print(set_comprehensions)
print(dict_comprehensions)

# is_valid_for_disco = True if age > 18 else False
is_valid_for_disco = age > 18
the_longest_structure = "set" if len(set_comprehensions) > len(dict_comprehensions) else "dict"
print(the_longest_structure)
print("set" if len(set_comprehensions) > len(dict_comprehensions) else "dict")
