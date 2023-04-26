import requests
from bs4 import BeautifulSoup


def get_code_academy_index():
    return requests.get("https://www.codeacademy.bg")


def parse_html_text(text):
    return BeautifulSoup(text, "html.parser")
