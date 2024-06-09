
#include "NonFaculty.h"
#include "Filemanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);


//Non Faculty menu
void NonFaculty::nonFacultyMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(n, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tNON - FACULTY MENU\n\n";

	SetConsoleTextAttribute(n, 15); //white

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

//student main menu
int NonFaculty::NFmainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {
		//clearing screen
		system("cls");

		SetConsoleTextAttribute(n, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\tNON - FACULTY MENU\n\n\n";

		SetConsoleTextAttribute(n, 15); //white

		cout << "\t\t\t\t\t\tCustomer ID: " << id << endl;

		//menu
		cout << "\n\t\t\t\t1. View Menu\t\t\t\t4. Place Order\n\t\t\t\t2. View Order History\t\t\t5. Rate Menu Items\n\t\t\t\t3. View Messages\t\t\t6. Logout\n\n\t\t\t\tEnter: ";

		//input
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);


	return option;


}