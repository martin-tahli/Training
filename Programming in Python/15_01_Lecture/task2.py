# imame list sus sgradi kolko sgradi shte mogat da vidqt zaleza Примерен вход - [8,10,7,6,9,5,4,3,2]
import albalacalculator

def buildings_able_to_see(buildings):
    highest = buildings[0]
    result = []
    for building in buildings:
        if building > highest:
            highest = building
        result.append(highest)
    for item in range(len(result) - 1):
        if result[item] == result[item+1]:
            result.pop()
            print()

    return result


buildings = [8, 10, 7, 6, 9, 5, 4, 3, 2]
print(buildings_able_to_see(buildings))
