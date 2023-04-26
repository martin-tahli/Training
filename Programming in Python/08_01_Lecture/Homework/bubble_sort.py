def bubble_sort(arr):
    n = len(arr)

    # Traverse through all elements in the array
    for i in range(n):
        # Last i elements are already in place, so no need to check them
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


numbers = [8, 5, 2, 9, 5, 6, 3]
# expected_output = [2, 3, 5, 5, 6, 8, 9]
print(bubble_sort(numbers))
