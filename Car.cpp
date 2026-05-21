#include "Car.h"
#include "Rental.h"
#include <iostream>
#include <fstream>



	//constructors
	Car::Car(int i, string b, string m, string lp, bool a, int s, gearType g) : carID(i), brand(b), model(m), licensePlate(lp), availability(a), size(s), gear(g) {}

	//getters and setters
	void Car::setCarID(int value) { carID = value; }
	int Car::getCarID() { return carID; }

	void Car::setBrand(string value) { brand = value; }
	string Car::getBrand() { return brand; }

	void Car::setModel(string value) { model = value; }
	string Car::getModel() { return model; }

	void Car::setLicensePlate(string value) { licensePlate = value; }
	string Car::getLicensePlate() { return licensePlate; }

	void Car::setAvailability(bool value) { availability = value; }
	bool Car::getAvailability() { return availability; }

	void Car::setSize(int value) { size = value; }
	int Car::getSize() { return size; }

	void Car::setGear(gearType value) { gear = value; }
	gearType Car::getGear() { return gear; }

	//Save car data to a file
	void Car::save(std::ofstream& file)
	{
		file << carID << ";" << brand << ";" << model << ";" << licensePlate << ";" << availability << ";" << size << ";" << gear << '\n';
	}

	//Retun one line info of the car
	string Car::getShortInfo()
	{
		return "ID: " + to_string(carID) +  ", " + brand + " " + model;
	}