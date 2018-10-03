#include<iostream>
#include"Person.h"
#include"Student.h"
#include<string>
#include<fstream>
using namespace std;
void TestingPersonClass()
{	
	//----------Testing Default Constructor-----------------
	cout<<"Creating Person x;\n";
	Person x;
	cout << "Testing Default constructor,\n"
		 << "Creating: Person x:\nPrinting out 'x':\n"
		 << x << "\nPress Enter to Continue...\n";
	cin.get();
	//----------Testing Constructor Function----------------
	Person a("Johnson",15,"123-45-6789");
	cout << "Testing constructor,\n"
		 <<"Creating: Person a(Johnson,15,123-45-6789)\n"
		 << "Press Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing << Operator------------------------
	cout << "Testing << operator on object 'a': \n" 
		 << a <<"\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing >> Operator------------------------
	cout << "Testing >> operator on 'a':\n";
	cin >> a;
	cout << "Press Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing Copy Constructor------------------
	cout << "Testing out Copy Constructor,"
		 <<"\nCreating Person b(a) and then outputing 'b':\n" << flush;
	Person b(a);
	cout << b;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing = Operator-----------------------
	Person c;
	//*
	cout << "Created a new Person 'c',\nTesting = operator,";
	c = b;
	cout << "Print out 'c' after c = b:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//*///--------------------------------------------------
	//----------Testing Name Mutator---------------------
	cout << "Testing Mutators:\n"<<"Name Mutator -c.name(""Micheal""):";
	c.name("Micheal");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing SSN Mutator---------------------
	cout << "SSN Mutator - Changing SSN to 999-99-9999, c.ssn(999-99-9999);:";
	c.ssn("999-99-9999");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing Age Mutator---------------------
	cout << "Age Mutator - Changing Age to 42, c.age(42);:";
	c.age(42);
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	/*----------Testing Write Function-----------------------
	cout<<"Testing Read Function\n";
	Person a("Thomas",23,"555-55-5555");
	cout<<"Created Person Object, printing info:\n";
	cout<<a;
	fstream fout;
	fout.open("Output.txt");
	cout<<"Printing object 'a' to 'Output.txt'\n";
	fout << a;
	fout.close();
	//*///-----------------------------------------------------
	/*----------Testing Read Function------------------------
	cout<<"Tesing Read Function\n";
	Person a("Mr.GenericName",00,"404",0.0);
	cout<<"Created Person Object, printing info:\n";
	cout<<a;
	fstream fin;
	fin.open("Readin.txt");
	fin >> a;
	cout<<"\nReading Info from Readin.txt, Printing Updated info:\n";
	cout<<a;
	fin.close();
	//*///------------------------------------------------------
	//Destructors gets invoked.
}