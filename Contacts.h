#pragma once
#include "Contact.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

class Contacts
{
private:
	// 0 for first name - 1 for last name - 2 for number
	vector <Contact> conVect;
	std::string path;
	bool formatDestroy();
	void displayContact(Contact &);
	bool compairWithF(Contact&, Contact&);
	bool compairWithL(Contact&, Contact&);
	bool compairWithN(Contact&, Contact&);


public:
	Contacts(std::string);
	bool readingFile();
	int find();
	void add();
	void showAll();
};

