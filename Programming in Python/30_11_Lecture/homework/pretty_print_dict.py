import json as json


def pretty_print_dict(dictionary):
    """
    :param dictionary:
    :return: NOne
    If we have the following dictionary
    {
        level1: {
            attr1: value,
            attr2: value,
            level2: {
                attr1: value,
                attr2: value,
                level3: {
                    attr1: value,
                }
            }
        }
    }
    The desired output is the dictionary data printed in a pretty manner - tabulated (4 tabs) per
    level
    """

    print(json.dumps(dictionary, indent=4))


university = {
    "dean": "Name",
    "coordinator": "name2",
    "faculty": {
        "math": "equation",
        "physics": "aerodynamics",
        "CompScience": {
            "coding": "c",
            "networking": "OSI model"
        }

    }
}
pretty_print_dict(university)