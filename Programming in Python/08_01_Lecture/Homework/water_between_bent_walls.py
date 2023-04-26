# def trapped_water(bar_heights):
#     n = len(bar_heights)
#     left_max = [0] * n
#     right_max = [0] * n
#     water = 0
#
#     # Finding the left max of each element
#     left_max[0] = bar_heights[0]
#     for i in range(1, n):
#         left_max[i] = max(left_max[i - 1], bar_heights[i])
#
#     # Finding the right max of each element
#     right_max[n - 1] = bar_heights[n - 1]
#     for i in range(n - 2, -1, -1):
#         right_max[i] = max(right_max[i + 1], bar_heights[i])
#
#     # Calculating the trapped water
#     for i in range(0, n):
#         water += min(left_max[i], right_max[i]) - bar_heights[i]
#
#     return water
#
#
# walls = [0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3]
# print(trapped_water(walls))

import itertools


def trapped_water(bar_heights):
    left_max = list(itertools.accumulate(bar_heights, max))
    right_max = list(itertools.accumulate(bar_heights[::-1], max))[::-1]
    return sum(min(left, right) - height for left, right, height in zip(left_max, right_max, bar_heights))


walls = [0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3]
print(trapped_water(walls))
