def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


numbers = [8, 5, 2, 9, 5, 6, 3]
# expected_output = [2, 3, 5, 5, 6, 8, 9]
print(insertion_sort(numbers))


def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        for j in range(i-1, -1, -1):
            if key < arr[j]:
                arr[j+1] = arr[j]
                arr[j] = key
            else:
                break
    return arr


print(insertion_sort(numbers))
