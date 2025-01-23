# Flask Finance Application

This is a Flask-based finance application that allows users to virtually manage their stock portfolio, buy and sell stocks, view transaction history, and register or log in to their accounts. The application uses SQLite for data storage and Flask-Session for session management. Yahoo's finance API is requested to fetch the real time stock prices. 

## Features

- **User Authentication**: Users can register, log in, and log out.
- **Portfolio Management**: Users can view their stock portfolio, including the number of shares and total value.
- **Buy and Sell Stocks**: Users can purchase and sell stocks, with real-time price lookups.
- **Transaction History**: Users can view their transaction history.
- **Symbol Lookup**: Users can look up stock symbols and their corresponding prices.
- **Error Handling**: The application provides user-friendly error messages for common issues.

## Technologies Used

- **Flask**: A lightweight WSGI web application framework in Python.
- **SQLite**: A lightweight database for storing user and transaction information.
- **Flask-Session**: An extension that adds server-side session capabilities to Flask applications.
- **Werkzeug**: A comprehensive WSGI web application library for password hashing.
- **Yahoo Finance API**: Used for fetching real-time stock prices.

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>^
   ```
2. Install the packages:
   ```bash
   pip install Flask Flask-Session Werkzeug requests pytz   
   ```
3. Run the application:
   ```bash
   flask run
   ```

## Usage

- **Register**: Create a new account by providing a username and password.
- **Log In**: Access your account using your credentials.
- **View Portfolio**: After logging in, view your current stock holdings and cash balance.
- **Buy Stocks**: Use the buy functionality to purchase stocks by entering the stock symbol and number of shares.
- **Sell Stocks**: Use the sell functionality to sell stocks from your portfolio.
- **View History**: Check your transaction history to see past purchases and sales.
- **Look Up Stock Prices**: Enter a stock symbol to retrieve the current price and historical data.

## Code Overview

### Key Functions

- **apology(message, code)**: Renders an apology message to the user in case of errors.
- **login_required(f)**: Decorator that ensures a user is logged in before accessing certain routes.
- **lookup(symbol)**: Fetches the latest stock price for a given symbol using the Yahoo Finance API.
- **usd(value)**: Formats a numerical value as USD, ensuring proper currency formatting.

### Session Management

The application uses Flask-Session to manage user sessions securely. User sessions are stored on the server side, enhancing security by avoiding the use of signed cookies on the client side.

### Error Handling

The application includes error handling for various scenarios, such as:

- Missing input during buy/sell operations.
- Invalid stock symbols.
- Insufficient funds for transactions.