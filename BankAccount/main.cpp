#include "account.h"
#include <iostream>
using namespace std;

int main() {

	bankAccount acc1("Ogun", "Birinci", 1500, "05071231212");
	acc1.credit(5000);
	acc1.displayProfile();


	bankAccount acc2("Orhan", "Yildirim", 500, "05423025705");
	acc2.displayProfile();

	bankAccount acc3 = acc1;
	acc3.setPersonName("TestUser");
	acc3.setPersonSurname("TestUserSurname");

	acc1.sendMoney(acc3, 5500);
	acc3.displayProfile();

	acc3.sendMoney(acc2, 11000);
	acc2.displayProfile();


	return 0;
}
