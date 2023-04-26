# 2) Намираме се на турнир. Всеки отбор се изправя срещу всеки останал отбор от турнира. От срещата един от отборите
# задължително излиза като победител (Няма равен резултат). Победителят печели 3 точки. Победител в турнира е отборът,
# който е събрал най-много точки.
# Напишете функиция, която получава 2 листа. Първият лист е със срещите, които са изиграни, а вторият е с резултати от
# срещите. Резултатите са представени по следния начин - [домакини, гости]. Като 1 означава, че домакините са спечелили,
# а 0 показва победа за гостите.
# Примерен input: competitions = [ ["Germany", "Japan"], ["Japan", "Spain"], ["Spain", "Germany"]]
#  results = [0, 0, 1]
# В първата среща печели Japan
# Във втората Spain
# Във третата отново Spain
# Резултатите са Germany - 0 т., Japan - 3 т., Spain - 6т.
# Функцията трябва да върне Spain под формата на стринг
#
def tournament(competition, result):
    new_result = []

    for x in range(len(result)):
        if result[x] == 1:
            new_result.append(competition[x].__getitem__(0))
        # new_result = competition.__getitem__(x)
        else:
            new_result.append(competition[x].__getitem__(1))
        # new_result = competition.__getitem__(1)
    counter = 0
    num = new_result

    for i in new_result:
        curr_frequency = new_result.count(i)
        if curr_frequency > counter:
            counter = curr_frequency
            num = i

    return num


competitions = [["Germany", "Japan"], ["Japan", "Spain"], ["Spain", "Germany"]]
results = [0, 0, 1]

print(tournament(competitions, results))
