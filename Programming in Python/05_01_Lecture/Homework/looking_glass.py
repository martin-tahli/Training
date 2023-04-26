#Define looking_glass context manager that should print out text reversed
# version while Context manager is acctive

# with looking_glass():
#     print('Pesho, Gosho, Mincho')
# Output: ohcniM ,ohsoG ,ohseP

#print("Pesho, Gosho, Mincho")  # Should print out 'Pesho, Gosho, Mincho'

import sys
from contextlib import contextmanager


@contextmanager
def looking_glass():
    original_write = sys.stdout.write

    def reverse_write(text):
        original_write(text[::-1])

    sys.stdout.write = reverse_write
    yield
    sys.stdout.write = original_write


with looking_glass():
    print("Pesho, Gosho, Mincho")  # prints "ohcniM ,ohsoG ,ohseP"

print("Pesho, Gosho, Mincho")  # prints "Pesho, Gosho, Mincho"
