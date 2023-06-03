#pragma once
#include <string>
using namespace std;


class Movie {
private:
	string ID;
	string name;
	string director;
	float duration;
	unsigned int basicPrice;

public:
	Movie(const string& _ID, const string& _name, const string& _dir, float _dur, unsigned int _bPrice);
	unsigned int getBasicPrice() const;
	string getName();
};

