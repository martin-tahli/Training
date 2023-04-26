# 4. Write a Python function to create and print a list where the values are square of numbers
# between 1 and 30 (both included)
def print_squares():
    squares = []
    for i in range(1, 31):
        squares.append(i ** 2)
    print(squares)


print_squares()
