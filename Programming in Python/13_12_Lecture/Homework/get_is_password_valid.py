import re


def get_is_password_valid():
    # Ask for user's password.
    # Check user's password against the following conditions:
    # At least 6 symbols, and maximum of 32 symbols.
    # At least 1 upper case letter.
    # At least 1 symbol.
    # hint: use the re library.

    # Ask for the user's password
    password = input("Enter your password: ")

    # Check if the password meets the conditions
    if re.match(r'^(?=.*[A-Z])(?=.*[!@#$%^&*\(\)])(?=.{6,32})', password):
        print("Valid password")
    else:
        print("Invalid password")


get_is_password_valid()
