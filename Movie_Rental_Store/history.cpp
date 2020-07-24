
// --------------------- history.cpp -----------------------------------------
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

#include "history.h"
#include "customer.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//----------------------------------------------------------------------------
History::History() : Transaction()
{
	transType = "History";
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies information from rightSide object to newly created history object
// @param rightSide history object copying from
//----------------------------------------------------------------------------
History::History(const History& rightSide) 
{
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
}

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynammically allocated memory back to the heap
//----------------------------------------------------------------------------
History::~History(){}

//----------------------------------------------------------------------------
// set Data
// sets data for history item 
// @param media unused but kept for polymorphic qualities
// @param item unused but kept for polymorphic qualities
// @param aCustomer customer contained in specific history object
// @return false to signal a non-stored value
// ----------------------------------------------------------------------------
bool History::setData(string media, Inventory * item, Customer * aCustomer) 
{
	aCustomer->displayCustomerHistory();
	// just displays customer history to keep polymorphism
	return false; 
}

//----------------------------------------------------------------------------
// Create
// creates new history object for factory
//----------------------------------------------------------------------------
Transaction * History::create() 
{ 
	return new History(); 
}

