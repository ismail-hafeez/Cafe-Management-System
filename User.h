#pragma once
#include <iostream>
using namespace std;

class User {

private:
	//data members
	int userID, userType;
	string userName, password;

public:
	//default constructor
	User();

	//parameterized constructor
	User(int user_ID, int user_type, string user_name, string Password);

	//main menu
	void userMain();

	//register
	void Register();

	//login
	int Login();

	//logout
	void logout();

	//getter
	int getID() const;

	string getUserame() const;
	
	string getPassword() const;


};

