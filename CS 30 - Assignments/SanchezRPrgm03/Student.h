//------------------------------------------------------------------------------
// Student.h                                                          
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Student: public virtual Person
{
	friend ostream& operator<<(ostream &os, const Student &s);
	friend istream& operator>>(istream &is, Student &s);
private:
	float m_gpa;
protected:
	virtual void read(istream& is);
	virtual void write(ostream& os)const;
public:
	//----------Constructors
	Student();
	Student(const char * name, int age, const string& ssn, float gpa);
	Student(const Student &s);
	//----------Assignment Operator
	Student& operator = (const Student &s);
	//----------Accessor and Mutator
	float gpa() const;
	void gpa(const float& gpa);

};