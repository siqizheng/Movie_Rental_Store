
// --------------------- history.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  child of transaction, displays the history for specific customer.
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class Customer;

class History : public Transaction{
public:
	History();
	History(const History& rightSide);
	~History(); //destructor

	virtual bool setData(string, Inventory *, Customer *);
	virtual Transaction * create();

};


#endif
