#pragma once

#include <iostream>
#include "User.h"
#include "Menu.h"
using namespace std;

class Staff : public User{

private:
	//data members

public:

	//main menu
	int mainMenu(int id);

	//staff menu
	void StaffMenu();

	//messages admin
	void messageAdmin();




};

