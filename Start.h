#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <lmcons.h>
#include <fstream>
#include <vector>
#include "Contact.h"

class Start
{
private:
	std::string path;
	void getUserName(char*);
	bool isPathExist(const std::string&);
	char* convertStrToChar(std::string);
public:
	bool directoryExist();
	std::string getPath();
};

