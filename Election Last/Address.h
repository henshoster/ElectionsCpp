#ifndef _ADDRESS_H
#define _ADDRESS_H
class Address {
private:
	char* street;
	int number;
	char* city;
public:
	bool setAddress(char* _street, int _number, char* _city);
	void showAddress();
	void free();
};
#endif // _ADDRESS_H