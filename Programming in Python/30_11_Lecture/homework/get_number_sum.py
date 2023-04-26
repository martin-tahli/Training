def get_number_sum(array, target_sum):
    """
    Example:
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    target_sum = 10
    result = [-1, 11]
    :param array: Non-empty array of integers
    :param target_sum: integer
    :return: new array holding 2 numbers which sum = target_sum. If no such numbers, return []
    """

    hashmap = {}
    for i in range(len(array)):
        hashmap[array[i]] = i
    for i in range(len(array)):
        complement = target_sum - array[i]
        if complement in hashmap and hashmap[complement] != i:
            return [i, hashmap[complement]]


print(get_number_sum([3, 5, -4, 8, 11, 1, -1, 6], 10))
