#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "main_functions.h"


void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

// function to get unknown length user input
char* readline() {
	char str[100];
	char* returnStr;
	int length;
	cleanBuffer();
	cin.getline (str,100);
	length = strlen(str);
	returnStr = new char[length + 1];
	strcpy(returnStr, str);
	return returnStr;
};

// menue function get Elections class reference
int showMenu(Elections& admin)
{
	int showAgain = 1;
	int userInput;
	cout << "------------------------------------------------------" << endl;
	cout << "Hello user, what whould you like to do? \n"
		<< "1 - add polling station\n"
		<< "2 - add citizen\n"
		<< "3 - add party\n"
		<< "4 - add candidates to party\n"
		<< "5 - show all polling stations\n"
		<< "6 - show all citizens\n"
		<< "7 - show all partys\n"
		<< "8 - new elections\n"
		<< "9 - show results\n"
		<< "10 - end\n";
	cout << "------------------------------------------------------" << endl;

	cin >> userInput;
	switch (userInput)
	{
		int id;
		char* name;
	case 1:
		// add polling station
		char* street;
		int number;
		char* city;
		cout << "Please enter serial number: ";
		cin >> id;
		// check if serial number of pollingstation valid
		while (admin.findPollingStationById(id))
		{
			cout << "ID alrady exist, please enter correct serial number : \n";
			admin.showAllPollingStations();
			cin >> id;
		}
		cout << "please enter street: ";
		street = readline();
		cout << "Please enter street Number: ";
		cin >> number;
		cout << "Please enter city name: ";
		city = readline();
		admin.addPollingStation(admin.createPollingStation(id, street, number, city));
		break;
	case 2:
		// add citizen
		int yearOfBirth;
		int pollingStationId;
		cout << "Please enter id number: ";
		cin >> id;
		while (admin.findCitizenById(id))
		{
			cout << "invalid ID, Citizen with same ID already exist, enter valid ID number : \n";
			admin.showAllCivilians();
			cin >> id;
		}
		cout << "Please enter year of birth: ";
		cin >> yearOfBirth;
		cout << "please enter your name: ";
		name = readline();
		cout << "here is a list of polling stations, please enter the serial number in the polling station which you prefer to vote: " << endl;
		admin.showAllPollingStations();
		cin >> pollingStationId;
		// input validation
		while (!(admin.findPollingStationById(pollingStationId)))
		{
			cout << "invalid ID, please enter correct serial number : \n";
			admin.showAllPollingStations();
			cin >> pollingStationId;
		}
		admin.addCitizen(admin.createCitizen(id, yearOfBirth, name, pollingStationId));
		break;
	case 3:
		// add party
		int wing;
		int day, month, year;
		cout << "Please Party name: ";
		name = readline();
		cout << "Please enter Party Wing: 0 - Left , 1-Center, 2 - Right";
		cin >> wing;

		//input validation
		while (wing < 0 || wing > 2)
		{
			cout << "invalid input, please enter again Party wing: 0 - Left , 1-Center, 2 - Right: \n";
			cin >> wing;
		}

		cout << "Please enter day of creation: ";
		cin >> day;
		cout << "Please enter month of creation: ";
		cin >> month;
		cout << "Please enter year of creation: ";
		cin >> year;
		admin.addParty(admin.createParty(name, eWing(wing), day, month, year));
		break;
	case 4:
		// add candidates to party
		cout << "here is a list of all civilians, please enter the id of the civilian you want to chose : " << endl;
		admin.showAllCivilians();
		cin >> id;

		// input validation
		while (!(admin.findCitizenById(id)))
		{
			cout << "invalid ID, please enter correct candidate ID : \n";
			admin.showAllCivilians();
			cin >> id;
		}
		cout << "here is a list of all parties, please enter the name of the party you want to chose : " << endl;
		admin.showAllParties();
		name = readline();

		// input validation
		while (!(admin.findPartyByName(name)))
		{
			cout << "invalid party, please enter correct party name : \n";
			admin.showAllParties();
			name = readline();
		}

		admin.addCandidateToParty(admin.findCitizenById(id), *(admin.findPartyByName(name)));
		break;
	case 5:
		// show all polling stations
		admin.showAllPollingStations();
		break;
	case 6:
		// show all citizens
		admin.showAllCivilians();
		break;
	case 7:
		// show all partys
		admin.showAllParties();
		break;
	case 8:
		// new elections
		int numberOfCitizens;
		int isCitizenWantToVote;
		numberOfCitizens = admin.getCitizensActualSize();
		for (int i = 0; i < numberOfCitizens; i++)
		{
			cout << "Hello: " << admin.getCitizenNameByOrder(i) << " whould you like to vote this time? 1 - Yes / 0 - NO: ";
			cin >> isCitizenWantToVote;
			if (isCitizenWantToVote)
			{
				cout << "here is a list of all parties, please enter the name of the party you want to chose : " << endl;
				admin.showAllParties();
				name = readline();

				// input validation
				while (!(admin.findPartyByName(name)))
				{
					cout << "invalid party, please enter correct party name : \n";
					admin.showAllParties();
					name = readline();
				}
				admin.addCitizenVote(i, name);
			}
		}
		break;
	case 9:
		// show results
		admin.showResults();
		break;
	case 10:
		// end
		admin.freeMemory();
		showAgain = 0;
		break;
	default:
		cout << "please enter valid input for the menu: \n";
	}
	return showAgain;
};