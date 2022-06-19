#pragma once
#include "Contact.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

struct {
	bool operator()(Contact &c1, Contact &c2)
	{
		if ((c1.getFName().compare(c2.getFName())) == 0)
		{
			return false;
		}
		else if ((c1.getFName().compare(c2.getFName())) == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
} compairWithF;

struct {
	bool operator()(Contact c1, Contact c2)
	{
		if ((c1.getLName().compare(c2.getLName())) == 0)
		{
			return false;
		}
		else if ((c1.getLName().compare(c2.getLName())) == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
} compairWithL;

struct {
	bool operator()(Contact c1, Contact c2)
	{
		if ((c1.getNumber().compare(c2.getNumber())) == 0)
		{
			return false;
		}
		else if ((c1.getNumber().compare(c2.getNumber())) == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
} compairWithN;

class Contacts
{
private:
	vector <Contact> conVect;
	std::string path;
	bool formatDestroy();
	void displayContact(Contact &);
public:
	Contacts(std::string);
	bool readingFile();
	int find(int);
	void add();
	void showAll();
	void displayAContact(int);
	void deleteAContact(int);
	void deleteAll();
	void edit(int);
	void findMenu(int);
	void save();
};

