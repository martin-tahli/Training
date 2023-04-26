# 2,6,8
# dictionary = dict()
# dictionary = dict()
# dictionary = dict(**kwarg)
# dictionary = dict(mapping)
# dictionary = dict(mapping, **kwarg)
# dictionary = dict(iterable)
# dictionary = dict(iterable, **kwarg)
#
#
#
#
# dictionary = dict(**kwarg)
# c = dict(zip(['one', 'four', 'two', 'three'], [1, 4, 2, 3]))
#
# print(**c)
#
#
university = {
    "basic information": "Plovdiv University",
    "faculties": {
        "faculty biology": {
            "faculty information": "Тука се учи биолия.",
            "faculty dekan": {
                "Name": "Georgi",
                "Details": "10 години опит в областта."
            }

        },
        "faculty mathematics": {
            "faculty information": "Тука се учи математика",
            "faculty dekan": {
                "Name": "Ivan",
                "Details": "4 години опит в областта"
            }
        }
    },
    "administration": "Ние сме кожодери. "
}
for k, v in university.items():
    print(k, '\n', v, '\n', )

print(university)



























