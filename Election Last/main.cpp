/*Hen Shoster - 203773411
  George Garama - 204616791*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include "Address.h" 
#include "results.h"
#include "PollingStation.h"
#include "Citizen.h"
#include "Party.h"
#include "Elections.h"
#include "main_functions.h"

using namespace std;



int main() {
	Elections admin;
	Date electionsDate;
	electionsDate.setDate(1, 2020);
	admin.createNewElections(electionsDate);

	char cities[4][10] = { "tel aviv","jer","holon","baytam" };
	char streets[4][10] = { "ashdod","petach","haifa","rishon" };
	PollingStation** psArr = new PollingStation * [4];
	for (int i = 0; i < 4; i++)
	{
		PollingStation* ps = new PollingStation;
		Address address;
		char* street = new char[10];
		strcpy(street, streets[i]);
		char* city = new char[10];
		strcpy(city, cities[i]);
		address.setAddress(street, i, city);
		ps->setId(i);
		ps->setAddress(address);
		admin.addPollingStation(ps);
		psArr[i] = ps;
	}

	char names[12][10] = { "beni","georede","camel","dimitri","eli","fuad","gamal","hen","igor","jira","kuki","lola" };
	Citizen** citizensArr = new Citizen * [12];
	for (int i = 0; i < 12; i++)
	{
		Citizen* c1 = new Citizen;
		Date d1;
		d1.setDate(1992 + i);
		char* n1 = new char[10];
		strcpy(n1, names[i]);
		c1->setId(100000000 + i);
		c1->setYearOfBirth(d1);
		c1->setName(n1);
		admin.addCitizenToPollingStation(c1, psArr[i % 4]);
		admin.addCitizen(c1);
		citizensArr[i] = c1;
	}

	char partyNames[3][10] = { "LIKUD","MERETZ","EMET" };
	Party** partyArr = new Party * [3];
	for (int i = 0; i < 3; i++)
	{
		Party* party1 = new Party;
		Date dParty;
		dParty.setDate(1 + i, 2 + i, 2000 + i);
		char* pName = new char[10];
		strcpy(pName, partyNames[i]);
		party1->setName(pName);
		party1->setWing((eWing)i);
		party1->setCreationDate(dParty);
		admin.addParty(party1);
		partyArr[i] = party1;
	}
	

	admin.addCandidateToParty(citizensArr[0], partyArr[0][0]);
	admin.addCandidateToParty(citizensArr[1], partyArr[0][0]);
	admin.addCandidateToParty(citizensArr[2], partyArr[1][0]);
	admin.addCandidateToParty(citizensArr[3], partyArr[1][0]);
	admin.addCandidateToParty(citizensArr[4], partyArr[2][0]);
	admin.addCandidateToParty(citizensArr[5], partyArr[2][0]);
	delete[] partyArr;
	delete[] citizensArr;
	delete[] psArr;
	while (showMenu(admin));



return 1;
};

