#include "CarRentalCompany.h"
#include "Car.h"
#include "Client.h"
#include "Rental.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <regex>

// constructor
CarRentalCompany::CarRentalCompany(string companyName)
{
    name = companyName;
};

//destructor
CarRentalCompany::~CarRentalCompany() {};

//adds new car to the company
void CarRentalCompany::AddCar(int carID, string brand, string model, string licensePlate, bool availability, int size, gearType gear)
{
    Car car(carID, brand, model, licensePlate, availability, size, gear);
    cars.push_back(car);
};

//adds new client to the company
void CarRentalCompany::AddClient(int clientID, string name, int contact, bool driversLicense)
{
    Client client(clientID, name, contact, driversLicense);
    clients.push_back(client);
};

//rent a car
operationStatus CarRentalCompany::Rent(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat)
{
    if (stat == leased || stat == booked)
    {
        //verification if car is available
        for (auto car : cars)
        {
            if (car.getCarID() == carID)
            {
                if (car.getAvailability() == false)
                {
                    return carRented;
                }
            }
        }

        //verification if client isn't renting
        for (auto rental : rentals)
        {
            if (rental.getClientID() == clientID)
            {
                if (rental.getStatus() == leased || rental.getStatus() == booked)
                {
                    return clientRenting;
                }
            }
        }

        //verification if client has a driving licence
        for (auto client : clients)
        {
            if (client.getClientID() == clientID)
            {
                if (!client.getDriversLicense())
                {
                    return noDrivingLicence;
                }
            }
        }
    }
    
    Rental rental(rentalID, clientID, carID, price, mileage, insurance, dateOfRental, dateOfReturn, stat);
    rentals.push_back(rental);

    //set car availability to false
    int index = 0;
    bool availability = !(stat == leased || stat == booked);

    for (auto car : cars)
    {
        if (car.getCarID() == carID)
        {
            car.setAvailability(availability);
            cars.at(index) = car;
            break;
        }
        index++;
    }
    return ok;
};

//set status of rental
operationStatus CarRentalCompany::SetRentStatus(int rentalID, time_t dateOfRental, time_t dateOfReturn, status stat)
{
    int index = 0;
    for (auto rental : rentals)
    {
        if (rental.getRentalID() == rentalID)
        {
            if (rental.getStatus() == stat)
            {
                return sameStatus;
            }

            switch (stat)
            {
            case booked:
                rental.setDateOfRental(dateOfRental);
                rental.setDateOfReturn(dateOfReturn);
                break;
            case canceled:
                break;
            case leased:
                rental.setDateOfRental(dateOfRental);
                rental.setDateOfReturn(dateOfReturn);
                break;
            case returned:
                rental.setDateOfReturn(dateOfReturn);
                break;
            }

            rental.setStatus(stat);
            rentals.at(index) = rental;

            if(stat == returned || stat == canceled || stat == booked)
            { 
                ReturnCar(rental.getCarID());
            }
            break;
        }
        index++;
    }
    return ok;
};

//Load rental to vactor
void CarRentalCompany::RentLoad(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat)
{
    Rental rental(rentalID, clientID, carID, price, mileage, insurance, dateOfRental, dateOfReturn, stat);
    rentals.push_back(rental);
};

//Save all data to files
void CarRentalCompany::Save()
{
    // Save cars
    ofstream fileCars(name + "_" + filenameCars);
    for (auto car : cars)
        car.save(fileCars);
    fileCars.close();

    // Save clients
    ofstream fileClients(name + "_" + filenameClients);
    for (auto client : clients)
        client.save(fileClients);

    fileClients.close();

    // Save Rentals
    ofstream fileRentals(name + "_" + filenameRentals);
    for (auto rental : rentals)
        rental.save(fileRentals);

    fileRentals.close();
};

