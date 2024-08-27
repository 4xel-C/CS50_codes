# Create shopping app using cookies to remember selection from databases, with discard option.


# Improvement axes: -put the cursor into a context manager (with)
#  -Use Object relationnal Mapping (SQLAlchemy or Django ORM) to manage data bases connection and extraction, more secure.

from flask import Flask, redirect, render_template, request, session
from flask_session import Session
import sqlite3

# session if an imported variable, which is essentially and empty dictionnary (key / values pair) that is unique for each user visiting the application.

app = Flask(__name__)

# cookies configuration (conventionnal / recommended configuration)
app.config["SESSION_PERMANENT"] = False  # Delete the cookie when leaving the browser
app.config["SESSION_TYPE"] = "filesystem"  # Ensure that  the content of the logins infos are stored in the server file and not in the cookies (for privacy)
Session(app)


@app.route("/")
def index():
    with sqlite3.connect("books.db") as conn:
        cur = conn.cursor()
        cur.execute("SELECT * FROM books")
        books = cur.fetchall()
        # books will return all line in the table BOOKS as list of tuple (id, title)
    return render_template("books.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():

    # ensure cart exist
    if "cart" not in session:
        session["cart"] = []
    
    # POST
    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id and book_id not in session["cart"]:
            session["cart"].append(book_id)
        return redirect("/cart")

        
    # GET
    with sqlite3.connect("books.db") as conn:
        cur = conn.cursor()
        placeholders = ",".join("?" for _ in session["cart"])
        cur.execute(f"SELECT * FROM books WHERE id IN ({placeholders})", session["cart"])
        books = cur.fetchall()
    return render_template("cart.html", books=books)


@app.route("/discard", methods=["GET", "POST"])
def discard():

    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id:
            session["cart"].remove(book_id)
        return redirect("/cart")