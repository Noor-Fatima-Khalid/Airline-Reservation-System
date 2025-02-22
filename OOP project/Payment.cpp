#ifndef PAYMENT
#define PAYMENT
#include<iostream>
#include<string>

using namespace std;

class Payment
{
	protected:
		string status;
		string cardNo;
    public: 
		// constructor
        CardPayment () {}
        CardPayment (string cardNo)
        {
            setCardNo (cardNo);
        }
		// setter
        void setCardNo (string cardNo) 
        {
	        this->cardNo = cardNo;
        }

		// this will ask for amount and cardNo to make payment
        void payment (string cardNo,  bool status) 
        {
        	setCardNo (cardNo);
        	setStatus (status);
		}
		
        void setStatus (bool status)
        {
        	bool flag = false;
            if (status)
				this->status = "---Paid---";
			else
				this->status = "---Pending---";
			cout << status << endl;       
        }
};  
#endif
