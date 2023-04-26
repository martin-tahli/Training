def set_entry_checker():
    # Ask for user's data: First name, age and VIP status.
    # If user's age is under 18, do not allow user to proceed
    # If user's age is between 18 - 25, allow them to stay up to 11pm
    # If group 18_25 has more than 10 users, do not allow user to enter.
    # If user is aged over 25, welcome them without any additional conditions.
    # As an output print out the users count from each group, and also print the VIPs
    # Example input: (Georgi 28, VIP) OR (Alex 25)
    number = input("enter number of users")
    counter = 0
    juveniles = 0
    users = []
    vips = []
    juveniles_ar = []
    standart = []
    while counter < int(number):

        users.append(input("Enter First name, age and VIP status. ").split())
        for user in users:
            if int(user[1]) < 18:
                print("You are not allowed")
                users.pop()
            if any("vip" in s for s in user):
                vips.append(user)

            elif 18 <= int(user[1]) <= 25:
                print("you are allowed to stay up to 11pm")
                juveniles += 1
                juveniles_ar.append(user)
                if juveniles > 10:
                    print("we cant accept anymore juveniles")
                    user.pop()
                users.pop()
                continue
            elif int(user[1]) > 25:
                print("ur wellcome")
                standart.append(user)
                users.pop()
                continue

            users.pop()
        counter += 1

    print(f'Standart users= {standart},Vip users={vips},Juveniles={juveniles_ar}')


set_entry_checker()
