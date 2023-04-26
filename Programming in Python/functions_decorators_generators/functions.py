__CONST_PI = 3.14

def hello_world():
    # You can write any valid Python code within the function body
    print("Hello world!")


def callback_fn_example():
    print("I am just an empty callback function, ready to print out this message when called!")


# Mandatory args
def print_human_info(name: str, age: int, /, year_of_graduate=None, callback_fn=None):
    """
    This function will be used to print out human name and age.

    Arguments:
        name (str): Human name
        age (int): Human age
        year_of_graduate (int): Graduate year
        callback_fn (def): Callback function example
    Returns:
        None
    """
    SPECIAL_FN_KEY = "588"

    print(f"Human is {name}, aged: {age}.", end="" if year_of_graduate is not None else "\n")
    if year_of_graduate:
        print(f" Human {name} graduated at {year_of_graduate}.")
    if callback_fn:
        callback_fn()


def store_names(name: str, names=[]):
    # It is dangerous to use mutable data types as kwarg default value.
    print(store_names.__defaults__)
    if len(name):
        names.append(name)
    return names


result = 80

def power(x, y):
    global result
    while y > 0:
        result *= x
        y -= 1
    return result


def users_list(main_user, *users, main_user_age=None, **user_options):
    print(main_user)
    print(type(users), len(users), users[0], user_options)
    for user in users:
        print(user, user_options[user])


def print_args_kwargs(*args, **kwargs):
    # Ready to be loaded with numerous args |& kwargs
    print(args)
    print(kwargs)


def function_with_only_args(*args):
    print(args)


def function_with_only_kwargs(**kwargs):
    print(kwargs)


def strict_arguments(age, user=15):
    print(age, user)


################################################################################
def f1_special_syntax(arg1, arg2, /):
    # Only positional arguments that must be passed as positional arguments in f1 call
    print(arg1, arg2)


def f2_special_syntax(arg1, arg2, /, arg_or_kwarg):
    # Combination of strict positional arguments and arg OR kwarg
    print(arg1, arg2, arg_or_kwarg)


def f3_special_syntax(arg1, arg2, /, arg_or_kwarg, *, kwarg1=None):
    # Combination of strict positional arguments, followed by arg OR kwarg, after which MUST come
    # kwarg
    print(arg1, arg2, arg_or_kwarg, kwarg1)

################################################################################


def scope_test():
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


if __name__ == "__main__":
    # print(locals())
    # hello_world()
    # print_name = "German"
    # print("print_name in locals()", print_name in locals())
    # print_age = 27
    # print_human_info(print_name, print_age, callback_fn=callback_fn_example, year_of_graduate=2018)

    # names = store_names("German")
    # names_after_next_call = store_names("Pesho")

    # Assigned as a variable or in a data structure
    # print_fn_ref = print_human_info
    # print_fn_ref("Pesho", 32)

    print(power(2, 3))
    # print(power(x=2, y=3))

    # print(users_list("German", "Radina", 558, "Filip", "Yordan", "Radoslav", main_user_age=25, Radina="fff", Delyan="ccc"))

    # print_args_kwargs(Radina="fff", Delyan="ccc")
    # strict_arguments(15, 20, 25, 25, user1=26)


    ###############################################################################################
    ################### Special syntax function calls #############################################

    # f1_special_syntax(1, 2)
    #
    # f2_special_syntax(1, 2, 5)
    # f2_special_syntax(1, 2, arg_or_kwarg=5)
    #
    # f3_special_syntax(1, 2, 5)
    # f3_special_syntax(1, 2, arg_or_kwarg=5, kwarg1="Something")

    scope_test()
    print("In global scope:", spam)

    variable_add = lambda x: x + 2
