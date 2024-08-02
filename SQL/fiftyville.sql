-- Keep a log of any SQL queries you execute as you solve the mystery.


-- Exerice to practice SQL request on MANY to MANY table relationship.

-- https://cdn.cs50.net/2023/fall/psets/7/fiftyville.zip

-- sqlite> .tables
-- airports              crime_scene_reports   people
-- atm_transactions      flights               phone_calls
-- bakery_security_logs  interviews
-- bank_accounts         passengers

SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 07 AND year = 2023;
-- | 295 | 2023 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- cs50 duck stolen on 2023-07-28 at 10:15am, 3 witness the ame day, mentioned "bakery"

--date selection
WHERE year = 2023 AND month = 7 AND day = 28

-- Get witness transcript
SELECT * FROM interviews WHERE day = 28 AND month = 07 AND year = 2023 AND transcript LIKE "%bakery%" LIMIT 10;
-- => 2023-07-28: thief's car parked in the bakery parking, exit within 10 minutes of the theft (10:15)
-- => morning 2023-07-28: thief withdrawed money at the ATM on Leggett Street earlier than 10:15
-- => Thief call less than 1 minute => accomplice bought the flight ticket, just afer the theft (10:15)
-- => Flight booked on the earliest of 2023-07-29


--Security logs
SELECT * FROM bakery_security_logs WHERE
   ...> year = 2023 AND month = 7 AND day = 28 AND activity = "exit" AND hour = 10;

-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55


SELECT * FROM atm_transactions
   ...> WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |


SELECT * FROM phone_calls
   ...> WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+

-- airport: 8  | CSF          | Fiftyville Regional Airport             | Fiftyville

-- SELECT * FROM flights WHERE
--    ...> origin_airport_id = 8 AND year = 2023 AND day = 29 AND month= 7
--    ...> ORDER BY hour, minute;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
-- | 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
-- | 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
-- | 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+


-- sqlite> SELECT * FROM passengers WHERE
--    ...> flight_id = 36;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+



-- This is the accomplice
SELECT name FROM people WHERE
   ...> phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2023 AND month = 07 AND day = 28 AND duration < 60)
   ...> AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);



-- Find all the suspects

SELECT name FROM people
   ...>  WHERE phone_number IN
   ...>        (SELECT caller FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60)
   ...>    AND passport_number IN
   ...>        (SELECT passport_number FROM passengers WHERE flight_id = 36)
   ...>    AND license_plate IN
   ...>        (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND DAY = 28 AND hour = 10 AND minute > 15 AND minute < 26 AND activity = "exit");


-- Find thief among suspects using account number
sqlite> SELECT name FROM people
   ...>  WHERE id IN
   ...>        (SELECT person_id FROM bank_accounts WHERE account_number IN
   ...>             (SELECT account_number FROM atm_transactions
   ...>              WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = "Leggett Street"))
   ...> AND name IN ("Sofia", "Kelsey", "Bruce");


   --  find complice

SELECT name FROM people
   ...>  WHERE phone_number IN
   ...>        (SELECT receiver FROM phone_calls
   ...>          WHERE caller IN
   ...>                (SELECT phone_number FROM people WHERE name = "Bruce")
   ...>          AND year = 2023 AND month = 7 AND day = 28 AND duration < 60);
