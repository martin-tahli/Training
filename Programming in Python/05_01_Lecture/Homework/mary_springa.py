# 3. Write a decorator that prints out "Mary Spring" whenever the decorated function is called.
def print_mary_spring(func):
    def wrapper(*args, **kwargs):
        print("Mary Spring")
        return func(*args, **kwargs)

    return wrapper


@print_mary_spring
def funct():
    return


funct()  # prints "Mary Spring"
