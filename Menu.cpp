
#include "Menu.h"
#include "Filemanager.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);

//default
Menu::Menu() : itemID(0), quantity(0), itemName(" "), itemDescription(" "), price(0.0) { }

//constructor
Menu::Menu(int id, int q, string n, string d, double p) : itemID(id), quantity(q), itemName(n), itemDescription(d), price(p) { }

//setters
void Menu::setID(int id) {
	itemID = id;
}
void Menu::setQuantity(int q) {
	quantity = q;
}
void Menu::setName(string n) {
	itemName = n;
}
void Menu::setDescription(string d) {
	itemDescription = d;
}
void Menu::setPrice(double p) {
	price = p;
}

//sets values
void Menu::setValues(Menu menu[], int size, int id, int q, string n, string d, double p) {
	
	//setting ID
	menu[size].setID(id);

	//setting Quantity
	menu[size].setQuantity(q);

	//setting name
	menu[size].setName(n);

	//setting description
	menu[size].setDescription(d);

	//setting price
	menu[size].setPrice(p);

	Filemanager save;


}

//sets values with 5 parameters
void Menu::setVal(int id, int q, string n, string d, double p) {
	itemID = id;
	quantity = q;
	itemName = n;
	itemDescription = d;
	price = p;
}

//getters
int Menu::getID() const {
	return itemID;
}
int Menu::getQuantity() const {
	return quantity;
}
string Menu::getName() const {
	return itemName;
}
string Menu::getDescription() const {
	return itemDescription;
}
double Menu::getPrice() const {
	return price;
}

//sets for ADMIN
void Menu::setAdminMenu(Menu menu[]) {

	//setting values
	menu[0].setVal(100, 5, "Prince", "Biscuits", 40);
	menu[1].setVal(321, 20, "Oreo", "Biscuits", 35);
	menu[2].setVal(123, 8, "Rio", "Biscuits", 40);
	menu[3].setVal(156, 10, "Lays", "Chips", 60);
	menu[4].setVal(176, 12, "Kurleez", "Chips", 50);
	menu[5].setVal(187, 20, "Chettos", "Chips", 30);
	menu[6].setVal(231, 5, "Pepsi", "Drink", 70);
	menu[7].setVal(132, 15, "Gourmet", "Drink", 70);
	menu[8].setVal(213, 15, "Biryani", "Snack", 200);
	menu[9].setVal(444, 15, "Roll Paratha", "Snack", 200);
	menu[10].setVal(542, 15, "Macaroni", "Snack", 180);
	menu[11].setVal(786, 15, "Samosa Chat", "Snack", 100);

}

//sets for Students
void Menu::setStudentMenu(Menu menu[]) {

	//setting values
	menu[0].setVal(100, 5, "Prince", "Biscuits", 40);
	menu[1].setVal(123, 8, "Rio", "Biscuits", 40);
	menu[2].setVal(156, 10, "Lays", "Chips", 60);
	menu[3].setVal(176, 12, "Kurleez", "Chips", 50);
	menu[4].setVal(187, 20, "Chettos", "Chips", 30);
	menu[5].setVal(231, 5, "Pepsi", "Drink", 70);
	menu[6].setVal(132, 15, "Gourmet", "Drink", 70);
	menu[7].setVal(213, 15, "Biryani", "Snack", 200);
	menu[8].setVal(444, 15, "Roll Paratha", "Snack", 200);
	menu[9].setVal(786, 15, "Samosa Chat", "Snack", 100);

}

//increments static count
void Menu::incCount() {
	adminCount++;
}

//gets count
int Menu::getCount() {
	return adminCount;
}


