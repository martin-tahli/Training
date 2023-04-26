def scope_example():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam
        spam = "global spam"

    spam = "test spam"
    do_local()
    print("After local assignment:", spam, id(spam))
    do_nonlocal()
    print("After nonlocal assignment:", spam, id(spam))
    do_global()
    print("After global assignment:", spam, id(spam))


scope_example()
print(f"In global scope spam is {spam}", id(spam))
