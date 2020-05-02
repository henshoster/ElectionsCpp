#include <iostream>
using namespace std;
# include "results.h"

bool Results::setName(char* name)
{
	nameOfPary = name;
	return true;
}

char* Results::getName()
{
	return nameOfPary;
}

// counting number of voters
bool Results::increaseVote()
{
	voters += 1;
	return true;
}

//free memory
void Results::free()
{
	delete[] nameOfPary;
}

int Results::getVotes()
{
	return voters;
}

// function to calculate final results
bool Results::increaseVoteByNumber(int num)
{
	voters += num;
	return true;
}