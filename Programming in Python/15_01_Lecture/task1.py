# напишете функция, която приема лист с минимум три позитвни числа. Трябва да върнете трите най-големи числа
# в сортиран лист. НЯМАТЕ ПРАВО ДА СОРТИРАТЕ ЛИСТА, КОЙТО ПОДАВАТЕ НА ФУНКЦИЯТА. Може да връщате дублиращи се стойности.
# Примерен вход - [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
# Очкаван изход = [18, 141, 541]


def three_biggest(data):
    largest = data[0]
    largest_second = data[0]
    largest_third = data[0]
    for number in data:
        if number > largest:
            largest_third = largest_second
            largest_second = largest
            largest = number
        elif number > largest_second:
            largest_third = largest_second
            largest_second = number
        elif number > largest_third:
            largest_third = number

    return largest, largest_second, largest_third


data = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
print(three_biggest(data))
