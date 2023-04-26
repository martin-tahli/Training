class Singleton:
    instance = None
    _total_score = 0

    def __new__(cls, score, *args, **kwargs):
        if cls.instance is None:
            instance = super().__new__(cls)
            cls.instance = instance
        return cls.instance

    def __init__(self, score):
        self._total_score += score

    @property
    def total_score(self):
        return self._total_score

    def add_score(self, score):
        try:
            self._total_score += int(score)
        except TypeError:
            print(f"Bad {score} value passed")


s_a = Singleton(0)
s_a.add_score(5)
print(s_a.total_score)

s_b = Singleton(10)
print(s_b.total_score)
print(s_a.total_score)
