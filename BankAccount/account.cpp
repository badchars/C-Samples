#include "account.h"
#include <iostream>
using namespace std;


bankAccount::bankAccount(string name, string surname, float balance, string phone_number) {
	setPersonName(name);
	setPersonSurname(surname);
	setPersonPhone(phone_number);
	setPersonBalance(balance);
	//cout << "Bank Account Created." << endl;
}

bankAccount::~bankAccount() {

}

bankAccount::bankAccount(const bankAccount& othAccount) {
	personName = othAccount.personName;
	personSurname = othAccount.personSurname;
	personPhone = othAccount.personPhone;
	accountBalance = othAccount.accountBalance;
}

void bankAccount::setPersonName(string name) {
	while (!controlNameSurname(name)) {
		cout << "Invalid name, please enter valid name: ";
		getline(cin, name);
	}
	personName = name;
}

void bankAccount::setPersonSurname(string surname) {
	while(!controlNameSurname(surname)){
		cout << "Invalid surname, please enter valid surname: ";
		getline(cin, surname);
	}
	personSurname = surname;
}

void bankAccount::setPersonPhone(string phone) {
	while (!controlPhoneNumber(phone)) {
		cout << "Invalid phone number, please enter valid phone number.";
		getline(cin, phone);
	}
	personPhone = phone;
}

void bankAccount::setPersonBalance(float balance) {
	if (balance <= 0) {
		accountBalance = 0;
	}
	else {
		accountBalance = balance;
	}
}


bool bankAccount::controlNameSurname(string nameOrSurname) {
	for (unsigned i = 0; i < nameOrSurname.length(); i++) {
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z'))) {
			return false;
		}
	}
	return true;
}


bool bankAccount::controlPhoneNumber(string phoneNumber) {
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


void bankAccount::credit(float amount) {
	while (amount <= 0) {
		cout << "Invalid amount; please enter valid amount.";
		cin >> amount;
	}
	accountBalance += amount;
	cout << personName << " " << personSurname << " used " << amount << " $ of credit." << endl;
}


void bankAccount::withdraw(float amount) {
	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount.";
		cin >> amount;
	}
	accountBalance -= amount;
}

void bankAccount::displayProfile() {
	cout << "----------Account Details----------" << endl;
	cout << "Name: " << personName <<" " << personSurname << "\n" << "Phone: " << personPhone << endl;
	cout << "Balance: " << accountBalance << " $" << endl;
	cout << "-----------------------------------" << endl;

}

void bankAccount::sendMoney(bankAccount& othAccount, float amount) {
	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount.";
		cin >> amount;
	}
	accountBalance -= amount;
	othAccount.accountBalance += amount;
}
