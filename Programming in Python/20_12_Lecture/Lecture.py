# Write a function that returns the max of 3 numbers.
def max_of_3(a, b, c):
    if a > b:
        if a > c:
            return a
        return c
    else:
        if b > c:
            return b
        return c


# print(max_of_3(2,84,0))

###################################################################################################
# Write a function that accepts list (int) and returns the sum of the elements. (Without sum) Input: [20, 5, 8, 40]
# Output: "The sum of {list} is 73"

def sum_of_list(my_list):
    summ = 0
    for elem in my_list:
        summ += elem
    return summ


new_list = [20, 5, 8, 40]


# print(sum_of_list(new_list))

###############################################################################################
# Write a function that accepts list (int) and returnes the product of the elements. Input: [8,2,3,-1,7] Output: -336
def product_of_list(my_list):
    summ = 1
    for elem in my_list:
        summ *= elem
    return summ


new_list1 = [8, 2, 3, -1, 7]


# print(product_of_list(new_list1))
###########################################################################################
# Write a function that reads and string and returns the number of the capital letters and the number of the lowercase
# letters within. Input: 'The quick Brow Fox' Output: No. of Upper case characters : 3 No. of Lower case Characters : 12

def count_low_capital(my_string):
    low = 0
    capitals = 0
    for c in my_string:
        if c.isupper():
            capitals += 1
        elif c.islower():
            low += 1

    print(f"No. of Upper case characters :{capitals}")
    print(f"No. of Lower case Characters :{low}")


# count_low_capital('The quick Brow Fox')
###############################################################################################################
# Write a function to print the even numbers from a given list. Input : [1, 2, 3, 4, 5, 6, 7, 8, 9] Output : [2,4,6, 8]
def even(my_list2):
    evens = []
    for elem in my_list2:
        if elem % 2 == 0:
            evens.append(elem)
    return evens


Input = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# print(even(Input))
############################################################################################################
# Write a function to create and print a list where the values are square of numbers between 1 and 30 (both included).
import math


def square():
    result = []
    for i in range(1, 30):
        result.append(math.sqrt(i))
    return result


# print(square())
########################################################################################################
# Write a function to detect the number of local variables declared in a function.
def detect_local():
    var = 3
    var2 = 3
    return len(locals())


# print(detect_local())


########################################################################################################
# Writer a function that tries to read a file that may not exists. The function should make total of 3 attempts to read
# the file. You should use while and recursion in combination of time.sleep(3).
def attempt_3_times(count: int, max_retry=3):
    try:
        f = open("file.txt")
    except FileNotFoundError:

        print(f"attempt {count}")
        count += 1
        if count > max_retry:
            print("we have successfully NOT found")
            # breakpoint()
            raise
    attempt_3_times(count)


attempt_3_times(1)
########################################################################################################
# Write a function that invoke a given function after specific milliseconds.
import time


def function_in_5sec():
    time.sleep(5/1000)
    print(square())

# function_in_5sec()
