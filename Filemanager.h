#pragma once

#include <iostream>
#include "Menu.h"
using namespace std;

class Filemanager {

private:
	//data members


public:
	//saves rating to text file
	void saveRating(int menuID, int userid, double Score, string message);

	//saves admin v staff messages
	void saveMessage(string message);

	//saves admin v user messages
	void saveNotification(string message);

	//reads notifications
	void ReadNotification();

	//saves user details 
	void saveUser(string userName, string password, int type, int id);

	//update menu
	void ReadMenu(Menu menu[]);

	//save receipt for order
	void saveReceipt(Menu order[], int size, double orderTotal, int orderID, double moneyGiven, double change);

	//reads receipt
	void readReceipt();

	//saving in total earnings
	void totalPayments(int orderID, int total);

	//reads total earning
	void ReadtotalPayments();

	//saves staff v admin messages
	void saveMessageStaff(string message);

	//reads messages bw admin and staff
	void ReadMessageAdminStaff();

};

