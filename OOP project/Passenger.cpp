#ifndef PASSENGER
#define PASSENGER
#include"Person.cpp"

class Passenger : public Person
{
	string age, city, destination, seat, serviceClass;			//seat is either window or aisle
    string CNIC;
    public:
		Passenger () {}
        Passenger (string name, string phoneNo, string CNIC, string age) : Person (name, phoneNo)
        {
            setCNIC(CNIC);
            setAge(age);
        }
        
        void setData (string name, string phoneNo, string CNIC, string age)
        {
            setName(name);
            setPhoneNo(phoneNo);
            setCNIC(CNIC);
            setAge(age);
        }
        void setCNIC (string CNIC)
        {
            this->CNIC = CNIC;
        }
        void setAge (string age)
        {
            this->age = age;
        }
        void setCity (string city) 
        {
            this->city = city;
        }
        void setDestination (string destination)
        {
            this->destination = destination;
        }
        void setSeat (string seat)
        {
            this->seat = seat;
        }
        void setServiceClass(string serviceClass)
        {
            this->serviceClass = serviceClass;
        }

        string getCNIC () const
        {
            return CNIC;
        }
        string getAge () const
        {
            return age;
        }
        string getCity () const
        {
            return city;
        }
        string getDestination () const
        {
            return destination;
        }
        string getServiceClass () const
        {
            return serviceClass;
        }
        string getSeat () const
        {
            return seat;
        }
		void display () const     
		{
            cout << "Name:\t\t" << getName() << endl << "Phone Number:\t" << getPhoneNo() << endl;
            cout << "CNIC:\t\t" << CNIC << endl;
        }
        friend void makeReservation();
};
#endif
