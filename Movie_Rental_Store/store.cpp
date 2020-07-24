
// --------------------- store.cpp -----------------------------------------
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

#include "store.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor of store
//----------------------------------------------------------------------------
Store::Store() : name("")
{
	
}

//----------------------------------------------------------------------------
// Name Constructor
// constructor assigning a name to the store, name is necessary for header
// output
// @param aName value defined as store's name
//----------------------------------------------------------------------------
Store::Store(string aName) : name(aName) 
{
}

//----------------------------------------------------------------------------
// Copy Constructor
// unimplemented copy constructor, useful if you wanted to copy the state of 
// a store item at any given point.
// @param rightSide store object copying from
//----------------------------------------------------------------------------
Store::Store(const Store& rightSide) 
{
}

//----------------------------------------------------------------------------
// Destructor
// destructor of store item for proper memory management
//----------------------------------------------------------------------------
Store::~Store() 
{
}

//----------------------------------------------------------------------------
// Create Customers
// Creates customer base from istream object and stores in store's customer
// list.
// @pre must be valid istream object
// @param infile istream object reading customer base from
//----------------------------------------------------------------------------
void Store::createCustomers(istream& infile)
{	
	//creates customers from customer textfile

	for (;;)
	{
		Customer* cust = new Customer();
		cust->setData(infile);

		if (infile.eof())
		{
			delete cust;
			cust = NULL;
			break;
		}
		customerList.addItem(cust->getCustomerID(), cust);
		
	}
}

//----------------------------------------------------------------------------
// Create Inventory
// Produces Inventory Objects from factory object and stores these objects 
// within the inventoryList. The istream is processed and data is sent to the
// factory for futher processing.
// @pre istream object must be valid before read
// @param infile istream object containing inventory information 
//----------------------------------------------------------------------------
void Store::createInventory(istream& infile)
{		
	//creates inventory from inventory textfile
	char ch = ' ';

	for (;;)
	{
		infile >> ch;

		if (infile.eof())
		{
			break;
		}

		Inventory * addedMovie = factory.createMovie(ch, infile);

		if (addedMovie != NULL)
		{
			addedMovie->setData(infile);

			bool inserted = inventoryList[factory.convertToSubscript(ch)].insert(addedMovie, 10);

			if (!inserted)
			{
				delete addedMovie;
				cout << "Not Inserted" << endl;
			}
		}
		addedMovie = NULL;
		delete addedMovie;
	}
}

