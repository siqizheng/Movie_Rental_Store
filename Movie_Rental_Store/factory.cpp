
// --------------------- factory.cpp -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: impelemented for building of inventory and transaction 
// objects. Uses predefined indexes for each coordinating type (either 
// an inventory type or a transaction type) and predefined maximum number of 
// items per hash table.
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------


#include "factory.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor. sets up initial objects within arrays
//----------------------------------------------------------------------------
Factory::Factory()
{
	initInventory();
	storeInventory[CLASSIC] = new Classic();
	storeInventory[DRAMA] = new Drama();
	storeInventory[COMEDY] = new Comedy();

	transactionInventory[BORROW] = new Borrow();
	transactionInventory[HISTORY] = new History();
	transactionInventory[RETURN] = new Return();

	mediaType[DRAMA] = "DVD";
}

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynamically allocated memory and returns it back to the heap
//----------------------------------------------------------------------------
Factory::~Factory()
{
	for (int i = 0; i < MAXITEMS; i++)
	{
		if (storeInventory[i] != NULL)
		{
			delete storeInventory[i];
			storeInventory[i] = NULL;
		}//end if store inventory

		if (transactionInventory[i] != NULL)
		{
			delete transactionInventory[i];
			transactionInventory[i] = NULL;
		}//end if transaction inventory
	}
} 

//----------------------------------------------------------------------------
// Create Movie
// creates specified movie object coordinating with array location
// @param ch char representing the specific movie type
// @param infile the rest of the data contained regarding the movie object
//----------------------------------------------------------------------------
Inventory * Factory::createMovie(char ch, istream& infile) 
{
	string temp;

	int subscript = hash(ch);	//return the proper index for type
	if (storeInventory[subscript] == NULL)	//throw away invalid data
	{
		getline(infile, temp, '\n');
		return NULL;
	}
	else
	{
		return storeInventory[subscript]->create();
	}
}
//----------------------------------------------------------------------------
// Create Transaction
// creates specific transaction object coordinating with array location
// @param ch char representing the specific transaction type
// @param infile the rest of the data contained regarding the transaction object
//----------------------------------------------------------------------------
Transaction * Factory::createTransaction(char ch, istream& infile) 
{
	string temp;

	int subscript = hash(ch);
	if (transactionInventory[subscript] == NULL)
	{
		getline(infile, temp, '\n');
		return NULL;
	}
	else
	{
		return transactionInventory[subscript]->create();
	}	
}	

//----------------------------------------------------------------------------
// Convert To Subscript
// returns the hash of the character passed in as parameters. translates to 
// array subscript later.
// @param ch char passed in
// @return integer value represented by the hash
//----------------------------------------------------------------------------
int Factory::convertToSubscript(char ch)
{
	return hash(ch);
}

//----------------------------------------------------------------------------
// Get media Type
// returns the media type based on the character passed in
// @param char representing the specific media type
// @return media type of ch
//----------------------------------------------------------------------------
string Factory::getMediaType(char ch) 
{
	return mediaType[hash(ch)];
}

//----------------------------------------------------------------------------
// Hash
// computes the integer value of a specific character
// @pre must be an uppercase letter
// @param ch
//----------------------------------------------------------------------------
int Factory::hash(char ch) const
{ 
	if (ch < 'a')
		return ch - 'A'; 
	else 
		return 0;
}

//----------------------------------------------------------------------------
// Initialize Inventory
// sets starting status of inventory hash table
// ----------------------------------------------------------------------------
void Factory::initInventory()
{
	for (int i = 0; i < MAXITEMS; i++)
	{
		storeInventory[i] = NULL;
		transactionInventory[i] = NULL;
		mediaType[i] = "";
	}
}
