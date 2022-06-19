#include <iostream>
#include "Tools.h"
#include "Contact.h"
#include "Contacts.h"
#include <chrono>
#include <thread>

bool menu(Contacts&, Tools&);

int main()
{
	Tools tools;
	if (!tools.directoryExist())
	{
		return 0;
	}
	Contacts contacts(tools.getPath());
	if (!contacts.readingFile())
	{
		return 0;
	}
	while (menu(contacts, tools)) {}
	std::cout << "do you want save your change? yes = 1, no = 0 " << std::endl;
	int choise = tools.getInput(0, 1);
	if (choise)
	{
		contacts.save();
	}
	std::cout << "					------------GodSpeed------------";
	std::chrono::seconds sleep(5);
	std::this_thread::sleep_for(sleep);
	return 0;
}

bool menu(Contacts& contacts, Tools& tools)
{

	std::cout << "					___Contact App___" << std::endl;
	std::cout << "					type your choise" << std::endl;
	std::cout << "					1) add a contact" << std::endl;
	std::cout << "					2) show a contact" << std::endl;
	std::cout << "					3) delete a contact" << std::endl;
	std::cout << "					4) find a contact" << std::endl;
	std::cout << "					5) edit a contact" << std::endl;
	std::cout << "					6) show all contact" << std::endl;
	std::cout << "					7) delete all contact" << std::endl;
	std::cout << "					8) Exit" << std::endl;

	int choise = tools.getInput(1, 8);
	switch (choise)
	{
	case 1:
	{
		int choise = 2;
		do {
			contacts.add();
			std::cout << "you want to add another contact?\n1)yes\n2)no\nwhich: ";
			int choise = tools.getInput(1, 2);
		} 
		while (choise == 1);
		std::cout << "thats clear after 1 seconds...";
		std::chrono::seconds sleep(1);
		std::this_thread::sleep_for(sleep);
		break;
	}
	case 2:
	{
		int id = contacts.find(1);
		if (id != -1)
		{
			std::system("cls");
			contacts.displayAContact(id);
			std::cout << "thats clear after 3 seconds...";
			std::chrono::seconds sleep(3);
			std::this_thread::sleep_for(sleep);
		}
		break;
	}
	case 3:
	{
		int id = contacts.find(2);
		if (id != -1)
		{
			contacts.deleteAContact(id);
			std::chrono::seconds sleep(3);
			std::this_thread::sleep_for(sleep);
		}
		break;
	}
	case 4:
	{
		std::system("cls");
		int id = contacts.find(0);
		if (id != -1)
		{
			contacts.displayAContact(id);
			contacts.findMenu(id);
			std::cout << "thats clear after 1 seconds...";
			std::chrono::seconds sleep(3);
			std::this_thread::sleep_for(sleep);
		}
		break;
	}
	case 5:
	{
		int id = contacts.find(3);
		if (id != -1)
		{
			contacts.edit(id);
		}
		break;
	}
	case 6:
	{
		contacts.showAll();
		break;
	}
	case 7:
	{
		contacts.deleteAll();
		break;
	}
	case 8:
	{
		return false;
		break;
	}
	}
	std::system("cls");
	return true;
}


