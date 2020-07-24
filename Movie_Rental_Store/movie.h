
// --------------------- movie.h -----------------------------------------
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


#ifndef MOVIE_H
#define MOVIE_H
#include "inventory.h"

using namespace std;


class Movie : public Inventory 
{
public:
	Movie();	//constructor
	Movie(const Movie& rightSide);
	~Movie();	//destructor

	 virtual void display() const;
	 virtual void displayHeader() const = 0;
	 virtual void setData(istream& infile);
	 virtual void setData2(istream&) = 0;	//addition information to set
	
	 virtual string getItem() const;	//return the inventory item
	 string getDirector(); //returns the director
	 string getTitle();	//returns the title
	 int getYear();		//returns the year

	 //these must be overridden in order to determin sort orders
	 virtual bool operator==(const Inventory&) const = 0;
	 virtual bool operator<(const Inventory&) const = 0;
	 virtual Inventory* create() = 0;

protected:
	string title;		//title of movie
	string director;	//director of movie
	int year;			//year created
	
};

#endif

