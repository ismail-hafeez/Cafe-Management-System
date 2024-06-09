#pragma once

#include <iostream>
#include "User.h"
using namespace std;

class Customer : public User {

private:
	//data members
	int customerType;

public:
	//default
	Customer();

	//setter
	void setType(int type);

	//getter
	int getType() const;

	//determining which customer
	void chooseCustomer();

	//student main menu
	virtual int StudentmainMenu(int id);

	//displays student menu
	virtual void StudentMenu();

	//Non Faculty menu
	virtual void nonFacultyMenu();

	//Non Faculty Menu
	virtual int NFmainMenu(int id);

	//Faculty menu
	virtual void FacultyMenu();

	//Faculty Menu
	virtual int FmainMenu(int id);



};

