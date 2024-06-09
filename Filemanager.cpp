
#include "Filemanager.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

HANDLE f = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

//saves rating to text file
void Filemanager::saveRating(int menuID, int userid, double Score, string message) {

	ofstream file("menuRating.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\tUser ID: " << userid << "\n\t\t\t\tItem ID: " << menuID << "\n\t\t\t\tScore: " << Score << "/10\n\t\t\t\tComment: " << message << "\n";

	file.close();

}

//saves admin v staff messages
void Filemanager::saveMessage(string message) {

	ofstream file("adminVstaff.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\t<Admin> " << message;

	file.close();

}

//saves staff v admin messages
void Filemanager::saveMessageStaff(string message) {

	ofstream file("adminVstaff.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\t<Staff> " << message;

	file.close();

}

//saves admin v user messages
void Filemanager::saveNotification(string message) {

	ofstream file("adminVcustomer.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\t\t*** MESSAGE FROM THE ADMIN ***\n\n\t\t\t\t\t" << message << "\n";

	file.close();


}

//saves user details 
void Filemanager::saveUser(string userName, string password, int type, int id) {

	//declaring variables
	string user_type;

	//opening file
	ofstream file("userdetails.txt", ios::app);

	//error if file not opened
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	//determining type
	switch (type) {
		case 1: user_type = "Administrator"; break;
		case 2: user_type = "Cafe Staff"; break;
		case 3: user_type = "Customer"; break;
	}

	//writing to file
	file << "\n\t\t\t\t" << user_type << " ID: " << id << "\n\t\t\t\tUsername: " << userName << "\n\t\t\t\tPassword: " << password << "\n";

	//closing file
	file.close();


}

//update menu
void Filemanager::ReadMenu(Menu menu[]) {

	Menu temp;

	ofstream file("stdmenu.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	for (int i = 0; i < 12; i++) {

		file << "\n" << setw(18) << menu[i].getID() << setw(15) << menu[i].getQuantity() << setw(25) << menu[i].getName() << setw(22) << menu[i].getDescription() << setw(21) << menu[i].getPrice();

	}

	
	file.close();


}

//save receipt for order
void Filemanager::saveReceipt(Menu order[], int size, double orderTotal, int orderID, double moneyGiven, double change) {

	ofstream file("receipt.txt", ios::app); 

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\t\tOrder ID: " << orderID << "\n";

	//entering order
	for (int i = 0; i < size; i++) {

		if (order[i].getID() == 0 && order[i].getName() == " " && order[i].getPrice() == 0)
			continue;

		file << "\n\t\t\t\t\tItem Id: " << order[i].getID() << "\n\t\t\t\t\tName: " << order[i].getName() << "\n\t\t\t\t\tPrice: " << order[i].getPrice() << "\n\n";

	}

	file << "\n\t\t\t\t\tTotal: " << orderTotal << "\n\t\t\t\t\tPaid: " << moneyGiven << "\n\t\t\t\t\tChange: " << change;

	file.close();

}

//reads receipt
void Filemanager::readReceipt() {

	ifstream file("receipt.txt");

	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(f, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\t   RECEIPT SECTION\n\n";

	SetConsoleTextAttribute(f, 15); //white

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

//saving in total earnings
void Filemanager::totalPayments(int orderID, int total) {

	ofstream file("total.txt", ios::app);

	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	file << "\n\t\t\t\t\tOrder ID: " << orderID << "\n\t\t\t\t\tTotal: " << total << "\n\n";


	file.close();

}

//reads total earning
void Filemanager::ReadtotalPayments() {

	ifstream file("total.txt");

	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(f, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tTOTAL EARNINGS SECTION\n\n";

	SetConsoleTextAttribute(f, 15); //white

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

//reads notifications
void Filemanager::ReadNotification() {

	ifstream file("adminVcustomer.txt");

	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	system("cls");

	SetConsoleTextAttribute(f, 3); //blue

	cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
	cout << "\t\t\t\t\t\tNOTIFICATION SECTION\n\n";

	SetConsoleTextAttribute(f, 15); //white

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

//reads messages bw admin and staff
void Filemanager::ReadMessageAdminStaff() {

	ifstream file("adminVstaff.txt");

	char ch;
	string press;

	//check
	if (!file.is_open()) {
		cout << "Error opening the file.\n";
	}

	SetConsoleTextAttribute(f, 15); //white

	// Read characters until the end of the file is reached	
	while (file.get(ch)) {
		cout << ch;
	}

	//closing file
	file.close();

}