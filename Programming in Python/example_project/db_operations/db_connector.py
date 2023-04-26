__all__ = [
    "connect_db",
]

__DB_USER = "test"
__DB_PASSWORD = "dbpassword"


def __connect_db():
    print(f"Connected to DB with creds: {__DB_USER}, {__DB_PASSWORD}")


def connect_db():
    return __connect_db()
