def get_is_valid_subsequence(array, sequence):
    """
    Given two non-empty arrays of integers, finish the function by adding code that determines if
    the second array is a subsequence of the first one.
    Subsequence is not mandatory adjacent in the array, but following the same order.
    Example:
    array = [5, 1, 22, 25, 6, -1, 8, 10]
    sequence = [1, 6, -1, 10]
    result: True
    :param array:
    :param sequence:
    :return: bool
    """
    arr_id = 0
    seq_id = 0
    while arr_id < len(array) and seq_id < len(sequence):
        if array[arr_id] == sequence[seq_id]:
            seq_id += 1
        arr_id += 1

    return seq_id == len(sequence)


print(get_is_valid_subsequence([5, 1, 22, 25, 6, -1, 8, 10], [1, 6, -1, 10]))
