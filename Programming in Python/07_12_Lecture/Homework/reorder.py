# 6) Напишете функция, която приема лист с ints и връща лист с два индекса. Двата индекса трябва да бъдат началната
# и крайната точна на подгрупата числа, която трябва да бъде пренаредена в листа. НЯМА НУЖДА ДА ГИ ПРЕНАРЕЖДАТЕ,
# а само да кажете кое е парчето, което трябва да се пренареди.
# примерене вход: [1 ,2 , 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
# примерен изход: [3, 9]
# обяснение: Всички числа от 3-ти индекс (първата седмица) до 9-ти индекс (втората седмица) трябва да бъдат пренаредени.
#
def reorder(my_list):
    new_list = sorted(my_list)
    result = []
    if not new_list == my_list:
        for count in range(len(my_list)):
            if new_list[count] != my_list[count]:
                result.append(count)
    else:
        print("all good")
    return [result[0], result[len(result) - 1]]


my = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
print(reorder(my))
