from flask import Flask, render_template, request

#  permet de creer une page web dynamique

# spécification du nom du fichier applicatif
app = Flask(__name__)

# decorator permettant d'exécuter la fonction si le path est à la racine (page index)
# @app.route("/")
# def index():
#     # next line generate a dictionnary when a request is made by the user under the format URL/?name="name" (request), if no request, default value "world" will be used.
#     # accessing URL/?name=Axel will edit the index.html file to insert "Axel" in the placeholder name.
#     name = request.args.get("name", "world")  
#     return render_template("index.html", name=name)

@app.route("/")
def index():
    return render_template("index.html")

# permet d'appliquer la fonction quand l'URI s'update sur /greet via le formulaire html et l'attribut action "Greet"
@app.route("/greet")
def greet():
    # récupère et parse les informations de requête de l'URI (?name=exemple) sous forme de dictionnaire
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)
