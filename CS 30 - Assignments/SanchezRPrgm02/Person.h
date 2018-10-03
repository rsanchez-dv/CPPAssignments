//------------------------------------------------------------------------------
// Person.h                                                          04-29-2013
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
using namespace std;
class Person
{
		friend ostream& operator<<(ostream &os, const Person &p);
		friend istream& operator>>(istream &is, Person &p);
	private:
		char* m_name;//name of that person
		int m_age;    //Age of Person
		string m_ssn; // Social Security number of the person
	public:
		Person();
		Person(const char * name, int age, const string& ssn);
		Person(const Person &p);
		~Person();
		Person& operator = (const Person &p);
		//Accessor for each member function
		int Age()   const;
		string Ssn()const;
		string Name() const;
		//mutator for each member function
		void Age(int age);
		void Ssn(string ssn);
		void Name(const char * const name);
};