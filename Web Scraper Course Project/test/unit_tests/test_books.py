import unittest
from module.modules.books import Book
from test.unit_tests.helper_testing.helper_tester import stats


class TestBookClass(unittest.TestCase):
    def setUp(self):
        test_stats = ["test_title", 20, "Love", 30, 3, "test"]
        self.book = Book(test_stats)

    def test_init_book_(self):
        self.assertEqual(self.book.tittle, "test_title")
        self.assertEqual(self.book.price, 20)
        self.assertEquals(self.book.availability, 30)
        self.assertEquals(self.book.rating, 3)
        self.assertEquals(self.book.description, "test")
        self.assertEquals(self.book.genre, "Love")

    def test_print_book_info(self):
        exp = "Book:test_title with price:20 and 30 available books in store "
        self.assertEquals(self.book.print_book_info(), exp)

    def test_getter_title(self):
        self.assertEquals(self.book.tittle, "test_title")

    def test_getter_price(self):
        self.assertEquals(self.book.price, 20)

    def test_getter_availability(self):
        self.assertEquals(self.book.availability, 30)

    def test_getter_genre(self):
        self.assertEquals(self.book.genre, "Love")

    def test_getter_description(self):
        self.assertEquals(self.book.description, "test")

    def test_setter_book_title(self):
        self.book.tittle = "NEW TITTLE"
        self.assertEquals(self.book.tittle, "NEW TITTLE")

    def test_setter_book_price(self):
        self.book.tittle = 0.00
        self.assertEquals(self.book.tittle, 0.00)

    def test_setter_book_rating(self):
        self.book.rating = 3
        self.assertEquals(self.book.rating, 3)

    def test_setter_book_description(self):
        self.book.description = "NEW DESCRIPTION"
        self.assertEquals(self.book.description, "NEW DESCRIPTION")

    def test_setter_book_gerne(self):
        self.book.description = "NEW GENRE"
        self.assertEquals(self.book.description, "NEW GENRE")


if __name__ == "main":
    unittest.main()
