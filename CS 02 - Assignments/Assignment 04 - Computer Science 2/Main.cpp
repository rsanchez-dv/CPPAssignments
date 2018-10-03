/*
Name: Roberto Sanchez
Date: November 14,2012
Class: Computer Science 02
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<afxwin.h>
#include "PhoneBook.h"
using namespace std;
#define new DEBUG_NEW

void DoAdd(PhoneBook& p);
//Handles the Add Function
//Precondition:Valid PhoneBook passed through Reference
//Postcondition: Adds a new Person in PhoneBook to list
void DoSearch(PhoneBook& p);
//Handles the Search Function
//Precondition:Valid PhoneBook passed through Reference
//Postcondition: Prints out person info
void DoRemove(PhoneBook& p);
//Handles the Remove Function
//Precondition:Valid PhoneBook passed through Reference
//Postcondition:Removes person that usr typed
void DoPrintList(PhoneBook& p);
//Handles the PrintList Function
//Precondition:Valid PhoneBook passed through Reference
//Postcondition:Print Entire List
void DoPrintSize(PhoneBook& p);
//Handles the PrintSize Function
//Precondition:Valid PhoneBook passed through Reference
//Postcondition:Print out size of list
void GetMaxAge(PhoneBook& p);
//Handles printing the biggest age in the list
//Precondition: None
//Postcondition: Prints oldest age on list
void DoGetPeopleWithGivenAge(PhoneBook& p);
//Handles retriving people with given age usr inputed
//Precondition: A valid age
//Postcondition: Prints People's Name,Age,and 
//				phone number of that given age
void GetAllPeopleWithMaxAge(PhoneBook& p);
//Handles retriving the oldest people on the list
//Precondition:Have members in the list
//Postcondition: Prints people's name,age,and phone
//			  number who are the oldest in the list

int main()
{
	//new int;// To deTecT memory leaks
	PhoneBook I;
	I.Insert("John",   32,"(213)456-1249");
	I.Insert("Adam",   28,"(123)456-7896");
	I.Insert("Vanessa",18,"(213)456-1241");
	I.Insert("Gary",   38,"(213)456-1247");
	I.Insert("Jenny",  17,"(213)456-1249");
	I.Insert("Becky",  17,"(456)789-1238");
	I.Insert("Jonny",  17,"(456)765-4237");
	I.Insert("James",  42,"(789)456-1236");
	I.Insert("Sam",    42,"(312)654-9781");
	I.Insert("Penny",  42,"(123)858-1237");
	cout<<"Original List:"<<endl<<endl;
	cout<<I<<endl;
	//Test copy ctor
	PhoneBook I2(I);
	cout<<"List after copy ctor:"<<endl<<endl;
	cout<<I2<<endl;
	//test operator =
	PhoneBook I3;
	I3=I;
	cout<<"List after operator = : "<<endl<<endl;
	cout<<I3<<endl;
	system("PAUSE");
	//Pause, then menu with the rest of Main code
	bool Loop = true;
	char answer;

	while(Loop)
	{	
		system("CLS");
		cout<<" Main Menu"<<setw(50)<<" "<<endl;
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n\n"<<"   Phone Book\n\n";
		cout<<"\t[1] -------------------- Add Phone Number\n";
		cout<<"\t[2] -------------------- Search for Person's Phone Number\n";
		cout<<"\t[3] -------------------- Remove a Phone Number\n";
		cout<<"\t[4] -------------------- Print Size of List\n";
		cout<<"\t[5] -------------------- Print Entire List\n";
		cout<<"\t[6] -------------------- Print Max Age\n";
		cout<<"\t[7] -------------------- Print People With Given Age\n";
		cout<<"\t[8] -------------------- Print People With Max Age   [NEW]\n";
		cout<<"\t[9] -------------------- Quit\n";
		cout<<"\t[Input]: ";
		cin>>answer;
		system("CLS");
		if(answer<'0' || answer>'9')
		{
			cout<<"  Main Menu >> Error Prompt\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n Answer not understood, try again!\n";
			system("PAUSE");
		}
		else
		{
			switch(answer)
			{
			case '1':
				cout<<"  Main Menu >> Add\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoAdd(I);
				system("PAUSE");
				break;
			case '2':
				cout<<"  Main Menu >> Search\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoSearch(I);
				system("PAUSE");
				break;
			case '3':
				cout<<"  Main Menu >> Remove\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoRemove(I);
				system("PAUSE");
				break;
			case '4':
				cout<<"  Main Menu >> Print Size\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoPrintSize(I);
				system("PAUSE");
				break;
			case '5':
				cout<<"  Main Menu >> Print List\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoPrintList(I);
				system("PAUSE");
				break;
			case '6':
				cout<<"  Main Menu >> Get Max Age (EXTRA)\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				GetMaxAge(I);
				system("PAUSE");
				break;
			case '7':
				cout<<"  Main Menu >> Get People With Given Age (EXTRA)\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoGetPeopleWithGivenAge(I);
				system("PAUSE");
				break;
			case '8':
				cout<<"  Main Menu >> Get All People With Max Age (EXTRA)\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				GetAllPeopleWithMaxAge(I);
				system("PAUSE");
				break;
			case '9':
				cout<<"  Main Menu >> Terminating Program\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				cout<<"\n Ending Program...\n ";
				cout<<endl;
				Loop = false;
				break;
			default: 
				cout<<"  Main Menu >> Error Prompt\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				cout<<"\n Answer not understood, try again!\n";
				system("PAUSE");
				break;
			}
		}
	}
	return 0 ;
}// list goes out of scope
void DoAdd(PhoneBook& p)
{
	string name,number;
	int age;
	cout<<" Please enter Name        : ";
	cin>>name;
	cout<<" Please enter age         : ";
	cin>>age;
	cout<<" Please enter Phone Number: ";
	cin>>number;
	//verify number already existes then insert

	if(!p.Insert(name,age,number))
	{
		cout<<" (!) Name Already Exists\n";
	}
	else
		cout<<" (!) Name Successfully Added"<<endl;

}
void DoSearch(PhoneBook& p)
{
	string name,phone;
	int age;
	cout<<"Please enter Name to Search: ";
	cin>>name;

	if(!p.LookUp(name,age,phone))
	{
		cout<<" (!) Name not found\n";
		return;
	}
	else
		cout<<"Name        : "<<name<<endl;
	cout<<"Age         : "<<age<<endl;
	cout<<"Phone Number: "<<phone<<endl;
}
void DoRemove(PhoneBook& p)
{
	string name;
	cout<<"Please enter Name to Remove: ";
	cin>>name;
	if(p.Delete(name))
	{
		cout<<" (!) Person Removed\n";
		return;
	}
	else
		cout<<" (!) Person could not be Deleted/Found...\n";
	return;

}
void DoPrintList(PhoneBook& p)
{
	cout<<"Printing List...\n\n";
	cout<<p<<endl;
}
void DoPrintSize(PhoneBook& p)
{
	cout<<"Printing Size of List: ";
	cout<<p.Size()<<endl;
}
void GetMaxAge(PhoneBook& p)
{
	cout<<" Printing Max Age: ";
	cout<<p.GetMaxAge()<<endl;
}
void DoGetPeopleWithGivenAge(PhoneBook& p)
{
	int age;
	cout<<" Enter age of people you want to look up: ";
	cin>>age;
	if(age<0||age>150)
	{
		cout<<" No one on list has that age...\n";
	}
	else
	{
		cout<<" Printing List:\n";
		cout<<p.GetPeopleWithGivenAge(age);
		cout<<" End of List\n";
	}

}
void GetAllPeopleWithMaxAge(PhoneBook& p)
{
	cout<<" Printing All People with Max Age:\n";
	cout<<p.GetAllPeopleWithMaxAge();
	cout<<" (!) End of List\n";
}