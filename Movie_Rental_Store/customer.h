
// --------------------- customer.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  holds necessary information about customer base of store. 
//Objects are created from text file and stored in array inside of store.
// Customer has the basics, first and last name and a 
//string customerID() which we use to obtain out hash() function 
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer {
public:
	Customer();
	Customer(istream&);
	Customer(const Customer&);
	virtual ~Customer();
	
	void setData(istream& infile);

	void displayCustomerHistory() const;
	void addTransaction(Transaction& );
	virtual void display() const;
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;
	virtual bool operator==(const Customer& rightSide) const;	
	virtual bool operator!=(const Customer& rightSide) const;
private:
	int id;
	string firstName;
	string lastName;
	vector<Transaction> transactionHistory;

};

#endif


