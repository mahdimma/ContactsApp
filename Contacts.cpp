#include "Contacts.h"

Contacts::Contacts(std::string _path) 
{
	path = _path;
}

bool Contacts::readingFile()
{
	ifstream contactFile(path + "contact.mmac");
	std::string line;
	if (!std::getline(contactFile, line))
	{
		contactFile.close();
		ofstream contactFile(path + "contact.mmac");
		contactFile.close();
		return true;
	}
}
