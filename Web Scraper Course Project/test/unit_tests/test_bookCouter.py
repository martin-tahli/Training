import unittest
from argparse import Namespace

from module.modules.bookCounter import BookCounter
from module.modules.books import Book

ARGS = Namespace(books=10, filter=None, genres=None, gui=False, json=None, keyword=None, sorting=None, title=None)
class TestBookCounterClass(unittest.TestCase):
    def setUp(self):
        self.stats1 = ["Test tittle", 34, 2, 2, "Travel", "desc1"]
        self.stats2 = ["Test tittle1", 34, 3, 3, "Travel", "desc2"]
        self.stats3 = ["Test tittle2", 34, 1, 1, "Travel", "desc3"]
    def test_init_book_counter(self):
        numbers_of_desired_books = 10
        books = BookCounter(numbers_of_desired_books, ARGS)
        self.assertEqual(books.desired_number_of_books, 10)
        self.assertEqual(books.args, ARGS)
        self.assertEqual(books.args.sorting, None)

    def test_add_a_book_increase_books_list(self):
        numbers_of_desired_books = 10
        books = BookCounter(numbers_of_desired_books, ARGS)
        self.assertEquals(books.list_of_books, [])
        books.add_a_book("test")
        self.assertEquals(len(books.list_of_books), 1)
        books.add_a_book("test1")
        self.assertEquals(len(books.list_of_books), 2)

    def test_if_number_is_reached_return_true(self):
        books = BookCounter(1, ARGS)
        self.assertFalse(books.if_number_reached(), False)
        books.add_a_book("test")
        self.assertEquals(len(books.list_of_books), 1)
        self.assertTrue(books.if_number_reached(), True)

    def test_print_correct_info(self):
        books = BookCounter(1, ARGS)
        books.add_a_book(Book(self.stats1))
        exp_output = "Got 1 out of 1 books\nBook:Test tittle with price:34 and 2 available books in store \n"
        res = books.print_info()
        self.assertEquals(res, exp_output)

    def test_sort_books_from_book_couter(self):
        args = Namespace(books=10, filter=None, genres=None, gui=False, json=None,
                         keyword=None, sorting=['rating', 'ascending'], title=None)
        books = BookCounter(1, args)
        book1 = Book(self.stats1)
        book2 = Book(self.stats2)
        book3 = Book(self.stats3)
        books.add_a_book(book1)
        books.add_a_book(book2)
        books.add_a_book(book3)
        exp_result = [book1, book2, book3]
        self.assertEquals(books.list_of_books, exp_result)


if __name__ == "main":
    unittest.main()
