#include <iostream>
using namespace std;

#include "Elections.h"

void Elections::initResults()
{
	isElectionsAppear = 1;
	char* partyName;
	results = new Results *[partysActualSize];
	for (int j = 0; j < partysActualSize; j++)
	{
		partyName = parties[j]->getName();
		results[j] = new Results;
		results[j]->setName(partyName);
	}
}
void Elections::showResults()
{
	initResults();
	PollingStation* pollingStation = nullptr;
	char* partyName = nullptr;
	Results* res = nullptr;
	int votes;
	cout << "!---Results by Polling Stations---!: " << endl;
	for (int i = 0; i < pollingStationsActualSize; i++)
	{
		pollingStation = pollingStations[i];
		pollingStation->show();
		for (int j = 0; j < partysActualSize; j++)
		{
			res = results[j];
			partyName = parties[j]->getName();
			votes = pollingStation->showResultsByPartyName(partyName);
			res->increaseVoteByNumber(votes);
			cout << "Party Name: " << partyName << " Votes: " << votes << endl;
		}
	}

	cout << endl << "!---TOTAL---! " << endl;
	for (int j = 0; j < partysActualSize; j++)
	{
		partyName = parties[j]->getName();
		cout << "Party Name: " << partyName << " Votes: " << results[j]->getVotes() << endl;
	}
}
void Elections::addCitizenVote(int citizenOrder, char* partyName)
{
	citizens[citizenOrder]->vote(partyName);
}
char* Elections::getCitizenNameByOrder(int order)
{
	return citizens[order]->getName();
}
int Elections::getCitizensActualSize()
{
	return citizensActualSize;
}
void Elections::createNewElections(Date& _date)
{
	date = _date;
}
void Elections::addParty(Party* party)
{
	if (parties == nullptr) {
		parties = new Party *[partysLogicalSize];
	}
	else if (partysActualSize == partysLogicalSize) {
		partysLogicalSize *= 2;
		Party** newParties = new Party *[partysLogicalSize];
		for (int i = 0; i < partysActualSize; i++)
		{
			newParties[i] = parties[i];
		}
		delete[] parties;
		parties = newParties;
	}
	parties[partysActualSize] = party;
	partysActualSize += 1;
}

void Elections::addCitizen(Citizen* citizen)
{
	if (citizens == nullptr) {
		citizens = new Citizen *[citizenLogicalSize];
	}
	else if (citizensActualSize == citizenLogicalSize)
	{
		citizenLogicalSize *= 2;
		Citizen** newCitizens = new Citizen *[citizenLogicalSize];
		for (int i = 0; i < citizensActualSize; i++)
		{
			newCitizens[i] = citizens[i];
		}
		delete[] citizens;
		citizens = newCitizens;
	}
	citizens[citizensActualSize] = citizen;
	citizensActualSize += 1;
}
void Elections::addPollingStation(PollingStation* pollingStation)
{
	if (pollingStations == nullptr) {
		pollingStations = new PollingStation *[pollingStationsLogicalSize];
	}
	else if (pollingStationsActualSize == pollingStationsLogicalSize) {
		pollingStationsLogicalSize *= 2;
		PollingStation** newPollingStations = new PollingStation *[pollingStationsLogicalSize];
		for (int i = 0; i < pollingStationsActualSize; i++)
		{
			newPollingStations[i] = pollingStations[i];
		}
		delete[] pollingStations;
		pollingStations = newPollingStations;
	}
	pollingStations[pollingStationsActualSize] = pollingStation;
	pollingStationsActualSize += 1;
}
void Elections::addCandidateToParty(Citizen* candidate, Party& party)
{
	party.addCandidate(candidate);
}
void Elections::addCitizenToPollingStation(Citizen* citizen, PollingStation* pollingStation)
{
	citizen->setPollingStation(pollingStation);
	pollingStation->addCitizenWhoMayVote(citizen);
}
Address Elections::createAddress(char* street, int num, char* city) {
	Address address;
	address.setAddress(street, num, city);
	return address;
}
PollingStation* Elections::createPollingStation(int id, char* street, int num, char* city)
{
	Address address;
	PollingStation* pollingStation = new PollingStation;
	address.setAddress(street, num, city);
	pollingStation->setId(id);
	pollingStation->setAddress(address);
	return pollingStation;
}
PollingStation* Elections::findPollingStationById(int id)
{
	PollingStation* pollingStation = nullptr;
	for (int i = 0; i < pollingStationsActualSize; i++)
	{
		if (pollingStations[i]->getId() == id)
		{
			pollingStation = pollingStations[i];
			break;
		}
	}
	return pollingStation;
}
Citizen* Elections::findCitizenById(int id)
{
	Citizen* citizen = nullptr;
	for (int i = 0; i < citizensActualSize; i++)
	{
		if (citizens[i]->getId() == id)
		{
			citizen = citizens[i];
			break;
		}
	}
	return citizen;
}
Party* Elections::findPartyByName(char* name)
{
	Party* party = nullptr;
	for (int i = 0; i < partysActualSize; i++)
	{
		if (strcmp(parties[i]->getName(), name) == 0)
		{
			party = parties[i];
			break;
		}
	}
	return party;
}
Citizen* Elections::createCitizen(int id, int yearOfBirth, char* name, int pollingStationId)
{
	Citizen* citizen = new Citizen;
	Date date;
	PollingStation* pollingStation = findPollingStationById(pollingStationId);
	date.setDate(yearOfBirth);
	citizen->setId(id);
	citizen->setYearOfBirth(date);
	citizen->setName(name);
	addCitizenToPollingStation(citizen, pollingStation);
	return citizen;
}

Party* Elections::createParty(char* name, eWing wing, int day, int month, int year)
{
	Party* party = new Party;
	Date date;
	
	while (!(date.setDate(day, month, year)))
	{
		cout << "Please enter day: ";
		cin >> day;
		cout << "Please enter month: ";
		cin >> month;
		cout << "Please enter year: ";
		cin >> year;
		date.setDate(day, month, year);
	}
	party->setCreationDate(date);
	party->setName(name);
	party->setWing(wing);
	return party;
}
void Elections::showAllPollingStations()
{
	for (int i = 0; i < pollingStationsActualSize; i++)
	{
		cout << "#" << (i + 1) << ": ";
		pollingStations[i]->show();
	}
}
void Elections::showAllCivilians()
{
	for (int i = 0; i < citizensActualSize; i++)
	{
		cout << "#" << (i + 1) << ": ";
		citizens[i]->show();
	}
}
void Elections::showAllParties()
{
	for (int i = 0; i < partysActualSize; i++)
	{
		cout << "#" << (i + 1) << ": ";
		parties[i]->show();
	}
}

void Elections::freeMemory()
{
	for (int i = 0; i < partysActualSize; i++)
	{
		parties[i]->free();
		delete[] parties[i];
		if (isElectionsAppear)
		{
			delete[] results[i];
		}
	}
	for (int i = 0; i < citizensActualSize; i++)
	{
		citizens[i]->free();
		delete[] citizens[i];
	}
	for (int i = 0; i < pollingStationsActualSize; i++)
	{
		pollingStations[i]->free();
		delete[] pollingStations[i];
	}
	delete[] pollingStations;
	delete[] citizens;
	delete[] parties;
	delete[] results;
}