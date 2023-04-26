def get_is_palindrome(string):
    """
    Finish the function by adding code that returns a boolean with palindrome check.
    A string is palindrome if it is written the same forward and backward. Single char string is
    a palindrome string.
    Example:
    string = 'abcdcba'
    result: True
    :param string:
    :return: bool
    """
    for i in range(0, len(string)):
        if string[i] != string[len(string) - i - 1]:
            return 0
        else:
            return 1


print(get_is_palindrome('abcdcba'))
print(get_is_palindrome('Hello'))
