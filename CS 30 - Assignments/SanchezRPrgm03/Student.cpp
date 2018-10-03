//------------------------------------------------------------------------------
// Student.cpp														  
//------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"Student.h"
using namespace std;
//------------------------------------------------------------------------------
//		Friend Functions
//------------------------------------------------------------------------------
ostream& operator<<(ostream &os, const Student &s)
{
	s.write(os);
	return os;
}
//------------------------------------------------------------------------------
istream& operator>>(istream &is, Student &s)
{
	s.read(is);
	return is;
}
//------------------------------------------------------------------------------
//		Functions
//------------------------------------------------------------------------------
Student::Student():Person(),m_gpa(0)
{}
//------------------------------------------------------------------------------
Student::Student(const char * name, int age, const string& ssn, float gpa): Person(name,age,ssn),m_gpa(gpa)
{}
//------------------------------------------------------------------------------
Student::Student(const Student &s):Person(s),m_gpa(s.m_gpa)
{}
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
void Student::read(istream& is)
{
	Person::read(is);
	if(is == cin)
	{
		cout << "Enter GPA: " << flush;
		is >> m_gpa;
		is.get();
	}
	else
	{
		is >> m_gpa;
	}
}
//------------------------------------------------------------------------------
void Student::write(ostream& os)const
{
	Person::write(os);
	if(os == cout)
	{
		os << "\n\tGpa : " << m_gpa;
	}
	else
	{
		os<<'\n' << m_gpa;
	}
	
}
//------------------------------------------------------------------------------