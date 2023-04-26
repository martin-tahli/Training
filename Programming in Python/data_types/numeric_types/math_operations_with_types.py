from decimal import Decimal

print(5 + 3, type(5 + 3))
print(5 + 3.3, type(5 + 3.3))
print(2.5 + 3.3, type(2.5 + 3.3))
print(5 + Decimal("2"), type(5 + Decimal("2")))
print(Decimal(3.5) + Decimal("3.5"), type(Decimal(3.5) + Decimal("3.5")))
