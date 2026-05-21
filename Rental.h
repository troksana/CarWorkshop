#pragma once
#include <iostream>
#include "Car.h"
#include "Client.h"

using namespace std;

enum status {
	booked,
	canceled,
	leased,
	returned
};

class Rental {

private:
	int rentalID;
	int clientID;
	int carID;
	int price;
	int mileage; //during rental time
	bool insurance;
	time_t dateOfRental;
	time_t dateOfReturn;
	status stat;
public:

	//constructor
	Rental(int rentalID, int clientID, int carID, int price, int mileage, bool insurance, time_t dateOfRental, time_t dateOfReturn, status stat);

	//getters and setters
	void setRentalID(int value);
	int getRentalID();

	void setClientID(int value);
	int getClientID();

	void setCarID(int value);
	int getCarID();

	void setPrice(int value);
	int getPrice();

	void setMileage(int value);
	int getMileage();

	void setInsurance(bool value);
	bool getInsurance();

	void setDateOfRental(time_t value);
	time_t getDateOfRental();

	void setDateOfReturn(time_t value);
	time_t getDateOfReturn();

	void setStatus(status value);
	status getStatus();


	void save(std::ofstream& file);

	string getShortInfo();
};