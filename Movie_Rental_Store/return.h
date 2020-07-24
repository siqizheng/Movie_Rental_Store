
// --------------------- return.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: return object, child of transaction. Used when processing items within store.
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------


#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"


class Customer;		//forward declaration
class Return : public Transaction {

public:
	Return();
	Return(const Return&);
	virtual ~Return(); //end destructor
	virtual bool setData(string, Inventory *, Customer *);
	virtual void display() const;
	virtual Transaction * create(); //create new return object

};

#endif

