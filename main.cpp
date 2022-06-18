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
		//save codes
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

	int choise = tools.getInput(1, 7);
	switch (choise)
	{
	case 1:
	{
		contacts.add();
		break;
	}
	case 2:
		break;
	case 3:
		break;
	case 4:
	{
		int id = contacts.find();
		if (id != -1)
		{
			//find menu
		}
		break;
	}
	case 5:
		break;
	case 6:
	{
		contacts.showAll();
		break;
	}
	case 7:
		break;
	case 8:
		return false;
		break;
	default:
		break;
	}
}


