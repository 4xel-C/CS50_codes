import os
import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.exc import IntegrityError
from models import Base, User, Absence
from werkzeug.security import check_password_hash, generate_password_hash


from helpers import login_required

# Configure application
app = Flask(__name__)

# Configure session to use filesystem on server side (instead of signed cookies on client side)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"

Session(app)

# Configure data bases
engine = create_engine('sqlite:///absences.db')

try:    
    Base.metadata.create_all(engine)
except Exception as e:
    print(e)

Session = sessionmaker(engine)
db = Session()


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



# Login_required decorator redirect to "/login" if the user is not logged on.
@app.route("/")
@login_required
def index():
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # # Forget any user_id optional?? conflict with flash message when registering
    # session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            flash("Must provide username")
            return redirect("/")

        # Ensure password was submitted
        elif not request.form.get("password"):
            flash("Must provide a password")
            return redirect("/")

        # Query database for username
        username = request.form.get('username')
        password = request.form.get('password')
        user = db.query(User).filter_by(login=username).first()

        # Ensure username exists and password is correct
        if not user or not check_password_hash(user.password, password):
            flash("Invalid username or password")
            return redirect('/')
        else:
            session["user_id"] = user.id
            return redirect('/')

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        login = request.form.get("login")
        first_name = request.form.get("first_name")
        last_name =  request.form.get("last_name")
        laboratory = request.form.get("laboratory")
        password = request.form.get("password")


        # check problems
        if not login or not last_name or not first_name:
            flash("Username or name missing")
            return redirect("/register")
        elif not password or not request.form.get("confirmation"):
            flash("Missing password or confirmation")
            return redirect("/register")
        elif password != request.form.get("confirmation"):
            flash("Confirmation and password not identical!")
            return redirect("/register")
            
        # update database
        user = User(last_name = last_name, first_name = first_name, laboratory = laboratory, login = login, password = generate_password_hash(password))
        try:
            db.add(user)
            db.commit()
            flash("Successfully registered")
            return redirect("/")
        except IntegrityError:
            flash("Username already taken!")
            return redirect("/register")
        
    return render_template("/register.html")

