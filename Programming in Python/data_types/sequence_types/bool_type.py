bool_true = True
bool_false = False

is_empty = bool([])
print(bool())
print(bool(None))
print(bool(0))
is_false = bool(len([]))
is_false_from_sets = bool({2, 3, 4}.union({2, 5, 6}))
print({2, 3, 4}.union({2, 5, 6}), is_false_from_sets)
is_false_by_not = not bool([])
print("not bool([])", is_false_by_not)

# all()
# any()
# print(is_empty)


for A in True, False:
    for B in True, False:
        for C in True, False:
            b1 = (A and B) or C
            b2 = A and (B or C)
            if b1 != b2:
                print(
                    """                               
                    for A = {}, B = {}, C = {}        
                    (A and B) or C = {}               
                    A and (B or C) = {}               
                    """.format(A, B, C, b1, b2)
                )
