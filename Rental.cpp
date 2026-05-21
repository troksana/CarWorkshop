#include "Rental.h"
#include "Client.h"
#include <iostream>
#include <fstream>

using namespace std;

//constructor
Rental::Rental(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat)
	: rentalID(rentalID), clientID(clientID), carID(carID), price(price), mileage(mileage), insurance(insurance), dateOfRental(dateOfRental), dateOfReturn(dateOfReturn), stat(stat){}

//getters and setters
void Rental::setRentalID(int value) { rentalID = value; }
int Rental::getRentalID() { return rentalID; }

void Rental::setClientID(int value) { clientID = value; }
int Rental::getClientID() { return clientID; }

void Rental::setCarID(int value) { carID = value; }
int Rental::getCarID() { return carID; }

void Rental::setPrice(int value) { price = value; }
int Rental::getPrice() { return price; }

void Rental::setMileage(int value) { mileage = value; }
int Rental::getMileage() { return mileage; }

void Rental::setInsurance(bool value) { insurance = value; }
bool Rental::getInsurance() { return insurance; }

void Rental::setDateOfRental(time_t value) { dateOfRental = value; }
time_t Rental::getDateOfRental() { return dateOfRental; }

void Rental::setDateOfReturn(time_t value) { dateOfReturn = value; }
time_t Rental::getDateOfReturn() { return dateOfReturn; }

void Rental::setStatus(status value) { stat = value; }
status Rental::getStatus() { return stat; }

//Save rental data to a file
void Rental::save(std::ofstream& file)
{
	file << rentalID << ";" << clientID << ";" << carID << ";" << price << ";" << mileage << ";" << insurance << ";" << dateOfRental << ";" << dateOfReturn << ";" << stat << '\n';
}

//Retun one line info of the rental
string Rental::getShortInfo()
{
	char strDateOfRental[40];
	char strDateOfReturn[40];
	struct tm tmDateOfRental;
	struct tm tmDateOfReturn;
	localtime_s(&tmDateOfRental, &dateOfRental);
	localtime_s(&tmDateOfReturn, &dateOfReturn);
	
	strftime(strDateOfRental, sizeof strDateOfRental, "%Y-%m-%d %H:%M", &tmDateOfRental);
	strftime(strDateOfReturn, sizeof strDateOfReturn, "%Y-%m-%d %H:%M", &tmDateOfReturn);

	return "ID: " + to_string(rentalID) + ", Start: " + strDateOfRental + ", End: " + strDateOfReturn;
}