import itertools


# Напишете функция, която да приема лист от Int-ове и target. Функцията трябва да намери свички тройки числа,
# които дават target-a и да ги запази групирани в лист. Числата въс всяка една запазена групичка трябва да са подредени
# във възходящ ред. Освен това групичките трябва да са сорирани.
# примерен вход: [12, 3, 1, 2, -6, 5, -8, 6]
# target = 0
# примерен изход = [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]

def target_sums(lists, target_sum):
    result = []
    results = [seq for i in range(len(lists), 0, -1)
               for seq in itertools.combinations(lists, i)
               if sum(seq) == target_sum]
    for r in results:
        if len(r) == 3:
            result.append(sorted(r))
    return sorted(result)


my_list = [12, 3, 1, 2, -6, 5, -8, 6]
target = 0
print(target_sums(my_list, target))
