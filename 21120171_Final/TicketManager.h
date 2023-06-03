#pragma once
#include <vector>
#include "Ticket.h"

using namespace std;

class TicketManager {
private:
	vector<Ticket*> tickets;
	string numberToFixedStr(int number, int length) const;

public:
	static int numberOfSoldTickets;

	TicketManager();
	~TicketManager();

	Ticket* sellTicket(Customer* customer, Movie* movie, const string& seat, const string& date, const string& time);
	Ticket* findTicket(const string& findID) const;

	unsigned long long getTotalRevenue() const;

};

