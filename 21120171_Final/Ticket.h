#pragma once
#include <iostream>
#include "Movie.h"
#include "Customer.h"
using namespace std;

class Ticket {
protected:
	string ID;
	Movie* movie;
	Customer* customer;
	string seat;
	string date;
	string time;

public:
	Ticket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time);
	string getID() const;
	virtual unsigned int getPrice() const;
	void print() const;
};

// ------------
class StudentTicket : public Ticket {
public:
	StudentTicket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time);
	unsigned int getPrice() const;
};

// ------------
class VIPTicket : public Ticket {
public: 
	VIPTicket(const string& _ID, Movie* _movie, Customer* _customer, const string& _seat, const string& _date, const string& _time);
	unsigned int getPrice() const;
};
