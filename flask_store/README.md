# Shopping App

This is a simple shopping application built using Flask that allows users to select books from a database and remember their selections using cookies. Users can also discard items from their cart.

## Features

- View a list of books from a database.
- Add books to a shopping cart.
- Remove books from the shopping cart.
- Session management to remember user selections.

## Technologies Used

- Flask: A lightweight WSGI web application framework in Python.
- SQLite: A lightweight database to store book information.
- Flask-Session: An extension that adds server-side session capabilities to Flask applications.

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Install the required packages
    ```bash
    pip install Flask Flask-Session
    ```
3. Run the application
    ```bash
    flask run
    ```

## Usage

- Navigate to the homepage to view the list of books.
- Click on a book to add it to your cart.
- Go to the cart page to view selected books and remove any if desired.