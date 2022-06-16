#include <iostream>
#include <Windows.h>
#include <vector>
#include "Start.h"
#include "Contact.h"
#include "Contacts.h"

int main()
{
	Start start;
	std::vector <Contact> vectC[3];
	if (!start.directoryExist())
	{
		return 0;
	}
	Contacts contacts(start.getPath());
	if (contacts.readingFile())
	{
		return 0;
	}
}



