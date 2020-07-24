
// --------------------- classic.h -----------------------------------------
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

#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include "movie.h"


//----------------------------------------------------------------------------
// Class: ClassicMovie
// child class of movie class, granchild of inventory class. 
//----------------------------------------------------------------------------
// 
//

class Classic : public Movie 
{

public:
	Classic();
	Classic(const Classic& rightSide);
	~Classic();

	void setData(istream& infile);
	virtual void setData2(istream& infile);
	void display() const;
	virtual void displayHeader() const;
	virtual bool operator==(const Inventory& rightSide) const;
	virtual bool operator<(const Inventory& rightSide) const;
	virtual Inventory * create();

private:
	string actorFName, actorLName;
	int month;
	const string GENRE;
};


#endif
