
// --------------------- borrow.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: Object that holds a "borrowed" item. Child of Transaction class. Each 
// object contains all data members contained in a transaction object.
// Borrow object updates the inventory and adds itself to customer's transaction history
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"

class Customer;

class Borrow : public Transaction 
{
public:
	Borrow();
	Borrow(const Borrow& );
	~Borrow(); //end destructor

	virtual bool setData(string , Inventory * , Customer * );
	virtual void display() const;
	virtual Transaction * create();

};


#endif

