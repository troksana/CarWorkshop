#pragma once
#include <string>
#include "Rental.h"

using namespace std;

enum gearType {
	manual,
	automatic
};

class Car {
private:

	int carID;
	string brand;
	string model;
	string licensePlate;
	bool availability;
	int size;
	gearType gear; // manual or automatic

public:

	//constructors
	Car(int i, string b, string m, string lp, bool a, int s, gearType g);

	void setCarID(int value);
	int getCarID();

	void setBrand(string value);
	string getBrand();

	void setModel(string value);
	string getModel();

	void setLicensePlate(string value);
	string getLicensePlate();

	void setAvailability(bool value);
	bool getAvailability();

	void setSize(int value);
	int getSize();

	void setGear(gearType value);
	gearType getGear();

	void save(std::ofstream& file);

	string getShortInfo();
};

