import datetime
import math

#
# example_string = "CodeAcademy"
# print(type(example_string), example_string)
# example_string = example_string + "BG"
# print(example_string)
#
# for x in range(1, 5):
#     example_string += str(x)
# print(example_string)
#
# # Better way for concatenation of str elements
# str_els = ["CodeAcademy"]
# str_els.append("BG")
# for x in range(1, 5):
#     str_els.append(str(x))
# print("".join(str_els))
#
# string_with_nested_quotes = 'This is a bit of string with " nested " quotes\' within'
# print(string_with_nested_quotes)
#
# multiline_string_opt_1 = """laskd;aksd;
# jalskdka;sd, akjsdlajsd;
# asaksl;dk;
# aks;ldkasld."""
#
# print(multiline_string_opt_1)
#
# multiline_string_opt_2 = (
#     "This is some pretty looking "
#     "multiline string. "
# )
#
# print(multiline_string_opt_2)
#
# # How to split a string in python.
# print(example_string.split("C"))
#
# print(example_string.find("ode"))
# print(example_string.split("e", maxsplit=1))
#
# external_string = "2022|||05|||125648"
# print(len(external_string))
# print(external_string.replace("|||", "_"))
#
# print(' abcd '.center(30, '+'))
# print("C:\\new folder")


#############################################
################# Formating #################


name = "Pesho"
code_key = 52
formatted_string = (
    f"My name is {name}. This is a string holding some"
    f" not valuable info {code_key}. \n"
    f"Current time is {datetime.datetime.now()}"
)
print(formatted_string)

print(f"{math.pi:.2F}")

# Work with bytes from strings
a = 'deヿfㇿg'
print(a, len(a), type(a))
a = 'deヿfㇿg'.encode()
print(a, len(a), type(a))

from_bytes_to_str_a = b'de\xe3\x83\xbff\xe3\x87\xbfg'.decode()
print(from_bytes_to_str_a)

