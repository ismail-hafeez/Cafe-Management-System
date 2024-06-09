#pragma once
#include <iostream>
using namespace std;

class Menu {

private:
	//data members
	int itemID, quantity;
	string itemName, itemDescription;
	double price;

	//static
	static int adminCount;

public:
	//default
	Menu();

	//constructor
	Menu(int id, int q, string n, string d, double p);

	//setters
	void setID(int id);
	void setQuantity(int q);
	void setName(string n);
	void setDescription(string d);
	void setPrice(double p);

	//sets all values
	void setValues(Menu menu[], int size, int id, int q, string n, string d, double p);

	//sets values with 5 parameters
	void setVal(int id, int q, string n, string d, double p);

	//sets for ADMIN
	void setAdminMenu(Menu menu[]);

	////sets for Students
	void setStudentMenu(Menu menu[]);

	//getters
	int getID() const;
	int getQuantity() const;
	string getName() const;
	string getDescription() const;
	double getPrice() const;

	//increments static count
	void incCount();

	//gets count
	int getCount();






	//updates stock

};

