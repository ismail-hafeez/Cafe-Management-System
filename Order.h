#pragma once

#include <iostream>
#include "Menu.h"
using namespace std;

class Order {

private:
	//data members
	int orderID, itemsOrdered, totalPrice;

public:
	//default
	Order();

	//adds item to cart
	void Additem();

	//displays cart
	void cart(Menu menu[], int index);

	//removes item from cart
	void RemoveItem(Menu cartArray[], int size);

	//checking out
	void checkout(Menu final[], int size);

	//proccesses payment
	void ProcessPayment(Menu arr[], int size, double total);

};

