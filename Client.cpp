#include "Client.h"
#include <string>
#include "Rental.h"
#include <fstream>

//constructors
Client::Client(int id, string n, int c, bool dl) : clientID(id), name(n), contact(c), driversLicense(dl) {}

//getters and setters
void Client::setClientID(int value) { clientID = value; }
int Client::getClientID() { return clientID; }

void Client::setName(string value) { name = value; }
string Client::getName() { return name; }

void Client::setContact(int value) { contact = value; }
int Client::getContact() { return contact; }

void Client::setDriversLicense(bool value) { driversLicense = value; }
bool Client::getDriversLicense() { return driversLicense; }

//Save client data to a file
void Client::save(std::ofstream& file) const
{
	file << clientID << ";" << name << ";" << contact << ";" << driversLicense << '\n';
}

//Retun one line info of the client
string Client::getShortInfo()
{
	return "ID: " + to_string(clientID) + ", " + name;
}