//------------------------------------------------------------------------------
// Person.cpp                                                       04-29-2013
//------------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
#include"Person.h"
using namespace std;
//------------------------------------------------------------------------------
//		Friend Functions
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const Person &p)
{
	if ( os == cout )
		os << "\tName: " << p.m_name << "\n\tAge : " << p .m_age << "\n\tSSN : " << p.m_ssn;
	else
		os << p.m_name << '\n' << p.m_age<< '\n' << p.m_ssn;
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Person &p)
{
	//is >> (Person)p;//Don't know what this does...
	//if ( is == cin )
	//{
		cout << "Enter Name: " << flush;
		is >> p.m_name;//WOuld this work??
		cout << "Enter Age : " << flush;
		is >> p.m_age;
		cout << "Enter SSN : " << flush;
		is >> p.m_ssn;
		is.get();
	//}
	//else
		//is >> p.m//What the fuck is this??
	
	return is;
}
//------------------------------------------------------------------------------
//		Member Functions
//------------------------------------------------------------------------------
Person::Person()
{
	
	m_name = new char[4];	
	for(int i = 0; i<3; i++)
		m_name[i] = '*';
	m_name[3] = '\0';
	m_age = 0;
	m_ssn = "000-00-0000";//Not sure if Initialize correctly
	cout<<"\t>>>Default Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::Person(const char * name, int age, const string& ssn)
{
	
	m_name = new char[(int)strlen(name)+1];
	for(int i = 0; i<= (int)strlen(name); i++)
		m_name[i] = name[i];	
	m_age = age;
	m_ssn = ssn;
	cout<<"\t>>> Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::Person(const Person &p)
{
	
	m_name = new char[(int)strlen(p.m_name)+1];
	for(int i = 0; i<=(int)strlen(p.m_name); i++)
		m_name[i] = p.m_name[i];
	m_age = p.m_age;//??
	m_ssn = p.m_ssn;
	cout<<"\t>>>Copy Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::~Person()
{
	delete [] m_name;
	cout<<"\t>>>Destructor Invoked<<<\n"<<"Press Enter to Continue...\n"<< flush;
	cin.get();
}
//------------------------------------------------------------------------------
Person& Person::operator = (const Person &p)
{
	if(this == &p)
		return *this;
	else
	{
		delete [] m_name;
		m_name = new char[(int)strlen(p.m_name)+1];
		for(int i = 0; i<=(int)strlen(p.m_name);i++)
			m_name[i]= p.m_name[i];
		m_age = p.m_age;
		m_ssn = p.m_ssn;
		return *this;
	}
}
//------------------------------------------------------------------------------
//		Accessors
//------------------------------------------------------------------------------
int Person:: Age()   const
{
	return m_age;
}
//------------------------------------------------------------------------------
string Person::Ssn()const
{
	return m_ssn;
}
//------------------------------------------------------------------------------
string Person::Name() const
{
	return m_name;
}
//------------------------------------------------------------------------------
//		Mutators
//------------------------------------------------------------------------------
void Person::Age(int age)
{
	m_age = age;
}
//------------------------------------------------------------------------------
void Person::Ssn(string ssn)
{
	m_ssn = ssn;
}
//------------------------------------------------------------------------------
void Person::Name(const char * const name)
{
	delete [] m_name;
	m_name = new char[(int)strlen(name)+1];
	for(int i =0; i<=(int)strlen(name);i++)
		m_name[i] = name[i];
}
//------------------------------------------------------------------------------
