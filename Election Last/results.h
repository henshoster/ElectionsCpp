#ifndef _RESULTS_H
#define _RESULTS_H


class Results
{
private:
	char* nameOfPary;
	int voters = 0;
public:
	bool setName(char* name);
	char* getName();
	bool increaseVote();
	int getVotes();
	bool increaseVoteByNumber(int num);
	void free();
};

#endif // _RESULTS_H