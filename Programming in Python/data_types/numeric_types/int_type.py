import math
from decimal import Decimal

number_one = 15
print(bin(number_one))
print(hex(number_one))
print(oct(number_one))

print(int(0o17))
print(int("88"))

float()
Decimal()
# The bellow will throw ValueError
# print(int("Pesho"))

long_number_display = 100_000_000_000
print(long_number_display)


a = 5
b = 3.5
c = a + b
