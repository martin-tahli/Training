# # 7) Представете си, че сте ментор, който трябва да награди курсистите си след упражнение
# # в 11 сутринта в неделя. Трябва да напишете функция, която приема лист с оценки на студентите (ints). Трябва да
# # върнете лист с "наградите", които всеки курсист ще получи.
# # Условията за даване на награда са следните:
# # 1) Всеки курсист трябва да получи поне една наград (Разбирайте 1)
# # 2) Всеки курсист трябва да получи по-висока награда от съседчетата си (вляво и вдясно)
# # ако има по-висока оценка от тях, НО ако има по-ниска оценка трябва да получи по-малко награди.
# # примерен вход: [8, 4, 2, 1, 3, 6, 7, 9, 5]
# # примерен изход: [4, 3, 2, 1, 2, 3, 4, 5, 1]
# #
# # def mentor(ocenki): nagradi=[] vhod=[8, 4, 2, 1, 3, 6, 7, 9, 5] print(mentor(vhod))
def reward_students(grades):
    rewards = []

    for i in range(len(grades)):
        rewards.append(1)
    counter = 0
    for i in range(len(grades)):
        if grades[i] > grades[i - 1]:
            rewards[i] = counter + 1
            counter += 1
    counters = 0
    i = len(grades) - 1
    while i >= 0:
        if grades[i] < grades[i - 1]:
            if rewards[i] < rewards[i - 1]:
                continue
            rewards[i] = counters + 1
            counters += 1
        i -= 1

    for i in range(len(grades) - 1, -1, -1):
        if grades[i] < grades[i - 1]:
            if rewards[i] < rewards[i - 1]:
                continue
            rewards[i] = counters + 1
            counters += 1

    return rewards


# Test the function with the example input
gradess = [8, 4, 2, 1, 3, 6, 7, 9, 5]
rewardss = reward_students(gradess)
print(rewardss)  # should print [4, 3, 2, 1, 2, 3, 4, 5, 1]
