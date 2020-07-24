
// --------------------- transaction.cpp -----------------------------------------
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

#include "transaction.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//----------------------------------------------------------------------------
Transaction::Transaction() : transType("Transaction"), mediaType(""), anItem(NULL) 
{
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies information from rightSide object into newly created transaction object
//----------------------------------------------------------------------------
Transaction::Transaction(const Transaction& rightSide)
{
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
} 

//----------------------------------------------------------------------------
// Destructor
// deallocates dynamically allocated memory and returns it to the heap
//----------------------------------------------------------------------------
Transaction::~Transaction()
{
}

//----------------------------------------------------------------------------
// Set Data
// sets data of transaction from inventory item and customer
// @param media mediaType
// @param item inventory item
// @param aCustomer customer involved with transaction
// @return true
//----------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory * item, Customer * aCustomer)
{
	mediaType = media;
	anItem = item;
	return true;
}	

//----------------------------------------------------------------------------
// Display
// displays media type and transaction type
//----------------------------------------------------------------------------
void Transaction::display() const
{
	cout << mediaType << " " << transType << ": ";
}

//----------------------------------------------------------------------------
// Create
// creates new transaction object for factory
//----------------------------------------------------------------------------
Transaction * Transaction::create() 
{
	return new Transaction();
}

//----------------------------------------------------------------------------
// Get Media Type
// @return mediaType
//----------------------------------------------------------------------------
string Transaction::getMediaType() 
{ 
	return mediaType; 
}

//----------------------------------------------------------------------------
// Get Transaction Type
// @return transType
//----------------------------------------------------------------------------
string Transaction::getTransactionType() 
{ 
	return transType; 
}

//----------------------------------------------------------------------------
// get Item
// @return anItem
//----------------------------------------------------------------------------
Inventory * Transaction::getItem() const 
{
	return anItem; 
}

