#pragma once
#include <iostream>
using namespace std;

class pulse {
private:
	string name, surname;
	int day, month, year;
public:
	pulse();
	pulse(string name,string surname,int day,int month,int year);
	void setName(string);
	void setSurname(string);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	string getName();
	string getSurname();
	int getDay();
	int getMonth();
	int getYear();
	int getAge();
	void getTargetPulse();
	int getMaxPulse();
	void print();
};
