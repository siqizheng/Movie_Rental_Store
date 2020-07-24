
// --------------------- factory.h -----------------------------------------
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


#ifndef FACTORY_H
#define FACTORY_H
#define MAXITEMS 26
#define CLASSIC 2
#define DRAMA 3
#define COMEDY 5
#define BORROW 1
#define HISTORY 7 
#define RETURN 17
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

class Movie;
class Transaction;

using namespace std;

class Factory 
{
public:
	Factory();
	~Factory();

	Inventory * createMovie(char , istream& );
	Transaction * createTransaction(char , istream& );
	int convertToSubscript(char );
	string getMediaType(char );
	
private:
	Inventory * storeInventory[MAXITEMS];
	Transaction * transactionInventory[MAXITEMS];
	string mediaType[MAXITEMS];

	int hash(char ) const;	//implemented by trans and inventory
	void initInventory();
};

#endif
