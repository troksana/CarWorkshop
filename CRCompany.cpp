#include <iostream>
#include <conio.h>
#include "Car.h"
#include "CarRentalCompany.h"
#include "Client.h"

void InsertTestData(CarRentalCompany* company);
time_t getDate(int year, int month, int day, int hour, int minute);

int main()
{
    // Object of Car rental Company
    // We can mannage many companies by creating many objects of CarRentalCompany class
    // for eg. we can use vactor of CarRentalCompany class objects
    CarRentalCompany company("CR1");
    operationStatus stat;

    cout << "Inserting test data..." << endl;
    InsertTestData(&company);
    cout << "Test data inserted." << endl << endl;

    cout << "Show all data..." << endl;
    company.ShowAllData();

    cout << "Save data to files..." << endl;
    company.Save();
    cout << "Data saved." << endl << endl;

    cout << "Clearing data..." << endl;
    company.Clear();
    cout << "Data cleared." << endl << endl;

    cout << "Show all data..." << endl;
    company.ShowAllData();

    cout << "Loadign data from files..." << endl;
    company.Load();
    cout << "Data loaded." << endl << endl;

    cout << "Show all data..." << endl;
    company.ShowAllData();

    cout << "Returning first car..." << endl;
    stat = company.SetRentStatus(0, getDate(2025, 5, 6, 9, 12), getDate(2025, 5, 8, 19, 40), returned);
    if(stat == ok)
        cout << "Car returned" << endl << endl;
    else
        cout << company.GetStatusMessage(stat) << endl << endl;

    cout << "Returning first car again..." << endl;
    stat = company.SetRentStatus(0, getDate(2025, 5, 6, 9, 12), getDate(2025, 5, 8, 19, 40), returned);
    if (stat == ok)
        cout << "Car returned" << endl << endl;
    else
        cout << company.GetStatusMessage(stat) << endl << endl;

    cout << "Show all data..." << endl;
    company.ShowAllData();

    cout << "Renting second car..." << endl;
    stat = company.Rent(3, 0, 1, 200, 80000, true, getDate(2025, 2, 10, 2, 34), getDate(2025, 2, 20, 16, 12), leased);
    if (stat == ok)
        cout << "Car rented." << endl << endl;
    else
        cout << company.GetStatusMessage(stat) << endl << endl;

    cout << "Renting fourth car for client with no driving licence..." << endl;
    stat = company.Rent(4, 2, 3, 200, 80000, true, getDate(2025, 2, 10, 2, 34), getDate(2025, 2, 20, 16, 12), leased);
    if (stat == ok)
        cout << "Car rented." << endl << endl;
    else
        cout << company.GetStatusMessage(stat) << endl << endl;

    cout << "Removing first car from vectors..." << endl;
    company.RemoveCar(0);
    cout << "First car removed." << endl << endl;

    cout << "Removing fourth car from vectors..." << endl;
    company.RemoveCar(3);
    cout << "Fourth car removed." << endl << endl;

    cout << "Removing first client from vectors..." << endl;
    company.RemoveClient(0);
    cout << "First client removed." << endl << endl;

    cout << "Show all data..." << endl;
    company.ShowAllData();

    //Example of using many companies
    cout << endl << "Example of using many companies..." << endl;
    CarRentalCompany company2("CR2");
    InsertTestData(&company2);
    company2.ShowAllData();
    company2.Save();

    return 0;
}

// Insert test data to vectors
void InsertTestData(CarRentalCompany* company)
{
    //Cars
    company->AddCar(0, "Toyota", "Camry", "KK76234", true, 5, automatic);
    company->AddCar(1, "Ford", "Focus", "WW02534", true, 4, manual);
    company->AddCar(2, "Mazda", "6", "WL02345", true, 5, automatic);
    company->AddCar(3, "Renault", "Megane", "NO82352", true, 4, manual);

    //Clients
    company->AddClient(0, "Mary Bob", 123456789, true);
    company->AddClient(1, "Patrcik Bateman", 987654321, true);
    company->AddClient(2, "Mad Man", 231444122, false);

    //Rentals
    company->Rent(0, 0, 0, 320, 120000, true, getDate(2025, 5, 6, 9, 12), getDate(2025, 5, 8, 19, 40), leased);
    company->Rent(1, 1, 1, 200, 80000, true, getDate(2025, 2, 10, 2, 34), getDate(2025, 2, 20, 16, 12), leased);
}

// Create time_t variable
time_t getDate(int year, int month, int day, int hour, int minute)
{
    struct tm date;

    date.tm_year = year - 1900;
    date.tm_mon = month-1;
    date.tm_mday = day;
    date.tm_hour = hour;
    date.tm_min = minute;
    date.tm_sec = 0;
    date.tm_isdst = -1;
    return mktime(&date);
}