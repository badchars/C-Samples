#include "account.h"
#include <iostream>
#include <string>
using namespace std;




// Person Class description

person::person(string personName, string personSurname, string personPhone) {
	setPersonName(personName);
	setPersonSurname(personSurname);
	setPersonPhone(personPhone);
}

person::~person() {

}

person::person(const person& oth) {
	personName = oth.personName;
	personSurname = oth.personSurname;
	personPhone = oth.personPhone;
}

void person::setPersonName(string personName) {
	while (!controlNameSurname(personName)) {
		cout << "Invalid name, please enter valid name: ";
		getline(cin, personName);
	}
	this->personName = personName;
}

void person::setPersonSurname(string personSurname) {
	while (!controlNameSurname(personSurname)) {
		cout << "Invalid surname, please enter valid surname: ";
		getline(cin, personSurname);
	}
	this->personSurname = personSurname;
}


void person::setPersonPhone(string personPhone) {
	while (!controlPhoneNumber(personPhone)) {
		cout << "Invalid phone number, please enter valid phone number.";
		getline(cin, personPhone);
	}
	this->personPhone = personPhone;
}

bool person::controlNameSurname(string nameOrSurname) {
	for (unsigned i = 0; i < nameOrSurname.length(); i++) {
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z'))) {
			return false;
		}
	}
	return true;
}

bool person::controlPhoneNumber(string phoneNumber) {
	if (phoneNumber.empty()) {
		return true;
	}
	if (phoneNumber.length() != 11) {
		return false;
	}
	for (unsigned i = 0; i < phoneNumber.length(); i++) {
		if (!(phoneNumber.at(i) >= '0' && phoneNumber.at(i) <= '9')) {
			return false;
		}
	}
	return true;
}


string person::getPersonName() {
	return personName;
}

string person::getPersonSurname() {
	return personSurname;
}
string person::getPersonPhone() {
	return personPhone;
}

void person::print() {
	cout << "----------Person Details----------" << endl;
	cout << "Person Details: " << getPersonName() << " " << getPersonSurname() << "\n" << "Phone Number : " << getPersonPhone() << endl;
	
}




// bankAccount 
bankAccount::bankAccount(string name, string surname, float balance, string phone_number) :person(name,surname,phone_number){
	setPersonBalance(balance);
	//cout << "Bank account created!" << endl;
}

void bankAccount::setPersonBalance(int balance) {
	if (balance <= 0) {
		accountBalance = 0;
	}
	else {
		accountBalance = balance;
	}
}

void bankAccount::displayProfile() {
	cout << "----------Account Details----------" << endl;
	cout << "Name: " << person::getPersonName() << " " << person::getPersonName() << "\n" << "Phone: " << person::getPersonPhone() << endl;
	cout << "Balance: " << accountBalance << " $" << endl;
	cout << "-----------------------------------" << endl;

}

void bankAccount::withdraw(float amount) {
	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount.";
		cin >> amount;
	}
	accountBalance -= amount;
}

void bankAccount::sendMoney(bankAccount& othAccount, float amount) {
	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount.";
		cin >> amount;
	}
	accountBalance -= amount;
	othAccount.accountBalance += amount;
	cout << "Money Transferred ( "<<amount<<" $) from "<<getPersonName() << " to " << othAccount.getPersonName() << "'s account!"<< endl;
}
