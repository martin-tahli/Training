# 5) Напишете функция, която получава лист и чило. Трябва да пренаредите листа, като всички числа,
# които са равни на подаденото към функцията трябва да отидат най-отзад в листа.
# array = [2, 1, 2, 2, 2, 3, 4, 2]
# to_move = 2
# очакван output = [4, 3, 1, 2, 2, 2, 2, 2]
#
def numbers(arr, to_move):
    result = sorted(arr, reverse=True)
    for i in result:
        if to_move > i:
            result.pop()
    return result


array = [2, 1, 2, 2, 2, 3, 4, 2]
to_moves = 2
print(numbers(array, to_moves))
