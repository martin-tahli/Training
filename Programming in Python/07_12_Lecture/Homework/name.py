from collections import Counter


# 2) Напишете функция, която приема стринг и връща индекса на първия character, който не се повтаря
# (среща се само един път в целия стринг). Ако няма такъв върнете -1.
# input: "abcdcaf"
# expected_output: 1 (връщаме 1, защото b е първият char, който не се повтаря и е с индекс 1 в стринга "abcdcaf")
# from collections import Counter
#

def name(string):
    print(Counter(string))
    for key, value in Counter(string).items():
        if value == 1:
            return string.index(key)
    return -1


string_input = "abcdcaf"
print(name(string_input))
