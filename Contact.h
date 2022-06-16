#pragma once
#include <string>
using namespace std;
class Contact
{
private:
	string fName, lName, number;
public:
	string getFName();
	string getLName();
	string getNumber();
	void setFName(string);
	void setLName(string);
	void setNumber(string);
};

