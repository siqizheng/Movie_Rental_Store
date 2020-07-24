
// --------------------- main.cpp -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: creates a store object, processes three provided files and ouputs results.
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------
 


#include "store.h"

using namespace std;

int main()
{
	Store myStore("MOVIE: Welcome to my store");
	ifstream infileCustomers("data4customers.txt");
	ifstream infileMovies("data4movies.txt");
	ifstream infileTransactions("data4commands.txt");


	if ((!infileCustomers) || (!infileMovies) || (!infileTransactions))
	{
		cout << "File Could Not be Opened!" << endl;
	
		return 1;
	}
	
	myStore.createCustomers(infileCustomers);
	myStore.createInventory(infileMovies);
	myStore.processTransactions(infileTransactions);

	return 0;

}



