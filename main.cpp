
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "User.h"
#include "Order.h"
#include "Administrator.h"
#include "Menu.h"
#include "Customer.h"
#include "Filemanager.h"
#include "Student.h"
#include "NonFaculty.h"
#include "Faculty.h"
#include "Staff.h"

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//initializing static variables
int Menu::adminCount = 12;

int main() {

	//declaring variables
	int userMenu, adminMenu, staffMenu;
	bool logout = false;

	//creating object
	User user;
	Menu temp;
	Filemanager saveFile;

	//clearing screen
	system("cls");

	//Main Menu
	user.userMain();

	//calling register function
	user.Register();

	//calling login function until correct details
	do {
		userMenu = user.Login();
	}
	while (userMenu == 0);
	
	//saving user details
	switch (userMenu) {
		case 1: saveFile.saveUser(user.getUserame(), user.getPassword(), 1, user.getID()); break;
		case 2: saveFile.saveUser(user.getUserame(), user.getPassword(), 2, user.getID()); break;
		case 3: saveFile.saveUser(user.getUserame(), user.getPassword(), 3, user.getID()); break;
	}
	
	//which menu to be called
	switch (userMenu) {
		//Admin
		case 1: {

			//creating object
			Administrator admin;

			//will terminate when logged out
			while (!logout) {

				//calling main menu
				do {
					adminMenu = admin.mainMenu(user.getID());
				} while (adminMenu < 1 || adminMenu > 10);

				switch (adminMenu) {
					//view menu
					case 1: admin.viewMenu(); break;
					//add item
					case 2: {

						if(temp.getCount() < 20)
							admin.AddMenuItem();

						else {

							system("cls");

							SetConsoleTextAttribute(h, 6); //yellow

							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNO MORE INVENTORY CAN BE ADDED";
							Sleep(1300);

						}
							
					
					}break;
					//remove item
					case 3: admin.RemoveItem(); break;
					//rate menu
					case 4: admin.rateMenu(user.getID()); break;
					//displays order history
					case 5: saveFile.readReceipt(); break;
					//send messages
					case 6: admin.AddNotification(); break;
					//view user details
					case 7: admin.viewUser(); break;
					//views ratings from file
					case 8: admin.DisplayRating(); break;
					//displays total payments
					case 9: saveFile.ReadtotalPayments(); break;
					//logs out
					case 10: user.logout(); logout = true; break;

				} //end inner admin switch
			}
		} break;

		//staff
		case 2: { 
			
			//creating object
			Staff staff;
			Administrator admin;

			//will terminate when logged out
			while (!logout) {

				//calling main menu
				do {
					staffMenu = staff.mainMenu(user.getID());
				} while (staffMenu < 1 || staffMenu > 6);

				switch (staffMenu) {

					//displays main menu
					case 1: admin.viewMenu(); break;
					//processes payment
					case 2: saveFile.readReceipt(); break;
					//messages admin
					case 3: staff.messageAdmin(); break;
					//adds item
					case 4: {

						if (temp.getCount() < 20)
							admin.AddMenuItem();

						else {

							system("cls");

							SetConsoleTextAttribute(h, 6); //yellow

							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tNO MORE INVENTORY CAN BE ADDED";
							Sleep(1300);

						}


					} break;
					//remove item
					case 5: admin.RemoveItem(); break;
					//logs out
					case 6: user.logout(); logout = true; break;
				}
			}
		
		} break;

		//customer
		case 3: {

			//creating object
			Customer customer;
			Administrator admin;

			//determining type of customer
			customer.chooseCustomer();

			//will terminate when logged out
			while (!logout) {

				//showing different menus to different customers
				switch (customer.getType()) {
					//Students
					case 1: {

						//applying polymorphism
						Student student;
						Order order;
						Customer* ptr = &student;

						//calling menu function
						int stdMenu = ptr->StudentmainMenu(user.getID());

						switch (stdMenu) {
							//displays menu
							case 1: ptr->StudentMenu(); break;
							//displays order history
							case 2: saveFile.readReceipt(); break;
							//displays notifications
							case 3: saveFile.ReadNotification(); break;
							//places order
							case 4: order.Additem(); break;
							//rates menu items
							case 5: admin.rateMenu(user.getID()); break;
							//logs out
							case 6: ptr->logout(); logout = true; break;
						} 
					} break;

					//Faculty
					case 2: {
					
						//applying polymorphism
						Faculty faculty;
						Student student;
						NonFaculty nFaculty;
						Order order;
						Customer* ptrS = &student;
						Customer* ptrNF = &nFaculty;
						Customer* ptrF = &faculty;

						//calling menu function
						int FMenu = ptrF->FmainMenu(user.getID());

						switch (FMenu) {
							//displays Student menu
							case 1: ptrS->StudentMenu(); break;
							//displays Non-Faculty menu
							case 2: ptrNF->nonFacultyMenu(); break;
							//displays notifications
							case 3: saveFile.ReadNotification(); break;
							//places order
							case 4: order.Additem(); break;
							//rates menu items
							case 5: admin.rateMenu(user.getID()); break;
							//vies order history
							case 6: saveFile.readReceipt(); break;
							//logs out
							case 7: ptrF->logout(); logout = true; break;
						}					
					
					} break;

					//Non - Faculty
					case 3: {

						//applying polymorphism
						NonFaculty nFaculty;
						Order order;
						Customer* ptr = &nFaculty;

						//calling menu funtion
						int NFMenu = ptr->NFmainMenu(user.getID());

						switch (NFMenu) {
							//displays menu
							case 1: ptr->nonFacultyMenu(); break;
							//displays order history
							case 2: saveFile.readReceipt(); break;
							//displays notifications
							case 3: saveFile.ReadNotification(); break;
							//places order
							case 4: order.Additem(); break;
							//rates menu items
							case 5: admin.rateMenu(user.getID()); break;
							//logs out
							case 6: ptr->logout(); logout = true; break;
						}

					} break;


				} //end inner switch

			} //end while		
		
		} break;

	}
	
	
	//clearing screen
	system("cls");

	SetConsoleTextAttribute(h, 15); //white


	return 0;
}