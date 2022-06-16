#include "Contact.h"

string Contact::getFName()
{
	return fName;
}

string Contact::getLName()
{
	return lName;
}

string Contact::getNumber()
{
	return number;
}

void Contact::setFName(string _fName)
{
	fName = _fName;
}

void Contact::setLName(string _lName)
{
	lName = _lName;
}

void Contact::setNumber(string _number)
{
	number = _number;
}
