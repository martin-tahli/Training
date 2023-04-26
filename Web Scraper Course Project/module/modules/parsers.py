import argparse
from utilities import *


def extract_filter_command(list_of_filters):
    filters = str(list_of_filters).split(",")
    tmp_list_filters = []
    for idx in range(len(filters)):
        for command in VALID_COMMANDS:
            if command in str(filters[idx]).replace(" ", ""):
                tmp_list_filters.append(str(filters[idx]).replace(" ", ""))
    return tmp_list_filters

class SortAction(argparse.Action):
    def __call__(self, parser, namespace, values, option_string=None):
        values = [s.lower() for s in values]
        for value in values:
            if not value in SORT_BY:
                parser.error("error: argument -s/--sorting: invalid choice:"
                             " {0} (choose from 'rating', 'genre', 'price',"
                             " 'title', 'availability', 'ascending', 'descending')".format(value))
        direction_of_sort = ["ascending", "descending"]
        default_direction = "ascending"
        if len(values) == 1:
            values.append(default_direction)
        elif len(values) == 2:
            if not values[1] in direction_of_sort:
                parser.error("second value must be direction of sorting "
                             "[ascending or descending]. Got '{0}'".format(values[1]))
        else:
            parser.error("sorting expected 1 or 2 arguments. Got {0}".format(len(values)))
        setattr(namespace, self.dest, values)

class GenreAction(argparse.Action):
    def __call__(self, parser, namespace, values, option_string=None):
        values = [s.lower() for s in values]
        values = list(set(values))
        setattr(namespace, self.dest, values)


class TitleAction(argparse.Action):
    def __call__(self, parser, namespace, values, option_string=None):
        values = [title for title in values[0].split(" ")]
        setattr(namespace, self.dest, values)


class KeyWordsAction(argparse.Action):
    def __call__(self, parser, namespace, values, option_string=None):
        values = [title for title in values[0].split(" ")]
        setattr(namespace, self.dest, values)


class ArgumentParser:
    def __init__(self):
        self.__parser = argparse.ArgumentParser(description="---Welcome to web scraper---")
        self.__parser.add_argument("-b", "--books",
                                   choices=range(1, 1001),
                                   nargs="?",
                                   default=1000,
                                   type=int,
                                   help="number of books(default = 1000)")
        self.__parser.add_argument("-g", "--genres",
                                   type=str,
                                   action=GenreAction,
                                   nargs="+",
                                   help="list of genres to search in")
        self.__parser.add_argument("-t", "--title",
                                   type=str,
                                   nargs="+",
                                   action=TitleAction,
                                   help="look for desired title")
        self.__parser.add_argument("-s", "--sorting",
                                   type=str,
                                   nargs="+",
                                   action=SortAction,
                                   help="list of sorting {ascending , descending}")
        self.__parser.add_argument("-d", "--keyword",
                                   type=str,
                                   nargs="+",
                                   action=KeyWordsAction,
                                   help="list of keywords for searching in descriptions")
        self.__parser.add_argument("-f", "--filter",
                                   type=extract_filter_command,
                                   nargs="?",
                                   help="list of filters")
        self.__parser.add_argument("-F", "--json",
                                   type=str,
                                   nargs="+",
                                   help="searching for titles in Json")
        self.__parser.add_argument("-X", "--gui", action='store_true', help="start gui")


    def parse_arguments(self):
        return self.__parser.parse_args()
