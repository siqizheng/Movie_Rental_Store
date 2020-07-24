// --------------------- classic.cpp -----------------------------------------
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


#include "classic.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor for classic movie object
 //----------------------------------------------------------------------------
Classic::Classic() : Movie(), actorFName(""), actorLName(""), month(0), GENRE("CLASSIC")
{ 
}//end constructor

//----------------------------------------------------------------------------
// Copy Constructor
// copies an existing classicMovie object to a newly created classicMovie
// object.
//----------------------------------------------------------------------------
Classic::Classic(const Classic& rightSide)
{
	director = rightSide.director;
	title = rightSide.title;
	actorFName = rightSide.actorFName;
	actorLName = rightSide.actorLName;
	month = rightSide.month;
	year = rightSide.year;
}

//----------------------------------------------------------------------------
// Destructor
// Deallocates dynamically allocated memory back to the heap
//----------------------------------------------------------------------------
Classic::~Classic() {}

//----------------------------------------------------------------------------
// setData
// Sets the data of a classicMovie object to the data read in from the 
// istream.
// @pre istream must be valid
// @param infile istream information about specific classic movie object
//----------------------------------------------------------------------------
void Classic::setData(istream& infile) 
{
	string s = ""; 

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18)
	{
		title.resize(18);		
	}

	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22)
	{
		title.resize(22);		
	}

	infile.get();
	infile >> actorFName >> actorLName;
	infile >> month >> year;
}

//----------------------------------------------------------------------------
// set Data 2
// process transaction data setting. This istream is in a  different format 
// than istream containing movie data.
// @pre istream must be valid
// @param infile istream containing data read in
//----------------------------------------------------------------------------
void Classic::setData2(istream& infile) 
{
	infile >> month;
	infile >> year;
	infile >> actorFName;
	infile >> actorLName;

}

//----------------------------------------------------------------------------
// display
// displays the classic movie object's information
//----------------------------------------------------------------------------
void Classic::display() const 
{
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(3) << month << " "
		 << setw(5) << year << " "
		 << actorFName << " " << actorLName << endl;
}

//----------------------------------------------------------------------------
// display Header
// displays specific header for classic movie object.
//----------------------------------------------------------------------------
void Classic::displayHeader() const 
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *MO**YEAR* " <<
		"*ACTOR* " << endl;
	cout <<
	"---------------------------------------------------------------------"
		<< endl;
}

//----------------------------------------------------------------------------
// operator ==
// overloaded == operator for classic movie types
// @param rightSide the right side of bool comparison
// @return true if they are the same, false otherwise
//----------------------------------------------------------------------------
 bool Classic::operator==(const Inventory& rightSide) const
 {
	//cast Inventory down to ClassicMovie
	const Classic& aClassic = static_cast<const Classic&>(rightSide);

	return (year == aClassic.year && month == aClassic.month
		&& actorFName == aClassic.actorFName &&
		actorLName == aClassic.actorLName);
}

//----------------------------------------------------------------------------
// operator <
// overloaded < operator for classic movie types
// @param rightSide the right side of the bool comparison
// @return true if left side less than, false otherwise
//----------------------------------------------------------------------------
 bool Classic::operator<(const Inventory& rightSide) const 
 {
	const Classic& aClassic = static_cast<const Classic&>(rightSide);

	if (year < aClassic.year)
		return true;
	else if (year == aClassic.year)
	{
		if (actorFName < aClassic.actorFName)
		{
			return true;
		}
		else if (actorFName == aClassic.actorFName)
		{
			return (actorLName < aClassic.actorLName);
		}
		else
			return false;
	}
	else
		return false;
}

//----------------------------------------------------------------------------
// Create
// creates new classic movie object for Inventory factory
//----------------------------------------------------------------------------
Inventory * Classic::create() 
{ 
	return new Classic(); 
}

