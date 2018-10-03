/*
		Roberto Sanchez
		Computer Science 02 Section:
		December 03, 2012
		Assignment 06: Read, Sort, & Print
*/
#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"StateInfo.h"
using namespace std;
//-----------------------------------------------------------------------------
int main()
{
	//StateInfo 
	StateInfo p[50],n;//Two StateInfo Structures
	int i= 0;//counter
	int Size = sizeof(StateInfo);

	OpenRead(p,n,Size,i);
	system("cls");
	HeapSort(p,i,NameLT,NameLTE);

	cout << " Sorted by State Name:" << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Print(p,i);

	system("pause");
	SelectionSort(p,i);
	cout << "\n Sorted by Population:" << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Print(p,i);
	return 0;
}