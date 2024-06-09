
#include "Customer.h"
#include "User.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <limits>
#include <iomanip>

HANDLE e = GetStdHandle(STD_OUTPUT_HANDLE);

//global object
Menu menuS[20];

using namespace std;

//default
Customer::Customer() : customerType(0) { }

//setter
void Customer::setType(int type) {
	customerType = type;
}

//getter
int Customer::getType() const {
	return customerType;
}

//determining which customer
void Customer::chooseCustomer() {

	//declaring variables
	int option;
	bool cond;

	do {
		//clearing screen
		system("cls");

		SetConsoleTextAttribute(e, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t    CUSTOMER MENU\n\n\n";

		SetConsoleTextAttribute(e, 15); //white

		cout << "\t\t\t\t\t1. Student\n\t\t\t\t\t2. Faculty\n\t\t\t\t\t3. Non-Faculty\n\n\t\t\t\t\tEnter: ";
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (option < 1 || option > 3 || cond);

	//setting type
	setType(option);

}

//student main menu
int Customer::StudentmainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(e, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t   STUDENT MENU\n\n\n";

		SetConsoleTextAttribute(e, 15); //white

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

//displays student menu
void Customer::StudentMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(e, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t   STUDENT MENU\n\n";

	SetConsoleTextAttribute(e, 15); //white

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

//Non Faculty menu
void Customer::nonFacultyMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(e, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tNON - FACULTY MENU\n\n";

	SetConsoleTextAttribute(e, 15); //white

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

//Non Faculty Menu
int Customer::NFmainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {
		//clearing screen
		system("cls");

		SetConsoleTextAttribute(e, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\tNON - FACULTY MENU\n\n\n";

		SetConsoleTextAttribute(e, 15); //white

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

//Faculty menu
void Customer::FacultyMenu() {

	//decalring variables
	ifstream file("record.txt");
	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(e, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t     FACULTY MENU\n\n";

	SetConsoleTextAttribute(e, 15); //white

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

//Faculty Menu
int Customer::FmainMenu(int id) {

	//declaring variables
	int option;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(e, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t     FACULTY MENU\n\n\n";

		SetConsoleTextAttribute(e, 15); //white

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