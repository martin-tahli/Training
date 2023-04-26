# Да се направи същото, но като сравнявате стойностите по индекси
# New
# 1:08
# тоест arrayOne[0] - arrayTwo[0] дали е най-близката до 0 стойност
# 1:08
# после arrayOne[1] - arrayTwo[1]
# 1:09
# hint - използвайте zip()
#
def abs_diff2(arr1, arr2):
    target = 999999
    result_list = []
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            if target > abs(arr1[i] - arr2[j]) >= 0:
                target = abs(arr1[i] - arr2[j])
                result_list = [arr1[i], arr2[j]]

    return result_list


arrayOne = [-1, 5, 10, 20, 28, 3]
arrayTwo = [26, 134, 135, 15, 17]
print(abs_diff2(arrayOne, arrayTwo))
