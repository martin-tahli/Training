############# Function 1 ############
def return_max_number(a, b, c):
    if a > b and a > c:
        return a
    elif b > a and b > c:
        return b
    elif c > a and c > b:
        return c


def return_max_number_with_list(a, b, c):
    numbers = [a, b, c]
    max_number = 0

    for number in numbers:
        if number > max_number:
            max_number = number
    return max_number


def return_max_of_three_numbers(a, b, c):
    def max_of_two_numbers(x, y):
        if x > y:
            return x
        return y
    return max_of_two_numbers(a, max_of_two_numbers(b, c))


################ Function 2 ##################
