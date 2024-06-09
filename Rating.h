#pragma once

#include <iostream>
using namespace std;

class Rating {

private:
	//data members
	int ratingID, menuID, customerID;
	double score;
	string comment;

public:
	//default
	Rating();

	//rates menut item
	void Rate(int menuID, int id, double Score, string message);


};

