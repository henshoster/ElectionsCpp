#ifndef _PARTY_H
#define _PARTY_H
#include "Date.h"
enum eWing { LEFT, CENTER, RIGHT };

class Citizen;


class Party
{
private:
	char* name;
	eWing wing;
	Date creationDate;
	Citizen** candidates = nullptr;
	int actualSize = 0;
	int logicalSize = 1;
public:
	bool setName(char* _name);
	bool setWing(eWing _wing);
	bool setCreationDate(Date& _creationDate);
	void addCandidate(Citizen* candidate);
	void show();
	char* getName();
	void free();
};


#endif // _PARTY_H