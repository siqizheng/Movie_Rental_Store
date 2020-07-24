
// --------------------- return.cpp -----------------------------------------
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

#include "return.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//----------------------------------------------------------------------------
Return::Return() : Transaction() 
{
	transType = "Return";
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies data from rightSide object into newly created return object
// @param rightSide object copying data from
//----------------------------------------------------------------------------
Return::Return(const Return& rightSide)
{
	mediaType = rightSide.mediaType;
	transType = rightSide.transType;
	anItem = rightSide.anItem;
} 

//----------------------------------------------------------------------------
// Destructor
// deallocates dynamically allocated memory and returns it to the heap
//----------------------------------------------------------------------------
 Return::~Return()
 {
 }

//----------------------------------------------------------------------------
// Set Data
// sets data of the return object from existing inventory item and customer
// @param media mediaType of object
// @param item inventory item returning
// @param aCustomer the customer who is returning the item
// @return true
// ----------------------------------------------------------------------------
bool Return::setData(string media, Inventory * item, Customer * aCustomer) 
{

	if (item != NULL){
		mediaType = media;
		anItem = item;

		if (mediaType != "")
		{
			anItem->increaseCopies();
		}		
	}
	return true;
}

//----------------------------------------------------------------------------
// Display
// displays media type and transaction type
// ----------------------------------------------------------------------------
void Return::display() const
{
	cout << mediaType << " " << transType << " ";
} 

//----------------------------------------------------------------------------
// Create
// creates new return object for factory
// ----------------------------------------------------------------------------
Transaction * Return::create()
{ 
	return new Return(); 
} 
