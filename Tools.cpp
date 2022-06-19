#include "Tools.h"


bool Tools::directoryExist()
{
	//getting UserName
	char userName[UNLEN + 1];
	getUserName(userName);
	//getting Path
	path = "C:\\Users\\";
	path = path + std::string(userName) + "\\Documents\\conatactApp\\";
	bool exist = isPathExist(path);
	if (!exist)
	{
		std::cout << "					---Welcome to your app---" << std::endl;
		std::string command = "mkdir " + path;
		try
		{
			if (system(convertStrToChar(command)))
			{
				throw 1;
			}
		}
		catch (int)
		{
			std::cout << "there are few problm to create directory" << std::endl;
			return false;
		}
		return true;
	}
	std::cout << "					---Welcome back to your app---" << std::endl;
	return true;
}

int Tools::getInput(int min, int max)
{
	std::string inpS;
	while (true)
	{
		try
		{
			cin >> inpS;
			int inpI;
			bool allNumber = toInt(inpS, inpI);
			if (!allNumber)
			{
				throw 1;
			}
			if (inpI < min || inpI > max)
			{
				throw 2;
			}
			return inpI;
		}
		catch (int e)
		{
			switch (e)
			{
			case 1:
			{
				std::cout << "write only number: ";
				continue;

			}
			case 2:
			{
				std::cout << "write only number between" << min << "," << max << " : ";
				continue;
			}
			default:
				break;
			}
		}
	}
}

std::string Tools::getPath()
{
	return path;
}

void Tools::getUserName(char* username)
{
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
}

bool Tools::isPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}

char* Tools::convertStrToChar(std::string str)
{
	int len = int(str.length());
	char* ch = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		ch[i] = str[i];
	}
	ch[len] = '\0';
	return ch;
}

//take str and push in inpI. if all of index is number return true else return false
bool Tools::toInt(std::string& str, int& inpI)
{
	int len = int(str.length());
	int number = 0;
	bool negativ = false;
	if (str[0] == '-') 
	{
		negativ = true;
	}
	else
	{
		number += int(str[0] - 48);
	}
	for (int i = 1; i < len; i++)
	{
		char ch = str[i];
		if (ch >= 48 && ch <= 57)
		{
			number = (number * 10) + int(ch - 48);
		}
		else
		{
			return false;
		}
	}
	if (negativ)
	{
		number *= -1;
	}
	inpI = number;
	return true;
}

