
// --------------------- store.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  maintains all customers, inventory items, and transactions within class.
// creates, modifies, and manipulates all data involving these objects as well
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H
#define MAXCUSTOMERS 50
#define MAXINVENTORY 53
#include <fstream>
#include <vector>
#include "customer.h"
#include "factory.h"
#include "bintree.h"
#include "hashtable.h"
#include <istream>
#include <string>

using namespace std;

class Store {

public:
	Store();
	Store(string );
	Store(const Store& );
	~Store();	//destructor

	void createCustomers(istream&);
	void createInventory(istream&);
	void processTransactions(istream&);
	void display();
	void displayInventory() const;
	void displayCustomerBase() const;
	bool lookUpCustomer(int) const;
	string getBusinessName() const;
	Customer getCustomer(const int) const;

private:
	HashTable<Customer> customerList;
	BinTree inventoryList[MAXINVENTORY];
	vector<Transaction> storeTransactionHistory;
	Factory factory;

	string name;
};

#endif



