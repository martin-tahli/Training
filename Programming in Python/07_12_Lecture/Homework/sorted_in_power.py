# напишете функция, която получава лист със сортирани във възходящ ред ints и връща нов лист със същата дължина,
# който има стойностите от първия лист повдигнати на втора степен. Вторият лист също трябва да е подреден във възходящ
# ред.
#

def func(my_list):
    temp_list = []
    for x in my_list:
        temp_list.append(x ** 2)
    # return sorted([item ** 2 for item in my_list])
    return temp_list


print(func([1, 2, 3, 5, 6, 8, 9]))
