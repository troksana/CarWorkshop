#pragma once
#include <string>
#include <vector>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

//File names of company data storage
//Files are created with company name as prefix for eg. company1_cars.txt
const string filenameCars = "cars.txt";
const string filenameClients = "clients.txt";
const string filenameRentals = "rentals.txt";

//Operation status
enum operationStatus {
    ok,
    carRented,
    clientRenting,
    sameStatus,
    noDrivingLicence
};

class CarRentalCompany {

private:
    vector<Car> cars; // all cars of the company
    vector<Client> clients; // all clients of the company
    vector<Rental> rentals; // all clients of the company
    string name; //company name
public:
    // constructor
    CarRentalCompany(string companyName);

    //destructor
    ~CarRentalCompany();

    //adds new car to the company
    void AddCar(int carID, string brand, string model, string licensePlate, bool availability, int size, gearType gear);
    void AddClient(int clientID, string name, int contact, bool driversLicense);

    operationStatus Rent(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat);
    operationStatus SetRentStatus(int rentalID, time_t dateOfRental, time_t dateOfReturn, status stat);
    void RentLoad(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat);

    void Save();

    void Load();

    void ReturnCar(int carID);

    void ShowCurrentRentals();
    void ShowCars();
    void ShowClients();

    void ShowAllData();

    void RemoveCar(int carID);
    void RemoveClient(int clientID);
    void RemoveRental(int rentalID);

    void Clear();

    string GetStatusMessage(operationStatus stat);
};
