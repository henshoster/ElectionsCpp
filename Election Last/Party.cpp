#include <iostream>
using namespace std;

#include "Party.h"




bool Party::setName(char* _name)
{
	name = _name;
	return true;
}
bool Party::setWing(eWing _wing)
{
	if (_wing >= 0 && _wing <= 2)
	{
		wing = _wing;
		return true;
	}
	else return false;
}
bool Party::setCreationDate(Date& _creationDate)
{
	creationDate = _creationDate;
	return true;
}
void Party::addCandidate(Citizen* candidate)
{
	if (candidates == nullptr)
	{
		candidates = new Citizen *[logicalSize];
	}

	else if (actualSize == logicalSize)
	{
		logicalSize *= 2;
		Citizen** newCandidates = new Citizen *[logicalSize];
		for (int i = 0; i < actualSize; i++)
		{
			newCandidates[i] = candidates[i];
		}
		delete[] candidates;
		candidates = newCandidates;
	}
	candidates[actualSize] = candidate;
	actualSize += 1;
}
void Party::show()
{
	cout << " name: " << name << endl;
}
void Party::free()
{
	delete[] candidates;
	delete[] name;
}
char* Party::getName()
{
	return name;
}