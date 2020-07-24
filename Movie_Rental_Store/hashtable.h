// --------------------- hashtable.h -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: Due to template implementation Templatized Hastable class has holds
// implementations in .h file. Serves as a data structure to hold customers
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;

template < class item_type>
class HashTable 
{
public:
	//----------------------------------------------------------------------------
	//default constructor
	// Description: calls buildTable() creates an empty hastable
	//----------------------------------------------------------------------------
	HashTable()
	{
		buildTable();
	}

	//----------------------------------------------------------------------------
	//default destructor
	// Description: calls makeEmpty() function. destructs Hashtable
	// ---------------------------------------------------------------------------
	~HashTable()
	{
		makeEmpty();
	}

	//----------------------------------------------------------------------------
	//getItem
	// Description: returns the items that we are looking for , returns null if not found
	//----------------------------------------------------------------------------
	item_type* getItem(int key) const
	{
		int hash = (key % SIZE);                // assign hash

		if (table[hash] == NULL)
		{         // no customer at index
			return NULL;
		}
		else
		{
			ItemList* node = table[hash]; // traves linked list until found
			while (node != NULL)
			{
				if (key == node->key)
					return node->data;

				node = node->next;
			}
		}
		return NULL;                           // not found
	}

	//----------------------------------------------------------------------------
	// addItem
	// Description: adds the item in hastable. Checks for duplicates
	// ---------------------------------------------------------------------------
	void addItem(int key, item_type* item)
	{
		// prime number 59 ?
		int hash = (key % SIZE);             // assign hash

		ItemList* node = new ItemList;      // node that hold customer
		node->data = item;               // point to customer
		node->key = key;                     // point to key
		node->next = NULL;                   // next null

		// check if the index is empty
		if (table[hash] == NULL)
		{
			node->next = table[hash];
			table[hash] = node;
		} // more than one nodes
		else
		{
			ItemList* current = table[hash];
			while (current->next != NULL)
			{
				// check if duplicate
				if (key == current->key)
				{
					delete node->data;      // delete customer
					delete node;            // delete pointer
					throw logic_error("Can't add same key twice");
				}
				current = current->next;
			}
			current->next = node; // add to the list
		}
	}


private:
	static const int SIZE = 50; // twice size of customer base

	// ----------------------------------------------------------------------------
	// makeEmpty()
	// Description: deletes all items in the table
	// ----------------------------------------------------------------------------
	void makeEmpty()
	{
		for (int i = 0; i < SIZE; ++i) {
			if (table[i] != NULL) {
				ItemList* del = table[i];             // hold del at head
				// loop until the last node
				while (table[i] != NULL) {
					table[i] = table[i]->next;   // moove head
					delete del->data;                      // delete customer
					delete del;                            // delete node
					del = NULL;
					del = table[i];	               // assing del to head
				}
			}
		}
	}

	// ----------------------------------------------------------------------------
	// buildTable
	// Description: creates an empty table
	// ----------------------------------------------------------------------------
	void buildTable()
	{
		for (int i = 0; i < SIZE; ++i) {
			table[i] = NULL;
		}
	}

	struct ItemList   // linked list that attached to index of table
	{
		item_type* data;   //  hold customer
		int key;           // hold ID  (key)
		ItemList* next;   // next
	};

	ItemList* table[SIZE];   // hastable array
};

#endif /* hashtable_h */

