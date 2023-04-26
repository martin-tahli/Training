from argparse import Namespace


class Custom_argparser_tester:
    def __init__(self, books=1000, filter=None, genres=None, gui=None, json=None, keyword=None, sorting=None,
                 title=None):
        self.books = books
        self.filter = filter
        self.genres = genres
        self.gui = gui
        self.json = json
        self.keyword = keyword
        self.sorting = sorting
        self.title = title


expected_output = "Got 1 out of 1 books\nBook:A Light in the Attic with price:51.77 and 22 available books in store \n\n"

TEST_DESCRIPTION = "TestTestTestDescription"

BOOK = {
    'TITLE': 0,
    'PRICE': 1,
    'GENRE': 2,
    'AVAILABILITY': 3,
    'RATING': 4,
    'DESCRIPTION': 5
}

CATEGORY_DICT = {
    u'young adult': u'http://books.toscrape.com/catalogue/category/books/young-adult_21/index.html',
    u'art': u'http://books.toscrape.com/catalogue/category/books/art_25/index.html',
    u'childrens': u'http://books.toscrape.com/catalogue/category/books/childrens_11/index.html',
    u'paranormal': u'http://books.toscrape.com/catalogue/category/books/paranormal_24/index.html',
    u'fantasy': u'http://books.toscrape.com/catalogue/category/books/fantasy_19/index.html',
    u'suspense': u'http://books.toscrape.com/catalogue/category/books/suspense_44/index.html',
    u'nonfiction': u'http://books.toscrape.com/catalogue/category/books/nonfiction_13/index.html',
    u'politics': u'http://books.toscrape.com/catalogue/category/books/politics_48/index.html',
    u'crime': u'http://books.toscrape.com/catalogue/category/books/crime_51/index.html',
    u'biography': u'http://books.toscrape.com/catalogue/category/books/biography_36/index.html',
    u'womens fiction': u'http://books.toscrape.com/catalogue/category/books/womens-fiction_9/index.html',
    u'autobiography': u'http://books.toscrape.com/catalogue/category/books/autobiography_27/index.html',
    u'humor': u'http://books.toscrape.com/catalogue/category/books/humor_30/index.html',
    u'psychology': u'http://books.toscrape.com/catalogue/category/books/psychology_26/index.html',
    u'spirituality': u'http://books.toscrape.com/catalogue/category/books/spirituality_39/index.html',
    u'travel': u'http://books.toscrape.com/catalogue/category/books/travel_2/index.html',
    u'novels': u'http://books.toscrape.com/catalogue/category/books/novels_46/index.html',
    u'poetry': u'http://books.toscrape.com/catalogue/category/books/poetry_23/index.html',
    u'fiction': u'http://books.toscrape.com/catalogue/category/books/fiction_10/index.html',
    u'romance': u'http://books.toscrape.com/catalogue/category/books/romance_8/index.html',
    u'religion': u'http://books.toscrape.com/catalogue/category/books/religion_12/index.html',
    u'add a comment': u'http://books.toscrape.com/catalogue/category/books/add-a-comment_18/index.html',
    u'music': u'http://books.toscrape.com/catalogue/category/books/music_14/index.html',
    u'health': u'http://books.toscrape.com/catalogue/category/books/health_47/index.html',
    u'self help': u'http://books.toscrape.com/catalogue/category/books/self-help_41/index.html',
    u'christian': u'http://books.toscrape.com/catalogue/category/books/christian_43/index.html',
    u'business': u'http://books.toscrape.com/catalogue/category/books/business_35/index.html',
    u'food and drink': u'http://books.toscrape.com/catalogue/category/books/food-and-drink_33/index.html',
    u'horror': u'http://books.toscrape.com/catalogue/category/books/horror_31/index.html',
    u'philosophy': u'http://books.toscrape.com/catalogue/category/books/philosophy_7/index.html',
    u'contemporary': u'http://books.toscrape.com/catalogue/category/books/contemporary_38/index.html',
    u'christian fiction': u'http://books.toscrape.com/catalogue/category/books/christian-fiction_34/index.html',
    u'parenting': u'http://books.toscrape.com/catalogue/category/books/parenting_28/index.html',
    u'cultural': u'http://books.toscrape.com/catalogue/category/books/cultural_49/index.html',
    u'historical fiction': u'http://books.toscrape.com/catalogue/category/books/historical-fiction_4/index.html',
    u'erotica': u'http://books.toscrape.com/catalogue/category/books/erotica_50/index.html',
    u'thriller': u'http://books.toscrape.com/catalogue/category/books/thriller_37/index.html',
    u'mystery': u'http://books.toscrape.com/catalogue/category/books/mystery_3/index.html',
    u'classics': u'http://books.toscrape.com/catalogue/category/books/classics_6/index.html',
    u'sports and games': u'http://books.toscrape.com/catalogue/category/books/sports-and-games_17/index.html',
    u'default': u'http://books.toscrape.com/catalogue/category/books/default_15/index.html',
    u'science': u'http://books.toscrape.com/catalogue/category/books/science_22/index.html',
    u'sequential art': u'http://books.toscrape.com/catalogue/category/books/sequential-art_5/index.html',
    u'science fiction': u'http://books.toscrape.com/catalogue/category/books/science-fiction_16/index.html',
    u'academic': u'http://books.toscrape.com/catalogue/category/books/academic_40/index.html',
    u'adult fiction': u'http://books.toscrape.com/catalogue/category/books/adult-fiction_29/index.html',
    u'historical': u'http://books.toscrape.com/catalogue/category/books/historical_42/index.html',
    u'new adult': u'http://books.toscrape.com/catalogue/category/books/new-adult_20/index.html',
    u'short stories': u'http://books.toscrape.com/catalogue/category/books/short-stories_45/index.html',
    u'history': u'http://books.toscrape.com/catalogue/category/books/history_32/index.html'}


stats = ["A Light in the Attic",
         51.77,
         22,
         3,
         "Poetry",
         """
It's hard to imagine a world without A Light in the Attic. This now-classic collection of poetry and
drawings from Shel Silverstein celebrates its 20th anniversary with this special edition. Silverstein's
 humorous and creative verse can amuse the dowdiest of readers. Lemon-faced adults and fidgety kids sit
  still and read these rhythmic words and laugh and smile and love th It's hard to imagine a world without
   A Light in the Attic. This now-classic collection of poetry and drawings from Shel Silverstein celebrates
    its 20th anniversary with this special edition. Silverstein's humorous and creative verse can amuse the
     dowdiest of readers. Lemon-faced adults and fidgety kids sit still and read these rhythmic words and 
     laugh and smile and love that Silverstein. Need proof of his genius? RockabyeRockabye baby, in the
      treetopDon't you know a treetopIs no safe place to rock?And who put you up there,And your cradle,
       too?Baby, I think someone down here'sGot it in for you. Shel, you never sounded so good. ...more"""
         ]
