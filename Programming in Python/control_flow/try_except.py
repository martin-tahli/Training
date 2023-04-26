# number_names = None

# while True:
#     try:
#         number_names = int(input("Please enter a number of names: "))
#         break
#     except ValueError:
#         continue

# print(number_names)

# Example with handling single Error
# try:
#     number_names = int(input("Please enter a number of names: "))
# except ValueError as e:
#     print(f"Received a bad value when asked when asked for int. {e.args[0]}")


# Example with handling any of Errors
try:
    number_names = int(input("Please enter a number of names: "))
except ValueError as e:
    print(f"Received a bad value when asked when asked for int. {e.args[0]}")
except AttributeError:
    print("Hit a Type error")
else:
    # Only when try code is successful
    print("Within else statement")
finally:
    # Always executed even when unhandled errors are raised
    print("Here in Finally")
