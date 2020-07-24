
// --------------------- comedy.cpp -----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: inherits from Movie class. Creates classics  movies. 
//implement comparable fuction for storing in BinTree sake
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#include "comedy.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
Comedy::Comedy() : Movie(), GENRE("COMEDY") 
{ 
}

//----------------------------------------------------------------------------
// Copy constructor
// copies the contents of rightSide to a newly created comedyMovie object
// @param rightSide right side object copying from
// ----------------------------------------------------------------------------
Comedy::Comedy(const Comedy& rightSide)
{
	title = rightSide.title;
	year = rightSide.year;
	director = rightSide.director;
} 

//----------------------------------------------------------------------------
//  Destructor
// Deallocates dynamically allocated memory back to the heap
//----------------------------------------------------------------------------
Comedy::~Comedy() {}//end destructor

//----------------------------------------------------------------------------
// Display
// displays the title, year, month, director, and actor for specific movie
//----------------------------------------------------------------------------
void Comedy::display() const 
{ 	
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(5) << year << endl;
}//end display

//----------------------------------------------------------------------------
// Display Header
// displays specific header for comedy movie type
//----------------------------------------------------------------------------
void Comedy::displayHeader() const 
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *YEAR*  " 
		<< endl;
	cout <<
	"---------------------------------------------------------------------"
		<< endl;
}//end displayHeaders

//----------------------------------------------------------------------------
// Set Data
// Sets the data for the comedy movie object from the istream parameter
// @pre istream object must be valid
// @param infile istream object pulling data from
//----------------------------------------------------------------------------
void Comedy::setData(istream& infile) 
{
	string s = "";

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18){
		title.resize(18);	
	}

	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22){
		title.resize(22);	
	}
	
	infile.get();
	infile >> year;
}

//----------------------------------------------------------------------------
// Set Data
// process transaction set data for inventory item contained. This istream 
// object is formatted differently than previous object.
// @pre istream object must be valid
// @param infile istream object reading data in from
//----------------------------------------------------------------------------
void Comedy::setData2(istream& infile) 
{
	infile.get();
	getline(infile, title, ',');

	infile >> year;

}
//----------------------------------------------------------------------------
// Operator ==
// overloaded == operator tests equality between two comedy movie objects
// @param movieItem right hand side of equality operation
// @return true if equal, false otherwise
//----------------------------------------------------------------------------
bool Comedy::operator==(const Inventory& movieItem) const 
{
	//static cast down to ComedyMovie
	const Comedy& aComedy = static_cast<const Comedy&>(movieItem);
	return (title == aComedy.title && year == aComedy.year);
}

//----------------------------------------------------------------------------
// Operator <
// overloaded < tests less than between two comedy movie objects
// @param movieItem right hand side of less than operation
// @return true if less than, false otherwise
//----------------------------------------------------------------------------
bool Comedy::operator<(const Inventory& movieItem) const 
{
	//static cast down to ComedyMovie
	const Comedy& aComedy = static_cast<const Comedy&>(movieItem);

	if (title < aComedy.title)
		return true;
	else if (title == aComedy.title){
		return (year < aComedy.year);
	}
	else
		return false;
}

//----------------------------------------------------------------------------
// Create
// create new comedy movie object for factory
//----------------------------------------------------------------------------
Inventory * Comedy::create() 
{ 
	return new Comedy();
}

