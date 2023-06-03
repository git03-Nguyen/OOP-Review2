#include "Customer.h"

Customer::Customer(const string& _ID, const string& _name, const string& _phone):
	ID(_ID), name(_name), phone(_phone) {}

string Customer::getName() const {
	return name;
}

string Customer::getType() const {
	return "Normal";
}

Student::Student(const string& _ID, const string& _name, const string& _phone): 
	Customer(_ID, _name, _phone) {}

string Student::getType() const {
	return "Student";
}

VIPCustomer::VIPCustomer(const string& _ID, const string& _name, const string& _phone):
	Customer(_ID, _name, _phone) {}

string VIPCustomer::getType() const {
	return "VIPCustomer";
}
