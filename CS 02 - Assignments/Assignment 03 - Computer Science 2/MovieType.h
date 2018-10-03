//|
//|		MovieType.h
//|------------------------------------
#include"SortedMovieList.h"
#ifndef __MOVIETYPE_H__
#define __MOVIETYPE_H__
#include <iostream>
#include<fstream>
using namespace std;

class MovieType
{
	//friend bool operator ==(const MovieType& p1,const MovieType& p2);
	////Compares two MovieType object's m_title
	////Precondition:p2  has a valid m_title
	////Postcondition:Either returns false if not true or returns true
	////if title's match
	//friend bool operator <(const MovieType& p1,const MovieType& p2);
	////Compare if object's m_title is less than p2's m_title
	////Precondition:p2 has a valid m_title
	////Postcondition:Either returns false if object's m_title is less than p2's m_title
	////or returns true if object's m_title is less than p2's m_title
	//friend bool operator >(const MovieType& p1, const MovieType& p2);
	////Compare if object's m_title is greater than p2's m_title
	////Precondition:p2 has a valid m_title
	////Postcondition: Either returns false if object's m_title is Greater than p2's m_title
	////or returns true if object's m_title is greater than p2's m_title
	//friend bool operator >=(const MovieType& p1,const MovieType& p2);
	////Compare if object's m_title is greater than or equal than p2's m_title
	////Precondition:p2 has a valid m_title
	////Postcondition: Either returns false if object's m_title is greater than or equal than p2's m_title
	////or returns true if object's m_title is greater than p2's m_title
	//friend bool operator <=(const MovieType& p1,const MovieType& p2);
	////Compare if object's m_title is less than or equal than p2's m_title
	////Precondition:p2 has a valid m_title
	////Postcondition: Either returns false if object's m_title is less than or equal than p2's m_title
	////or returns true if object's m_title is greater than p2's m_title
	//friend bool operator !=(const MovieType& p1,const MovieType& p2);
	////Compare if object's m_title is not equal than p2's m_title
	////Precondition:p2 has a valid m_title
	////Postcondition: Either returns false if object's m_title is NOT equal than p2's m_title
	////or returns true if object's m_title is greater than p2's m_title
private:
	string m_title,m_year,m_receipts,m_studio,m_stars;//m_title is key
public:
	MovieType();
	//Constructor- Sets all the private members to " "
	bool ReadOneMovieFromFile(ifstream &fin);
	//Reads one movie from file
	//Precondition:A file must be open with the 
	//appropriate information
	//Postcondition:Reads the givin information to 
	//fill in the givin private members
	void Initialize(string title, string year, string receipts,string studio,string stars);
	//Initialize private members
	//Precondition: data in parameters must be valid
	//Postcondition: Sets given data in parameters to 
	//be set to private data
	void Display()const;
	//Prints out data of MovieType Object
	//Preconditions: NONE
	//Postconditions: Prints out private data inside object
	int CompareKeys(const MovieType& p2)const;
	//Compares movie titles between two objects
	//Preconditions:p2 must have data in m_title
	//Postcondition: returns difference between the two
	string getkey()const;
	//Retrieves title
	//Precondition: None
	//Postcondition: returns m_title
	bool operator ==(const MovieType& p2)const;
	//Compares two MovieType object's m_title
	//Precondition:p2  has a valid m_title
	//Postcondition:Either returns false if not true or returns true
	//if title's match
	bool operator <(const MovieType& p2)const;
	//Compare if object's m_title is less than p2's m_title
	//Precondition:p2 has a valid m_title
	//Postcondition:Either returns false if object's m_title is less than p2's m_title
	//or returns true if object's m_title is less than p2's m_title
	bool operator >(const MovieType& p2)const;
	//Compare if object's m_title is greater than p2's m_title
	//Precondition:p2 has a valid m_title
	//Postcondition: Either returns false if object's m_title is Greater than p2's m_title
	//or returns true if object's m_title is greater than p2's m_title
	bool operator >=(const MovieType& p2)const;
	//Compare if object's m_title is greater than or equal than p2's m_title
	//Precondition:p2 has a valid m_title
	//Postcondition: Either returns false if object's m_title is greater than or equal than p2's m_title
	//or returns true if object's m_title is greater than p2's m_title
	bool operator <=(const MovieType& p2)const;
	//Compare if object's m_title is less than or equal than p2's m_title
	//Precondition:p2 has a valid m_title
	//Postcondition: Either returns false if object's m_title is less than or equal than p2's m_title
	//or returns true if object's m_title is greater than p2's m_title
	bool operator !=(const MovieType& p2)const;
	//Compare if object's m_title is not equal than p2's m_title
	//Precondition:p2 has a valid m_title
	//Postcondition: Either returns false if object's m_title is NOT equal than p2's m_title
	//or returns true if object's m_title is greater than p2's m_title

	void setkey(string title);
	//Sets object's m_title 
	//Precondition:title is a valid string
	//Postcondition: m_title is set to title
};
#endif