def store_calcs(number1, number2, calcs):
    """
    Write a code that stores the sum, subtract, product and reminder
    of number1 and number2 within calcs_array
    :param number1:
    :param number2:
    :param calcs: calcs_array
    :return: calcs
    """


num1 = int(input("num1= ?"))
num2 = int(input("num2= ?"))
result = 0
operand = input("choose operation + - * /")

if operand == "+":
    result = num1 + num2
elif operand == "-":
    result = num1 - num2
elif operand == "*":
    result = num1 - num2
elif operand == "/":
    result = num1 / num2
else:
    print("WRONG OPERAND")

print(num1, operand, num2, "=", result)

pass
