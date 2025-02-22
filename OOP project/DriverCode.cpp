#include<iostream>
#include<conio.h>
#include<windows.h>
#include "Person.cpp"
#include "menu.cpp"
#include"Reservation.cpp"
#include"Seat.cpp"
using namespace std;

int main()
{
	short mode;
	cout << "1) Dark Mode			2) Light Mode" << endl;
	cin >> mode;
	if (mode == 2)
		system("color E0");
	system("cls");
	
    int role;
    roles:
    cout << "Are you \n 1) Passenger \t 2) Admin \n";
    cin >> role;
    if (role == 2)
    {
    	mainmenu:
    	int choice;
        Admin admin;
        menuAdmin();
        cout << "Choose an option: ";				
		cin >> choice;
        if (choice == 1)
		{
		    admin.AddFlight();
		    cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto mainmenu;
		}
    	else if (choice == 2)	
		{
			admin.viewAllPassengers();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto mainmenu;
		}
		else if (choice == 3)
		{
			Seats seat;
			seat.showStatus();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto mainmenu;
		}
    	else if (choice == 4)
		{	
			cout << "Thank you for visiting our app! Bye!" << endl;
			return 0;
		}
		else
		{
			system("cls");
		    cout << "\n\n\n\t\t\t\t\t   Wrong Input" << endl;
		    cout << "\t\t Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto mainmenu;
		}
	}
    
	else if (role == 1)
    {
    	Pmainmenu:
    	Passenger myPassenger;
    	menuPassenger();
   		
   		Reservation form;
   		int choice;
   		cout << "Choose an option: ";				cin >> choice;
        if (choice == 1)
		{
			Flight f1;
        	f1.displaySchedule();
        	cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}
    	else if (choice == 2)
    	{
			form.makeReservation();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}

    	else if (choice == 3)
		{
			form.cancelReservation();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}
		else if (choice == 4)
		{
			int search = form.searchPassenger();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}
		else if (choice == 5)
		{
			Seats seat;
			seat.showStatus();
			cout << "Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}
		
		if (choice == 6)
		{
			cout << "Thank you for visiting our app! Bye!" << endl;
			return 0;
		}
		else
		{
			system("cls");
		    cout << "\n\n\n\t\t\t\t\t   Wrong Input" << endl;
		    cout << "\t\t Press any key to go back to menu..." << endl;
			getch();
			system("cls");
    		goto Pmainmenu;
		}
	}
	return 0;
}
