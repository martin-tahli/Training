# Искам да намерите начин да си съберете заглавията от този сайт:
# http://books.toscrape.com/catalogue/category/books_1/index.html. И като използвате регекс да изкарате
# само заглавията, които започват със S или M и са между 10 и 20 символа.

import requests
from bs4 import BeautifulSoup
import re

url = "http://books.toscrape.com/catalogue/category/books_1/index.html"
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')

while True:
    titles = soup.find_all('h3')
    for title in titles:
        match = re.search(r'^[SM][a-zA-Z\s]{9,19}$', title.text)
        if match:
            print(title.text)
    next_page = soup.find("li", class_="next")
    if next_page is None:
        break
    next_link = next_page.a["href"]
    url = "http://books.toscrape.com/catalogue/" + next_link
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
