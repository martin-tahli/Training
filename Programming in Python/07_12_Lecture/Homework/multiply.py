# 3) Напишете функция, която приема лист с Int-ове. Функцията трябва да връща лист,
# който да съдържа резултатите на умножените числа (без настоящото).
# примерен вход = [5,1,4,2]
# примерен изход = [8,40,10,20]
#
def multiply(arr):
    arr2 = []
    for i in range(len(arr)):
        result = 1
        for j in range(len(arr)):
            if arr[i] != arr[j]:
                result *= arr[j]
        arr2.append(result)
    return arr2


arrs = [5, 1, 4, 2]
print(multiply(arrs))
