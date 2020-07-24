
// --------------------- drama.cpp-----------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: inherits from Movie class. Creates drama movies. 
//implement comparable fuction for storing in BinTree sake
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------

#include "drama.h"
//----------------------------------------------------------------------------
// Constructor
// default constructor 
//----------------------------------------------------------------------------
Drama::Drama() : Movie(), GENRE("DRAMA") 
{ 
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies information about right side object to newly created drama movie 
// object.
//----------------------------------------------------------------------------
Drama::Drama(const Drama& rightSide) 
{
	title = rightSide.title;
	director = rightSide.director;
	year = rightSide.year;
} 

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynamically allocated memory back to the heap
//----------------------------------------------------------------------------
Drama::~Drama() 
{
}

//----------------------------------------------------------------------------
// display
// displays the title, year, month, director, and actor for specific movie
//----------------------------------------------------------------------------
void Drama::display() const
{ 
	cout << left << setw(22) << title << " " << setw(18) << director << " " << setw(5) << year << endl;
}

//----------------------------------------------------------------------------
// display Header
// displays specific drama movie header for object
//----------------------------------------------------------------------------
void Drama::displayHeader() const 
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *YEAR*  " << endl;
	cout << "---------------------------------------------------------------------" << endl;
}

//----------------------------------------------------------------------------
// set Data
// sets data within the drama movie object read in from istream object
// @pre istream object must be valid
// @param infile istream object reading data from
//----------------------------------------------------------------------------
void Drama::setData(istream& infile) 
{
	string s = "";

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;

} 

//----------------------------------------------------------------------------
// set Data 2
// process transaction data setting method. This is used because transaction
// istream object of a different format than inventory istream object.
// @pre istream object must be valid
// @param infile istream object reading from
//----------------------------------------------------------------------------
void Drama::setData2(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

//----------------------------------------------------------------------------
// operator ==
// overloaded == operator tests equality in two drama movie objects
// @param rightSide object testing equality against
// @return true if equal, false otherwise
//---------------------------------------------------------------------------
bool Drama::operator==(const Inventory& rightSide) const
{
	//cast Inventory down to Drama
	const Drama& aDrama = static_cast<const Drama&>(rightSide);

	return (title == aDrama.title && director == aDrama.director);
} 

//----------------------------------------------------------------------------
// operator <
// overloaded < operator tests less than in two drama movie objects
// @param rightSide object testing less than against
// @return true if less than, false otherwise
//---------------------------------------------------------------------------
 bool Drama::operator<(const Inventory& rightSide) const 
 {
	const Drama& aDrama = static_cast<const Drama&>(rightSide);

	if (director < aDrama.director){
		return true;
	}
	else if (director == aDrama.director){
		return (title < aDrama.title);
	}
	else
		return false;
}

//----------------------------------------------------------------------------
// create
// creates new drama movie object for factor
//---------------------------------------------------------------------------
 Inventory * Drama::create() 
 {
	 return new Drama(); 
 }

