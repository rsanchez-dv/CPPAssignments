//------------------------------------------------------------------------------
// Voter.h                                                         
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Voter:public virtual Person
{
	friend ostream& operator<<(ostream &os, const Voter &v);
	friend istream& operator>>(istream &is, Voter &v);
private:
	string m_partyAffilitation;
protected:
	virtual	void read(istream& is);
	virtual void write(ostream& os)const;
public:
	Voter();
	Voter(char * name, int age, const string &ssn, const string& partyAffiliation);
	Voter(const Voter& v);
	string partyAffiliation() const;
	void partyAffiliation(const string& partyAffiliation);
};