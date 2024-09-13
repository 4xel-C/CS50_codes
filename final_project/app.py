import os
from datetime import datetime, timedelta
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.exc import IntegrityError
from models import Base, User, Absence
from werkzeug.security import check_password_hash, generate_password_hash


from helpers import login_required, laboratory_list

# Configure application
app = Flask(__name__)

# Configure session to use filesystem on server side (instead of signed cookies on client side)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
app.config["DEBUG"] = True

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
    today = datetime.now()
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
        status = request.form.get("manager")
        if not status:
            status = "technician"


        # check problems
        if not login or not last_name or not first_name:
            flash("Username or name missing")
            return redirect("/register")
        elif status != "manager" and status != "technician":
            flash("Invalid datas")
            return redirect("/register")
        elif laboratory not in laboratory_list:
            flash("Invalid laboratory")
            return redirect("/register") 
        elif not password or not request.form.get("confirmation"):
            flash("Missing password or confirmation")
            return redirect("/register")
        elif password != request.form.get("confirmation"):
            flash("Confirmation and password not identical!")
            return redirect("/register")
            
        # update database
        user = User(last_name = last_name, first_name = first_name, laboratory = laboratory, login = login, status = status, password = generate_password_hash(password))
        try:
            db.add(user)
            db.commit()
            flash("Successfully registered")
            return redirect("/")
        except IntegrityError:
            flash("Username already taken!")
            db.rollback()
            return redirect("/register")
        
    return render_template("/register.html", laboratory_list=laboratory_list)

@app.route("/declare", methods=["GET", "POST"])
@login_required
def declare():
    
    if request.method == "POST":
        today = datetime.now().date()
        start = request.form.get("start")
        end = request.form.get("end")
        
        try:
            start = datetime.strptime(start, "%Y-%m-%d").date()
            if end:
                end = datetime.strptime(end, "%Y-%m-%d").date()
        except ValueError:
            flash("Please input a correct date")
            return redirect("/declare")
        
        if not start:
            flash("Please input a correct date")
            return redirect("/declare")
        
        # If only 1 day is declared:
        if not end or end == start:
            # SAVE THE DAY ENTERED IN START
            try:
                db.add(Absence(date=today, user_id=session["user_id"]))
                db.commit()
            except IntegrityError:
                flash(f"{start} is already declared!")
                db.rollback()
                return redirect("/declare")
            flash(f"Absence declared on {start}")
            return redirect("/declare")
        
        elif start < today or end < start:
            flash("Please input a correct date")
            return redirect("/declare")
        
        else:
            # calculate each day of absence and save them into the db absences
            while today <= end:
                try:
                    db.add(Absence(date=today, user_id=session["user_id"]))
                    db.commit()
                except IntegrityError:
                    db.rollback()
                today += timedelta(days=1)
            
            flash(f"Absence declared from {start} to {end}")
            return redirect("/declare")
            
    return render_template("/declare.html")

@app.route("/account",  methods=["GET", "POST"])
@login_required
def account():
    user = db.query(User).filter_by(id=session["user_id"]).first()
    # Change password.
    if request.method == "POST" and request.form.get("submit_type") == "password":
        # manage change password 
        old_password = request.form.get("old_password")
        password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")

        if not old_password or not password or not confirmation:
            flash("Missing inputs")
            return redirect("/account")
        
        if password == old_password:
            flash("Password already in use")
            return redirect("/account")

        if password != confirmation:
            flash("password and confirmation different")
            return redirect("/account")
        
        # update  the password hash in the db
        user.password = generate_password_hash(password)
        db.commit()
        flash("New password  Updated!")
        return redirect("/account")
    
    # Change laboratory
    if request.method == "POST" and request.form.get("submit_type") == "laboratory":
        # manage change laboratory 
        laboratory = request.form.get("laboratory")

        # check user input
        if laboratory not in laboratory_list:
            flash("Incorrect laboratory selected")
            return redirect("/account")
        
        # upddate laboratory
        user.laboratory = laboratory
        db.commit()
        flash("Laboatory successfully updated!")
        return redirect("/account")


    if request.method == "POST" and request.form.get("submit_type") == "info":
        # manage change information 
        last_name = request.form.get("lname")
        first_name = request.form.get("fname")
        status = request.form.get("manager")

        if not last_name or not first_name:
            flash("Name missing")
            return redirect("/account")

        if status != "manager" and status != None:
            flash("Wrong parameter")
            return redirect("/account")
        
        if status == None:
            status = "technician"

        # update database
        user.last_name = last_name
        user.first_name = first_name
        user.status = status
        db.commit()
        flash("Changes successful")
        return redirect("/account")
        
    return render_template("/account.html", user=user, laboratory_list=laboratory_list)

@app.route("/third")
@login_required
def third():
    return render_template("/third.html")

  
@app.route("/fourth")
@login_required
def fourth():
    return render_template("/fourth.html")



if __name__ == "__main__":
    app.run(debug=True)
    
