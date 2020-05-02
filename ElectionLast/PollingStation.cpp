#include <iostream>
using namespace std;
# include "PollingStation.h"



int PollingStation::showResultsByPartyName(char* partyName)
{
	int isFound = 0;
	Results* res = nullptr;
	for (int i = 0; i < resActualSize; i++)
	{
		if (strcmp(results[i]->getName(), partyName) == 0)
		{
			res = results[i];
			isFound = 1;
			break;
		}
	}
	if (isFound)
	{
		return res->getVotes();
	}
	else
	{
		return 0;
	}
}
void PollingStation::free()
{
	for (int i = 0; i < resActualSize; i++)
	{
		results[i]->free();
		delete[] results[i];
	}
	address.free();
	delete[] results;
	delete[] citizenWhoMayVote;
}
void PollingStation::vote(char* partyName)
{
	int isFound = 0;
	Results* res = nullptr;
	for (int i = 0; i < resActualSize; i++)
	{
		if (strcmp(results[i]->getName(), partyName) == 0)
		{
			res = results[i];
			isFound = 1;
			break;
		}
	}
	if (!isFound)
	{
		res = new Results;
		res->setName(partyName);
		addResult(res);
	}
	res->increaseVote();
	voters += 1;
}

void PollingStation::addResult(Results* result)
{
	if (results == nullptr)
	{
		results = new Results *[resLogicalSize];
	}
	else if (resActualSize == resLogicalSize)
	{
		resLogicalSize *= 2;
		Results** newResults = new Results *[resLogicalSize];
		for (int i = 0; i < resActualSize; i++)
		{
			newResults[i] = results[i];
		}
		delete[] results;
		results = newResults;
	}
	results[resActualSize] = result;
	resActualSize += 1;
}

bool PollingStation::setId(int _id)
{
	id = _id;
	return true;
}

int PollingStation::getId() 
{
	return id;
}

void PollingStation::show()
{
	cout << "Station ID: " << id << " ";
	address.showAddress();
}

bool PollingStation::setAddress(Address& _address)
{
	address = _address;
	return true;
}

void PollingStation::addCitizenWhoMayVote(Citizen* citizen)
{
	if (citizenWhoMayVote == nullptr)
	{
		citizenWhoMayVote = new Citizen *[logicalSize];
	}
	else if (actualSize == logicalSize)
	{
		logicalSize *= 2;
		Citizen** newCitizenWhoMayVote = new Citizen *[logicalSize];
		for (int i = 0; i < actualSize; i++)
		{
			newCitizenWhoMayVote[i] = citizenWhoMayVote[i];
		}
		delete[] citizenWhoMayVote;
		citizenWhoMayVote = newCitizenWhoMayVote;
	}
	citizenWhoMayVote[actualSize] = citizen;
	actualSize += 1;
}