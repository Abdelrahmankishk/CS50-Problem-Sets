-- Keep a log of any SQL queries you execute as you solve the mystery.

-- the description of the crime happened at the given location and time
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

SELECT name, transcript
 FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;
-- found 2 , one is related to the crime and the other does not

SELECT name , transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%'
ORDER BY name;
-- Witnesses are Eugene, Raymond, and Ruth

-- Eugene said :  Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money
SELECT name, atm_transactions.amount FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';

-- Raymond said : In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--finding the information about the aiport in Fiftyville which would be the origin of the flight of the thief.
SELECT abbreviation, full_name, city FROM airports WHERE city = 'Fiftyville';

--Finding the flights on July 29 from Fiftyville airport
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29
ORDER BY flights.hour, flights.minute;

-- First flight comes out to be at 8:20 to LaGuardia Airport in New York City (id = 36); this may be the first place the thief went to
-- Checking the list of passengers in that flight.
SELECT passengers.flight_id, name, passengers.passport_number FROM people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
 WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20
 ORDER BY passengers.passport_number;
 -- Names found: Edward , Sofia ,Taylor , Bruce , Doris , Kelsey, Luca ,and Kenny


 -- Checking the phone call records to find the person who bought the tickets.
SELECT name, phone_calls.duration FROM people
  JOIN phone_calls ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- checking the possible names of the call-receiver
SELECT name, phone_calls.duration FROM people
  JOIN phone_calls ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;


-- Ruth said : The thief drove away in a car from the bakery, within 10 minutes from the theft
-- checking the license plates of cars within that time frame
-- checking out the names of those cars' owners
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28  AND bakery_security_logs.activity = 'exit'  AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;



-- Bruce must the thief as he is THE ONLY ONE present in all the 4 lists
-- List of passengers, list of people who did the specific atm transactions, list of people who called, and list of people who drove away in cars from the bakery.

-- He must have escaped to the New York City, as he took the New York City flight.

-- Robin must be the accomplice who purchased the flight ticket, and helped Bruce escape to the New York City.
-- AS Bruce talked only to Robin all the time affter his stealing