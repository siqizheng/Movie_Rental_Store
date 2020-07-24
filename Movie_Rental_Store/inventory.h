
// --------------------- inventory.h -----------------------------------------
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

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory 
{
public:
	Inventory(); //constructor
	Inventory(const Inventory&); //copy constructor

	virtual ~Inventory(); //destructor
	virtual void setData(istream& ) = 0; //sets data of inventory itme
	virtual void setData2(istream& ) = 0;	//addition information to set
	virtual void display() const = 0;	//display all data
	virtual void displayHeader() const = 0;
	virtual string getItem() const = 0;	//return the inventory item

	void setMaxCopies(const int);
	void increaseCopies();
	void decreaseCopies();
	int getAmountIn();		//return current stock
	int getAmountOut();		//return current stock

	virtual bool operator==(const Inventory&) const = 0;	
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;

private:
	int stockNumber;
	int maxStock;

};

#endif


