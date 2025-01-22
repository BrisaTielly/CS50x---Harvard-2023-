SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
SELECT name, day, month, year, transcript FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE "%bakery%";
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10;
SELECT bakery_security_logs.minute, bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM bakery_security_logs
    JOIN people ON people.license_plate = bakery_security_logs.license_plate
    WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND bakery_security_logs.activity = "exit";
SELECT * FROM atm_transactions
    WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
SELECT people.name FROM people
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;
SELECT people.name FROM people
    JOIN phone_calls ON phone_calls.caller = people.phone_number
    WHERE month = 7 AND day = 28 AND duration < 60;
SELECT people.name FROM people
    JOIN phone_calls ON phone_calls.receiver = people.phone_number
    WHERE month = 7 AND day = 28 AND duration < 60;
SELECT * FROM airports WHERE city = "Fiftyville"; 
SELECT * FROM flights 
SELECT flights.id, flights.origin_airport_id, flights.destination_airport_id, airports.full_name FROM flights
    JOIN airports ON airports.id = flights.origin_airport_id
    WHERE month = 7 AND day = 29 ORDER BY flights.hour ASC LIMIT 1;
SELECT flights.id, airports.full_name, airports.city FROM flights
    JOIN airports ON airports.id = flights.destination_airport_id
    WHERE month = 7 AND day = 29 ORDER BY flights.hour ASC LIMIT 1;
SELECT people.name FROM people
    JOIN passengers ON passengers.passport_number = people.passport_number
    JOIN flights ON flights.id = passengers.flight_id
    JOIN airports ON airports.id = flights.destination_airport_id
    WHERE flights.id = 36;
SELECT name from people
    JOIN passengers ON passengers.passport_number = people.passport_number
    JOIN flights ON flights.id = passengers.flight_id
    JOIN airports ON airports.id = flights.destination_airport_id
    WHERE flights.id = 36 AND name IN (
        SELECT people.name FROM people
            JOIN phone_calls ON phone_calls.caller = people.phone_number
            WHERE month = 7 AND day = 28 AND duration < 60
            AND name IN (
                SELECT people.name FROM people
                    JOIN bank_accounts ON bank_accounts.person_id = people.id
                    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
                    WHERE atm_transactions.month = 7 AND atm_transactions.day = 28
                    AND atm_transactions.atm_location = "Leggett Street"
                    AND atm_transactions.transaction_type = "withdraw"
                    AND people.name IN (
                        SELECT people.name FROM bakery_security_logs
                            JOIN people ON people.license_plate = bakery_security_logs.license_plate
                            WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND bakery_security_logs.activity = "exit"
                    )
            )
    ); 
SELECT name FROM people
    JOIN phone_calls ON phone_calls.receiver = people.phone_number
    WHERE  month = 7 AND day = 28 AND duration < 60 AND caller = (
    SELECT phone_number FROM people WHERE name = 'Bruce'
); 