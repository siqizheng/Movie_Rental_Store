
// --------------------- customer.cpp -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose:  holds necessary information about customer base of store. 
//Objects are created from text file and stored in array inside of store.
// Customer has the basics, first and last name and a 
//string customerID() which we use to obtain out hash() function 
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#include "customer.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor for customer class. sets the stock on creation.
//----------------------------------------------------------------------------
Customer::Customer() : id(-1), firstName(""), lastName("")
{
	transactionHistory.reserve(10);	//sets a reserved size of the vector
}//end constructor

//----------------------------------------------------------------------------
// Constructory
// constructor from istream
// @pre infile must be valid
// @param infile istream reading from
//----------------------------------------------------------------------------
Customer::Customer(istream& infile) 
{
	setData(infile);
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies rightSide's information to a newly created Customer object
// @pre infile must be valid
// @param rightSide Customer object copying data from
//----------------------------------------------------------------------------
Customer::Customer(const Customer& rightSide) 
{
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
} 

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynammically allocated memory back to the heap
//----------------------------------------------------------------------------
Customer::~Customer()
{
}

//----------------------------------------------------------------------------
// Set Data
// sets customer information from istream object
// @pre infile must be valid
// @param infile instream object reading data from
//----------------------------------------------------------------------------
void Customer::setData(istream& infile)
{
	infile >> id;
	if (infile.eof()) return;
	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

//----------------------------------------------------------------------------
// Display Customer History
// outputs the history vector for specified customer
//----------------------------------------------------------------------------
void Customer::displayCustomerHistory() const 
{
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName 
		<< endl;
	int size = transactionHistory.size();
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
		//if(transactionHistory[i])
			transactionHistory[i].display();
			transactionHistory[i].getItem()->display();
		}
		cout << endl;
	}
	else
	{
		cout << "No Transactions for Customer" << endl;
	}	
	cout << endl;
} 

//----------------------------------------------------------------------------
// Add Transaction
// adds a transaction to the transaction history of a Customer
// @param trans transaction item adding
//----------------------------------------------------------------------------
void Customer::addTransaction(Transaction& trans) 
{
	transactionHistory.push_back(trans);
}

//----------------------------------------------------------------------------
// Display
// displays the customer along with their history
//----------------------------------------------------------------------------
void Customer::display() const 
{
	displayCustomerHistory();
}

//----------------------------------------------------------------------------
// Get Customer ID
// returns the ide of a customer
// @return id
//----------------------------------------------------------------------------
int Customer::getCustomerID() const 
{ 
	return id;
}

//----------------------------------------------------------------------------
// Get First Name
// returns first name of customer
// @return firstName
//----------------------------------------------------------------------------
string Customer::getFirstName() const 
{ 
	return firstName;
}

//----------------------------------------------------------------------------
// Get Last Name
// returns last name of a customer
// @return lastName
//----------------------------------------------------------------------------
string Customer::getLastName() const 
{ 
	return lastName; 
}

//----------------------------------------------------------------------------
// Operator == 
// overloaded == operator that tests equality between two customer objects
// @param rightSide right side of equality test
// @return true if equal, false otherwise
//----------------------------------------------------------------------------
bool Customer::operator==(const Customer& rightSide) const 
{
	return (id == rightSide.id);
} 

//----------------------------------------------------------------------------
// Operator !=
// overloaded != operator that tests inequality between two customer objects
// @param rightSide right side of inequality test
// @return true if inequal, false otherwise
//----------------------------------------------------------------------------
bool Customer::operator!=(const Customer& rightSide) const 
{
	return (id != rightSide.id);
}

