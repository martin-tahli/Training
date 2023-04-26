class A:
    def method(self):
        print("A.method() called")


class B:
    def method(self):
        print("B.method() called")


class C(A, B):
    pass


class D(C, B):
    pass


d = D()
# Shows the order of inheritance if possible to order, leading to object itself.
print(D.mro())
d.method()

c = C()
c.method()

object()
