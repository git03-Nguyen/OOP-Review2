#pragma once
#include <string>
using namespace std;

class Customer {
protected:
	string ID;
	string name;
	string phone;

public:
	Customer(const string& _ID, const string& _name, const string& _phone);
	string getName() const;
	virtual string getType() const;
};

// -------------------------------
class Student : public Customer {
public:
	Student(const string& _ID, const string& _name, const string& _phone);
	string getType() const;
};

// -------------------------------
class VIPCustomer : public Customer {
public:
	VIPCustomer(const string& _ID, const string& _name, const string& _phone);
	string getType() const;
};


