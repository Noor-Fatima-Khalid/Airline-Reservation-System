# Airline Reservation System

## Description
It is a C++ console-based application that allows users to book, cancel, and manage flight reservations. It provides two roles:
- **Passengers** can view flights, book and cancel reservations, and check seat status.
- **Admins** can add flights, view all passengers, and monitor seat status.

## Features

### Passenger Mode:
1. **View Flight Schedule** – Display available flights.
2. **Make a Reservation** – Book a flight.
3. **Cancel Reservation** – Remove an existing reservation.
4. **Search Passenger** – Find details of a booked passenger.
5. **Show Seat Status** – View occupied and available seats.
6. **Exit** – Quit the application.

### Admin Mode:
1. **Add Flights to Schedule** – Extend the flight schedule by adding more flights.
2. **View All Passengers** – Display a list of all passengers and their bookings.
3. **Show Seat Status** – Check available and reserved seats.
4. **Exit** – Quit the application.

## File Structure
- `main.cpp` – Entry point of the application, manages user interactions.
- `Person.cpp` – Defines the `Person` class and derived classes like `Passenger` and `Admin`.
- `Flight.cpp` – Handles flight details such as schedule, pricing, and airline information.
- `Reservation.cpp` – Manages the booking and cancellation of flights.
- `Seat.cpp` – Controls seat allocation and availability.
- `Payment.cpp` – Handles payment status and transactions.
- `menu.cpp` – Displays menus for both Admin and Passenger roles.

## Requirements
C++ compiler (GCC, MinGW, or MSVC)
Windows OS (for conio.h and windows.h usage)
Basic knowledge of command-line execution

