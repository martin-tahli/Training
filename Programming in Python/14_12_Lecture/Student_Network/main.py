import csv
import os
from pathlib import Path
import json as json
import random

current_directory = Path(os.path.abspath(__file__)).parent
text_file_path = os.path.join(current_directory, "students_exams.csv")

if os.path.exists(text_file_path):
    with open(text_file_path, "r") as file_source:
        file_content = file_source.read()
else:
    print(f"File  does not exist in {current_directory}")

students_dic = {}
HEADER_ROW = ['student', 'exam', 'points']
with open(os.path.join(current_directory, "students_exams.csv"), "r") as csv_source:
    reader = csv.reader(csv_source)
    print(type(reader))

    for row in reader:
        if row == HEADER_ROW:
            continue
        if not all(row):
            continue
        if row[0] in students_dic:
            students_dic[row[0]]["Ocenki"].append(int(row[2]))
        else:
            students_dic.update({row[0]: {"status": False, "Ocenki": [int(row[2])]}})

for keys, values in students_dic.items():
    cur_ocenka = values.get("Ocenki")
    average = sum(cur_ocenka) / len(cur_ocenka)

    if average >= 80:
        students_dic[keys]["status"] = True
    else:
        for i in range(len(cur_ocenka)):
            if not cur_ocenka[i] >= 80:
                for j in range(3):
                    cur_ocenka[i] = random.randint(40, 100)
                    if (sum(cur_ocenka) / len(cur_ocenka)) >= 80:
                        students_dic[keys]["status"] = True
                        break
            if values.get("status"):
                break

print("Pass:")
for key, value in students_dic.items():
    if value.get("status"):
        print(json.dumps(key, indent=10))

print("\nNot Pass:")
for key, value in students_dic.items():
    if not value.get("status"):
        print(json.dumps(key, indent=10))


