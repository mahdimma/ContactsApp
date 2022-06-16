#pragma once
#include "Contact.h"
#include <vector>
#include <iostream>
#include <fstream>

class Contacts
{
private:
	// 0 for first name - 1 for last name - 2 for number
	vector <Contact> conVect[3];
	std::string path;

public:
	Contacts(std::string);
	bool readingFile();
};

