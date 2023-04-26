Project directory
    - module1.py
    - module2.py
    .....


Project directory (Better)
    - module1.py
    package_1 (DB operations)
        tests
            - __init__.py
            - test_db_connector.py
            - test_db_parser.py
        - __init__.py
        - db_connector.py
        - db_reader.py
        - db_parser.py
        - utils.py
    package_2 (heavy computations)
        - __init__.py
        - stocks_computer.py
        - convertors.py
        - currencies_latest_courses.json (filled one time daily with CRON job)
    cron_jobs.py (Any cron jobs used in project)
    package_3 (frontend components)
        - __init__.py
        - gui_setup.py
        - gui_constants.py
    tests
        __init__.py
        package_1
            - __init__.py
            - test_db_connector.py
        package_2
        package_3

Project directory (Worsts)
    - module1.py
    - module2.py
    - module3.py


We use flake8 as linter and black as formatter.
To use them, you must navigate to the Project root directory and from them:
- black ./
- flake8
