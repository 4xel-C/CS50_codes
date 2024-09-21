import csv
import datetime

pka = {
        "triethylamine" : 11,
        "morpholine" : 8,
        "pyridine" : 5,
        "sulfuric acid" : -3,
        "NH4Cl" : 9,
        "OH-" : 14,
        "H3O+" : 0,
        "phosphoric acid" : 2,
        "nitric acid" : -2,
        "acetic acid" : 5,
        "formic acid": 4,
        "ammoniac" : 9,
        "NaNH2" : 38,
        "DBU" : 12,
        "phtalimide" : 8,
        "succinimide" : 9.5,
        "DMAP" : 9,
        "guanidine" : 20,
        "imidazolium" : 7,
        "aniline" : 4,
        "trifluoroacetic acid" : 0,
        "potassium carbonate" : 10,
        "phenol" : 10,
        "LDA" : 35, 
        "ethyl malonate" : 11,
        "ROH" : 15, 
        "sodium tert-butoxide" : 18,
        "nBuLi" : 45,
        "thiophenol" : 6,
        "LiHMDS" : 26,
        "HCl": 0,
       }  


# scoreboard class to update the csv file.
class Scoreboard:
    fieldnames = ["date", "name", "score", "level"]
    today = datetime.datetime.today().date()

    def __init__(self, path='scores.csv'):
        self.path = path

    def get_data(self):
        data = []
        try:
            with open(self.path) as file:
                reader = csv.DictReader(file, fieldnames=self.fieldnames)
                for row  in reader:
                    data.append(row)
                return data
        except FileNotFoundError:
                return data

    def write_score(self, name, score, level):
        """Write score in the csv using the name and the score"""
        with open(self.path, mode='a') as file:
            writer = csv.DictWriter(file, fieldnames=self.fieldnames)
            writer.writerow({"date": self.today, "name": name, "score": score, "level": level})
        print("Score registered!")

    def get_mean_score(self, name, level):
        data = self.get_data()
        scores = []
        for row in data:
            if row["name"] == name and row["level"] == str(level):
                scores.append(int(row["score"]))
        try:
            mean = sum(scores) / len(scores)
        except ZeroDivisionError:
            mean = 0
        return mean

