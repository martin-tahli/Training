import copy
import random

ages = [14, 15, 14, 15, 16, 17, 8, 19, 18]
# print(id(ages), ages)
#
# ages.append(88)
# print(id(ages), ages)

# print(ages[5])  # Get specified element by given index
# print(ages[-1])  # Get the last element of ages list
# print(ages[-2])  # 18 | 19 | 8
# print(ages[-3])  # 8 | 17 | 19
# print(ages[-8])  # 15 | 14 | 16
#
# # Reverse a list
# # print(ages.reverse())
# # With cycle
# print(ages[::-1])

# sub_ages_list = ages[2:6:2]  # Created new list by using slicing
# print(id(sub_ages_list), sub_ages_list)
# ages.insert(7, 29)
# print(ages)
# ages.remove(15)
# print(ages)
# last_age_by_pop = ages.pop()
# print(last_age_by_pop, ages)
# # Would cause IndexError
# print(ages[25])

modified_ages = [age + (index * 3) for index, age in enumerate(ages)]
# modified_ages_2 = modified_ages
# print(id(modified_ages), id(modified_ages_2))
# modified_ages[0] += 10
# print(modified_ages, modified_ages_2)
# modified_ages_2[0] += 10
# print(modified_ages, modified_ages_2)
# modified_ages_easiest_shallow_copy = modified_ages[:]
#
# modified_ages_safe = copy.deepcopy(modified_ages_2)
# print(id(modified_ages_2), id(modified_ages_safe))

# modified_ages_safe[0] -= 10
# print(modified_ages_safe, modified_ages_2)

matrix = [
    [1, 4, 5, [89, 0, []]],
    [1, 5, 6],
    [3, 5, 8],
]

first_el_of_first_matrix_el = matrix[0][0]

# print(len(matrix), len(ages))

ages.extend([4, 6, 9])
# print(ages)

# print(ages.index(15, 4, 7))

numbers = [1, 2, 3, 4]
numbers2 = [5, 6, 7, 8]
numbers3 = numbers + numbers2
# print(numbers3, id(numbers3), id(numbers), id(numbers2))

# print(numbers2 == numbers)  # How it works  - Comparing

random.shuffle(numbers3)


print(numbers3)
# numbers3.sort(key=lambda element: element > 2)
numbers3 = sorted(numbers3, key=lambda element: element > 2)
print(numbers3)
