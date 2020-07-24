
// --------------------- inventory.cpp -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  parent class of all items stored within the store. contains all virtual
// and pure virtual methods necessary for transactions as well as setting data
// of child classes.
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------


#include "inventory.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
// ----------------------------------------------------------------------------
Inventory::Inventory() : stockNumber(-1), maxStock(0)
{
} 

//----------------------------------------------------------------------------
// Copy Constructor
// copies information from rightSide into the newly created inventory item
// ----------------------------------------------------------------------------
Inventory::Inventory(const Inventory& rightSide) 
{
} 

//----------------------------------------------------------------------------
// Destructor
// deallocates dynamically allocated memory and returns it to the heap
//----------------------------------------------------------------------------
 Inventory::~Inventory() 
 {
 } 

//----------------------------------------------------------------------------
// Set Max Copies
// sets the maximum copies of a specific inventory item
// @param maxCopies number of the max of the stock
// ----------------------------------------------------------------------------
void Inventory::setMaxCopies(const int maxCopies) 
{
	maxStock = maxCopies;

	if (stockNumber < 0)
	{
		stockNumber = maxCopies;
	}
		
}

//----------------------------------------------------------------------------
// Increase Copies
// increase stock 
// ----------------------------------------------------------------------------
void Inventory::increaseCopies()
{
	if (stockNumber != maxStock)
	{
		stockNumber++;
	}		
}

//----------------------------------------------------------------------------
// Decrease Copies
// decreases stock
// ----------------------------------------------------------------------------
void Inventory::decreaseCopies() 
{
	if (stockNumber != 0)
	{
		stockNumber--;
	}		
}

//----------------------------------------------------------------------------
// Get Amount In
// return current stock
// @return integer representing stock available
//----------------------------------------------------------------------------
int Inventory::getAmountIn()
{ 
	return stockNumber; 
}

//----------------------------------------------------------------------------
// Get Amount Out
// return the number of borrowed items
// @return integer representing stock out
//----------------------------------------------------------------------------
int Inventory::getAmountOut()
{ 
	return maxStock - stockNumber; 
}

