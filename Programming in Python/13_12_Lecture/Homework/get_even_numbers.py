def get_even_numbers(array):
    # Finish the function by adding code that would print out only the even numbers.
    result = []
    for elem in array:
        if elem % 2 == 0:
            result.append(elem)
    print(result)


arrays = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
get_even_numbers(arrays)
