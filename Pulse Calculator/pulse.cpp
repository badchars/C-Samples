#include "pulse.h"
#include <iostream>
using namespace std;

pulse::pulse() {
	cout << "Default pulse constructor worked!" << endl;
	name = "";
	surname= "";
	day = 0;
	month = 0;
	year = 0;

}

pulse::pulse(string name, string surname, int day, int month, int year) {
	setName(name);
	setSurname(surname);
	setDay(day);
	setMonth(month);
	setYear(year);
}

void pulse::setName(string name) {
	this->name= name;
}

void pulse::setSurname(string surname) {
	this->surname = surname;
}

void pulse::setDay(int day) {
	if (day > 0 && day <= 31) {
		this->day = day;
	}
	else {
		cout << "Invalid value." << endl;
	}
}

void pulse::setMonth(int month) {
	if (month > 0 && month <= 12) {
		this->month = month;
	}
	else {
		cout << "Invalid value." << endl;
	}
}

void pulse::setYear(int year) {
	if (year >= 1900) {
		this->year = year;
	}
	else {
		cout << "Invalid value." << endl;
	}
}

string pulse::getName() { return name; };
string pulse::getSurname() { return surname; };
int pulse::getDay() { return day; };
int pulse::getMonth() { return month; };
int pulse::getYear() { return year; };
int pulse::getAge() { return 2022 - getYear(); };
void pulse::getTargetPulse() {
	int min_value = getMaxPulse() * 0.5;
	int max_value = getMaxPulse() * 0.8;
	cout << "Min value: " << min_value << "\n" << "Max value : " << max_value << endl;
}

int pulse::getMaxPulse() { return 220 - getAge(); };
void pulse::print() {
	cout << "Name Surname: " << getName() << " " << getSurname() << "\n" << "Birthdate: " << day << "/" << month << "/" << year << "\n" << "Yas: " << getAge() << "\n" << "Max value: " << getMaxPulse() << "\n";
	getTargetPulse();
}
