# 3. Write a function that would return if given int is within a certain range
def within_range(mins, maxs, target):
    if mins > maxs:
        mins, maxs = maxs, mins
    print(mins, maxs)
    return mins <= target <= maxs


print(within_range(15, 10, 13))
