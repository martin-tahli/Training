import requests
from bs4 import BeautifulSoup
import re
from bookCounter import BookCounter
from books import Book
from input_check import json_params

words_to_numbers_dict = {
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
}


class Flow_control:
    def __init__(self, args):
        self.__args = args
        self.__init_url = "https://books.toscrape.com/catalogue/category/books_1/index.html"

    @property
    def args(self):
        return self.__args

    @property
    def init_url(self):
        return self.__init_url

    @args.setter
    def args(self, new_args):
        self.__args = new_args

    @init_url.setter
    def init_url(self, new_init_url):
        self.__init_url = new_init_url

    def hud(self):
        """"
        This func is the pseudo hud
        """
        url_list = [self.init_url]

        if self.args.genres:
            url_base_category = 'https://books.toscrape.com/index.html'
            category_dict = self.create_category_dictionary(self.get_html_content(url_base_category))
            url_list = self.check_requested_category(category_dict)
            if not url_list:
                return

        counter = self.book_count_assigning(url_list)
        print(counter.print_info())
        if self.args.json is not None:
            json_params(counter.print_info(), self.args.json[0])

        return

    @staticmethod
    def create_category_dictionary(html_content):
        """"
        This func creates a dictionary using the categories as keys and their urls as values
        """
        initial_url = "http://books.toscrape.com/"
        category_dict = {}
        soup = BeautifulSoup(html_content, "html.parser")
        sidebar = soup.find("aside", class_="sidebar col-sm-4 col-md-3")
        wrapper_list = sidebar.find("ul", class_="nav nav-list")
        category_list = wrapper_list.find("ul")
        tittle_set = category_list.find_all("li")
        a_set = category_list.find_all("a")

        for tittle, hrefs in zip(tittle_set, a_set):
            category_dict[tittle.text.replace("\n", "").lower().strip()] = initial_url + hrefs["href"]
        return category_dict

    def check_requested_category(self, category_dict):
        """"
        This func check if the requested category is valid and if it is
        it return the correct url extension and if it is not it
        return an empty string
        """
        url_list = []
        tmp_list = []
        for category in self.args.genres:
            tmp_category = category.lower().strip()
            if tmp_category in category_dict.keys():
                tmp_list.append(tmp_category)
                url_list.append(category_dict[tmp_category])
            else:
                print("Category: {0} does not exist".format(category))
        self.args.genres = tmp_list
        return url_list

    def book_count_assigning(self, url_list):
        """
        This func assigns the correct number of books which should be scrapped from each category
        """
        books_per_category = int(self.args.books) // len(url_list)
        if int(self.args.books) % len(url_list) != 0:
            counter = BookCounter(books_per_category + (self.args.books - books_per_category * len(url_list)), self.args)
        else:
            counter = BookCounter(books_per_category, self.args)
        self.page_cycling(url_list[0], counter)
        for url in url_list[1:]:
            counter.desired_number_of_books = counter.desired_number_of_books + books_per_category
            self.page_cycling(url, counter)
        return counter

    def page_cycling(self, initial_url, counter):
        extension = ["index.html"]
        book_urls = []
        exit = 0
        initial_url = initial_url.replace("index.html", "")
        while exit != 1:
            if self.get_list_of_books_urls(self.get_html_content(initial_url + str(extension[0])),
                                           initial_url, extension, book_urls):
                exit = 1
            for book_url in book_urls:
                html_content = self.get_html_content(book_url)
                stats = self.take_book_data(html_content)
                if self.compare_stats(stats):
                    counter.add_a_book(Book(stats))
                    if counter.if_number_reached():
                        return
            book_urls = []


    @staticmethod
    def get_html_content(url):
        req = requests.get(url)
        return req.content

    @staticmethod
    def get_list_of_books_urls(html_content, url, next_page_url, book_urls):
        soup = BeautifulSoup(html_content, "html.parser")
        wrapper = soup.find("ol", class_="row")
        base_url = "/".join(url.split("/")[0:-3:1])
        for book in wrapper.find_all("li", class_="col-xs-6 col-sm-4 col-md-3 col-lg-3"):
            book_url = base_url + "/" + book.find("h3").a["href"][6:]
            book_urls.append(book_url)
        next_page = soup.find("li", class_="next")
        if next_page is None:
            next_page_url.pop(0)
            return True
        else:
            next_page_url[0] = next_page.a["href"]
            return False


    @staticmethod
    def take_book_data(book_page_content):
        soup = BeautifulSoup(book_page_content, "html.parser")
        book_page_wrapper = soup.find("div", class_="container-fluid page")
        book_page = book_page_wrapper.find("div", class_="page_inner")
        genre_list = book_page.find("ul", class_="breadcrumb")
        title = genre_list.find("li", class_='active').text
        price = "".join(book_page.find("p", class_='price_color').text[1::])
        rating_wrapper = soup.find("div", class_='col-sm-6 product_main')
        rating = rating_wrapper.find_all("p")[-1].get("class")[-1]
        genre = genre_list.find_all("li")[-2].a.text
        page_content = book_page.find("div", class_="content")
        inner_content = page_content.find("article", class_="product_page")
        availability = book_page.find("p", class_="instock availability").text.strip().split(" ")[-2][1:]
        try:
            description = inner_content.find("p", class_="").text
        except AttributeError:
            description = ""
        return [title, price, genre, availability, rating, description]

    def json_compare(self, tittle, genre):
        if self.args.genres is not None and genre.lower() not in self.args.genres[0].lower():
            return True
        if self.args.title is not None:
            for titles in self.args.title:
                if titles.lower().strip() in tittle.lower():
                    return False
        return True

    def compare_stats(self, stats):
        """
        This func compares basic parameters gotten from the catalogue page
        """
        tittle, price, genre, available, rating, description = stats
        if self.args.json is not None:
            if self.json_compare(tittle, genre):
                return False
        else:
            if self.args.title is not None and self.args.title[0].lower() not in tittle.lower():
                return False
            if self.args.keyword is not None:
                for word in self.args.keyword:
                    if not re.search(word, description):
                        return False
            if self.args.genres is not None and genre.lower() not in self.args.genres:
                return False
            if self.args.filter is not None:
                for filters in self.args.filter:
                    if not eval(filters):
                        return False
        return True
