/*
Name: Roberto Sanchez
Class: CSCI 30, Advance C++ Programming
Section: 0110
Assignment Number: 01
File(s): SanchezRPgm01.cpp, MyVector.h
Due Date: On or before March 20, 2013.
----------------------------------------------------------------------
I, Roberto Sanchez, pledge that this is my own independent work, which
conforms to generally accepted guidelines of academic honesty.
----------------------------------------------------------------------
*/
#include<iostream>
#include<string>
#include<iomanip>
#include"MyVector.h"
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;
// ----------Menu Handlers
template <class T>
void DisplaySize(MyVector<T> V);
template <class T>
void DisplayCap( MyVector<T> V);
template <class T>
void PushbackItem( MyVector<T>& V);
template <class T>
void InsertItem(MyVector<T>& V);
template <class T>
void DisplayArray(MyVector<T> V);
void VectorDemo();
void Exit();
void InputError(char input);
// -----------------------
int main()
{
	bool loop = true;
	char response;
	MyVector<string> Vector;

	while(loop)
	{	
		system("CLS");
		cout << "\n\t"<<"Vector Database\n\n"
			 << "\t[C] ----------------- Display Capacity\n"
			 << "\t[S] ----------------- Display Size \n"
			 << "\t[I] ----------------- Insert Item\n"
			 << "\t[P] ----------------- Pushback Item\n"
			 << "\t[D] ----------------- Display Array\n"
			 << "\t[V] ----------------- Vector Operator Demo\n"
			 << "\t[X] ----------------- Exit Program\n" << flush;
		cout << "\tInput Character: " << flush;
		cin >> response;
		
		switch(response)
		{		
		case'C':
		case'c': 
			DisplayCap(Vector);
			cin.get();
			break;
		case'S':
		case's': 
			DisplaySize(Vector);
			cin.get();
			break;
		case'I':
		case'i': 
			InsertItem(Vector);
			cin.get();
			break;
		case'P':
		case'p': 
			PushbackItem(Vector);
			cin.get();
			break;
		case'D':
		case'd':
			DisplayArray(Vector);
			cin.get();
			break;
		case'V':
		case'v': 
			VectorDemo();
			cin.get();
			break;
		case'X':
		case'x':
			Exit();
			loop = false ;
			break;
		default:
			InputError(response);
			cin.get();
			break;
		}
		
	}
	return 0;
}
//----------------------------------------------------------------------------------
//  Menu Handlers Functions
//----------------------------------------------------------------------------------

template <class T>
void DisplaySize( MyVector<T> V)
{
	system("CLS");
	cout << " Current Size of Array: " << V.size()
		 << "\n\n Hit enter to continue the program: " << flush;
	cin.get();
}
template <class T>
void DisplayCap(MyVector<T> V)
{
	system("CLS");
	cout << " Current Capacity: " << V.capacity()
		 << "\n\n Hit enter to continue the program: " << flush;
	cin.get();
}
template <class T>
void PushbackItem(MyVector<T>& V)
{
	string input;
	system("CLS");
	cout <<" Enter String To Push Back: ";
	cin.ignore();
	getline(cin,input);
	V.push_back(input);
	cout << "\n\t(!) Push Back Complete"
	     << "\n\n Hit enter to continue the program: " << flush;
}
template <class T>
void InsertItem( MyVector<T>& V)
{
	string input;
	int index;
	system("CLS");
	cout << " Please enter an INTEGER to select index to store item: " << flush;
	cin >> index;
	cout << " Please enter string: ";
	cin.ignore();
	getline(cin,input);
	V.insert(index,input);
	cout << "\n\t(!) Insert Complete";
	cout << "\n\n Hit enter to continue the program: " << flush;
}
template <class T>
void DisplayArray(MyVector<T> V)
{	system("CLS");
	if(V.size() == 0)
		cout<<"\n\t(!) Array Empty";
	else
	{
		for(int i =0; i<V.size();i++)
			cout<<"\tVector ["<< i <<"] = " << V[i] << '\n';
	}
	cout << "\n\n Hit enter to continue the program: " << flush;
	cin.get();
}

void VectorDemo()							// Showcasing copy construtor, [] and = operators
{
	system("CLS");
	MyVector<string> Vector;				// Creating Array (will go out of scope after this)
		
	Vector.push_back("Jimmy");
	Vector.push_back("Gus");
	Vector.push_back("Jennifer");			//Filling Array with Data
	Vector.push_back("Monica");
	Vector.insert(4,"Saul");
	Vector.insert(2,"Lewis");
	Vector.insert(6,"Ted");
	Vector.insert(5,"Jackie");
	Vector.push_back("Walter");
	Vector.push_back("Jesse");

	cout << "Playing with a template class and the overloaded subscript operator."
		 << "\n\nAfter:"
		 << "\n       MyVector<string> Vector(" << Vector.capacity() << ")"
		 << "\nVector[0]: " << Vector[0]
		 << "\n\nAfter:";
		 for(int i = 0; i < Vector.size();i++)
			cout<<"\tVector ["<< i <<"] = "<<Vector[i]<<'\n';
	cout << "\n\nCapacity of Vector: " << Vector.capacity()
		 << "\n\nSize of Vector    : " << Vector.size()
		 << "\n\nHit enter to continue the program: " << flush;

	cin.get();
	cin.get();
	cout << "\n--------------------------------------------------------";

	cout << "\nTesting out Copy Constructor: Vector2(Vector)\n";
	MyVector<string> Vector2(Vector);									// Copy Constructor
	for(int i = 0; i < Vector.size();i++)
		cout<<"\tVector2 ["<< i <<"] = "<<Vector2[i]<<'\n';
	cout << "\n\nCapacity of Vector2: " << Vector2.capacity()
		 << "\n\nSize of Vector2    : " << Vector2.size()
		 << "\n\nHit enter to continue the program: " << flush;
	cin.get();
	cout << "\n--------------------------------------------------------";

	cout<<"\nTesting Equal Operator: Vector3 = Vector2\n";
	MyVector<string> Vector3;
	Vector3 = Vector2;													// = Op
	for(int i = 0; i < Vector.size();i++)
		cout<<"\tVector3 ["<< i <<"] = "<<Vector3[i]<<'\n';
	cout << "\n\nCapacity of Vector3: " << Vector3.capacity()
		 << "\n\nSize of Vector3    : " << Vector3.size()
		 << "\n\nHit enter twice to return to Main Menu: " << flush;
	cin.get();
}
void Exit()
{
	system("CLS");
	cout << " Ending Program...\n" << flush;
	cin.get();
}
void InputError(char input)
{
	system("CLS");
	cout << " (!) ERROR - '" << input << "' is not a valid input. Please try again!\n" 
		 << "\n\n Hit enter to continue the program: " << flush;
	cin.get();
}

