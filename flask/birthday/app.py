import os

import sqlite3 
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST", "DELETE"])
def index():
# DELETE an entry
    if request.method == "POST" and request.form.get("id"):
        id = request.form.get("id")
        try:
            id = int(id)
        except ValueError:
            return redirect("/")
        with sqlite3.connect("birthdays.db") as conn:
            cur = conn.cursor()
            cur.execute("DELETE FROM birthdays WHERE id=?", str(id))
        return redirect("/")

# POST new birthday
    elif request.method == "POST":
        # recuperate datas from form
        name = request.form.get("name")
        if not name:
            return redirect("/")

        month = request.form.get("month")
        try:
            month = int(month)
        except ValueError:
            return redirect("/")
        if not month or month < 1 or month > 12:
            return redirect("/")

        day = request.form.get("day")
        try:
            day = int(day)
        except ValueError:
            return redirect("/")
        if not day or day < 1 or day > 31:
            return redirect("/")

        with sqlite3.connect("birthdays.db") as conn:
            cur = conn.cursor()
            cur.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", (name, month, day))
        return redirect("/")

    else:
        # Display the entries in the database on index.html
        with sqlite3.connect("birthdays.db") as conn:
            cur = conn.cursor()
            cur.execute("SELECT * FROM birthdays")
            birthdays = cur.fetchall()
        return render_template("index.html", birthdays=birthdays)


