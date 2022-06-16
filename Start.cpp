#include "Start.h"


bool Start::directoryExist()
{
	//getting UderName
	char userName[UNLEN + 1];
	getUserName(userName);
	//getting Path
	path= "C:\\Users\\";
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

std::string Start::getPath()
{
	return path;
}

void Start::getUserName(char* username)
{
	DWORD username_len = UNLEN + 1;
	GetUserNameA(username, &username_len);
}

bool Start::isPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}

char* Start::convertStrToChar(std::string str)
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