//----------------------------------------------------------------------------
// Process Transactions
// Processes Transactions recorded in the istream object. Customer history and
// store inventory are updated accordingly depending on each transaction item.
// @param infile
//----------------------------------------------------------------------------
void Store::processTransactions(istream& infile) 
{
	char actCh = ' ';
	char movCh = ' ';
	char medCh = ' ';
	int custID = 0;
	bool found = false;
	string mediaType = "";
	char EOL = '\n';
	Inventory * itemLoc = NULL;
	Customer * tempCust = NULL;
	Inventory *  tempItem = NULL;

	for (;;)
	{
		infile >> actCh;

		if (infile.eof()) break; //check for end of file

		if (actCh == 'I')
		{
			displayInventory();
			actCh = ' ';
			
		}
		else if (infile.get() == EOL)
		{
			actCh =' ';
		}	
		else 
		{
			Transaction * processedTran = factory.createTransaction(actCh, infile);

			if (processedTran != NULL)
			{ //no action code
				infile >> custID;

				if (infile.eof()) {
					break;
				}
				if (lookUpCustomer(custID))
				{ //customer exists
					tempCust = customerList.getItem(custID);

					bool isHistory = processedTran->setData(mediaType, itemLoc, tempCust);

					if (infile.get() != EOL && isHistory)
					{ 
						//not EOL or is history

						infile >> medCh;

						mediaType = factory.getMediaType(medCh);


						if (mediaType != "")
						{  //movie genre

							infile >> movCh;

							tempItem = factory.createMovie(movCh, infile);

							if (tempItem != NULL)
							{
								tempItem->setData2(infile);

								found = inventoryList[factory.convertToSubscript(movCh)].retrieve(*tempItem, itemLoc);

								if (found == false)	//if movie not found
								{
									cout << "ERROR: Invalid Movie Request!"<< tempItem->getItem() << endl;
								}

								delete tempItem;
								tempItem = NULL;

								bool found2 = processedTran->setData(mediaType, itemLoc, tempCust);
		
								if ((found && found2) && mediaType != "")
								{
									customerList.getItem(custID)->addTransaction(*processedTran);
									
								}
								delete processedTran;
								processedTran = NULL;
							}
							else{
								cout << "ERROR: " << movCh << " not Found!" << endl;

								if (processedTran != NULL)
								{
									delete processedTran;
								}
									
								processedTran = NULL;
							}

							string temp;
							getline(infile, temp, EOL);
							delete tempItem;
							tempItem = NULL;

						}
						else
						{
							string temp;
							getline(infile, temp, EOL);

							cout << "ERROR: Invalid Code " << medCh << endl;

							if (processedTran != NULL)
							{
								delete processedTran;
							}	
							processedTran = NULL;
						}//end if not media type
					}
					else {
						if (processedTran != NULL)
						{
							delete processedTran;
						}	
						processedTran = NULL;
					}//end if not EOL and isHistory
				}
				else {
					cout << "Error: Invalid Customer ID " << custID << endl;

					if (processedTran != NULL)
					{
						delete processedTran;
					}	
					processedTran = NULL;

					string temp;
					getline(infile, temp, EOL);
				}//end if customer exists
			}
			else {
				cout << "ERROR: Invalid Action Code " << actCh << endl;

				if (processedTran != NULL)
				{
					delete processedTran;
				}	
				processedTran = NULL;
			}//end if no action code
		}//end process infile if

		found = false;
		custID = 0;
		itemLoc = NULL;
		tempCust = NULL;
		tempItem = NULL;
	}//end for
}//end processTransaction


//----------------------------------------------------------------------------
// Display
// used for testing purposes. displays all items within store
//
void Store::display() 
{
	displayCustomerBase();
	displayInventory();
}

//----------------------------------------------------------------------------
// Display Inventory
// Displays all items within in the inventory along with their stock in and
// out.
// ----------------------------------------------------------------------------
void Store::displayInventory() const
{
	if (name != "")
	{
		cout << "--------------------------------------------------------------"<< endl;
		cout << "Inventory for " << name << endl;
		cout << "--------------------------------------------------------------"<< endl;
	}

	for (int i = 0; i < MAXINVENTORY; i++)
	{
		if (!inventoryList[i].isEmpty())
		{
			
			inventoryList[i].inorderDisplay(inventoryList[i].getRoot());
		cout << endl;
		}
	}
}

//----------------------------------------------------------------------------
// Display Customer Base
// Displays the customer base stored within the Store.
// ----------------------------------------------------------------------------
void Store::displayCustomerBase() const 
{
	for (int i = 0; i < MAXCUSTOMERS; i++)
	{
		if (lookUpCustomer(i))
		{
			getCustomer(i).display();
		}
	}
}

//----------------------------------------------------------------------------
// lookup Customer
// Checks whether a customer is within the store's customer list by checking 
// if their idnumber is in the list.
// @param IDNumber customer ID number searching the customer list for
// @return true if found, false otherwise
//----------------------------------------------------------------------------
bool Store::lookUpCustomer(int customerID) const 
{
	if (customerList.getItem(customerID) == NULL)
	{
		return false;
	}
		
	if (customerList.getItem(customerID)->getCustomerID() == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
		
} 

//----------------------------------------------------------------------------
// Get Business Name
// returns the business name
// @return name of business
//----------------------------------------------------------------------------
string Store::getBusinessName() const 
{
	return name;
}

//----------------------------------------------------------------------------
// Get Customer
// returns the customer within the list with the ID number passed in as a 
// parameter. 
// @pre IDNumber must not exceed MAXCUSTOMERS
// @param IDNumber potential customer's Id number
// @return Customer object if valid IDNumber, -1 otherwise
//----------------------------------------------------------------------------
Customer Store::getCustomer(const int IDNumber) const 
{
	return *customerList.getItem(IDNumber);
}

