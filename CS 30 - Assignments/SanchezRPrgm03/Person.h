//------------------------------------------------------------------------------
// Person.h                                                          
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
protected:
		virtual void read(istream& is);
		virtual void write(ostream& os)const;
	public:
		//----------Constructors
		Person();
		Person(const char * name, int age, const string& ssn);
		Person(const Person &p);
		~Person();
		//----------Assignment operator
		virtual Person& operator = (const Person &p);
		//----------Accessor 
		int age()   const;
		string ssn()const;
		string name() const;
		//----------Mutators
		void age(int age);
		void ssn(string ssn);
		void name(const string& name);
};