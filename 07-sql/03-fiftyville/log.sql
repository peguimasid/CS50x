-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find info about the crime -> crime_id = 295 - duck was stolen at 10:15 AM
select * from crime_scene_reports
where street = 'Humphrey Street'
and year = 2023 and month = 7 and day = 28;

-- Find interviews that mention the crime - useful = 161 (Ruth), 162 (Eugene), 163 (Raymond)
-- 1. Thief drive away 10 minutes after rob
-- 2. Thief withdraw money at ATM before rob the bakery
-- 3. Thief talk one the phone for less than a minute about take the first flight tomorrow, thief ask the person to buy the ticket
select * from interviews
where year = 2023 and month = 7 and day = 28;

-- get info about withdraws in atm that morning
select * from atm_transactions as t
inner join bank_accounts as ba on ba.account_number = t.account_number
inner join people as p on p.id = ba.person_id
where year = 2023 and month = 7 and day = 28
and atm_location = 'Leggett Street' and transaction_type = 'withdraw';

-- get info about phone phone_calls
select * from phone_calls as pc
inner join people as p on p.phone_number = pc.caller
where year = 2023 and month = 7 and day = 28
and duration < 60;

select 
-- p.id, caller, receiver,
p.name, passport_number, license_plate from phone_calls as pc
inner join people as p on p.phone_number = pc.receiver
where year = 2023 and month = 7 and day = 28
and duration < 60;

-- see flights - in 29/07/2023 the earliest flight is the flight with id = 36
select * from flights
where origin_airport_id = 8
and year = 2023 and month = 7 and day = 29
order by hour, minute asc
limit 1;

select * from bakery_security_logs as bsl
inner join people as p on p.license_plate = bsl.license_plate
where year = 2023 and month = 7 and day = 28
and activity = 'exit' and bsl.license_plate IN ('94KL13X', '1106N58', '30G67EN')

-- Bruce  exit 10:18
-- Taylor exit 10:35



















