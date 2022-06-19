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
		ofstream formating(path + "contacts.txt", ios::trunc);
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
	ifstream contactFile(path + "contacts.txt");
	std::string line;
	if (!std::getline(contactFile, line))
	{
		contactFile.close();
		ofstream contactFile(path + "contacts.txt");
		contactFile.close();
		return true;
	}
	try
	{
		int len;
		Tools tools;
		if (!tools.toInt(line, len))
		{
			throw 1;
		}
		std::cout << "					loading Contacts  ";
		for (int i = 0; i < len; i++)
		{
			if (i % 10 == 0)
			{
				std::cout << "\b\\";
			}
			else
			{
				std::cout << "\b/";
			}
			Contact newContact;
			if (!std::getline(contactFile, line))
			{
				throw 1;
			}
			newContact.setFName(line);
			if (!std::getline(contactFile, line))
			{
				throw 1;
			}
			newContact.setLName(line);
			if (!std::getline(contactFile, line))
			{
				throw 1;
			}
			newContact.setNumber(line);
			conVect.push_back(newContact);
		}
		std::system("cls");
		std::cout << "					---Welcome back to your app---" << std::endl;
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
	return true;
}

// 0 for find, 1 for show, 2 for delete, 3 for edit
int Contacts::find(int mode)
{
	std::cout << "Enter the word you are looking for: ";
	std::string target;
	cin >> target;
	int len = int(conVect.size());
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
	int lenF = int(finded.size());
	std::cout << std::endl;
	for (int i = 0; i < lenF; i++)
	{
		std::cout << "ID: " << i << std::endl;
		displayContact(conVect[finded[i]]);
	}
	std::string modeText;
	modeText = ((mode == 0) ? "select" : ((mode == 1) ? "show" : ((mode == 2) ? "delete" : "edit")));
	std::cout << "-1) main menu\nID)for " << modeText  << " a cotact, type your wana ID : ";
	Tools tools;
	int id = tools.getInput(-1, lenF - 1);
	if (id == -1)
	{
		return -1;
	}
	std::cout << std::endl;
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
	std::system("cls");
	while (true)
	{
		std::cout << "you want show all contact in which sorting?" << std::endl;
		std::cout << "1- First Name\n2- LastName\n3- Number\n4- default (now mode)\n5- main menu\ntype : ";
		Tools tools;
		int choise = tools.getInput(1, 5);
		switch (choise)
		{
		case 1:
		{
			std::sort(conVect.begin(), conVect.end(), compairWithF);
			break;
		}
		case 2:
		{
			std::sort(conVect.begin(), conVect.end(), compairWithL);
			break;
		}
		case 3:
		{
			std::sort(conVect.begin(), conVect.end(), compairWithN);
			break;
		}
		case 4:
			break;
		default:
			return;
			break;
		}
		std::system("cls");
		int len = int(conVect.size());
		std::cout << std::endl;
		for (int i = 0; i < len; i++)
		{
			std::cout << "ID: " << i << std::endl;
			displayContact(conVect[i]);
		}
	}
}

void Contacts::displayAContact(int index)
{
	displayContact(conVect[index]);
}

void Contacts::deleteAContact(int index)
{
	std::system("cls");
	std::cout << "removed" << std::endl;
	displayAContact(index);
	conVect.erase(conVect.begin() + index);
	std::cout << "thats clear after 1 seconds...";
		
}

void Contacts::deleteAll()
{
	conVect.clear();
}

void Contacts::edit(int index)
{
	displayAContact(index);
	while (true)
	{
		std::cout << "\nyou want change\n1) First name\n2) Last name\n3) number\n4) Main menu" << std::endl;
		std::cout << "write your wanted process: ";
		Tools tools;
		int choise = tools.getInput(1, 4);
		switch (choise)
		{
		case 1:
		{
			std::cout << "now First name: " << conVect[index].getFName() << std::endl;
			std::cout << "input your wanted First name for change: ";
			std::string fn;
			std::cin >> fn;
			conVect[index].setFName(fn);
			break;
		}
		case 2:
		{
			std::cout << "now Last name: " << conVect[index].getLName() << std::endl;
			std::cout << "input your wanted Last name for change: ";
			std::string ln;
			std::cin >> ln;
			conVect[index].setLName(ln);
			break;
		}
		case 3:
		{
			std::cout << "now Numeber: " << conVect[index].getNumber() << std::endl;
			std::cout << "input your wanted Numebr for change: ";
			std::string number;
			std::cin >> number;
			conVect[index].setNumber(number);
			break;
		}
		case 4:
		{
			return;
		}
		default:
			break;
		}
	}
}

void Contacts::findMenu(int index)
{
	std::cout << "					1) edit contact" << std::endl;
	std::cout << "					2) delete contact" << std::endl;
	std::cout << "					3) Main menu" << std::endl;
	std::cout << "					-what you want?: ";
	Tools tools;
	int choise = tools.getInput(1, 3);
	switch (choise)
	{
	case 1:
		edit(index);
		break;
	case 2:
		deleteAContact(index);
		break;
	case 3:
		return;
	default:
		break;
	}
}

void Contacts::save()
{
	int size = int(conVect.size());
	ofstream saving(path + "contacts.txt", ios::trunc);
	saving << size << "\n";
	if (saving.is_open())
	{
		std::cout << "in saving..." << std::endl;
		for (int i = 0; i < size; i++)
		{
			saving << conVect[i].getFName() << "\n";
			saving << conVect[i].getLName() << "\n";
			saving << conVect[i].getNumber() << "\n";
		}
		saving.close();
		std::cout << "saved";
	}
	else
	{
		//open file exeption
		std::cout << "somthing wrong to open file" << std::endl;
	}
}
