#pragma once
#include <string>
#include "Rental.h"

using namespace std;

class Client {
private:

	int clientID;
	string name;
	int contact;
	bool driversLicense;
	
public:
	//constructors
	Client(int id, string n, int c, bool dl);

	//getters and setters
	void setClientID(int value);
	int getClientID();

	void setName(string value);
	string getName();

	void setContact(int value);
	int getContact();

	void setDriversLicense(bool value);
	bool getDriversLicense();

	void save(std::ofstream& file) const;

	string getShortInfo();
};