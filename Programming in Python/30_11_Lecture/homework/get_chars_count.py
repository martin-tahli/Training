from collections import Counter


def get_chars_count(string):
    """
    :param string:
    :return: dict holding string chars count with and without counter
    """

    counter = {}

    for letter in string:
        if letter not in counter:
            counter[letter] = 0
        counter[letter] += 1

    my_dict = {
        "With counter ": Counter(string),
        "Without counter": counter,
    }

    for key, value in my_dict.items():
        print(f' {key}, {value}')

pass

get_chars_count("halleluq")
