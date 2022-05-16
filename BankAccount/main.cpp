#include "account.h"
#include <iostream>
using namespace std;


int main() {

	/*person p1("Orhan", "Yildirim", "05423025705");
	p1.print();

	person p2 = p1;
	p2.setPersonPhone("05455555452");
	p2.print();*/

	bankAccount acc1("Orhan", "Yildirim",1000, "05423025705");
	acc1.setPersonBalance(2000);
	acc1.displayProfile();

	bankAccount acc2 = acc1;
	acc2.setPersonName("Burhan");
	acc2.setPersonBalance(2500);
	acc2.displayProfile();

	acc1.sendMoney(acc2, 500);
	acc1.displayProfile();

	
	return 0;
}
