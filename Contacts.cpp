#include "Contacts.h"
#include "Tools.h"

bool Contacts::formatDestroy()
{
	std::cout << "file is destroyed, for continue must format file. if you want fomat type \'1\' for exit \'0\' : ";
	Tools tools;
	int choise = tools.getInput(0, 1); //must rewrite with function
	if (choise == 0)
	{
		return false;
	}
	else
	{
		ofstream formating(path + "contact.cmma", ios::trunc);
		if (formating.is_open())
		{
			formating.close();
			std::cout << "file formated" << std::endl;
			return true;
		}
		else
		{
			//open file exeption
			std::cout << "somthing wrong to open file" << std::endl;
			return false;
		}

	}
}

void Contacts::displayContact(Contact& contact)
{
	std::cout << "First Name: " << contact.getFName() << std::endl;
	std::cout << "Last Name: " << contact.getLName() << std::endl;
	std::cout << "Number: " << contact.getNumber() << std::endl << std::endl;
}

Contacts::Contacts(std::string _path)
{
	path = _path;
}

bool Contacts::readingFile()
{
	ifstream contactFile(path + "contact.cmma");
	std::string line;
	if (!std::getline(contactFile, line))
	{
		contactFile.close();
		ofstream contactFile(path + "contact.cmma");
		contactFile.close();
		return true;
	}
	try
	{
		int len;
		Tools tools;
		if (tools.toInt(line, len))
		{
			throw 1;
		}
		for (int i = 0; i < len; i++)
		{
			Contact newContact;
			std::getline(contactFile, line);
			newContact.setFName(line);
			std::getline(contactFile, line);
			newContact.setLName(line);
			std::getline(contactFile, line);
			newContact.setNumber(line);
			conVect.push_back(newContact);
		}
		return true;
	}
	catch (int s)
	{
		switch (s)
		{
		case 1:
			return formatDestroy();
		default:
			break;
		}
	}
}

int Contacts::find()
{
	std::string target;
	cin >> target;
	int len = conVect.size();
	vector <int> finded;
	for (int i = 0; i < len; i++)
	{
		if ((conVect[i].getFName().find(target) != -1) || (conVect[i].getLName().find(target) != -1) || (conVect[i].getNumber().find(target) != -1))
		{
			finded.push_back(i);
		}
	}
	if (finded.size() == 0)
	{
		std::cout << "that's not there" << std::endl;
		return -1;
	}
	int lenF = finded.size();
	std::cout << std::endl;
	for (int i = 0; i < lenF; i++)
	{
		std::cout << "ID: " << i << std::endl;
		displayContact(conVect[finded[i]]);
	}
	std::cout << "type your wana ID: ";
	Tools tools;
	int id = tools.getInput(0, lenF - 1);
	std::cout << std::endl;
	displayContact(conVect[finded[id]]);
	return finded[id];
}

void Contacts::add()
{
	Contact contact;
	std::string temp;
	std::cout << "type your contact First Name : ";
	cin >> temp;
	contact.setFName(temp);
	std::cout << "type your contact Last Name : ";
	cin >> temp;
	contact.setLName(temp);
	std::cout << "type your contact Number : ";
	cin >> temp;
	contact.setNumber(temp);
	conVect.push_back(contact);
}

void Contacts::showAll()
{
	std::cout << "you want show all contact in which sorting?" << std::endl;
	std::cout << "1- First Name 2- LastName 3- Number 4- default (now mode)- type : ";
	Tools tools;
	int choise = tools.getInput(1, 4);
	switch (choise)
	{
	case 1:
	{
		sort(conVect.begin(), conVect.end()/*need to select function*/);
		break;
	}
	case 2:
	{
		
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	default:
		break;
	}
	int len = conVect.size();
	std::cout << std::endl;
	for (int i = 0; i < len ; i++)
	{
		displayContact(conVect[i]);
	}
}
