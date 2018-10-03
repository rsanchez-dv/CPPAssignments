#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
#include <iostream>
#include<string>
#include<afxwin.h>
using namespace std;
#define new DEBUG_NEW
const int MAX_SIZE = 20;
struct PhoneBookItem{
	string m_name;
	int m_age;
	string m_phone;

	PhoneBookItem* m_next;
	PhoneBookItem();
	//Default Constructor: Initializes PhoneBook Item
	PhoneBookItem(const string& name,int age, const string& phone,PhoneBookItem* next=0);
	//Constructor: Creates a PhoneBook Item with the parameters
};
class PhoneBook
{
	friend ostream& operator <<(ostream&, const PhoneBook&);
	//Prints out one PhoneBookItem of the incoming PhoneBook
public:
	PhoneBook();
	//Default Constructor: Sets m_head and m_num to zero
	PhoneBook(const PhoneBook&);
	//Constructor: Creates a new PhoneBook
	~PhoneBook();
	//Destructor: Deletes list from memory
	PhoneBook& operator = (const PhoneBook&);
	//Copies one PhoneBook to another if they are not the same
	bool IsEmpty() const;
	//Returns if the list is empty
	//Precondition: None
	//Postcondition: returns: 
	//				 true if current list is empty
	//				 or
	//				 false if current list is NOT empty
	int Size()const;
	//Returns the Size of the current list
	//Preconditions:None
	//Postconditions: returns size of the list "m_num"
	bool Insert(const string& name,int age, const string& phone);
	//Returns if you can insert a PhoneBookItem
	//Precondition:A valid name, age, phonenumber
	//Postcondition: Either return:
	//					true if the phone number does not exist then insert phonebook item into list
	//					or
	//					false if the phone number already exists
	bool Delete(const string & name);
	//Deletes the person the user typed name
	//Precondition: A valid name to delete
	//Postcondition:Either return:
	//				true if name exisits and was deleted
	//				or 
	//				false if name doesn't not exist in list
	bool LookUp(const string& name, int& age, string& phone);
	// Searches name in the list and returns phonenumber and age
	//Preconditon:A name
	//Postcondition: Either returns:
	//				true if name is found
	//				or
	//				false if name is not found
	int GetMaxAge();
	//Return MaxAge
	PhoneBook GetPeopleWithGivenAge(int age);
	//Prints people who share the same incoming age
	PhoneBook GetAllPeopleWithMaxAge();
	//Records and Print people with Max Age
private:
	void Clear();
	//Deletes entire list
	//Preconditions: None
	//Postconditions: Deletes entire list
	void Copy(const PhoneBook&);
	//Makes a copy of entire list
	//Precondition: Valid PhoneBook
	//Postcondition: Copies the list to a new list
	PhoneBookItem* m_head;
	int m_num;
};
#endif