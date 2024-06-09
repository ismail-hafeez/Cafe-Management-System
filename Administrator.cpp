
#include "Administrator.h"
#include "User.h"
#include "Rating.h"
#include "Menu.h"
#include "Filemanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);

//global object
Menu menu[20];

//main menu
int Administrator::mainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\tADMINISTRATOR MENU\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		cout << "\t\t\t\t\t\t  Admin ID: " << id << endl;

		//menu
		cout << "\n\t\t\t\t1. View Menu\t\t\t6. Add Notification\n\t\t\t\t2. Add Items\t\t\t7. View User\n\t\t\t\t3. Remove Items\t\t\t8. View Ratings";
		cout << "\n\t\t\t\t4. Rate Items\t\t\t9. View Payments\n\t\t\t\t5. View Order History\t\t10. Logout\n\n\t\t\t\tEnter: ";

		//input
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);


	return option;
}

//view menu
void Administrator::viewMenu() {

	//declaring var
	int opt;
	static int removeCount = 0;

	//clearing screen
	system("cls");

	SetConsoleTextAttribute(c, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t      CAFE MENU\n\n\n";

	SetConsoleTextAttribute(c, 15); //white

	//menu
	cout << "\t\tITEM ID\t\tQUANTITY\t     NAME\t\tDESCRIPTION\t\tPRICE\n\n";

	//crating object 
	Menu temp;
	
	//setting values
	if (removeCount == 0)
		temp.setAdminMenu(menu);

	//inc Count
	removeCount++;

	//printing menu
	for (int i = 0; i < temp.getCount(); i++) {

		if (menu[i].getID() == 0 && menu[i].getQuantity() == 0 && menu[i].getName() == "0" && menu[i].getDescription() == "0" && menu[i].getPrice() == 0)
			continue;
		else {
			cout << setw(18) << menu[i].getID();
			cout << setw(15) << menu[i].getQuantity();
			cout << setw(25) << menu[i].getName();
			cout << setw(22) << menu[i].getDescription();
			cout << setw(21) << menu[i].getPrice();

			cout << endl;
		}
	

	}

	cout << "\n\n\t\t\t\t\t\tPress 1 to Continue: ";
	cin >> opt;



}

//add menuitem
void Administrator::AddMenuItem() {

	//creating object
	Menu temp;

	//declaring variables
	int currentCount = temp.getCount();
	int id, q;
	string n, d;
	double p;
	bool cond;

	//user input id
	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t      CAFE MENU\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		//user input
		cout << "\t\t\t\t\tItem ID: ";
		cin >> id;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);

	//user input quantity
	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t      CAFE MENU\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		cout << "\t\t\t\t\tItem ID: " << id;

		//user input
		cout << "\n\t\t\t\t\tItem Quantity: ";
		cin >> q;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);


	//user input name
	cout << "\n\t\t\t\t\tItem Name: ";
	cin >> n;

	//user input description
	cout << "\n\t\t\t\t\tItem Description: ";
	cin >> d;

	//user input price
	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t      CAFE MENU\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		cout << "\t\t\t\t\tItem ID: " << id;
		cout << "\n\t\t\t\t\tItem Quantity: " << q;
		cout << "\n\t\t\t\t\tItem Name: " << n;
		cout << "\n\t\t\t\t\tItem Description: " << d;

		//user input
		cout << "\n\t\t\t\t\tItem Price: ";
		cin >> p;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);

	//incrementing count
	temp.incCount();

	//setting values
	temp.setValues(menu, currentCount, id, q, n, d, p);

	system("cls");

	SetConsoleTextAttribute(c, 6); //yellow

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tUPDATING STOCK... ";
	Sleep(1300);


}

//removes item
void Administrator::RemoveItem() {

	//declaring variables
	int id;
	static int removeCount = 0;
	bool success = false;
	bool cond;

	//declaring object
	Menu temp;

	do {

		//showing Menu
		viewMenu();

		cout << "\n\n\t\t\t\t\t\tREMOVE AN ITEM";
		cout << "\n\n\t\t\t\tItem ID: ";
		cin >> id;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);
	

	//Deleting if ID exists
	for (int i = 0; i < temp.getCount(); i++) {

		if (id == menu[i].getID()) {

			//setting to null
			temp.setValues(menu, i, 0, 0, "0", "0", 0);

			system("cls");

			SetConsoleTextAttribute(c, 6); //yellow

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tUPDATING STOCK... ";
			Sleep(1300);

			success = true;

			break;
			
		}

	}

	//error if not exist
	if (!success) {

		system("cls");

		SetConsoleTextAttribute(c, 6); //yellow

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tERROR: ID NOT FOUND";
		Sleep(1300);

	}

}

