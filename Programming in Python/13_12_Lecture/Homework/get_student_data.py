import csv
import os


# Finish the function by adding code that would extract the students data from the file.
# We only need valid students_data, i.e. from filled rows.
def get_students_data():
    INPUT_DIR = r'D:\PycharmProjects\Course\Programming in Python\13_12_Lecture\Homework\\'

    with open(os.path.join(INPUT_DIR, 'example_new.csv'), 'r') as source:
        reader = csv.reader(source, delimiter='\n')

        header = next(reader)
        incorrect = [',,,']
        print(header)
        for row in reader:
            if row == header:
                continue
            elif row == incorrect:
                continue
            print(row)


get_students_data()
