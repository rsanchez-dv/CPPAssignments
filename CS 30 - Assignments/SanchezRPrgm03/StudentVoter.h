//------------------------------------------------------------------------------
// StudentVoter.h                                                         
//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include "Student.h"
#include "Voter.h"
using namespace std;
class StudentVoter:public  Student, public  Voter
{
	friend ostream& operator<<(ostream &os, const StudentVoter &sv);
	friend istream& operator>>(istream &is, StudentVoter &sv);
protected:
	virtual void read(istream& is);
	virtual void write(ostream& os)const;
public:
	StudentVoter();
	StudentVoter(char * name, int age, const string &ssn,float gpa, const string& partyAffiliation);
	StudentVoter(const StudentVoter& sv);

};