//rate menu items
void Administrator::rateMenu(int user_id) {

	//declaring variables
	int id, key;
	double score;
	bool success = false; 
	bool cond;
	string feedback;

	//creating object
	Menu temp;
	Rating rate;

	do {

		//showing Menu
		viewMenu();

		cout << "\n\n\t\t\t\t\t\tREMOVE AN ITEM";
		cout << "\n\n\t\t\t\tItem ID: ";
		cin >> id;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);

	//checking if ID exists
	for (int i = 0; i < temp.getCount(); i++) {

		if (id == menu[i].getID()) {
			success = true;
			break;
		}

	}

	if (success) {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 6); //yellow

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tREDIRECTING ...";
		Sleep(1200);

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t      CAFE MENU\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		cout << "\t\t\t\t\tFeedback on Item Id " << id << endl;
		cout << "\t\t\t\t\tScore (Out of 10): ";
		cin >> score;

		cout << "\t\t\t\t\tType here ...  ";

		cin.ignore();

		//user input
		getline(cin, feedback);

		//calling rate function
		rate.Rate(id, user_id, score, feedback);

	}

	//error if not exist
	else {

		system("cls");

		SetConsoleTextAttribute(c, 4); //red

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tERROR: ID NOT FOUND";
		Sleep(1300);

	}

}

//displaying ratings from file
void Administrator::DisplayRating() {

	//decalring variables
	ifstream file("menuRating.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(c, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t   FEEDBACK SECTION\n\n";

	SetConsoleTextAttribute(c, 15); //white

	// Read characters until the end of the file is reached	
	while (file.get(ch)) {
		cout << ch;
	}

	//closing file
	file.close();

	cin.ignore();

	//user input
	cout << "\n\n\n\n\t\t\t\t\t\tPress Any Key to Continue: ";
	getline(cin, press);


}

//send messages
void Administrator::AddNotification() {

	//declaring variables
	int choose;
	bool cond;

	//user input + validation check
	do {
		//clearing screen
		system("cls");

		SetConsoleTextAttribute(c, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t   ADD NOTIFICATION\n\n\n";

		SetConsoleTextAttribute(c, 15); //white

		cout << "\t\t\t\t\t1. Staff\n\t\t\t\t\t2. Customer\n\n\t\t\t\t\tEnter: ";
		cin >> choose;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (choose < 1 || choose > 2 || cond);
	
	///////////////////////////////////////////////////////////

	//determining type
	switch (choose) {
		//staff
		case 1: {

			//clearing screen
			system("cls");

			//creating object
			Filemanager save;

			SetConsoleTextAttribute(c, 3); //blue

			cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
			cout << "\t\t\t\t\t\tCHAT BOX - Admin & Staff\n";

			//reading previous messages
			save.ReadMessageAdminStaff();

			SetConsoleTextAttribute(c, 15); //white

			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tType here ...  ";
			string message;

			cin.ignore();

			getline(cin, message);

			save.saveMessage(message);


		} break;
		//customer
		case 2: {

			//clearing screen
			system("cls");

			SetConsoleTextAttribute(c, 3); //blue

			cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
			cout << "\t\t\t\t\t\   NOTIFICATION - Admin & Customer\n\n\n";

			SetConsoleTextAttribute(c, 15); //white

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tType here ...  ";
			string message;

			cin.ignore();

			getline(cin, message);

			Filemanager save;

			save.saveNotification(message);


		} break;



	}

}

//views user credentials
void Administrator::viewUser() {

	//decalring variables
	ifstream file("userdetails.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(c, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tVIEW USER CREDENTIALS\n";

	SetConsoleTextAttribute(c, 15); //white

	// Read characters until the end of the file is reached	
	while (file.get(ch)) {
		cout << ch;
	}

	//closing file
	file.close();

	cin.ignore();

	//user input
	cout << "\n\n\n\n\t\t\t\t\t\tPress Any Key to Continue: ";
	getline(cin, press);



}