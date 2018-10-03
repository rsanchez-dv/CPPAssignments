//------------------------------------------------------------------------------
// Person.cpp                                                       
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
	p.write(os);
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Person &p)
{
	p.read(is);
	return is;
}

//------------------------------------------------------------------------------
//		Member Functions
//------------------------------------------------------------------------------
Person::Person():m_age(0),m_ssn( "000-00-0000")
{
	m_name = new char[4];	
	for(int i = 0; i<3; i++)
		m_name[i] = '*';
	m_name[3] = '\0';
	cout<<"\t>>>Default Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::Person(const char * name, int age, const string& ssn):m_age(age),m_ssn(ssn)
{
	m_name = new char[(int)strlen(name)+1];
	for(int i = 0; i<= (int)strlen(name); i++)
		m_name[i] = name[i];	
	m_age = age;
	m_ssn = ssn;
	cout<<"\t>>> Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::Person(const Person &p): m_age(p.m_age),m_ssn(p.m_ssn)
{
	
	m_name = new char[(int)strlen(p.m_name)+1];
	for(int i = 0; i<=(int)strlen(p.m_name); i++)
		m_name[i] = p.m_name[i];
	cout<<"\t>>>Copy Constructor Invoked!<<<\n";
}
//------------------------------------------------------------------------------
Person::~Person()
{
	delete [] m_name;
	cout<<"\n\t>>>Person Class Destructor Invoked<<<\n"<<"Press Enter to Continue...\n"<< flush;
	cin.get();
}
//------------------------------------------------------------------------------
Person& Person::operator=(const Person &p)
{
	if(this == &p)
		return *this;
	else
	{	
		delete [] m_name;
		m_name = new char[(int)strlen(p.m_name)+1];
		for(int i =0; i<=(int)strlen(p.m_name);i++)
			m_name[i] = p.m_name[i];
		m_age = p.m_age;
		m_ssn = p.m_ssn;
		return *this;
	}
}
//------------------------------------------------------------------------------
//		Accessors
//------------------------------------------------------------------------------
int Person:: age()const
{
	return m_age;
}
//------------------------------------------------------------------------------
string Person::ssn()const
{
	return m_ssn;
}
//------------------------------------------------------------------------------
string Person::name() const
{
	return m_name;
}
//------------------------------------------------------------------------------
//		Mutators
//------------------------------------------------------------------------------
void Person::age(int age)
{
	m_age = age;
}
//------------------------------------------------------------------------------
void Person::ssn(string ssn)
{
	m_ssn = ssn;
}
//------------------------------------------------------------------------------
void Person::name(const string& name)
{
	delete [] m_name;
	m_name = new char[(int)name.length()+1];
	for(int i =0; i<=(int)name.length();i++)
		m_name[i] = name[i];
}
//------------------------------------------------------------------------------
//		Read And Write Functions
//------------------------------------------------------------------------------
void Person::read(istream& is)
{
	if(is == cin)
	{
		cout << "Enter Name: " << flush;
		is >> m_name;
		cout << "Enter Age : " << flush;
		is >> m_age;
		cout << "Enter SSN : " << flush;
		is >> m_ssn;
		is.get();
	}
	else
	{
		string temp;
		getline(is,temp);
		delete []  m_name;
		m_name = new char[temp.length()+1];
		int i;
		for(i = 0; i < temp.length();i++)
			m_name[i] = temp[i];
		m_name[i++] ='\0';
		is >> m_age >> m_ssn;
		is.ignore(10,'\n');
	}
}
void Person::write(ostream& os)const
{
	if(os == cout)
	{
		os << "\tName: " << m_name << "\n\tAge : " << m_age << "\n\tSSN : " <<m_ssn;
	}
	else 
	{
		os << m_name << '\n' << m_age<< '\n' << m_ssn<<'\n';
	}
}