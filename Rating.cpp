
#include "Rating.h"
#include "Filemanager.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE r = GetStdHandle(STD_OUTPUT_HANDLE);


//default
Rating::Rating() : ratingID(0), menuID(0), customerID(0), score(0.0), comment(" ") { }

//rates menut item
void Rating::Rate(int menuID, int id, double Score, string message) {

	//creating object
	Filemanager save;

	//saving to file
	save.saveRating(menuID, id, Score, message);



}