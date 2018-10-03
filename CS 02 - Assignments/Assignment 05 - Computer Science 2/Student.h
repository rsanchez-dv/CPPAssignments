/*
	Student.h
*/
#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<iostream>
#include<string>
#include<fstream>
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;

//--------------------------------------------------------------------------------------
class Student
{
private:
	string m_name;
	int m_age;
	string m_major;
	int m_test[3];
	int m_id;//KEY
public:
	Student(string name, int age, string major, int tests[],int id);
	//CopyCtor
	Student();
	//Default  constructor
	bool readFromFile(ifstream& is);
	//reads from file
	//Precondition: 'is' is a valid
	//Postcondition: copys 
	bool readFromKeyboard();
	//read from Keyboard
	//Precondition:None
	//Postcondition:getss information
	void WriteToFile(ofstream& os);
	//write to file
	//Precondition:incoming os stream
	//Postcondition:writes information to output file
	void WriteToScreen();
	//Writes to screen
	//Precondition: None
	//Postcondition: prints information inside treeclass
	//Add aditional functions here
	//Setter Functions
	void SetId(int id){m_id = id;};
	//sets value for the id
	//Precondition: Valid id
	//Postcondition: sets id to student
	void SetAge(int age){m_age = age;};
	//sets value for the age
	//Precondition: Valid age
	//Postcondition: sets age to student
	void SetName(string name){m_name = name;};
	//sets value for the name
	//Precondition: Valid name 
	//Postcondition: sets name to student
	void SetMajor(string major){m_major = major;};
	//sets value for the major
	//Precondition: Valid major
	//Postcondition: sets major to student
	void SetTest (int test[]){m_test[0]=test[0];m_test[1] =test[1];m_test[2] = test[2];};
	//sets value for the tests
	//Precondition: Valid tests 
	//Postcondition: sets tests to student
	string GetName()const;
	// Returns Name
	//Precondition: None
	//postcondition: returns name
	int    GetAge()const;
	//returns age
	//Precondition: None
	//Postcondition: returns age
	string GetMajor()const;
	//returns major
	//Precondition: None 
	//Postcondition: return major
	int    GetID()const;
	//returns id
	//Precondition: None
	//Postcondition: returns id
	//Getting tests
	int GetTest1()const{return m_test[0];};
	//returns test
	//Precondition: None
	//Postcondition: returns test
	int GetTest2()const{return m_test[1];}
	//returns test
	//Precondition: None
	//Postcondition: returns test
	int GetTest3()const{return m_test[2];};
	//returns test
	//Precondition: None
	//Postcondition: returns test
};
//--------------------------------------------------------------------------------------

struct TreeNode
{
	Student m_student;

	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode(const Student& student, TreeNode* left = NULL, TreeNode* right = NULL);
	//CopyCtor
};
//--------------------------------------------------------------------------------------
class Tree
{
	friend ostream& operator<<(ostream& os, const Tree& tree);
	//outputs information on tree
	//Precondition:Information inside of tree
	//Postcondition: prints to screen
public:
	Tree();
	//Default Constructor
	Tree(const Tree& tree2);
	//Copy Constructor
	~Tree();
	//Destructor
	bool IsEmpty()const;
	//Checks if there is nothing in the tree
	//Precondition: None
	//Postcondition: Returns Either 
	int  Size()const;
	//Returns size
	//Precondition:None
	//Postcondition:
	bool Insert(const Student& student);
	//Inserts student into tree
	//Precondition:valid student data
	//Postcondition:Insert student into tree. Returns either true if insert was successful 
	//													or false if someone has similar id's
	bool Delete(int id);
	//Deletes student from tree
	//Precondition:valid id
	//Postcondition:Deletes the student from tree. Returns either true if found
	//													or false if not
	bool LookUp(Student& student)const;
	//Looks up Student from tree
	//Precondition:Valid Student data(ID)
	//Postcondition:Returns either True: returns true and passes student information through reference
	//											or false if student not found
	void Print()const;
	//Prints students from Tree
	//Precondition:None
	//Postcondition:Prints treeout
	void PrintFile(ofstream&)const;
	//Prints student info on to txt file
	//Precondition:Valid ofstream
	//Postcondition:Prints to file
	Tree& operator = (const Tree& tree2);
	//Copies information from one tree to another
private:
	TreeNode* m_root; // points to root of tree
	//Helper functions
	bool Insert(const Student& student, TreeNode*& pTree);
	//Inserts new student
	//Precondition:Valid Student data(ID)
	//Postcondition:Insert student into tree. Returns either true if insert was successful 
	//													or false if someone has similar id's
	int Size(TreeNode* pTree)const;
	//returns size
	//Precondition:valid pTree
	//Postcondition:Returns size
	void Print(ostream& os, TreeNode* pTree)const;
	//Prints out one student data
	//Precondition:Valid Treenode
	//Postcondition:Prints one student's info through write to screen function
	void Print(TreeNode* pTree)const;
	//prints to screen
	//Precondition:None
	//Postcondition:Calls other print function to print entire tree
	void PrintFile(ofstream&, TreeNode* pTree)const;
	//Prints student data to file
	//Precondition:valid outstream and pTree
	//Postcondition:Prints each student info to output file
	bool LookUp(Student& student, TreeNode* pTree)const;
	//Looks up Student from tree
	//Precondition:Valid Student data(ID)
	//Postcondition:Returns either True: returns true and passes student information through reference
	bool Delete(int id, TreeNode*& pTree);//&???????????
	//Deletes student from tree
	//Precondition:valid id
	//Postcondition:Deletes the student from tree. Returns either true if found
	//	
	void DeleteNode(TreeNode*& pTree);
	//Deletes node from tree
	//Precondition:valid pTree
	//Postcondition:Deletes node and shifts tree
	void GetPredecessor(Student& student,TreeNode* pTree) const;
	//Gets the one before the student you want to delete
	//Precondition:valid pTree
	//Postcondition:returns student data.
	void Clear(TreeNode* pTree);
	//Deletes TreeNode
	//Precondition:
	//Postcondition:
	void Copy(const Tree& list2);
	//Copies from list 2 to this
	//Precondition:valid list2
	//Postcondition:returns list2
	void Copy(TreeNode*& pThis, TreeNode* pTree2);
};
#endif