#!/usr/bin/python
# from db_operations.db_connector import connect_db
from web.web_url_connector import get_code_academy_index, parse_html_text


if __name__ == "__main__":
    # connect_db()

    code_academy_index = get_code_academy_index()
    # print(type(code_academy_index))
    # print(code_academy_index.status_code)
    parsed_content = parse_html_text(code_academy_index.text)
    print(parsed_content.contents)

    # Please the runnable python file within the Project directory, not within
    # the package it is related to. Package should store all the relevant logic and components,
    # but should not have the runnable scripts within.

    # python3 -m main
    # python3 ./main.py
    # python3 main.py
