#include "Ticket.h"

Ticket::Ticket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time) :
	ID(_ID), movie(_movie), customer(_customer), seat(_seat), date(_date), time(_time) {}

string Ticket::getID() const {
	return ID;
}

unsigned int Ticket::getPrice() const {
	unsigned int bPrice = movie->getBasicPrice();
	return (stoi(time.substr(0, 2)) >= 18) ? bPrice * 1.1 :
		((date != "Saturday" && date != "Sunday") ? bPrice * 0.7 : bPrice);
}

void Ticket::print() const {
	cout << "Ticket ID: " << ID << endl;
	cout << "Customer name: " << customer->getName() << endl;
	cout << "Movie name: " << movie->getName() << endl;
	cout << "Seat: " << seat << endl;
	cout << "Date: " << date << endl;
	cout << "Time: " << time << endl;
	cout << "Price: " << getPrice() << " VND" << endl;
}

StudentTicket::StudentTicket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time):
	Ticket(_ID, _movie, _customer, _seat, _date, _time) {}

unsigned int StudentTicket::getPrice() const {
	return Ticket::getPrice() * 0.6;
}

VIPTicket::VIPTicket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time):
	Ticket(_ID, _movie, _customer, _seat, _date, _time) {}

unsigned int VIPTicket::getPrice() const {
	return Ticket::getPrice() * 0.8;
}
