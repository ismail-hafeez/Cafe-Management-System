
#include "Faculty.h"
#include "Filemanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE q = GetStdHandle(STD_OUTPUT_HANDLE);


//Faculty menu
void Faculty::FacultyMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(q, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t     FACULTY MENU\n\n";

	SetConsoleTextAttribute(q, 15); //white

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

//Faculty main Menu
int Faculty::FmainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(q, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t     FACULTY MENU\n\n\n";

		SetConsoleTextAttribute(q, 15); //white

		cout << "\t\t\t\t\t\tCustomer ID: " << id << endl;

		//menu
		cout << "\n\t\t\t\t1. View Menu(Students)\t\t\t\t4. Place Order\n\t\t\t\t2. View Menu(Non-Faculty)\t\t\t5. Rate Menu Items\n\t\t\t\t3. View Messages\t\t\t\t6. View Order History\n\t\t\t\t7. Logout\n\n\t\t\t\tEnter: ";

		//input
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);

	return option;





}


