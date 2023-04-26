num = input("Enter amount of names")
while True:
    if num.isdigit() and int(num) > 0:
        num = int(num)
        break
    else:
        num = input("Enter amount of names")

name = []
while num:
    names = (input(f"Enter name"))
    if names.isalpha():
        name.append(names)
        num -= 1

name.sort(reverse=True)

print(name)
