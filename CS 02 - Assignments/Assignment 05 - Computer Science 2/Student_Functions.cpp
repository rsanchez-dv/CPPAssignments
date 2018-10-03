#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;
ostream& operator<<(ostream& os, const TreeNode& n);
//Prints out a TreeNode information
//Precondition:None
//Postcondition: Print out Student Info inside TreeNode
//*********************STUDENT CLASS******************************************************
Student::Student(string name, int age, string major,int test[], int id)
{
	m_name = name;
	m_age = age;
	m_major = major;
	m_test[0]=test[0];
	m_test[1]=test[1]; 
	m_test[2]=test[2];
	m_id = id;
}
//----------------------------------------------------------------------------------------
Student::Student()
{
	m_name = " ";
	m_age = -1;
	m_major = " ";
	m_test[0]= -1;
	m_test[1]= -1; 
	m_test[2]= -1;
	m_id = -1;
}
//----------------------------------------------------------------------------------------
bool Student::readFromFile(ifstream& is)
{
	getline(is,m_name);
	if(m_name == "***")
		return true;
	getline(is,m_major);
	is>>m_age;
	is>>m_test[0];
	is>>m_test[1];
	is>>m_test[2];
	is>>m_id;
	is.ignore(10,'\n');
	return false;
}
//----------------------------------------------------------------------------------------
bool Student::readFromKeyboard()
{
	//Verifications on Good DATA???
	cin.ignore(10,'\n');
	cout<<" Enter Student's:\n";
	cout<<" Name      : ";
	getline(cin,m_name);
	cout<<" Major     : ";
	getline(cin,m_major);
	cout<<" Age       : ";
	cin>>m_age;
	cout<<" Enter each score indivudualy:\n";
	for(int i = 0; i<3; i++)
	{
		cout<<" Test Score: ";
		cin>>m_test[i];
	}
	cout<<"Enter Student's ID Number: ";
	cin>>m_id;
	return false;
}
//----------------------------------------------------------------------------------------
void Student::WriteToFile(ofstream& os)
{
	os<<m_name<<endl;
	os<<m_major<<endl;
	os<<m_age<<endl;
	os<<m_test[0]<<" "<<m_test[1]<<" "<<m_test[2]<<endl;
	os<<m_id<<endl;
}
//----------------------------------------------------------------------------------------
void Student::WriteToScreen()
{
	cout<<"_____________________________________________________\n";
	cout<<"   Name  : "<<m_name<<endl;
	cout<<"   Age   : "<<m_age<<endl;
	cout<<"   Major : "<<m_major<<endl;
	cout<<"   Grades: "<<m_test[0]<<" "<<m_test[1]<<" "<<m_test[2]<<endl;
	cout<<"   ID    : "<<m_id<<endl;
}
//----------------------------------------------------------------------------------------
string Student::GetName()const
{return m_name;}
int Student::GetAge()const
{return m_age;}
string Student::GetMajor()const
{return m_major;}
int Student::GetID()const
{return m_id;}
//***********************  PUBLIC FUNCTION  **********************************************
ostream& operator<<(ostream& os, const TreeNode& n)
{
	os<<"_____________________________________________________\n";
	os<<" Name  : "<<n.m_student.GetName()<<endl;
	os<<" Age   : "<<n.m_student.GetAge()<<endl;
	os<<" Major : "<<n.m_student.GetMajor()<<endl;
	os<<" Grades: "<<n.m_student.GetTest1()<<" "<<n.m_student.GetTest2()<<" "<<n.m_student.GetTest3()<<endl;
	os<<" ID    : "<<n.m_student.GetID()<<endl;
	return os;
}
//*********************** TREE NODE STRUCT ***********************************************
TreeNode::TreeNode(const Student& student, TreeNode* left, TreeNode* right):m_student(student),m_left(left),m_right(right)
{
}
//***********************  TREE CLASS  ***************************************************
ostream& operator<<(ostream& os, const Tree& tree)
{
	os<<tree.m_root->m_student;
	return os;
}
//----------------------------------------------------------------------------------------
Tree::Tree()
{
	m_root = 0;
}
//----------------------------------------------------------------------------------------
Tree::Tree(const Tree& tree2)
{
	Copy(tree2);
}
//----------------------------------------------------------------------------------------
Tree::~Tree()
{
	Clear(m_root);
}
//----------------------------------------------------------------------------------------
bool Tree::IsEmpty()const
{
	return m_root == 0;
}
//----------------------------------------------------------------------------------------
int Tree::Size()const
{
	return Size(m_root);
}
//----------------------------------------------------------------------------------------
bool Tree::Insert(const Student& student)
{
	return Insert(student,m_root);
}
//----------------------------------------------------------------------------------------
bool Tree::Delete(int id)
{
	return Delete(id,m_root);
}
//----------------------------------------------------------------------------------------
bool Tree::LookUp(Student& student)const
{
	return LookUp(student,m_root);
}
//----------------------------------------------------------------------------------------
void Tree::Print()const
{
	Print(this->m_root);
}
//----------------------------------------------------------------------------------------
Tree& Tree::operator = (const Tree& tree2)
{
	if(this != &tree2)
	{
		Clear(this->m_root);
		m_root = NULL;
		Copy(tree2);
	}
	return *this;
}
//=========================== PRIVATE =====================================================
//Helper functions
//----------------------------------------------------------------------------------------
bool Tree::Insert(const Student& student, TreeNode*& pTree)
{
	if(pTree == 0)
	{
		pTree = new TreeNode(student,NULL,NULL);
		return true;
	}
	if(student.GetID() < pTree->m_student.GetID())
		return Insert(student,pTree->m_left);
	else 
		if(student.GetID() > pTree->m_student.GetID())
			return Insert(student,pTree->m_right);
	return false; 
}
//----------------------------------------------------------------------------------------
int Tree::Size(TreeNode* pTree)const
{
	if(pTree == 0)
		return 0;
	return 1+ Size(pTree->m_left)+Size(pTree->m_right);
}
//---------------------------------------------------------------------------------------- 
void Tree::Print(TreeNode* pTree)const
{
	if(pTree == 0)
		return;

	Print(pTree->m_left);
	Print(cout,pTree);
	Print(pTree->m_right);
	
}
//---------------------------------------------------------------------------------------
void Tree::Print(ostream& os, TreeNode* pTree)const
{
	os<<*pTree;
}
//----------------------------------------------------------------------------------------
bool Tree::LookUp(Student& student, TreeNode* pTree)const
{
	if(pTree==0)
		return false;
	if(pTree->m_student.GetID() == student.GetID())
	{
		//student = pTree->m_student;
		int temp[3];//
		temp[0] = pTree->m_student.GetTest1();//
		temp[1] = pTree->m_student.GetTest2();//Must be an easier way...
		temp[2] = pTree->m_student.GetTest3();//
		student.SetName(pTree->m_student.GetName());
		student.SetAge(pTree->m_student.GetAge());
		student.SetId(pTree->m_student.GetID());
		student.SetMajor(pTree->m_student.GetMajor());
		student.SetTest(temp);
		return true;
	}
	if(student.GetID() < pTree->m_student.GetID())
		return LookUp(student, pTree->m_left);
	else
		return LookUp(student, pTree->m_right);
}
//---------------------------------------------------------------------------------------- 
bool Tree::Delete(int id, TreeNode*& pTree)//&???????????
{
	if(pTree == 0)
		return false;
	else 
		{
			if (id == pTree->m_student.GetID())
		{
			DeleteNode(pTree);
			return true;
		}
		else 
			if(id >pTree->m_student.GetID())
				return Delete(id,pTree->m_right);
			/*else
				if(id < pTree->m_student.GetID())*/
			else
					return Delete(id,pTree->m_left);
	    }
}
//----------------------------------------------------------------------------------------
void Tree::DeleteNode(TreeNode*& pTree)
{	TreeNode* temp = pTree;
	Student student;
	if(pTree-> m_left == 0)
	{
		pTree = pTree->m_right;
		delete temp;
	}
	else if(pTree->m_right == 0)
	{
		pTree = pTree->m_left;
		delete temp;
	}
	else //if(pTree->m_left != 0 && pTree->m_right !=0)// -> hard case!!! two children
	{
		GetPredecessor(student, pTree->m_left);
		pTree->m_student = student;
		Delete(student.GetID(), pTree->m_left);
	}

}
void Tree::GetPredecessor(Student& student, TreeNode* pTree) const
{
	while( pTree->m_right != 0 )
	{
		pTree = pTree->m_right;
	}
	student = pTree->m_student;
}

//----------------------------------------------------------------------------------------
void Tree::Clear(TreeNode* pTree)
{
	if(pTree == 0)
		return;

	Clear(pTree->m_right);
	Clear(pTree->m_left);
	delete pTree;
}
//----------------------------------------------------------------------------------------
void Tree::Copy(const Tree& list2)
{
	Copy(m_root,list2.m_root);
}
//----------------------------------------------------------------------------------------
void Tree::Copy(TreeNode*& pThis, TreeNode* pTree2)
{
	if(pTree2==0)
		return;
	//YOU FINISH THE REST --> 3 LINES
	// ??? = new TreeNode(...);
	TreeNode* NewNode = new TreeNode(pTree2->m_student, pTree2->m_left,pTree2->m_right);
	Copy(pThis->m_left,pTree2->m_left);
	Copy(pThis->m_right,pTree2->m_right);
}
//----------------------------------------------------------------------------------------
void Tree::PrintFile(ofstream& fout)const
{
	PrintFile(fout,m_root);
}
void Tree::PrintFile(ofstream& fout, TreeNode* pTree)const
{
	if(pTree == 0)
		return;
	PrintFile(fout,pTree->m_left);
	pTree->m_student.WriteToFile(fout);
	PrintFile(fout,pTree->m_right);
}