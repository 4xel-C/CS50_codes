# Presence Manager
### Video  Demo: <URL>
#### Description:

Presence manage is a small web aplication intended to bu use in  the scobe of my daily work routine as a Final Project to validate CS50 certification.

-**Context
To give you some context, I'm working as a chemist. As a chemist, our company provided us some strict rules: 
-we cannot work alone in  our laboratory! 
    -As we manipulate dangerous chemicals, we must be at least 2 for safety reasons.
-At least 1 manager must be on site
-Our laboratories are spreaded obver 2 floor in our building:
    -More than 2 person must be on a floor.

-**My application

My aplication is a small web app where you can declare which day you are absent. The main page present a table containing all the colleagues present on site on the current day.
You have also counter and visibility on how many chemists are in the lab, per floor, and how many managers are on site. 
In case chemist are detected "isolated" by the algorithm, their name and their corresponding laboratory are displayer.

This help managing the risk on a daily basis to have a quick glance whether or not there is any presence problems wihtout having to check the presence physically or manually row by row on an excel tab.

-**How does it work? 

The first time you launch the application, you enter the logni page. You can register by entering all the information requested. Flask application make use of cookie (session).
Once registered you can login and enter the main page: you'll see here the report of the day, who is on site working today, and a table of all the absences you declared.
You have a second tab where you can register an absence, by specifying only one day or a range of day.

-** the Code:
The main application can be found in **app.py where all the logic and error / input checking were made.
The **helpers.py give the wrapper function to ensure an user is logged in. The helper function contain a python list of laboratory, used to check the registration of users, and to generate the HTML using Jinja.
In the **model.py you will find the SQLAlchemy models used to create (if needed) and interact with the database

No code was writting by an AI. ChatGPT was only used to help documentation serach and retrieve certain functions I could not remember on the moment.
