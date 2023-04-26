

class BookCounter:
    """"
    This class hold an array with all Book class instances and keeps track of their count and order
    """
    def __init__(self, number_of_desired_books, args):
        self.__list_of_books = []
        self.__desired_number_of_books = number_of_desired_books
        self.__args = args
        if args.sorting:
            self.sort = args.sorting[0]
            self.sort_direction = True if args.sorting[1] == "ascending" else False
        else:
            self.sort = None
            self.sort_direction = None

    @property
    def args(self):
        return self.__args

    @args.setter
    def args(self, value):
        self.args = value

    @property
    def sort(self):
        return self.__sort

    @sort.setter
    def sort(self, value):
        if self.__args.sorting:
            self.__sort = value

    @property
    def list_of_books(self):
        return self.__list_of_books

    @property
    def desired_number_of_books(self):
        return self.__desired_number_of_books

    @desired_number_of_books.setter
    def desired_number_of_books(self, value):
        self.__desired_number_of_books = value

    @list_of_books.setter
    def list_of_books(self, new_list):
        self.__list_of_books = new_list

    def add_a_book(self, book):
        self.__list_of_books.append(book)

    def if_number_reached(self):
        return len(self.list_of_books) == self.desired_number_of_books

    def print_info(self):
        if self.__args.sorting:
            self.sort_books()
        result_str = "Got {0} out of {1} books\n".format(len(self.__list_of_books), self.desired_number_of_books)
        for book in self.__list_of_books:
            result_str += book.print_book_info()
            result_str += '\n'
        return result_str

    def sort_books(self):
        sort_condition = "book." + str(self.sort)
        return self.list_of_books.sort(key=lambda book: eval(sort_condition), reverse=self.sort_direction)
