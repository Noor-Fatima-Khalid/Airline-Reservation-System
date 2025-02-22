#ifndef RESERVATION
#define RESERVATION
#include"Person.cpp"
#include"Passenger.cpp"
#include"Payment.cpp"
#include"Seat.cpp"
#include<vector>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
using namespace std;

class Reservation
{
	protected:
		string name, phoneNo, age, city, destination, seat, serviceClass, CNIC;
		string myFlightId;
		vector<Passenger> passengers;
		Flight flight;
		Seats seats;
		Payment payment;
    public:
		// constructor
        Reservation ()
		{ 
			srand(time(0));
		}
    	
		// makes resrvation by storing the record in a vector and file (Passenger Record.txt). 
		// steps involve taking input from user and storing it in file side by side, then making payment and 
		// allocation of seats. It also prints the passenger's details. User can also make more reservations 
		// in a single go, for this, I have used vector.
    	int calculatedPrice;
    	int numPassengers;
        vector<Passenger> makeReservation ()
        {
        	ofstream out ("Passenger Record.txt", ios::out | ios::app);
        	
        	cout << "Enter the number of passengers: ";
        	cin >> numPassengers;

	        passengers.resize(numPassengers);
	        // taking input
		    for (int i = 0; i < numPassengers; i++)
        	{
        		int code = rand () % 3000 + 1000;
	        	cout << "\nYour reservation code is " << code << endl;
    	    	cout << "Remember this code." << endl;
        		out << setw(3) << code << "\t";
        		
        	    cout << "Name: \t";
            	cin >> name;
				passengers[i].setName(name);
            	out << setw(7) << left << passengers[i].getName() << "\t";
            
            	try{
					cout << "Phone Number: ";                         
					cin >> phoneNo;
						if (phoneNo.length() != 11)
						throw (phoneNo);
					passengers[i].setPhoneNo (phoneNo);			
					out << setw(13) << left << passengers[i].getPhoneNo() << "\t";
				}
				catch(string){
					while (phoneNo.length() != 11)
					{
						cout << "Enter your valid 11 digit phone number: ";
						cin  >> phoneNo;
					}
					passengers[i].setPhoneNo (phoneNo);			
					out << setw(13) << left << passengers[i].getPhoneNo() << "\t";
				}
				
           		try{
					cout << "CNIC: \t";                               
					cin >> CNIC;
					if (CNIC.length() != 13)
						throw (CNIC);
					passengers[i].setCNIC(CNIC);
					out << setw(14) << left << passengers[i].getCNIC() << "\t";
				}catch(string){
					while (CNIC.length() != 13)
					{
						cout << "Enter your valid 13 digit CNIC: ";
						cin  >> CNIC;
					}
					passengers[i].setCNIC(CNIC);
					out << setw(14) << left << passengers[i].getCNIC() << "\t";
				}
				
	            cout << "Age: \t";                                
				cin  >> age;
				passengers[i].setAge(age);
				out << setw(4) << left << passengers[i].getAge() << "\t";
											
    	        cout << "From: \t";                               
				cin  >> city;
				passengers[i].setCity(city);				
				out << setw(9) << left << passengers[i].getCity() << "    \t";
        	    
				cout << "To: \t";                                 
				cin  >> destination;
				passengers[i].setDestination(destination);
				out << setw(9) << left << passengers[i].getDestination() << "    \t";
				
            	cout << "Travel Class \n business ($60) \t economy($50): ";    
				cin  >> serviceClass;
				if (serviceClass == "business" || serviceClass == "Business")
					calculatedPrice += 60;
				else 
					calculatedPrice += 50;
				passengers[i].setServiceClass(serviceClass);
				out << setw(9) << left << passengers[i].getServiceClass() << " \t";
            	
				cout << "Seat preference (window-(adds 10$ extra charges) / aisle): ";     
				cin  >> seat;
				if (seat == "window" || seat == "Window")
					calculatedPrice += 10;
				passengers[i].setSeat(seat);				
				out << setw(7) << left << passengers[i].getSeat() << "\n";
			}
        	out << "\n";
        	out.close();

			// displaying information for each passenger
			for (int i = 0; i < numPassengers; ++i)
    	    {
	            cout << "\nPassenger " << i + 1 << " details:\n";
	            cout << "____________________\n";
    	        passengers[i].display();
    	        cout << "Age:\t\t" << age << endl;
    	        cout << "From:\t\t" << city << endl;
    	        cout << "To:\t\t" << destination << endl;
    	        cout << "Travel Class:\t" << serviceClass << endl;
    	        cout << "Seat Type:\t" << seat << endl;
    	        
				// seats fetch
	        	ifstream in ("Passenger Record.txt");
    	    	in.seekg (0, ios::end);
				int size = in.tellg ();
				in.seekg (0, ios::beg); 
				int seatNo = size / 77.1;
				seats.setSeat(seatNo-i);
				in.close();
				
    	        cout << "Seat Number:\t" << seats << endl;
    	        cout << "----------------------" << endl;
        	}
        	// payment implementation
        	cout << "Payment Details: " << endl;
			string cardNo;
			cout << "Card Number: ";
			cin >> cardNo;
			if (cardNo.length() == 16)
				payment.payment(cardNo, true);
			while (cardNo.length() != 16)
			{
				payment.setStatus(false);
				cout << "Enter 16 digit valid card number: ";
				cin  >> cardNo;
			}
			
			cout << "Reservation has successfully been made. " << (char)251 << endl;
			seats++;
			return passengers;
	    }
	
		// this will delete the reservation from file
		void cancelReservation () 
        {
        	string choice;
        	int lineRemove = searchPassenger(); 
        	if(lineRemove != -1)				// means passenger has been found
        	{
        		cout << "\nAre you sure you want to cancel your reservation?" << endl;
        		cin >> choice;
        		if (choice == "Yes" || choice == "yes")
        		{
					int i = 1;							// i is to spot the line that is to be deleted
					string line;
        			ifstream in ("Passenger Record.txt");
					ofstream temp ("temp.txt");
					while (getline(in, line))
					{
						if (i != lineRemove)
							temp << line << endl;
						i++;
					}
					in.close();
    				temp.close();
				    // Removing the original file	
    				remove("Passenger Record.txt");
				    // Renaming the temporary file to the original file
				    rename("temp.txt", "Passenger Record.txt");
				    cout << "Reservation canceled successfully." << (char)251 << endl;
				}	
        		else if (choice == "No" || choice == "no")
        		{
        			cout << "Reservation retained." << endl;
				}
        	}
		}
		
		// this will search for the passenger by his reservation code and print his record
		int searchPassenger () 
		{
		    bool found = false;
    		int code;
    		cout << "Enter your reservation code: ";
    		cin >> code;

		    ifstream in("Passenger Record.txt");
		    if (!in) 
			{
        		cout << "Error opening file." << endl;
    		    return false;
    		}
    		
		    int currentCode, i=1;
    		string line;
    		while (in >> currentCode) 
			{
    		    getline(in >> ws, line); 					// Reading the rest of the line with spaces
        		if (currentCode == code) 
				{
		            cout << "Reservation found.\n";
		            cout << "Code \tName \tPhone Number \t     CNIC \tAge    Departure       Destination    Service Class\tSeat\n";
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					cout << currentCode << "\t" << line << endl;
        		    in.close();
            		return i;
        		}
				i++;
		    }

    		cout << "Reservation not found." << endl;
    		in.close();
    		return -1;
		}
};
#endif
