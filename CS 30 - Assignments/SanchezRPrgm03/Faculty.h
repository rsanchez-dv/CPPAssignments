//------------------------------------------------------------------------------
// Faculty.h                                                         
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Faculty: public Person
{
	friend ostream& operator<<(ostream &os, const Faculty &f);
	friend istream& operator>>(istream &is, Faculty &f);
private:
	int m_numOfDegrees;
	string* m_degrees;//Dynamic allocated memory
public:
	//----------Constructors
	Faculty();
	Faculty(const char * name, int age, const string& ssn, int numberOfDegrees,const string* degrees);
	Faculty(const Faculty &f);
	~Faculty();
	//----------Assignment Operator
	virtual Faculty& operator = (const Faculty &f); 
	//----------Accessor and Mutator
	int numOfDegrees() const;
	string degrees()const;
	void degrees(const string* degrees, int numOfDegrees);
	//----------Read/Write
	void read(istream& is);
	void write(ostream& os) const;
};