
// --------------------- transaction.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  parent class of borrow, return, and history. 
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "movie.h"

class Customer;
class Transaction {
public:
	Transaction(); // constructor
	Transaction(const Transaction& ); //copy constructor
	virtual ~Transaction(); // destructor

	virtual bool setData(string media, Inventory * item, Customer * aCustomer);	// setData
	virtual void display() const;// display
	virtual Transaction * create();

	string getMediaType();//get media type
	string getTransactionType();	// transaction type
	Inventory * getItem() const;	//pointer to Inventory Item

protected:
	string transType;
	string mediaType;
	Inventory * anItem;

};

#endif



