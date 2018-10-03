//------------------------------------------------------------------------------
// Student.cpp														  04/30/2013
//------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"Student.h"
using namespace std;
//------------------------------------------------------------------------------
//		Friend Functions
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const Student &p)
{
	os << (Person)p;
	os << "\tGpa : " << p.m_gpa << '\n';
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Student &p)
{
	is>>(Person)p;
	cout << "Enter GPA: " << flush;
	is>>p.m_gpa;
	is.get();
	return is;
}
//------------------------------------------------------------------------------
//		Functions
//------------------------------------------------------------------------------
Student::Student()
{
	Person();
	m_gpa = 0;
}
//------------------------------------------------------------------------------
Student::Student(const char * name, int age, const string& ssn, float gpa)
{
	/*Person(name,age,ssn);
	m_gpa = gpa;*/
	Name(name);
	Age(age);
	Ssn(ssn);
	m_gpa = gpa;
}
//------------------------------------------------------------------------------
Student::Student(const Student &s)
{
	//code
	//Name(s.m_name);
	//Age(s.m_age);
	//Ssn(s.m_ssn);
	m_gpa = s.m_gpa;
}
//------------------------------------------------------------------------------
Student::~Student()
{
	cout<<"\t>>>Student Destructor Invoked<<<\n";
	//No memory allocation here??!?
}
//------------------------------------------------------------------------------
Student& Student::operator = (const Student &p)
{
	// Make = Operator
	return *this;
}
//------------------------------------------------------------------------------
float Student::gpa() const
{
	return m_gpa;
}
//------------------------------------------------------------------------------
void Student::gpa(const float& gpa)	
{
	m_gpa = gpa;
}
//------------------------------------------------------------------------------