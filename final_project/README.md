# Presence Manager
### Video  Demo: https://www.youtube.com/watch?v=AD53mTT1R-4
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

The first time you launch the application, you enter the login page. You can register by entering all the informations requested. Flask application make use of cookie (session).
Once registered you can login and enter the main page: you'll see here the report of the day, who is on site working today, and a table of all the absences you declared.
You have a second tab where you can register an absence, by specifying only one day or a range of day.
And finally an "My account" tab where you can edit all of your information at will.

-** Files and the code:
    -**General design: For this application I've used Flask framework to keep track of cookies, and render the correct web pages as well as managing the form submissions. I've used a sqlite3 database and I communicate with it through an ORM you can find in models.py using SQLAlchemy to make the interaction between the datas and the functionnalities easier. All the logic  for the presence and absences, the detection of isolated employee, are integrated in the app.py for the corresponding routes. For the web pages, I used a lot of bootstrap element to help desinging a responsive application, using breakpoint to implement different table disposition depending of the view screen. 

    -**app.py: Here  you can find all the logic for the code, it includes all the differents routes for the application. Each routes are wrapped with the  @login_required wrapper to make sure the user is authentified to acces the desired route. 
        -The index route display all the informations concerning the employees present on site and display the count on each floor alongside with isolated people and in which laboratory. To keep track of all of these information, I'm using a python dictionnary for the differents count. A second dictionnary is used to keep track of how many people work in which laboratory, in which I can loop to detect if there is 1 person (isolated person) in the corresponding laboratory. I can then extract the name of the isolated person from the data base using the laboratory number, storing the infomartion in another dictionnary in which I have "laboratory: person" as a key value pair I can display on the index page.

        -The login route is a classic login block code in which I mainly handle user input and hash the password.

        -Logout route to clear the session (cookies)

        -A register route: Where I fetch all the data from the user input and made al ot of error handling / input checking. To avoid code repetition, I've created a laboratory_list variable in which I save all the laboratory numbers. I use this variable for the input checkink andd for the Jinja generation of the selection / option form to avoid typing all tags manually. I use SQLAlchemy to update the database and handle integrity error in case a problem happen of if a user try to register a duplicated login.

        -The declare route handle another form to declarre an absence. It works either if the user input 1 date (for on single date) of a range of dates for multiple declaration at a time. I'm using the datetime library to handle the dates. You can find here error handling, avoinding duplicate, and I took into consideration the "today" date to prevent the user registering a past date. After checking the date range is correctly input (startinting date > ending date), I loop through each day incrementing using timedelta(days=1) to register each day of absence in the database. If a date is already registered in the database, the registration is just ignored and the loop continue to the next iteration.

        -The account make use of different form to update certain value in the database. Lot of error handling here too. To make sure the code extract the correct information in the correct code, i've implemented an "hidden" "submit_type" input with a fix value (info, laboratory, password) to allow the code to select which block code to run as the 3 forms use the "POST" method to sent the data to the server.
    
    -**helper.py: Declaration of the "login_required" decorator. We can also find the laboratory_list in this file used in the app.py and for Jinja loop for form generation.

    -**models.py: In this file you will find the object mapping the database containing 2 tables:
        -An "users" table to store the information of all the user registered.

        -An "absences" table: To store all the absences day of each employee. Using user_id as a foreing key ta make a relationnal database with users. I've also implemented a unique constraint to avoid any duplicated line in this table.  It return an Integrity error if we try to save a duplicated line, helping app.py avoinding double registration when user declare an absence.

