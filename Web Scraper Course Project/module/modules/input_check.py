import json
from gui.display import Gui
from module.modules.parsers import ArgumentParser
from argparse import Namespace


def input_check():
    parse_args = ArgumentParser()
    args = parse_args.parse_arguments()
    if args.gui:
        gui_instance = Gui()
        gui_instance.start_gui()
        stats = gui_instance.get_arguments()
        args = stats
    elif args.json:
        stats = read_json_file(args.json[0])
        print stats
        args = stats
    return args


def read_json_file(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
        data = data.split(",")
    return Namespace(books=1000, filter=None, genres=[data[-1].lower()], gui=False, json=[file_path], keyword=None, sorting=None,
                  title=[tittle.lower() for tittle in data[:-1:]])


def json_params(final_collection, file_path):
    with open(file_path, "w") as collection:
        collection.write(
            json.dumps(final_collection, indent=2, encoding="latin-1")
        )
    print("JSON created successfully!")
    print("Collection JSON saved in output/Book collection.txt")

