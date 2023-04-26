# Напишете функция която приема лист от уникални стрингове и връща само палиндромите.
# words = ['diaper', 'abc', 'test', 'cba', 'repaid']
# expected_output = [['diaper', 'repaid'], ['abc', 'cba']]
def find_palindromes(words):
    palindromes = {}

    for word in words:
        if word != word[::-1]:
            length = len(word)
            if length not in palindromes:
                palindromes[length] = []
            palindromes[length].append(word)
    if len(words) % 2 == 0:
        return list(palindromes.values())
    else:
        palindromes.pop(len(words))
        return list(palindromes.values())


words = ['diaper', 'abc', 'test', 'cba', 'repaid']
# words = ['diaper', 'abc', 'test', 'cba', 'diaper']
print(find_palindromes(words))  # [['diaper', 'repaid'], ['abc', 'cba']]
