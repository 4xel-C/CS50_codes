# Create a login page using flask and cookies configuration

from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# session if an imported variable, which is essentially and empty dictionnary (key / values pair) that is unique for each user visiting the application.

app = Flask(__name__)

# cookies configuration (conventionnal / recommended configuration)
app.config["SESSION_PERMANENT"] = False  # Delete the cookie when leaving the browser
app.config["SESSION_TYPE"] = "filesystem"  # Ensure that  the content of the logins infos are stored in the server file and not in the cookies (for privacy)
Session(app)


@app.route("/")
def index():
    # the index html use the session object to get the name if the user has already logged in and use Jinja placeholder to dynamically update the webpage.
    return render_template("index.html", name=session.get("name"))


@app.route("/loggin", methods=["GET", "POST"])
def loggin():
    if request.method == "POST":
        # remember the name of the user connecting to the app
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("loggin.html")

@app.route("/logout")
def logout():
    # Clear the session and the cookies
    session.clear()
    return redirect("/")
