#ifndef _DATE_H
#define _DATE_H
class Date {
private:
	int day;
	int month;
	int year;
	bool validateDate(int _day, int _month);
public:
	bool setDate(int _day, int _month, int _year);
	bool setDate(int _month, int _year);
	bool setDate(int _year);
	void showDate();
	int getDay();
	int getMonth();
	int getyear();
};
#endif // _DATE_H