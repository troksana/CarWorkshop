---------------------------------------------------------------------------------------------------------------------------------
# Car Rental & Fleet Management System (C++)
-------------------------------------------
A lightweight, object-oriented console application written in native C++ designed to simulate a car rental company management system. The project focuses on clean architecture, dynamic data management using the Standard Template Library (STL), and serialization/deserialization for persistent storage.

## Key Features
-------------------------------------------
* **Fleet & Client Management:** Complete CRUD-like operations for handling vehicle fleets (`Car`), customer databases (`Client`), and live transactions (`Rental`).
* **Business Logic Verification:** Built-in safeguards preventing illegal operations (e.g., renting an already leased vehicle, verifying driver's license status, and preventing overlapping rentals for a single client).
* **Multi-Company Support:** Scalable system architecture allowing instantiation of multiple independent rental company objects (`CarRentalCompany`) concurrently.

##  Architecture & Tech Stack
-------------------------------------------
* **Language:** C++11 / C++14 (Native)
* **Paradigm:** Object-Oriented Programming (OOP) with strict encapsulation, modular class design, and custom constructors/destructors.
* **Data Structures:** Heavy reliance on STL containers (`std::vector`) and data casting methodologies (`static_cast`).
* **Time & Date Tracking:** Leveraging standard `time_t` and `tm` structures for precise timestamp management for leasing and returns.

## Project Structure
-------------------------------------------
* `CarRentalCompany` - Core manager handling backend operations, data vectors, and business logic routing.
* `Car` - Represents vehicle entities, technical specifications, and availability states.
* `Client` - Stores customer credentials, contact info, and legal driving status.
* `Rental` - Manages transactional states (`booked`, `canceled`, `leased`, `returned`) and time windows.
---------------------------------------------------------------------------------------------------------------------------------
