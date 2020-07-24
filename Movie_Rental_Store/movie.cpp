
// --------------------- movie.cpp -------------------------------------------
//
// Siqi Zheng, CSS 502A
// Created:         Mar. 7, 2020
// Last Modified:   Mar. 12, 2020
// --------------------------------------------------------------
// Purpose: child of inventory class, and parent to classic, comedy, and drama. 
// --------------------------------------------------------------
// Assumptions: All input data is assumed to be correctly formatted
// and valid. 
// ---------------------------------------------------------------------------


#include "movie.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//----------------------------------------------------------------------------
Movie::Movie() : Inventory(), title(""), director(""), year(0) 
{
}

//----------------------------------------------------------------------------
// Copy Constructor
// copies data from rightSide object into newly created movie object
// @param rightSide movie object copying from
//----------------------------------------------------------------------------
Movie::Movie(const Movie& rightSide)
{
	title = rightSide.title;
	director = rightSide.director;
	year = rightSide.year;
	
}

//----------------------------------------------------------------------------
// Destructor
// deallocates dynamically allocated memory and returns it to the heap
// ----------------------------------------------------------------------------
Movie::~Movie()
{
}

//----------------------------------------------------------------------------
// Display
// displays the title, year, month, director, and actor for specific movie
// ----------------------------------------------------------------------------
void Movie::display() const 
{ 
	cout << title << " " << director
		<< " "
		<< year
		<< endl;
}

//----------------------------------------------------------------------------
// Set Data
// sets data for specific movie object from istream object parameter
// @pre infile must be valid
// @param infile istream object reading data from
// ----------------------------------------------------------------------------
void Movie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
} 

//----------------------------------------------------------------------------
// Display Header
// ----------------------------------------------------------------------------
void Movie::displayHeader() const 
{
	cout << " ****** MOVIE ITEM ***** " << endl;
}	

//----------------------------------------------------------------------------
// Get Item
// returns the title of movie
// @return title
// ----------------------------------------------------------------------------
string Movie::getItem() const 
{
	return title; 
}

//----------------------------------------------------------------------------
// Get Director
// returns the director of movie
// @return director
//----------------------------------------------------------------------------
string Movie::getDirector() 
{ 
	return director; 
} 

//----------------------------------------------------------------------------
// Get Title
// returns the title of the movie
// @return title
// ----------------------------------------------------------------------------
string Movie::getTitle() 
{ 
	return title;
}

//----------------------------------------------------------------------------
// Get Year
// returns the year
// @return year
// ----------------------------------------------------------------------------
int Movie::getYear()
{
	return year; 
}
