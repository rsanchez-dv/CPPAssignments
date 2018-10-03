/*
Name : Roberto Sanchez
Date : November 22,2012
Class: Computer Science 02
*/
#include"Student.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;
void DoRead(Tree& p);
void DoWrite(Tree& p,bool& FlagFile,ofstream&);
void DoSearch(Tree& p);
void DoAdd(Tree& p);
void DoRemove(Tree& p);
void DoDisplay(Tree& p);
void DoAsk(Tree& p,bool flag,bool FlagFile,ofstream& fout);
void DoSave(Tree p,ofstream& fout);
int main()
{
	Tree p;
	ofstream fout;
	bool Loop = true,Flag = true,FlagFile = false;
	char answer;
	while(Loop)
	{	
		system("CLS");
		cout<<" Main Menu"<<setw(50)<<" "<<endl;
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n\n"<<"   Student DataBase\n\n";
		cout<<"\t[1] -------------------- Read From File\n";
		cout<<"\t[2] -------------------- Write To File\n";
		cout<<"\t[3] -------------------- Search\n";
		cout<<"\t[4] -------------------- Add \n";
		cout<<"\t[5] -------------------- Remove\n";
		cout<<"\t[6] -------------------- Display\n";
		cout<<"\t[7] -------------------- Quit\n";
		cout<<"\t[Input]: ";
		cin>>answer;
		system("CLS");
		if(answer<'0' || answer>'7')
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
				cout<<"  Main Menu >> Read From File\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoRead(p);
				Flag = false;
				system("PAUSE");
				break;
			case '2':
				cout<<"  Main Menu >> Write To File\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoWrite(p,FlagFile,fout);
				Flag = true;
				system("PAUSE");
				break;
			case '3':
				cout<<"  Main Menu >> Search\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoSearch(p);
				system("PAUSE");
				break;
			case '4':
				cout<<"  Main Menu >> Add\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoAdd(p);
				Flag = false;
				system("PAUSE");
				break;
			case '5':
				cout<<"  Main Menu >> Remove\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoRemove(p);
				Flag = false;
				system("PAUSE");
				break;
			case '6':
				cout<<"  Main Menu >> Display\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				DoDisplay(p);
				system("PAUSE");
				break;
			case '7':
				DoAsk(p,Flag,FlagFile,fout);
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
void DoRead(Tree& p)
{
	cin.ignore(10,'\n');
	ifstream fin;
	string fileName;
	cout<<" Please enter a file name to read from: ";
	getline(cin,fileName);
	fin.open(fileName.c_str());
	if(fin.fail())
	{
		cout<<" (!) File FAILED to Open...\n";
	}
	Student temp;
	while(!temp.readFromFile(fin))
	{
		p.Insert(temp);
	}
	cout<<" Finished Reading Data\n";
}
void DoWrite(Tree& p,bool& FlagFile,ofstream& fout)
{
	cin.ignore(10,'\n');
	string fileName;
	cout<<" Please enter a file name to write to: ";
	getline(cin,fileName);
	fout.open(fileName.c_str());
	if(fout.fail())
	{
		cout<<" (!) File FAILED to be created...";
	}
	cout<<" Writing to file...";
	p.PrintFile(fout);
	cout<<" Creating OutPut File Complete!\n";
	fout.close(); 
	FlagFile= true;
}

void DoSearch(Tree& p)
{
	Student temp;
	int id;
	cout<<" Enter Student's ID to Search: ";
	cin>>id;
	temp.SetId(id);
	if(!p.LookUp(temp))
	{
		cout<<" Student not Found (!)\n";
	}
	else
	{
		cout<<" Student found (!)\n";
		temp.WriteToScreen();
		cout<<"_____________________________________________________\n";
	}
}
void DoAdd(Tree& p)
{
	Student temp;
	temp.readFromKeyboard();
	if(!p.Insert(temp))
	{
		cout<<" Something went wrong...\n";
	}
	else
		cout<<" Student has been added (!)\n";
}
void DoRemove(Tree& p)
{
	int id;
	cout<<"Enter Student's ID to Remove: ";
	cin>>id;
	if(!p.Delete(id))
	{
		cout<<" (!) Delete Failed...\n";
	}
	else
		cout<<" (!) Sucessfully Deleted Student\n";

}
void DoDisplay(Tree& p)
{
	cout<<" Printing List:\n";
	p.Print();
	cout<<"___________________________________\n";
	cout<<" End of List (!)\n";
}
void DoAsk(Tree& p,bool flag,bool FlagFile,ofstream& fout)
{
	char answer;
	cout<<"  Main Menu >> Terminating Program\n";
	cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
	if(!flag)
	{
		cout<<" (!) Changes have been made since your last save point.\n";
		cout<<"     Do you want to save changes? [Y/N]\n";
		cout<<"     Response: ";
		cin>>answer;
		if(answer == 'Y'||answer=='y')
		{
			if(FlagFile)
			{
				DoSave(p,fout);
				cout<<" Changes were saved!\n";
			}
			else
			DoWrite(p,FlagFile,fout);
			cout<<" Changes were saved!\n";
		}
		else if(answer == 'N'||answer == 'n')
			cout<<" (!) Changes were not Saved\n";


	}
	cout<<"\n Ending Program...\n ";
	system("pause");
}
void DoSave(Tree p,ofstream& fout)
{
	p.PrintFile(fout);

}