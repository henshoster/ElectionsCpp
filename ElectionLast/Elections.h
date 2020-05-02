#ifndef _ELECTIONS_H
#define _ELECTIONS_H

#include "Date.h"
#include "Address.h" 
#include "results.h"
#include "PollingStation.h"
#include "Citizen.h"
#include "Party.h"

class Elections
{
private:
	int citizensActualSize = 0;
	int citizenLogicalSize = 1;
	int partysActualSize = 0;
	int partysLogicalSize = 1;
	int pollingStationsActualSize = 0;
	int pollingStationsLogicalSize = 1;
	int isElectionsAppear = 0;
	Date date;
	Citizen** citizens = nullptr;
	Party** parties = nullptr;
	PollingStation** pollingStations = nullptr;
	Results** results = nullptr;
public:
	void initResults();
	void showResults();
	void addCitizenVote(int citizenOrder, char* partyName);
	char* getCitizenNameByOrder(int order);
	int getCitizensActualSize();
	void createNewElections(Date& _date);
	void addParty(Party* party);
	void addCitizen(Citizen* citizen);
	void addPollingStation(PollingStation* pollingStation);
	void addCandidateToParty(Citizen* candidate, Party& party);
	void addCitizenToPollingStation(Citizen* citizen, PollingStation* pollingStation);
	Address createAddress(char* street, int num, char* city);
	PollingStation* createPollingStation(int id, char* street, int num, char* city);
	PollingStation* findPollingStationById(int id);
	Citizen* findCitizenById(int id);
	Party* findPartyByName(char* name);
	Citizen* createCitizen(int id, int yearOfBirth, char* name, int pollingStationId);
	Party* createParty(char* name, eWing wing, int day, int month, int year);
	void showAllPollingStations();
	void showAllCivilians();
	void showAllParties();
	void freeMemory();
};



#endif // _ELECTIONS_H
