def get_min_of_three_members(x, y, z):
    # finish the function by adding code that would return the minimum of x, y and z
    # Use another function to find the minimum of y and z
    # Do not use the builtin min()
    return min_of_two(z, min_of_two(x, y))


def min_of_two(x, y):
    if x > y:
        return y
    return x


print(get_min_of_three_members(359, 729, 150))
