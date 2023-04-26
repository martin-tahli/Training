import unittest
from StringIO import StringIO
from mock.mock import Mock
from mock import patch, mock
from module.modules.Flow_control import *
from test.unit_tests.helper_testing.helper_tester import *



class TestControlFLow(unittest.TestCase):

    def get_html_content(self, file_content):
        file_path = file_content
        with open(file_path, "r") as f:
            html_contents = f.read()
            return html_contents

    def test_if_we_have_only_books_like_argument(self):
        arguments = Custom_argparser_tester(books=1)
        with patch('sys.stdout', new=StringIO()) as fake_out:
            flow = Flow_control(arguments)
            flow.hud()
            self.assertEqual(fake_out.getvalue(), expected_output)


    def test_category_dict_create_correct_dictinary(self):
        expected_dict = Flow_control.create_category_dictionary(self.get_html_content(
            "helper_testing/base_html_page_content.html"))
        sort_category_dict = sorted(CATEGORY_DICT.items(), key=lambda x: x)
        sort_expected_dict = sorted(expected_dict.items(), key=lambda x: x)
        self.assertEqual(sort_expected_dict, sort_category_dict)

    def test_check_requested_category_function_with_two_valid_category(self):
        arguments_input = Custom_argparser_tester(genres=['travel', 'art'])
        test_flow_control = Flow_control(arguments_input)
        url1 = CATEGORY_DICT[arguments_input.genres[0]]
        url2 = CATEGORY_DICT[arguments_input.genres[1]]
        expected_result = [url1, url2]
        result = Flow_control.check_requested_category(test_flow_control, CATEGORY_DICT)
        self.assertEqual(result, expected_result)

    def test_check_requested_category_function_with_invalid_category(self):
        arguments_input = Custom_argparser_tester(genres=['invalid category'])
        test_flow_control = Flow_control(arguments_input)
        result = Flow_control.check_requested_category(test_flow_control, CATEGORY_DICT)
        self.assertEqual(result, [])

    def test_check_requested_category_function_with_invalid_category_massage(self):
        arguments_input = Custom_argparser_tester(genres=['invalid category'])
        test_flow_control = Flow_control(arguments_input)
        expected_output = "Category: invalid category does not exist\n"
        with patch('sys.stdout', new=StringIO()) as fake_out:
            Flow_control.check_requested_category(test_flow_control, CATEGORY_DICT)
            self.assertEqual(fake_out.getvalue(), expected_output)

    def test_check_requested_category_function_return_only_valid_genres_in_args(self):
        arguments_input = Custom_argparser_tester(genres=['invalid category', 'art'])
        test_flow_control = Flow_control(arguments_input)
        Flow_control.check_requested_category(test_flow_control, CATEGORY_DICT)
        self.assertEqual(len(arguments_input.genres), 1)

    def test_book_count_assigning_create_count_object_with_correct_value(self):
        url_list = ['https://test_example.html']
        arguments_input = Custom_argparser_tester(books=5)
        test_flow_control = Flow_control(arguments_input)
        with patch('module.modules.Flow_control.Flow_control.page_cycling') as mock_page_cycling:
            count = Flow_control.book_count_assigning(test_flow_control, url_list)
            mock_page_cycling.assert_called_with(url_list[0], mock.ANY)
            self.assertEqual(count.desired_number_of_books, 5)

    def test_get_list_of_books_urls_function_return_corect_list_with_urls_one_page_category(self):
        books_urls = []
        html_content = self.get_html_content("helper_testing/historical_category_content.html")
        # url of category with one page
        url = 'http://books.toscrape.com/catalogue/category/books/historical_42/'
        next_page_url = ["index.html"]
        Flow_control.get_list_of_books_urls(html_content, url, next_page_url, books_urls)
        self.assertEqual(len(books_urls), 2)

    def test_get_list_of_books_urls_function_return_correct_list_with_urls_two_page_category(self):
        books_urls = []
        html_content = self.get_html_content("helper_testing/children_category_content.html")
        # url of category with two pages
        url = 'http://books.toscrape.com/catalogue/category/books/childers_11/'
        next_page_url = ["index.html"]
        Flow_control.get_list_of_books_urls(html_content, url, next_page_url, books_urls)
        self.assertEqual(len(books_urls), 20)

    def test_take_book_data_function(self):
        html_content = self.get_html_content("helper_testing/book_page_content.html")
        result = Flow_control.take_book_data(html_content)
        self.assertEqual(len(result), 6)

    def test_take_book_data_correct_data_take(self):
        html_content = self.get_html_content("helper_testing/book_page_content.html")
        result = Flow_control.take_book_data(html_content)
        self.assertEqual(result[BOOK['TITLE']], "Birdsong: A Story in Pictures")
        self.assertEqual(result[BOOK['PRICE']], '54.64')
        self.assertEqual(result[BOOK['GENRE']], "Childrens")
        self.assertEqual(result[BOOK['AVAILABILITY']], "19")
        self.assertEqual(result[BOOK['RATING']], "Three")
        self.assertEqual(result[BOOK['DESCRIPTION']], TEST_DESCRIPTION)

    def test_take_book_data_if_book_has_no_description(self):
        html_content = self.get_html_content("helper_testing/book_page_without_description.html")
        result = Flow_control.take_book_data(html_content)
        self.assertEqual(result[BOOK["DESCRIPTION"]], "")


    @patch('requests.get')
    def test_get_html_content_response_corectly(self, mock_get):
        mock_response = Mock()
        mock_response.status_code = 200
        mock_get.return_value = mock_response
        url = 'http://example.com'
        result = Flow_control.get_html_content(url)
        mock_get.assert_called_with(url)
        self.assertEqual(result, mock_response.content)
        self.assertEqual(mock_response.status_code, 200)

    def test_compare_stats_with_match(self):
        args = Custom_argparser_tester(genres=['poetry'], title="book title", keyword="simple", filter=["'rating=4'"])
        test_stats = ["book title", 23, 'Poetry', 23, 4, 'simple descrioption']
        test_flow_control = Flow_control(args)
        result = Flow_control.compare_stats(test_flow_control, test_stats)
        self.assertTrue(result)

    def test_compare_stats_with_not_match_of_genres(self):
        args = Custom_argparser_tester(genres=['not searching genres'], title="book title",
                                       keyword="simple", filter=["'rating=4'"])
        test_stats = ["book title", 23, 'Poetry', 23, 4, 'simple descrioption']
        test_flow_control = Flow_control(args)
        result = Flow_control.compare_stats(test_flow_control, test_stats)
        self.assertFalse(result)

    def test_compare_stats_with_not_match_of_book_title(self):
        args = Custom_argparser_tester(genres=['poetry'], title="not searching book title",
                                       keyword="simple", filter=["'rating=4'"])
        test_stats = ["book title", 23, 'Poetry', 23, 4, 'simple descrioption']
        test_flow_control = Flow_control(args)
        result = Flow_control.compare_stats(test_flow_control, test_stats)
        self.assertFalse(result)

    def test_compare_stats_with_not_match_of_rating_desire_3_in_book_4(self):
        args = Custom_argparser_tester(genres=['poetry'], title="not searching book title",
                                       keyword="simple", filter=["'rating=3'"])
        test_stats = ["book title", 23, 'Poetry', 23, 4, 'simple descrioption']
        test_flow_control = Flow_control(args)
        result = Flow_control.compare_stats(test_flow_control, test_stats)
        self.assertFalse(result)

    def test_compare_stats_with_not_match_of_keyword(self):
        args = Custom_argparser_tester(genres=['poetry'], title="not searching book title",
                                       keyword="not match", filter=["'rating=4'"])
        test_stats = ["book title", 23, 'Poetry', 23, 4, 'simple descrioption']
        test_flow_control = Flow_control(args)
        result = Flow_control.compare_stats(test_flow_control, test_stats)
        self.assertFalse(result)



if __name__ == "main":
    unittest.main()
