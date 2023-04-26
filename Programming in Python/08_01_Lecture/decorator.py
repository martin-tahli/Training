def to_upper(func):
    def wrap():
        result=func()
        return result.upper()
    return wrap()

@to_upper
def hi():
    return "hi"

@to_upper
def zdrasti():
    return "drasti"

print(hi)
print(zdrasti)