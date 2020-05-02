#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Address.h" 

bool Address::setAddress(char* _street, int _number, char* _city)
{
	number = _number;
	street = _street;
	city = _city;
	return true;
}

void Address::showAddress() {
	cout << "Address: " << street << ", " << number << "," << city << endl;
}
void Address::free() {
	delete[] street;
	delete[] city;
}
