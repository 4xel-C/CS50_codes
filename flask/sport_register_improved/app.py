from flask import Flask, redirect, render_template, request

app = Flask(__name__)

# liste de sport qu'il est possible d'utiliser pour générer l'HTML en utilisant Jinja.
# Uppercase utilisé pour signifier une constante
SPORTS = [
    "Basketball", 
    "Soccer", 
    "Ultimate Frisbee"
    ]

# keeping track of registration
REGISTRANTS = {}

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

   
@app.route("/register", methods=["POST"])
def register():

    # validate name
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing Name")  # (messsage correspond to the value in error.html to replace the placehold by "missing name")
    
    # validate sport
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="No sport selected")
    if sport not in SPORTS:
        return render_template("error.html", message="Incorrect sport selected")
    
    # remember registrant
    REGISTRANTS[name] = sport

    # confirm registration and show table
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)  #  Use the place holder in the HTML to use the REGISTRANTS dictionnaries keys values to construct the table.
