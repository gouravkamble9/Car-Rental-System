# Car-Rental-System
This C++ code represents a console-based Car Rental System. It provides functionality for both administrators and users to manage car rental operations. It includes features for admin login, user login, user registration, forgot password functionality, adding and deleting cars, viewing car details, and booking cars.

Here's a brief description of the code:
1. The code defines several functions for different operations like login, registration, forgot password, admin login, adding a car, deleting a car, displaying car details, and user login.
2. It also defines a class called `cardetails` that represents the details of a car.
3. The `main` function acts as the entry point of the program and presents a menu for the user to choose from various options.
4. Based on the user's choice, the program calls corresponding functions to perform the desired operations.
5. The program reads and writes data to text files (‘database.txt’, ‘car_details.txt’, and ‘book_details.txt’) to store user information, car details, and booking history.
6. The `admin` and 'user_login' functions provide separate menus for administrators and users, respectively, allowing them to perform specific tasks related to car management.
7. The `cars` function displays the available cars and their details.
8. The `book_car` function allows users to select and book a car by entering the car code.
9. The `invoice` function generates an invoice for the booked car, including customer details, car details, rental amount, etc.
10. The code handles input validation and includes error messages in case of invalid inputs or login failures.



