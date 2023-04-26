import csv
import os


def get_top_three_students():
    # 1. Read the students_data.csv
    # 2. Collect the students data
    # 3. Return the top 3 students, ranked by current result.


    # Open the students_data.csv file in read mode
    INPUT_DIR = r'D:\PycharmProjects\Course\Programming in Python\13_12_Lecture\Homework\\'
    with open(os.path.join(INPUT_DIR, 'example_new.csv'), 'r') as file:
        # Create a CSV reader object
        reader = csv.reader(file)

        # Initialize an empty list to store the students data
        students = []
        header = next(reader)
        incorrect = [',,,']
        #print(header)
        for row in reader:
            if row == header:
                continue
            elif row == incorrect:
                continue
            students.append(row)

    # Print the students data
    #print(students)
    # Sort the students list by current result in descending order
    students.sort(key=lambda x: x[3], reverse=True)

    # Return the top 3 students
    top_students = students[:3]

    # Print the top 3 students
    print(top_students)


get_top_three_students()