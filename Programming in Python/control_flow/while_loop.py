counter = 0


# while counter < 5:
#     print(f"Counter value is: {counter}")
#     counter += 1  # If we don’t add this line, we’ll simply enter an infinite loop

starting_point = 20
# while starting_point < 30:
#     print("I'm in while loop")
#     if starting_point >= 25:
#         # Cause endless while loop
#         continue
#     starting_point += 1


while starting_point < 30:
    print("I'm in while loop with break")
    if starting_point >= 25:
        # Terminate the loop
        print("We hit the break")
        break
    starting_point += 1
else:
    print("While loop ended successfully")


# while starting_point < 22:
#     print(f"{starting_point} ** 2 // 3 % 5 = ", starting_point ** 2 // 3 % 5)
#     starting_point += 1
# else:
#     print("While loop ended successfully")


while True:
    # define some retry logic
    break
