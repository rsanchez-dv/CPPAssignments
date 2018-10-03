//------------------------------------------------------------------------------
// Faculty.cpp                                                    
//------------------------------------------------------------------------------
#include<iostream>
#include"Voter.h"
#include<string>
using namespace std;
//------------------------------------------------------------------------------
//	Input/Output Operator
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const Voter &v)
{
	v.write(os);
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Voter &v)
{
	v.read(is);
	return is;
}
//------------------------------------------------------------------------------
//	Member Functions
//------------------------------------------------------------------------------
Voter::Voter():Person(), m_partyAffilitation("***")
{}
//------------------------------------------------------------------------------
Voter::Voter(char * name, int age, const string &ssn, const string& partyAffiliation)
	:Person(name,age,ssn),m_partyAffilitation(partyAffiliation)
{}
//------------------------------------------------------------------------------
Voter::Voter(const Voter& v):Person(v),m_partyAffilitation(v.m_partyAffilitation)
{}
//------------------------------------------------------------------------------
string Voter::partyAffiliation() const
{
	return m_partyAffilitation;
}
//------------------------------------------------------------------------------
void Voter::partyAffiliation(const string& partyAffiliation)
{
	m_partyAffilitation = partyAffiliation;
}
//------------------------------------------------------------------------------
//	Read/write Functions
//------------------------------------------------------------------------------
void Voter::read(istream& is)
{
	Person::read(is);
	if(is == cin)
	{
		cout << "Enter Party Affiliation: ";
		getline(is,m_partyAffilitation);
	}
	else
	{
		getline(is,m_partyAffilitation);
	}
	
}
//------------------------------------------------------------------------------
void Voter::write(ostream& os)const
{
	Person::write(os);
	if(os == cout)
	{
		os << "\n\tParty Affiliation: " << m_partyAffilitation;
	}
	else
	{
		os << m_partyAffilitation<< '\n';
	}
}
//------------------------------------------------------------------------------