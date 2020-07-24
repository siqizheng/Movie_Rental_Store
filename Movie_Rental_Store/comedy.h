// --------------------- comedy.h -----------------------------------------
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

#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"


//----------------------------------------------------------------------------
// Class: ComedyMovie
// child class of movie class, granchild of inventory class. 
//----------------------------------------------------------------------------
// 
//

class Comedy : public Movie {
public: 
	Comedy();
	Comedy(const Comedy& );
	~Comedy();//end destructor

	virtual void display() const;
	virtual void displayHeader() const;
	virtual void setData(istream& );
	virtual void setData2(istream& );
	virtual bool operator==(const Inventory& ) const;
	virtual bool operator<(const Inventory& ) const;
	virtual Inventory * create(); //end create
private:
	const string GENRE;
};



#endif

