class Book:
    """
   A class to represent a book.
   Attributes
   ----------
   tittle : str
       tittle of book
   price : float
       price of book
   availability : int
       how many books is in store
   rating : int
       rating of book
   description : str
       description of book
   genre : str
       genre of book
   Methods
   -------
   print_book_info():
       Prints book tittle.
   """

    def __init__(self, stats):
        tittle, price, genre, availability, rating, description,  = stats
        self.__tittle = tittle
        self.__price = price
        self.__availability = availability
        self.__rating = rating
        self.__description = description
        self.__genre = genre

    def print_book_info(self):
        tmp_str = "Book: "
        tmp_str += self.tittle + " with " + self.price + " price - " + self.availability + " books in store"
        return tmp_str

    @property
    def tittle(self):
        return self.__tittle

    @property
    def price(self):
        return self.__price

    @property
    def availability(self):
        return self.__availability

    @property
    def rating(self):
        return self.__rating

    @property
    def description(self):
        return self.__description

    @tittle.setter
    def tittle(self, new_tittle):
        self.__tittle = new_tittle

    @price.setter
    def price(self, new_price):
        self.__price = new_price

    @availability.setter
    def availability(self, new_availability):
        self.__availability = new_availability

    @rating.setter
    def rating(self, new_rating):
        self.__rating = new_rating

    @description.setter
    def description(self, new_description):
        self.__description = new_description

    @property
    def genre(self):
        return self.__genre

    @genre.setter
    def genre(self, value):
        self.__genre = value
