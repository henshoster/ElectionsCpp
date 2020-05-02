#include <iostream>
using namespace std;
# include "Citizen.h"
# include "PollingStation.h" 
# include "Date.h"

void Citizen::vote(char* partyName)
{
	pollingStation->vote(partyName);
}
bool  Citizen::setId(int _id)
{
	id = _id;
	return true;
}
bool  Citizen::setYearOfBirth(Date& _yearOfBirth)
{
	yearOfBirth = _yearOfBirth;
	return true;
}
void Citizen::free() {
	delete[] name;
}
bool  Citizen::setPollingStation(PollingStation* _pollingStation)
{
	pollingStation = _pollingStation;
	return true;
}
bool  Citizen::setName(char* _name)
{
	name = _name;
	return true;
}
char*  Citizen::getName()
{
	return name;
}
void  Citizen::show()
{
	cout << " id: " << id << " name: " << name << endl;
}
int  Citizen::getId()
{
	return id;
}