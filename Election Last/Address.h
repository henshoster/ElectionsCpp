#ifndef __ADDRESS_H
#define __ADDRESS_H
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
#endif // __ADDRESS_H