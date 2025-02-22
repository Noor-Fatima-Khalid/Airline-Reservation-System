#ifndef SEAT
#define SEAT
#include<iostream>
#include<fstream>
using namespace std;

class Seats
{
    static int seatsTotal;
    static int seatsFilled;
    public:
		// constructor
        Seats () {}
        bool isAvailable (int seatNo) const
        {
            return seatsFilled < seatsTotal;
        }
        
        Seats operator ++ (int)
        {
        	Seats temp(*this);
        	seatsFilled++;
        	return temp;
		}
		
		void setSeat (int seatNo)
		{
			seatsFilled = seatNo;
		}
        // it show the occupied and total number of seats
        void showStatus () const
        {
        	ifstream in ("Passenger Record.txt");
    		in.seekg (0, ios::end);
			int size = in.tellg ();
			in.seekg (0, ios::beg); 
			int seatsFilled = size / 77.1;
			in.close();
            cout << "Seats Occupied: " << seatsFilled << endl;
        	cout << "Seats Available: " << seatsTotal - seatsFilled << endl;
		}
		
		friend ostream& operator << (ostream &out, const Seats s)
		{
			cout << s.seatsFilled << endl;
		}
};
int Seats::seatsFilled = 0;
int Seats::seatsTotal = 50;
#endif