//------------------------------------------------------------------------------
// StudentVoter.cpp                                                      
//------------------------------------------------------------------------------
#include <iostream>
#include "StudentVoter.h"
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const StudentVoter &sv)
{
	sv.write(os);
	return os;
}
istream& operator>>(istream &is, StudentVoter &sv)
{
	sv.read(is);
	return is;
}
//------------------------------------------------------------------------------
// Protected Read And Write
//------------------------------------------------------------------------------
void StudentVoter::write(ostream &os) const
{
	Student::write(os);
	if ( os == cout )
		os << "\nParty Affiliation: " << Voter::partyAffiliation();
	else
	os << '\n' <<  Voter::partyAffiliation();
}
//------------------------------------------------------------------------------
void StudentVoter::read(istream &is)
{
	string partyaffiliation;
	Student::read(is);
	if ( is == cin )
	{
		cout << "Enter Party Affiliation: " << flush;
		is >> partyaffiliation;
		is.get();
	}
	else
		is >> partyaffiliation;
	Voter::partyAffiliation(partyaffiliation);
}
//------------------------------------------------------------------------------
// Public Member Functions
//------------------------------------------------------------------------------
StudentVoter::StudentVoter() : Person(), Student(), Voter()  
{}
//------------------------------------------------------------------------------
StudentVoter::StudentVoter(char * name, int age, const string &ssn,float gpa, const string& partyAffiliation)
	: Person(name,age,ssn),
	  Student(name,age,ssn,gpa),
	  Voter(name,age,ssn,partyAffiliation)
{}
//------------------------------------------------------------------------------
StudentVoter::StudentVoter(const StudentVoter &sv) : Person(sv), Student(sv), Voter(sv)
{}

