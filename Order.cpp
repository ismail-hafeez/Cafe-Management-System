
#include "Order.h"
#include "Filemanager.h"
#include "Menu.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);

//default
Order::Order() : orderID(0), itemsOrdered(0), totalPrice(0) { }

//adds item to cart
void Order::Additem() {

	//creating object
	Student student;
	Menu temp, menu[20];

	//setting
	temp.setAdminMenu(menu);

	//declaring variables
	int id, index;
	bool success = false;

	//displaying menu
	student.StudentMenu();

	cout << "\n\n\t\t\t\t\t\Add ITEM TO CART";
	cout << "\n\n\t\t\t\tItem ID: ";
	cin >> id;

	//checking if ID exists
	for (int i = 0; i < temp.getCount(); i++) {

		if (id == menu[i].getID()) {

			success = true;
			index = i;

			//clearing screen
			system("cls");

			SetConsoleTextAttribute(o, 6); //yellow

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Item ID: " << id << " Added to Cart";
			Sleep(1300);

			//calling cart
			cart(menu, index);
			
			
			break;
		}
	}
		

	//error if not exist
	if (!success) {

		system("cls");

		SetConsoleTextAttribute(o, 4); //yellow

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tERROR: ID NOT FOUND";
		Sleep(1300);

	}


}

//displays cart
void Order::cart(Menu menu[], int index) {

	//declaring variables
	int option;
	static int times = 0;
	bool cond;

	//temp array
	static Menu tempArr[10];

	//setting temp array
	tempArr[times].setID(menu[index].getID()); 
	tempArr[times].setName(menu[index].getName());
	tempArr[times].setPrice(menu[index].getPrice());
	
	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(o, 3); //blue

		//displaying
		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t\tCART\n\n";

		SetConsoleTextAttribute(o, 15); //white

		//showing cart
		for (int i = 0; i < times + 1; i++) {

			//not reading null
			if (tempArr[i].getID() == 0 && tempArr[i].getName() == " " && tempArr[i].getPrice() == 0)
				continue;

			cout << "\t\t\t\t\tItem ID: " << tempArr[i].getID() << "\n\t\t\t\t\tName: " << tempArr[i].getName() << "\n\t\t\t\t\tPrice: " << tempArr[i].getPrice();
			cout << endl << endl;
		}

		cout << "\n\n\n\n\n\t\t\t\t\t1. Check Out\n\t\t\t\t\t2. Add More\n\t\t\t\t\t3. Remove\n\t\t\t\t\tEnter: ";
		cin >> option;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (option < 1 || option > 3 || cond);
	

	//incrementing times
	times++;

	//determining choice
	switch (option) {
		//check out 
		case 1: checkout(tempArr, times); break;
		//adds more
		case 2: Additem(); break;
		//removes item
		case 3: RemoveItem(tempArr, times); break;
	}
	    
}

//removes item from cart
void Order::RemoveItem(Menu cartArray[], int size) {

	//declaring variables
	int removeID;
	bool success = false;
	bool cond;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(o, 3); //blue

		//displaying
		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t\tCART\n\n";

		SetConsoleTextAttribute(o, 15); //white

		//displaying cart
		for (int i = 0; i < size; i++) {

			//not reading null
			if (cartArray[i].getID() == 0 && cartArray[i].getName() == " " && cartArray[i].getPrice() == 0)
				continue;

			cout << "\t\t\t\t\tItem ID: " << cartArray[i].getID() << "\n\t\t\t\t\tName: " << cartArray[i].getName() << "\n\t\t\t\t\tPrice: " << cartArray[i].getPrice();
			cout << endl << endl;
		}

		cout << "\n\n\n\n\n\t\t\t\t\tEnter ID: ";
		cin >> removeID;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');

	} while (cond);

	//checking if ID exists
	for (int i = 0; i < size; i++) {

		if (removeID == cartArray[i].getID()) {

			//removing
			cartArray[i].setID(0);
			cartArray[i].setName(" ");
			cartArray[i].setPrice(0);

			system("cls");

			SetConsoleTextAttribute(o, 6); //yellow

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tREMOVING ITEM ID: " << removeID << " FROM CART";
			Sleep(1300);

			success = true;
			break;
		}
	}

	if (success)
		cart(cartArray, size);

	//error if not exist
	else if (!success) {

		system("cls");

		SetConsoleTextAttribute(o, 4); //red

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tERROR: ID NOT FOUND";
		Sleep(1300);

	}



}

//checking out
void Order::checkout(Menu final[], int size) {

	//declaring variables
	double total = 0;
	int choice;
	bool cond;

	srand(time(NULL));

	//setting order id
	orderID = rand() % 5000;

	do {

		//clearing screen
		system("cls");

		SetConsoleTextAttribute(o, 3); //blue

		//displaying
		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t\tCHECK OUT\n\n";

		SetConsoleTextAttribute(o, 15); //white

		cout << "\t\t\t\t\tOrder ID: " << orderID << " Details\n\n";

		//displaying order
		for (int i = 0; i < size + 1; i++) {

			//not reading null
			if (final[i].getID() == 0 && final[i].getName() == " " && final[i].getPrice() == 0)
				continue;

			cout << "\t\t\t\t\tItem ID: " << final[i].getID() << "\n\t\t\t\t\tName: " << final[i].getName() << "\n\t\t\t\t\tPrice: " << final[i].getPrice();
			cout << endl << endl;

			//adding total
			total += final[i].getPrice();
		}

		//displaying total bill 
		cout << "\n\t\t\t\t\tTotal : " << total << endl;

		//user input 
		cout << "\n\n\t\t\t\t\t1. Proceed to Payment\n\t\t\t\t\t2. Cancel Order\n\t\t\t\t\tEnter: ";
		cin >> choice;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');


	} while (choice > 1 || choice > 2 || cond);

	//determining choice
	switch (choice) {
		//payment
		case 1: ProcessPayment(final, size, total);  break;

		//cancelling order
		case 2: {

			//clearing screen
			system("cls");

			SetConsoleTextAttribute(o, 6); //yellow

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     CANCELLING ORDER ID: " << orderID;
			Sleep(1300);	
	
	
		} break;
	}



}

//proccesses payment
void Order::ProcessPayment(Menu arr[], int size, double total) {
	
	//declaring variables
	double money, change;
	bool cond;

	//user input
	do {
		//clearing screen
		system("cls");

		SetConsoleTextAttribute(o, 3); //blue

		//displaying
		cout << "\n\n\n\t\t\t\t\t*** Welcome to Cafe Fast Islamabad ***\n\n\n";
		cout << "\t\t\t\t\t\t\tPROCESS PAYMENT\n\n";

		SetConsoleTextAttribute(o, 15); //white

		//displaying total bill 
		cout << "\n\t\t\t\t\tTotal Rs:  " << total << endl;

		cout << "\n\t\t\t\t\tEnter Money: ";
		cin >> money;

		cond = cin.fail();

		cin.clear();
		cin.ignore(INT_MAX, '\n');


	} while (money < total || cond);

	//clearing screen
	system("cls");

	SetConsoleTextAttribute(o, 6); //yellow

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tGENERATING RECIEPT FOR ORDER ID: " << orderID;
	Sleep(1300);

	//creating object
	Filemanager save;

	//calculating change
	change = money - total;

	//saving receipt
	save.saveReceipt(arr, size, total, orderID, money, change);

	//saving in total earnings
	save.totalPayments(orderID, total);

	//reading receipt
	save.readReceipt();


}