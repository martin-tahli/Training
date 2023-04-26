# 1. Write a decorator that would be used on a function that return a number. If today is wednesday,
# friday, or sunday, the function should return the number decreased byt 1.5.
import datetime


def decrease_on_weekend(func):
    def wrapper():
        result = func()
        day_of_week = datetime.datetime.today().weekday()
        if day_of_week in (2, 4, 6):  # Wednesday, Friday, Sunday
            result -= 1.5
        return result

    return wrapper


@decrease_on_weekend
def get_number():
    return 10


print(get_number())
