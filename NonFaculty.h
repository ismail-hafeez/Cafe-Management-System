#pragma once

#include <iostream>
#include "Customer.h"
using namespace std;

class NonFaculty : public Customer {

private:
	//data members

public:

	//Non Faculty menu
	void nonFacultyMenu();

	//Menu
	int NFmainMenu(int id);
};

