# 1) Целта на задачата е да създадете функция, която получава 2 аргумента. Име на документ под формата на стринг и стринг,
# който съдържа налични символи. Функцията трябва да проверява дали има необходимия вид и брой символи, за да се създаде
# документа и трябва да връща boolean стойност (True/False).
# Пример: characters = "abcabc" и document = "aabbccc", функцията трябва да връща False защото не достига едно c, за да
# се създаде документа.
#
def name_of_doc(name, available_chars):
    flag = 3
    sorted_name = sorted(name)
    new = sorted(available_chars)

    for chars in sorted_name:
        for char in new:
            if chars == char:
                list(available_chars).pop()
                flag = 1
            else:
                flag = 0
    if flag == 1:
        return True
    else:
        return False


characters = "abvabv"
document = "aabbvva"
print(name_of_doc(document, characters))
