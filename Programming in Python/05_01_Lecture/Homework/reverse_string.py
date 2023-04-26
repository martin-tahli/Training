def reverse_string(string):
    # Add code that would return reversed string
    # Do not use slice notation or reverse()

    rev = ''
    for i in range(len(string)-1, - 1, -1):
        rev += string[i]

    return rev


print(reverse_string("Hello"))
