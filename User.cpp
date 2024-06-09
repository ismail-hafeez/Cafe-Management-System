
#include "User.h"
#include "Filemanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <limits>
#include <cstdlib>
using namespace std;

HANDLE d = GetStdHandle(STD_OUTPUT_HANDLE);

//default constructor
User::User() : userID(0), userType(0), userName(" "), password(" ") { }

//parameterized constructor
User::User(int user_ID, int user_type, string user_name, string Password) {

	//initializing
	userID = user_ID;
	userType = user_type;
	userName = user_name;
	password = Password;

}

//main menu
void User::userMain() {

	//declaring variables
	char box = 219;
	char sbox = 220;
	string press;

	SetConsoleTextAttribute(d, 3); // blue;

	//displaying menu
	cout << "\n\n\n\n\t\t\t\t" << box << box << box << box << box << box << box << box << "\t" << box << box << box << box << box << box << box << box << "\t" << box << box << box << box << box << box << box << box << "\t" << box << box << box << box << box << box << box << box << box << endl;
	cout << "\t\t\t\t" << box << box << box << "\t\t" << box << box << "    " << box << box << "\t" << box << box << box << "\t\t" << box << box << box << sbox << sbox << sbox << endl;
	cout << "\t\t\t\t" << box << box << box << "\t\t" << box << box << box << box << box << box << box << box << "\t" << box << box << box << box << box << "\t\t" << box << box << box << endl;
	cout << "\t\t\t\t" << box << box << box << box << box << box << box << box << "\t" << box << box << "    " << box << box << "\t" << box << box << box << "\t\t" << box << box << box << box << box << box << box << box << box << endl;

	cout << "\n\n\t\t\t\t    M  A  N  A  G  E  M  E  N  T     S  Y  S  T  E  M";

	SetConsoleTextAttribute(d, 15); // white

	//user input
	cout << "\n\n\n\n\t\t\t\t\t\tPress Any Key to Continue: ";
	getline(cin, press);


}

//registering
void User::Register() {

	//declaring variables
	int option;
	bool cond;

	srand(time(NULL));

	//random 4 digit number to ID
	userID = rand()%5000;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(d, 3); //blue

		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t      REGISTER\n\n\n";

		SetConsoleTextAttribute(d, 15); //white

		cout << "\n\t\t\t\t\tUser ID: " << userID << endl;

		cout << "\n\t\t\t\t\t1. Admin\n\t\t\t\t\t2. Staff\n\t\t\t\t\t3. Customer\n\n\t\t\t\t\tEnter: ";

		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	
	} while (option < 1 || option > 3 || cond);

	//option between users
	switch (option) {
		case 1: userType = 1; break;
		case 2: userType = 2; break;
		case 3: userType = 3; break;
	}

	//user input
	cout << "\n\t\t\t\t\tUser Name: ";
	getline(cin, userName);

	cout << "\t\t\t\t\tPassword: ";
	getline(cin, password);

	//clearing screen
	system("cls");

	SetConsoleTextAttribute(d, 6); //yellow

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tID " << userID << " REGISTERED";
	Sleep(1300);


}

//login
int User::Login() {

	//clearing screen
	system("cls");

	string user_name, pass_word;
	int count = 0;

	SetConsoleTextAttribute(d, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t\tLOGIN\n\n\n";

	SetConsoleTextAttribute(d, 15); //white

	cout << "\n\t\t\t\t\tUser ID: " << userID << endl;

	//user input
	cout << "\n\t\t\t\t\tUser Name: ";
	getline(cin, user_name);

	cout << "\t\t\t\t\tPassword: ";
	getline(cin, pass_word);

	//checking validity
	if (user_name == userName && password == pass_word)
		count++;

	if (count == 1) {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(d, 6); //yellow

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOGIN SUCCESSFULL";
		Sleep(1300);

		return userType;

	}

	else {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(d, 4); //red

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tINCORRECT DETAILS ... REDIRECTING";
		Sleep(1200);

		//recalling function
		return 0;
	}

}

//gets ID
int User::getID() const {
	return userID;
}

//logout
void User::logout() {

	system("cls");

	SetConsoleTextAttribute(d, 6); //yellow

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOGGING OUT... ";
	Sleep(1600);
}

string User::getUserame() const {
	return userName;
}

string User::getPassword() const {
	return password;
}

