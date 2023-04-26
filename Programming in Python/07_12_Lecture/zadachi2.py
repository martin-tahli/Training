
# ##########################################################################################################
# 8)Искате
# да си смените апартамента и търсите на определена улица. На тази улица има поредица от блокове, в които можете да
# се нанесете, като във всеки от тези блокове има свободен апартамент, който да наемете. Освен това имате списък с
# изисквания за сгради, които са ви важни и искате да има в близост. (В случая ще ви е важно да има фитнес,
# училище и магазин). Блоковете са подредени и за всеки има информация дали в близост до него има желаните неща.
# Трябва да изберете апартамент в блока, който ще има училище, фитнес и магазин в най-голяма близост. Напишете
# функция, която ще приема dict с блокове и list с изисквания и ще връща индекса на най-добрия блок (NOTE: ако има 2
# еднакво оптимални блока няма значение кой от двата ще върнете) примерен вход:
# blocks = [{'gym': False,
#            'school': True,
#            'store': False, }, {'gym': True,
#                                'school': False,
#                                'store': False, }, {'gym': True,
#                                                    'school': False,
#                                                    'store': False, }, {'gym': False,
#                                                                        'school': True,
#                                                                        'store': False, }, {'gym': False,
#                                                                                            'school': True,
#                                                                                            'store': True, }]
# reqs = ['gym', 'school', 'store']
# example output: 3
# def proper_agency(block, requirements):
#     calc = []
#     requirement = requirements[0]
#     for i, j in zip(range(len(block)), block):
#         for key, value in j.items():
#             if requirement == key:
#                 if not value:
#                     calc.append(1)
#                 else:
#                     continue
#     print(calc)
#     # skip
#     # if not true calc where is nearest
def proper_agency(block, requirements):
    calc = list()

    for i, j in zip(range(len(block)), block):

        for requirement in requirements:
            if j.get(requirement) == True:
                calc.append(1)
                if calc == i:
                    calc[i] += 1

    print(calc)
    # skip
    # if not true calc where is nearest


blocks = [{'gym': False,
           'school': True,
           'store': False, }, {'gym': True,
                               'school': False,
                               'store': False, }, {'gym': True,
                                                   'school': False,
                                                   'store': False, }, {'gym': False,
                                                                       'school': True,
                                                                       'store': False, }, {'gym': False,
                                                                                           'school': True,
                                                                                           'store': True, }]
reqs = ['gym', 'school', 'store']
print(proper_agency(blocks, reqs))
# blocks.
