#include "Date.h"
#include <iostream>
using namespace std;

void Date::showDate() {
	cout << day << "/" << month << "/" << year;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}


// check if the date is valid
bool Date::validateDate(int _day, int _month)
{
	bool isValid = true;
	switch (_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (_day < 1 || _day > 31)
		{
			cout << "invalid date \n";
			isValid = false;
		}
		break;
	case 2:
		if (_day < 1 || _day > 28)
		{
			cout << "invalid date \n";
			isValid = false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (_day < 1 || _day > 30)
		{
			cout << "invalid date \n";
			isValid = false;
		}
		break;
	default:
		cout << "invalid date \n";
		isValid = false;
		break;
	}
	return isValid;
}

// function to set citizens year of birth (day and month default 1)
bool Date::setDate(int _year)
{
	year = _year;
	month = 1;
	day = 1;
	return true;
}

// function to set election Date with defaule 1 for day
bool Date::setDate(int _month, int _year)
{
	if (validateDate(1, _month)) 
	{
		year = _year;
		month = _month;
		day = 1;
		return true;
	}
	return false;
}

// function to set party creation date
bool Date::setDate(int _day, int _month, int _year)
{
	if (validateDate(_day, _month)) 
	{
		year = _year;
		month = _month;
		day = _day;
		return true;
	}
	return false;
}