//Load all data from files to vectors
void CarRentalCompany::Load()
{
    string fileLine;
    vector<string> line;
    regex regexz(";");

    // Load cars
    ifstream fileCars;
    fileCars.open(name + "_" + filenameCars);

    while (getline(fileCars, fileLine))
    {
        
        line = { sregex_token_iterator(fileLine.begin(), fileLine.end(), regexz, -1), sregex_token_iterator() };

        AddCar(atoi(line[0].c_str()), line[1], line[2], line[3], atoi(line[4].c_str()), atoi(line[5].c_str()), static_cast<gearType>(atoi(line[6].c_str())));
    } 

    fileCars.close();

    // Load clients
    ifstream fileClients;
    fileClients.open(name + "_" + filenameClients);
    
    while (getline(fileClients, fileLine))
    {

        line = { sregex_token_iterator(fileLine.begin(), fileLine.end(), regexz, -1), sregex_token_iterator() };

        AddClient(atoi(line[0].c_str()), line[1], atoi(line[2].c_str()), atoi(line[3].c_str()));
    }

    fileClients.close();

    // Load clients
    ifstream fileRentals;
    fileRentals.open(name + "_" + filenameRentals);

    while (getline(fileRentals, fileLine))
    {

        line = { sregex_token_iterator(fileLine.begin(), fileLine.end(), regexz, -1), sregex_token_iterator() };

        RentLoad(atoi(line[0].c_str()), atoi(line[1].c_str()), atoi(line[2].c_str()), atoi(line[3].c_str()),
            atoi(line[4].c_str()), atoi(line[5].c_str()), static_cast<time_t>(atoi(line[6].c_str())), static_cast<time_t>(atoi(line[7].c_str())), static_cast<status>(atoi(line[8].c_str())));
    }

    fileRentals.close();
};

//Return a car
void CarRentalCompany::ReturnCar(int carID)
{
    //return car
    int index = 0;
    for (auto car : cars)
    {
        if (car.getCarID() == carID)
        {
            car.setAvailability(true);
            cars.at(index) = car;
            break;
        }
        index++;
    }
}

//Show current rental
void CarRentalCompany::ShowCurrentRentals()
{
    cout << endl << "CURRENT RENTALS:" << endl;
    for (auto rental : rentals)
    {
        if (rental.getStatus() == leased)
        {
            for (auto car : cars)
            {
                if (car.getCarID() == rental.getCarID())
                {
                    cout << car.getShortInfo();
                    break;
                }
            }

            for (auto client : clients)
            {
                if (client.getClientID() == rental.getClientID())
                {
                    cout << " " << client.getShortInfo();
                    break;
                }
            }
            cout << " " << rental.getShortInfo() << endl;
        }
    }
    cout << "-------------------------" << endl;
}

//Show all cars
void CarRentalCompany::ShowCars()
{
    cout << endl << "CARS:" << endl;
    for (auto car : cars)
    {
        cout << car.getShortInfo() << endl;
    }
    cout << "-------------------------" << endl;
}

//Show all clients
void CarRentalCompany::ShowClients()
{
    cout << endl << "CLIENTS:" << endl;
    for (auto client : clients)
    {
        cout << " " << client.getShortInfo() << endl;
    }
    cout << "-------------------------" << endl;
}

//Show all data
void CarRentalCompany::ShowAllData()
{
    ShowCars();
    ShowClients();
    ShowCurrentRentals();
}

//Remove a car from vectors
void CarRentalCompany::RemoveCar(int carID)
{
    int index = 0;
    for (auto rental : rentals)
    {
        if (rental.getCarID() == carID)
        {
            rentals.erase(rentals.begin() + index++);
        }
    }

    index = 0;
    for (auto car : cars)
    {
        if (car.getCarID() == carID)
        {
            cars.erase(cars.begin()+ index++);
            break;
        }
    }
}

//Remove a client from vectors
void CarRentalCompany::RemoveClient(int clientID)
{
    int index = 0;
    for (auto rental : rentals)
    {
        if (rental.getClientID() == clientID)
        {
            rentals.erase(rentals.begin() + index++);
        }
    }

    index = 0;
    for (auto client : clients)
    {
        if (client.getClientID() == clientID)
        {
            clients.erase(clients.begin() + index++);
            break;
        }
    }
}

//Remove a rental from vectors
void CarRentalCompany::RemoveRental(int rentalID)
{
    int index = 0;
    for (auto rental : rentals)
    {
        if (rental.getRentalID() == rentalID)
        {
            rentals.erase(rentals.begin() + index++);
            break;
        }
    }
}

//Clear all vectors
void CarRentalCompany::Clear()
{
    cars.clear();
    clients.clear();
    rentals.clear();
}

//Get message of status
string CarRentalCompany::GetStatusMessage(operationStatus stat)
{
    switch (stat)
    {
    case ok:
        return "OK!";
    case carRented:
        return "Car already rented!";
    case clientRenting:
        return "Client is renting a car!";
    case sameStatus:
        return "The same status!";
    case noDrivingLicence:
        return "The client doesn't have a driving license!";
    default:
        return "Wrong status!";
    }
}
