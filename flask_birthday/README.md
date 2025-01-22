# Flask Birthday Tracker

This is a Flask-based web application to manage a list of birthdays. Users can add, view, and delete birthday entries stored in a SQLite database.

## Features
- **Add a Birthday**: Submit a name, month, and day to add a birthday.
- **View Birthdays**: Display all stored birthdays on the main page.
- **Delete a Birthday**: Remove a specific birthday by its ID.

## Requirements
To run this application, you'll need the following:

- Python 3.6 or higher
- Flask
- SQLite3

## Installation
1. Clone the repository or copy the code into a directory on your machine.
2. Create a virtual environment (optional but recommended):
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
3. Install Flask:
    ```
    pip install flask
    ```

## Usage

1. Run the Flask application
    ```
    flask run
    ```

2. Access the local web server to `http://127.0.0.1:5000/`