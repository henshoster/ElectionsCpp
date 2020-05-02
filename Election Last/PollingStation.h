#ifndef _POLLINGSTATION_H
#define _POLLINGSTATION_H

#include "Address.h"
#include "results.h"
class Citizen;

class PollingStation
{
private:
	int actualSize = 0;
	int logicalSize = 1;
	int id;
	Address address;
	Citizen** citizenWhoMayVote = nullptr;
	int resActualSize = 0;
	int resLogicalSize = 1;
	int voters = 0;
	double percentageOfVoters;
	Results** results = nullptr;
public:
	int showResultsByPartyName(char* partyName);
	void vote(char* partyName);
	void addResult(Results* result);
	bool setId(int _id);
	int getId();
	void free();
	void show();
	bool setAddress(Address& _address);
	void addCitizenWhoMayVote(Citizen* citizen);
};

#endif // _POLLINGSTATION_H