#include "TicketManager.h"

string TicketManager::numberToFixedStr(int number, int length) const {
	string newStr = to_string(number);
	if (newStr.length() > length) throw string("ERROR: Run out of ID!");
	while (newStr.length() < length) newStr = "0" + newStr;
	return newStr;

}

TicketManager::TicketManager() {
	tickets = vector<Ticket*>();
}

TicketManager::~TicketManager() {
	for (auto& t : tickets) {
		delete t;
	}
	tickets.clear();
}

Ticket* TicketManager::sellTicket(Customer* customer, Movie* movie, const string& seat, const string& date, const string& time) {
	if (!customer || !movie) return nullptr;

	string newID = "VE" + numberToFixedStr(numberOfSoldTickets + 1, 4);
	Ticket* newTicket = nullptr;

	if (customer->getType() == "Normal") {
		newTicket = new Ticket(newID, movie, customer, seat, date, time);
	}
	else if (customer->getType() == "Student") {
		newTicket = new StudentTicket(newID, movie, customer, seat, date, time);
	}
	else if (customer->getType() == "VIPCustomer") {
		newTicket = new VIPTicket(newID, movie, customer, seat, date, time);
	}
	else {
		throw string("ERROR: invalid customer type!");
	}

	numberOfSoldTickets++;
	tickets.push_back(newTicket);
	return newTicket;

}

Ticket* TicketManager::findTicket(const string& findID) const {
	for (auto& ticket : tickets)
		if (ticket->getID() == findID) return ticket;
	return nullptr;
}

unsigned long long TicketManager::getTotalRevenue() const {
	unsigned long long totalRev = 0;
	for (auto& t : tickets) {
		totalRev += t->getPrice();
	}
	return totalRev;
}
