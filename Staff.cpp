
#include "Staff.h"
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

HANDLE st = GetStdHandle(STD_OUTPUT_HANDLE);

//staff main menu
int Staff::mainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(st, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t     STAFF MENU\n\n\n";

		SetConsoleTextAttribute(st, 15); //white

		cout << "\t\t\t\t\t\t  STAFF ID: " << id << endl;

		//menu
		cout << "\n\t\t\t\t1. View Menu\t\t\t4. Add Item\n\t\t\t\t2. Process Order\t\t5. Remove Item\n\t\t\t\t3. Message Admin\t\t6. Logout\n\n\t\t\t\tEnter: ";

		//input
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);


	return option;
}

//Staff menu
void Staff::StaffMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(st, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t     STAFF MENU\n\n";

	SetConsoleTextAttribute(st, 15); //white

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

//messages admin
void Staff::messageAdmin() {

	//crating object 
	Filemanager read;

	//clearing screen
	system("cls");

	SetConsoleTextAttribute(st, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tCHAT BOX - Admin & Staff\n";

	//reading previous messages 
	read.ReadMessageAdminStaff();

	SetConsoleTextAttribute(st, 15); //white

	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tType here ...  ";
	string message;

	cin.ignore();

	getline(cin, message);

	Filemanager save;

	save.saveMessageStaff(message);
}