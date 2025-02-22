#ifndef PERSON
#define PERSON
#include<iostream>
#include<string>
#include <vector>
#include<fstream>
#include <unistd.h>
#define SIZE 10
using namespace std;

class Person
{
    string name, phoneNo;
    public:
        // constructor
        Person () {}
        Person (string name, string phoneNo)
        {
            setName (name);
            setPhoneNo (phoneNo);
        }
        // setters
        void setName (string name)
        {
            this->name = name;
        }
        void setPhoneNo (string phoneNo)
        {
            this->phoneNo = phoneNo;
        }
        string getName () const
        {
        	return name;
		}
        // getter
		string getPhoneNo () const
        {
        	return phoneNo;
		}

        virtual void display () const = 0;
        friend void makeReservation();
};


class Flight
{
    protected:
        string flightId;   
        string Source, Destination;
        string time;
        int price;
        string airline;
    public:
        // constructors
        Flight () {}
        Flight (string source, string destination, string time, int price, string flightId) 
        {
            this->Source = source;
            this->Destination = destination;
            this->time = time;
            this->price = price;
            this->flightId = flightId;
        }
        // setters
        void setId (string id)
        {
            this->flightId = id;
        }
        void setCity (string city) 
        {
            this->Source = city;
        }
        void setDestination (string destination)
        {
            this->Destination = destination;
        }
        void setAirline (string airline)
        {
            this->airline = airline;
        }
        void setTime (string time)
        {
            this->time = time;
        }
        void setPrice (int price)
        {
            this->price = price;
        }
        // printing flight schedule
		void displaySchedule () const
        {
        	char c;
            cout << "\n\t FLIGHT\t| SOURCE      | DESTINATION     | AIRLINE\t  | TIME      | PRICE" << endl;
            cout << "\t_____________________________________________________________________________\n" << endl;
            ifstream in ("Flight Schedule.txt");
			while (!in.eof())
			{
				c = in.get(); 
				cout << c;
			}
        }
		    
        // getter
        string getFlightId () const
        {
        	return flightId;
	    }
        int getPrice ()
        {
            return price;
        }
        
        // stream operators
        friend istream& operator >> (istream& in , Flight& obj)
        {
            in >> obj.flightId;
            obj.Source="";
            obj.Destination="";
            obj.airline="";
            obj.time="";
            string dep,des,tim,air;
            in >> dep;
            while(dep != "-1")
            {
                obj.Source+=dep+" ";
                in >> dep;
            }

            in >> des;
            while(des != "-1")
            {
                obj.Destination+=des+" ";
                in >> des;
            }

            in >> air;
            while(air != "-1")
            {
                obj.airline+=air+" ";
                in >> air;
            }
            in >> tim;
            while(tim != "-1")
            {
                obj.time+=tim;
                in >> tim;
            }

            in >> obj.price;
            return in;
        }

        friend ostream& operator <<  (ostream& out ,const Flight &obj)
        {
            out <<"\n\t" << obj.flightId <<"\t|" << obj.Source << "\t|" <<obj.Destination<<"\t|"<<obj.airline<<"\t|"<<obj.time<<"\t| $"<<obj.price<<endl;
        }

        // it will search a particular flight no by its Id
		int  searchFlight (string id)
        {
            ifstream input ("newflights.txt");
            int count = 1;
            while (!input.eof())
            {
                Flight obj;
                cin >> obj;

                if(obj.getFlightId() == id)
                    return count;
                else 
                    count++;
            }
        }
};
        
class Admin : public Person
{
    int employeeId;
    Flight flight;
    public:
        // constructor
        Admin () {}
        Admin (int employeeId) : Person ()
        {
        	this->employeeId = employeeId;
        }
        // admin function adding flights (menu = 1)
        int AddFlight () 
        {
        	string ans;
            cout << "Do you want to enter the remaining flights: ";
            cin >> ans;
            if (ans == "Yes" || ans == "yes")
            {
            // it will add next flights from flight data.txt to flight schedule.txt and
            // then print the flight schedule file (which at the end has existing flights and added flights)
            ifstream in("Flight Data.txt");
            fstream file("Flight Schedule.txt", ios::out | ios::app);
            if (!in)
            {
            	"Error opening the file with Flight Data. Please wait while we try again.";
            	sleep(1);	cout << ".";	sleep(1);	cout << ".";
            	ifstream in("Flight Data.txt");
			}
			if(!file)
			{
            	cout << "Error opening the file with Flight Schedule. Please wait while we try again.";
            	sleep(1);	cout << ".";	sleep(1);	cout << ".";
            	fstream file("Flight Schedule.txt", ios::out | ios::app);
			}
			cout << "Adding flight(s)."; 
			sleep(1);   cout << ".";    sleep(1);    cout << ".\n";
            cout << "Flights added." << (char)251 << endl << "Here is the revised Flight Schedule." << endl;
            
            string line;
            	// get existing number of flights for seekg()
			ifstream ifin ("Flight Schedule.txt");
            ifin.seekg(0, ios::end);
            int existingFlights = ifin.tellg() / 76.1;
            ifin.close();
            in.seekg(76.1*existingFlights, ios::beg);            //76.1 is the number of bytes
			for (int i=existingFlights+1; i<(78.1)*2 && !in.eof(); i++)
            {
            	getline (in, line);
            	file << line << endl;
			}
            in.close();
            file.close();
            flight.displaySchedule();
    		}
    		else 
    			return 0;
    	}
        
        void viewAllPassengers ()
		{
			cout << endl;
			cout << "Code \tName \tPhone Number \t     CNIC \tAge    Departure       Destination    Service Class\t Seat\n";
			cout << "----------------------------------------------------------------------------------------------------------------" << endl;
			ifstream in ("Passenger Record.txt");
			while (!in.eof())
			{
				cout << (char)in.get();
			}
		}
		
		void display () const     
		{
            cout << "Name: " << getName() << endl << "Phone Number: " << getPhoneNo() << endl;
            cout << "Employee Id: " << employeeId << endl;
        }
};
#endif
