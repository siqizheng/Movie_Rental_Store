// --------------------- borrow.cpp -----------------------------------------
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

#include "borrow.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//----------------------------------------------------------------------------
Borrow::Borrow() : Transaction() 
{
	transType = "Borrow";
} 

//----------------------------------------------------------------------------
// Copy Constructor
// Constructor copying data from another Borrow type
// @param rightSide the borrow object copying from
//----------------------------------------------------------------------------
Borrow::Borrow(const Borrow& rightSide) 
{
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
} 

//----------------------------------------------------------------------------
// Destructor
// returning dynamically allocated memory back to the heap
//----------------------------------------------------------------------------
Borrow::~Borrow() {} //end destructor

//----------------------------------------------------------------------------
// Set Data
// sets data of Borrow object
// @param media type of media contained in borrow object
// @param item inventory item contained in borrow object
// @param aCustomer customer object borrowing the item
// @return true no matter what
//----------------------------------------------------------------------------
bool Borrow::setData(string media, Inventory * item, Customer * aCustomer)
{
	if (item != NULL)
	{
		mediaType = media;
		anItem = item;

		if (mediaType != "")
		{
			anItem->decreaseCopies();
		}
	}
	return true;
}

//----------------------------------------------------------------------------
// Display
// displays the mediaType and transaction Type of object
//----------------------------------------------------------------------------
void Borrow::display() const
{
	cout << mediaType << " " << transType << " ";
}

//----------------------------------------------------------------------------
// Create
// creates a new borrow object for factory
//----------------------------------------------------------------------------
Transaction * Borrow::create() 
{
	return new Borrow();
}

