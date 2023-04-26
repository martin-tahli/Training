# 5) Напишете функция, която приема 2D лист. Функцията трябва да взима елементите на матрицата в спираловиден
# ред и да ги записва в лист. Накрая върнете листа.
# примерен вход:
# array = [
# [1, 2, 3, 4],
# [12, 13, 14, 5],
# [11, 16, 15, 6],
# [10, 9, 8, 7],
# ]
# примерен изход: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
def spiral(arra):
    arr = []
    top = 0
    bottom = len(arra[0]) - 1
    left = 0
    right = len(arra) - 1
    direction = 0
    while top <= bottom and left <= right:
        ## move from left to right
        if direction == 0:
            for i in range(left, right + 1):
                arr.append(arra[top][i])
            direction = 1
            top += 1
        ## move from top right to bottom
        elif direction == 1:
            for i in range(top, bottom + 1):
                arr.append(arra[i][right])
            right -= 1
            direction = 2
        ## move from bottom right to bottom left
        elif direction == 2:
            for i in range(right, left - 1, -1):
                arr.append(arra[bottom][i])
            bottom -= 1
            direction = 3
        ##move from bottom left to top left
        elif direction == 3:
            for i in range(bottom, top - 1, -1):
                arr.append(arra[i][left])
            left += 1
            direction = 0

    return arr


array = [[1, 2, 3, 4],
         [12, 13, 14, 5],
         [11, 16, 15, 6],
         [10, 9, 8, 7], ]
arrays = [
    [1, 2, 3, 4],
    [10, 11, 12, 5],
    [9, 8, 7, 6]
]

print(spiral(array))
