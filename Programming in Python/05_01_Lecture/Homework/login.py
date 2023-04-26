# 2. Write decorator login_required that would be used to check if a user is logged, and if not,
# it should print out "Login required", and if user is logged, the decorated function should print
# "Welcome"
# For user you can use {'name': 'User name', 'logged': True / False}

def login_required(func):
    def wrapper(user):
        if user['logged']:
            print(f"Hello, {user['name']}!")
            print("Welcome")
        else:
            print("Login required")

    return wrapper


@login_required
def greeting():
    return


user1 = {'name': 'Ivan', 'logged': True}
user2 = {'name': 'Grozniq', 'logged': False}

greeting(user1)  # prints "Hello, Alice!" and "Welcome"
greeting(user2)  # prints "Login required"
