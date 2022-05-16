#include <iostream>
#include <string>
using namespace std;


class bankAccount {
private:
	float accountBalance;
	string personName, personSurname, personPhone;
public:
	bankAccount(string name, string surname, float balance = 0, string phone_number = "");
	bankAccount(const bankAccount& oth);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(float);
	void withdraw(float);
	void sendMoney(bankAccount& othAccount, float amount);
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance = 0);
	int getPersonBalance() const { return accountBalance; };
	string getPersonName()const { return personName; };
	string getPersonSurname() const { return personSurname; };
	string getPersonPhone() const { return personPhone; };
};

