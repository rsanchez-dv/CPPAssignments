//------------------------------------------------------------------------------
// Student.h                                                          04-29-2013
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Student: public Person
{
		friend ostream& operator<<(ostream &os, const Student &p);
		friend istream& operator>>(istream &is, Student &p);
	private:
		float m_gpa;
	public:
		Student();
		Student(const char * name, int age, const string& ssn, float gpa);
		Student(const Student &s);
		~Student();
		Student& operator = (const Student &p);
		//Accessor for each member function
		float gpa() const;
		//mutator for each member function
		void gpa(const float& gpa);
};