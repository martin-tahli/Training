def one_correction_away(string_one, string_two):
    if abs(len(string_one) - len(string_two)) > 1:
        return False
    elif len(string_one) == len(string_two):
        return one_edit_replace(string_one, string_two)
    else:
        return one_edit_insert(string_one, string_two)


def one_edit_replace(string_one, string_two):
    found_difference = False
    for i in range(len(string_one)):
        if string_one[i] != string_two[i]:
            if found_difference:
                return False
            found_difference = True
    return True


def one_edit_insert(string_one, string_two):
    index1 = 0
    index2 = 0
    found_difference = False
    while index1 < len(string_one) and index2 < len(string_two):
        if string_one[index1] != string_two[index2]:
            if found_difference:
                return False
            found_difference = True
            if len(string_one) < len(string_two):
                index2 += 1
            else:
                index1 += 1
        else:
            index1 += 1
            index2 += 1
    return True


print(one_correction_away("hello", "hell0"))  # True
print(one_correction_away("hllo", "hallo"))  # True
print(one_correction_away("hallo", "haallo"))  # True
print(one_correction_away("hello", "hheelllooo"))  # False
