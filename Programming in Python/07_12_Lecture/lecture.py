# condition = 5
#
# if condition < 6:
#     print(" we have fullfilled the condition 0")
#
# if condition > 6:
#     print(" we have fulfilled the condition 1")
#
# else:
#     print(" we have fulfilled the condition 2 ")
#
# string_for_input = input("enter something")
#
# if len(string_for_input) > 10:
#     print("bravo")
# elif len(string_for_input) < 5:
#     print("too short")
# else:
#     print("not good")
#
# my_set = {1, 2, 5, 4, 3}
#
# if len(my_set) > 3:
#     print("set is bigger than 3 ")
# elif len(my_set) > 4:
#     print("set is bigger than 4")
nums = []
for x in range(2000, 3201):
    if x % 7 == 0 and x % 5 != 0:
        nums = x
print(nums)
