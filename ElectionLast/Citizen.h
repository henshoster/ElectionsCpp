#ifndef _CITIZEN_H
#define _CITIZEN_H
#include "PollingStation.h"
#include "Date.h"

class Citizen
{
private:
	int id;
	Date yearOfBirth;
	char* name;
	PollingStation* pollingStation;
public:
	void vote(char* partyName);
	bool setId(int _id);
	bool setYearOfBirth(Date& _yearOfBirth);
	bool setPollingStation(PollingStation* _pollingStation);
	bool setName(char* _name);
	char* getName();
	void show();
	int getId();
	void free();
};

#endif // _CITIZEN_H