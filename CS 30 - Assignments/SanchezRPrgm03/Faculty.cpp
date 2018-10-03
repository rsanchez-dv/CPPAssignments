//------------------------------------------------------------------------------
// Student.cpp														    
//------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"Faculty.h"
using namespace std;
//------------------------------------------------------------------------------
//		Friend Functions
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const Faculty &f)
{
	f.write(os);
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Faculty &f)
{
	f.read(is);
	return is;
}
//------------------------------------------------------------------------------
//		Functions
//------------------------------------------------------------------------------
Faculty::Faculty():Person(), m_numOfDegrees(0),m_degrees(new string[1])
{
		m_degrees[0] = "***";
}
//------------------------------------------------------------------------------
Faculty::Faculty(const char * name, int age, const string& ssn, int numberOfDegrees,const string* degrees)
	:Person(name,age,ssn), m_numOfDegrees(numberOfDegrees), m_degrees(new string[m_numOfDegrees])
{
	for(int i =0; i< m_numOfDegrees;i++)
		m_degrees[i] = degrees[i];
}
Faculty::~Faculty()
{
	delete [] m_degrees;
}
//------------------------------------------------------------------------------
Faculty::Faculty(const Faculty &s):Person(s), m_numOfDegrees(s.m_numOfDegrees),m_degrees(s.m_degrees)
{}
//------------------------------------------------------------------------------
Faculty& Faculty::operator = (const Faculty &f)
{
	if(this == &f)
		return *this;
	else
	{	this->name(f.name());
		this->age(f.age());
		this->ssn(f.ssn());
		m_numOfDegrees = f.m_numOfDegrees;
		delete [] m_degrees;
		m_degrees = new string[f.m_numOfDegrees];
		for(int i =0; i< f.m_numOfDegrees;i++)
			m_degrees[i] = f.m_degrees[i];
		return *this;
	}
}
//------------------------------------------------------------------------------
int Faculty::numOfDegrees() const
{
	return m_numOfDegrees;
}
//------------------------------------------------------------------------------
string Faculty::degrees()const
{
	return *m_degrees;
}
//------------------------------------------------------------------------------
void Faculty::degrees(const string* Degrees,int numOfDegrees)
{
	m_numOfDegrees = numOfDegrees;
	delete [] m_degrees;
	m_degrees = new string[m_numOfDegrees];
	int i;									 
	for (i = 0; i < m_numOfDegrees; i++ )
		m_degrees[i] = Degrees[i];
}
//------------------------------------------------------------------------------
void Faculty::read(istream& is)
{
	Person::read(is);
	if(is == cin)
	{
		cout << "Enter Number of Degrees: ";
		is >> m_numOfDegrees;
		delete [] m_degrees;
		m_degrees = new string[m_numOfDegrees];
		for(int i = 0; i < m_numOfDegrees; i++)
		{
			cout<<"Enter Degree: ";
			is>>m_degrees[i];
		}
	}
	else
	{
		is >> m_numOfDegrees;
		delete [] m_degrees;
		m_degrees = new string[m_numOfDegrees];
		for(int i = 0; i< m_numOfDegrees; i++)
			is>>m_degrees[i];
	}
}
//------------------------------------------------------------------------------
void Faculty::write(ostream& os)const
{
	Person::write(os);
	if(os == cout)
	{
		os << "\n\tNumber of Degrees: "<<m_numOfDegrees
		   << "\n\tDegrees:";
		for(int i = 0; i< m_numOfDegrees; i++)
		{
			os <<" "<< m_degrees[i];
		}
	}
	else
	{
		os<<m_numOfDegrees<<'\n';
		for(int i = 0; i< m_numOfDegrees; i++)
		{
			os << m_degrees[i] << '\n';
		}
	}
	
}
//------------------------------------------------------------------------------