# def print_nested_list(lsts, level=0):
#     for item in lsts:
#         if isinstance(item, list):
#             print_nested_list(item, level + 1)
#         else:
#             print('  ' * level + str(item))
#
#
# lst = [[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]]
# print_nested_list(lst)
#
# def get_nested_list(lsts, level=0):
#     result = ''
#     for item in lsts:
#         if isinstance(item, list):
#             result += get_nested_list(item, level + 1)
#         else:
#             result += '  ' * level + str(item) + '\n'
#     return result
#
#
# lst = [[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]]
# print(get_nested_list(lst))
#
# def print_nested_list(lst, level=0):
#     for item in lst:
#         if isinstance(item, list):
#             print_nested_list(item, level + 1)
#         else:
#             print("  " * level + str(item))
#
#
# lst = [[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]]
# print_nested_list(lst)

def print_nested_list(lst, level=0):
    for item in lst:
        if isinstance(item, list):
            print_nested_list(item, level + 1)
        else:
            print("  " * level + str(item))
    #print("\n" if level > 0 else "")


lst = [[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]]
print_nested_list(lst)

# Write a function that accepts multidimensional list and prints out list elements nested by
# their dimension:
# Example: [[1, 2, [3, 4, [6]]], [[], [], [3, 4, 5]]]
# 1, 2
#      3, 4
#          6
#
#
#          3, 4, 5
#
# Hint: You may, or you may not use recursion
