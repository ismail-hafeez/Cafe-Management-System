#pragma once

#include <iostream>
#include "User.h"
#include "Menu.h"
using namespace std;

class Administrator : public User {

private:
	//data members

public:
	//main menu
	int mainMenu(int id);

	//view menu
	void viewMenu();

	//add menuitem
	void AddMenuItem();

	//removes item
	void RemoveItem();

	//rate menu items
	void rateMenu(int user_id);

	//displaying ratings from file
	void DisplayRating();

	//send messages
	void AddNotification();

	//views user credentials
	void viewUser();




};

