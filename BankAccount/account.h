#include <iostream>
using namespace std;

class person {
private:
	string personName, personSurname, personPhone;
public:
	person(string name, string surname,string phone_number = "");
	person(const person& oth);
	~person();
	void setPersonName(string personName);
	void setPersonSurname(string personSurname);
	void setPersonPhone(string personPhone);
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	string getPersonName();
	string getPersonSurname();
	string getPersonPhone();
	void print();
};

class bankAccount :public person {
private:
	float accountBalance;
public:
	bankAccount(string name, string surname, float balance, string phone_number);
	//bankAccount(const bankAccount& oth);
	//~bankAccount();
	void displayProfile();
	/*void credit(float);
	*/void withdraw(float);
	void sendMoney(bankAccount& othAccount, float amount);
	void setPersonBalance(int balance);
	/*int getPersonBalance() const { return accountBalance; }; */
};
