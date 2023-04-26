import json
import os
 
 
def json_params(final_collection):
    cwd = os.getcwd()
    path = os.path.join(cwd, "output")
 
    try:
        os.mkdir(path)
    except OSError:
        path = "output/"
 
    with open(os.path.join(path, "Book collection"), "w") as collection:
        collection.write(
            json.dumps(final_collection, indent=2, encoding="latin-1")
        )
    print("JSON created successfully!")
    print("Collection JSON saved in output/Book collection.txt")
 
 
def json_read():
    cwd = os.getcwd()
    path = os.path.join(cwd, "output")
 
    try:
        os.mkdir(path)
    except OSError:
        path = "output/"
 
    # Opening JSON file
    with open(os.path.join(path, "Book collection"), "r") as openfile:
        # Reading from json file
        json_object = json.load(openfile)
    print(json.dumps(json_object, indent=2, encoding="latin-1"))
    return json_object
