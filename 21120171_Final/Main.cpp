#include <iostream>

#include "TicketManager.h"

using namespace std;

// Initilize a cinema -> maybe having a lot of TicketManager (Ticket booth, Electronic wallet, Banking app, ...)
int TicketManager::numberOfSoldTickets = 0;

int main() {
	TicketManager* tMgr = new TicketManager();

	Customer* ctmA = new Customer("KH001", "Lionel Messi", "0111222333"),
		* ctmB = new Customer("KH002", "Cristiano Ronaldo", "0222333444"),
		* ctmC = new Customer("KH003", "Harry Maguire", "0333444555");

	Movie* mv1 = new Movie("PH001", "Harry Potter - The Deadly Hallow", "David Yates", 2.4, 100000),
		* mv2 = new Movie("PH002", "Dragon Ball Super: Super Hero", "Tetsuro Kodama", 2.7, 80000);

	Ticket* tA = tMgr->sellTicket(ctmA, mv1, "A05", "Sunday", "19:00"); 
	Ticket* tB = tMgr->sellTicket(ctmB, mv1, "A04", "Monday", "13:00"); 
	Ticket* tC1 = tMgr->sellTicket(ctmC, mv1, "B08", "Wednesday", "20:00"); 
	Ticket* tC2 = tMgr->sellTicket(ctmC, mv2, "C01", "Thursday", "15:00"); 
	
	cout << "TICKETS INFO:" << endl;
	tMgr->findTicket(tA->getID())->print(); cout << "---\n";
	tMgr->findTicket(tB->getID())->print(); cout << "---\n";
	tMgr->findTicket(tC1->getID())->print(); cout << "---\n";
	tMgr->findTicket(tC2->getID())->print(); cout << "---\n";

	cout << "---\n";
	cout << "Total Revenue of TicketManager: " << tMgr->getTotalRevenue() << " VND" << endl;
	cout << "---\n";
	
	Student* stdA = new Student("SV001", "Kylian Mbappe", "0444555666");
	Ticket* tStdA = tMgr->sellTicket(stdA, mv1, "A01", "Monday", "10:00");
	tMgr->findTicket(tStdA->getID())->print(); cout << "---\n";

	VIPCustomer* vipB = new VIPCustomer("VP001", "Erling Haaland", "0555666777");
	Ticket* tVipB = tMgr->sellTicket(stdA, mv2, "A01", "Monday", "19:00");
	tMgr->findTicket(tVipB->getID())->print(); cout << "---\n";

	system("PAUSE");
	return 0;
}


