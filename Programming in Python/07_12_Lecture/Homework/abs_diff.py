# Най-малката разлика - напишете функция, която получава два равни по дължина листа. Трябва да върнете двойката числа,
# чиято абсолютна разлика е най-близко до 0 под формата на лист.
# Примерен Input:
# arrayOne = [-1, 5, 10, 20, 28, 3]
# arrayTwo = [26, 134, 135, 15, 17]
# Очакван Outpu: [28, 26]
#
def abs_diff(arr1, arr2):
    target = 999999
    result_list = []
    for i in arr1:
        for j in arr2:
            if target > abs(i - j) >= 0:
                target = abs(i - j)
                result_list = [i, j]

    return result_list


arrayOne = [-1, 5, 10, 20, 28, 3]
arrayTwo = [26, 134, 135, 15, 17]
print(abs_diff(arrayOne, arrayTwo))
