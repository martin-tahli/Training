# 4) Напишете функция, която приема сортиран лист и target Int. Използвайки binary search algorithm намерете
# дали дадената стойност се съдържа в листа и върнете индекса й. Ако я няма върнете -1.
# примерен вход:
# array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 73]
# target = 33
# примерен изход:
# 3
def binary_search(arr, target):
    start = 0
    end = len(arr)

    while start <= end:
        mid = (start + end) // 2
        if arr[mid] < target:
            start = mid + 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            return mid
    return -1


array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 73]
tar = 33
print(binary_search(array, tar))
