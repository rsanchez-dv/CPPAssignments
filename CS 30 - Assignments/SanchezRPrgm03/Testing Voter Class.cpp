#include<iostream>
#include"Person.h"
#include"Voter.h"
#include<string>
#include<fstream>
using namespace std;
void TestingVoterClass()
{	
	/*//----------Testing Default Constructor-----------------
	cout<<"Creating Voter x;\n";
	Voter x;
	cout << "Testing Default constructor,\n"
		 << "Creating: Voter x:\nPrinting out 'x':\n"
		 << x << "\nPress Enter to Continue...\n";
	cin.get();
	//----------Testing Constructor Function----------------
	Voter a("Johnson",15,"123-45-6789","Green Party");
	cout << "Testing constructor,\n"
		 <<"Creating: Voter a(Johnson,15,123-45-6789,Green Party)\n"
		 << "Press Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing << Operator------------------------
	cout << "Testing << operator on object 'a': \n" 
		 << a <<"\nPress Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing >> Operator------------------------
	cout << "Testing >> operator on 'a':\n";
	cin >> a;
	cout << "Press Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing Copy Constructor------------------
	cout << "Testing out Copy Constructor,"
		 <<"\nCreating Voter b(a) and then outputing 'b':\n" << flush;
	Voter b(a);
	cout << b;
	cout << "\nPress Enter to Continue...\n" << flush;
	cin.get();
	Voter c;
	//----------Testing Name Mutator---------------------
	cout << "Testing Mutators:\n"<<"Name Mutator -c.name(""Micheal""):";
	c.name("Micheal");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing SSN Mutator---------------------
	cout << "SSN Mutator - Changing SSN to 999-99-9999, c.ssn(999-99-9999);:";
	c.ssn("999-99-9999");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n" << flush;
	cin.get();
	//----------Testing Age Mutator---------------------
	cout << "Age Mutator - Changing Age to 42, c.age(42);:";
	c.age(42);
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n" << flush;
	//----------Testing Party Affiliation Mutator-------
	cout << "Part Affiation Mutator - Changing Party to Whig, c.partyAffiliation(whig);:";
	c.partyAffiliation("Whig");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n" << flush;
	/*----------Testing Write Function-----------------------
	cout << "Testing Read Function\n";
	Voter a("Thomas",23,"555-55-5555");
	cout << "Created Voter Object, printing info:\n";
	cout << a;
	fstream fout;
	fout.open("Output.txt");
	cout << "Printing object 'a' to 'Output.txt'\n";
	fout << a;
	fout.close();
    cout << "\nPress Enter to Continue...\n" << flush;
	*///-----------------------------------------------------
	/*///------------------------------------------------------
	cout<<"Testing Read Function\n";
	Voter a("Thomas",23,"555-55-5555","Republican Party");
	cout<<"Created Student Object, printing info:\n";
	cout<<a;
	fstream fout;
	fout.open("Output.txt");
	cout<<"Printing object 'a' to 'Output.txt'\n";
	fout << a;
	fout.close();
	//*///-----------------------------------------------------
	//*----------Testing Read Function------------------------
	cout <<"Tesing Read Function\n";
	Voter a("Mr.GenericName",00,"404","Democratic Party");
	cout << "Created Voter Object, printing info:\n";
	cout << a;
	fstream fin;
	fin.open("Output.txt");
	fin >> a;
	cout << "\nReading Info from Readin.txt, Printing Updated info:\n";
	cout << a;
	fin.close();
	cout << "\nPress Enter to Continue...\n" << flush;
	
	//Destructors gets invoked.
	//*///-------------------
}