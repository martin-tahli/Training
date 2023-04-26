import csv
import os
from contextlib import suppress
from pathlib import Path

# try:
#     file = open("test_with_statement5.txt", "r")
#     print(file.read())
# except IOError:
#     print("An I/O error has occurred!")
# except:
#     print("An unknown error has occurred!")
# else:
#     file.close()

"""
file = open("test_with_statement5.txt", "r")
print(file.read())
file.close()
"""


# print(__file__)
current_directory = Path(os.path.abspath(__file__)).parent
text_file_path = os.path.join(current_directory, "test_with_statement.txt")
# print(text_file_path)

if os.path.exists(text_file_path):
    with open(text_file_path, "r") as file_source:
        file_content = file_source.read()
else:
    print(f"File test_with_statement5.txt does not exist in {current_directory}")

# Print globals and locals to check how we're using 'file_source' and 'file_content' after 'with'
# context manager is done, i.e. the __exit__ method of it has been called.
# print(f"Globals: {globals()}")
# print(f"Locals: {locals()}")
# print(f"Is file {file_source.name} closed? {file_source.closed}")
# print(file_content)

# Create and write in File
# text_file_to_be_created_path = os.path.join(current_directory, "test_with_statementW.txt")
# with open(text_file_to_be_created_path, "a") as file_saved:
#     # file_saved.write("Content on line 1\n")
#     # file_saved.write("Content on line 2\n")
#     # file_saved.write("Content on line 3\n")
#     # file_saved.write("Content on line 4\n")
#     file_saved.writelines([
#         "Content on line 1\n",
#         "Content on line 2\n",
#         "Content on line 3\n",`
#         "Content on line 4\n",
#     ])


# Example for reading .csv file
HEADER_ROW = ['student_name', 'student_age', 'exam_number', 'exam_result']
with open(os.path.join(current_directory, "example_new.csv"), "r") as csv_source:
    reader = csv.reader(csv_source)
    print(type(reader))

    for row in reader:
        if row == HEADER_ROW:
            continue
        if not all(row):
            continue
        print(row)

