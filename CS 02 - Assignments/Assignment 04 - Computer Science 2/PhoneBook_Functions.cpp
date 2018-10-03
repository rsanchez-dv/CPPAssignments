#include"PhoneBook.h"
#include<iostream>
#include<string>
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;
ostream& operator<<(ostream&, const PhoneBookItem&);
//OutPut Operator: Prints PhoneBookItem Data
//______________________________________________________________________________
PhoneBookItem::PhoneBookItem()
{
	m_name = "";
	m_age = -99;
	m_phone = " ";
	m_next = NULL;
}
//______________________________________________________________________________
PhoneBookItem::PhoneBookItem(const string& name,int age, const string& phone,PhoneBookItem *next)
{
	m_name = name;
	m_age = age;
	m_phone = phone;
	m_next = next;
}
//______________________________________________________________________________
PhoneBook::PhoneBook()
{
	m_head= new PhoneBookItem(" ",-99," ",NULL);
	m_num   = 0;
}
//______________________________________________________________________________
PhoneBook::PhoneBook(const PhoneBook& pb)
{
	m_head   = pb.m_head;
	m_num    = pb.m_num;
	Copy(pb);
}
//______________________________________________________________________________
PhoneBook::~PhoneBook()
{
	Clear();
}
//______________________________________________________________________________
PhoneBook& PhoneBook::operator=(const PhoneBook& pb)
{
	if(this != &pb)
	{
		Clear();
		Copy(pb);
	}
	return *this;
}
//______________________________________________________________________________
bool PhoneBook::IsEmpty()const
{
	return m_num == 0;
}
//______________________________________________________________________________
int PhoneBook::Size()const
{
	return m_num;
}
//______________________________________________________________________________
bool PhoneBook::Insert(const string& name, int age, const string& phone)
{
	PhoneBookItem *p = m_head->m_next;
	PhoneBookItem *n = m_head;
	bool flag = true;

	while(p!=0)	
	{
		if(name < p->m_name)
		{
			break;
		}
		if(name == p->m_name)
		{
			return false;
		}
		p=p->m_next;
		n=n->m_next;
	}
	n->m_next = new PhoneBookItem(name,age,phone,n->m_next);
	m_num++;
	return true;


}
//______________________________________________________________________________
bool PhoneBook::Delete(const string& name)
{
	PhoneBookItem *p  = m_head->m_next;
	PhoneBookItem *tp = m_head;
	while( p != 0)
	{
		if( p->m_name == name)
		{
			tp->m_next = p->m_next;
			delete p;
			m_num--;
			return true;
		}
		else if(p->m_name > name)
		{
			return false;
		}
		tp = p;
		p = p->m_next;
	}
	return false;
}
//______________________________________________________________________________
bool PhoneBook::LookUp(const string& name, int& age , string& phone)
{
	PhoneBookItem *p = m_head;
	while(p != 0)
	{
		if(name == p->m_name)
		{
			age = p->m_age;
			phone = p->m_phone;
			return true;
		}
		else if(p->m_name >name)
		{
			return false;
		}
		p = p->m_next;
	}
	return false;

}
//______________________________________________________________________________
void PhoneBook::Clear()
{
	PhoneBookItem *p = m_head;
	PhoneBookItem *save;
	while(p != 0)
	{
		save= p->m_next;
		delete p;
		p = save;
	}
}
//______________________________________________________________________________
void PhoneBook::Copy(const PhoneBook& ExistingPhoneBook)
{
	m_num = ExistingPhoneBook.m_num;
	m_head = new PhoneBookItem(" ",-99," ",0);
	PhoneBookItem *p = ExistingPhoneBook.m_head->m_next;
	PhoneBookItem *pThis = m_head;
	while(p != 0)
	{
		pThis->m_next = new PhoneBookItem(p->m_name,p->m_age,p->m_phone,p->m_next);
		p = p->m_next;
		pThis = pThis->m_next;
	}
}
//______________________________________________________________________________
ostream& operator <<(ostream& os, const PhoneBook& book)
{
	PhoneBookItem *p= book.m_head->m_next;
	while( p!=0)
	{
		os << *p << endl;
		p = p->m_next;
	}
	return os;
}
//______________________________________________________________________________
ostream& operator<<(ostream& cout, const PhoneBookItem& n)
{
	//cout<<" Name: "<<n.m_name<<"\tAge: "<<n.m_age<<"\t Phone_Number: "<<n.m_phone;
	cout<<"______________________________________________\n";
	cout<<" Name:         "<<n.m_name <<"\n";
	cout<<" Age:          "<<n.m_age  <<"\n";
	cout<<" Phone Number: "<<n.m_phone<<"\n";
	
	return cout;
}
//______________________________________________________________________________
int PhoneBook::GetMaxAge()
{
	int MaxAge=0;
	PhoneBookItem *p = m_head;
	while(p != 0)
	{

		if(p->m_age >MaxAge)
		{
			MaxAge = p->m_age;
		}
		p = p->m_next;
	}
	return MaxAge;
}
//______________________________________________________________________________
PhoneBook PhoneBook::GetPeopleWithGivenAge(int age)
{
	bool flag = false;
	PhoneBook hold;
	PhoneBookItem *p = m_head;
	while(p != 0)
	{
		if(age == p->m_age)
		{
			flag = true;
			hold.Insert(p->m_name,p->m_age,p->m_phone);
		}
		p = p->m_next;
	}
	if(flag == false)//if none has been found
		cout<<" (!) No one has that age\n";

	return hold;//USEFULL!
}
//_____________________________________________________________________________
PhoneBook PhoneBook::GetAllPeopleWithMaxAge()
{
	PhoneBook hold;
	PhoneBookItem *p = m_head->m_next;
	int Max_Age = 0;

	while(p != 0)
	{ 
		if(p->m_age > Max_Age)
		{
			hold.Clear();
			hold.m_head = new PhoneBookItem(" ",-99," ",0);
			hold.Insert(p->m_name,p->m_age,p->m_phone);
			Max_Age = p->m_age;
		}
		else if(p->m_age == Max_Age)
		{
			hold.Insert(p->m_name,p->m_age,p->m_phone);
		}
		p = p->m_next;
	}
	return hold;
}
