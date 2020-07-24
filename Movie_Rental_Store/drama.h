// --------------------- drama.h -----------------------------------------
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


#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

using namespace std;

class Drama: public Movie {
public: 
	Drama();
	Drama(const Drama& ); //copy constructor
	~Drama(); //destructor


	virtual void display() const;
	virtual void displayHeader() const;
	virtual void setData(istream&);
	virtual void setData2(istream&);
	virtual bool operator==(const Inventory& ) const;
	virtual bool operator<(const Inventory& ) const;
	virtual Inventory * create(); 

private:
	const string GENRE;	//set to drama
};


#endif

