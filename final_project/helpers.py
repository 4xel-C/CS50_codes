from flask import redirect, session
from functools import wraps

laboratory_list = ["340", "345", "348", "353", "356", "361", "363", "368", "425", "448", "453", "456", "461"]

def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/latest/patterns/viewdecorators/
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function
