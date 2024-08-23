from flask import Flask, render_template, request

app = Flask(__name__)

# liste de sport qu'il est possible d'utiliser pour générer l'HTML en utilisant Jinja.
# Uppercase utilisé pour signifier une constante
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

   
@app.route("/register", methods=["POST"])
def register():
    # check is there is indeed something in the form in case the "required" attribute is deleted by the user in the html dev tools.
    if not request.form.get("name"):
        return render_template("failure.html")
    
    # Check if the form is filled with the correct values in case the user input inject something else via HTML edition in dev tools.
    for sport in request.form.getlist("sport"):
        if sport not in SPORTS:
            return render_template("failure.html")
    return render_template("success.html")