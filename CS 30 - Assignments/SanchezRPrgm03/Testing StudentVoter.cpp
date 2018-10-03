#include<iostream>
#include"Voter.h"
#include"Student.h"
#include"StudentVoter.h"
#include<string>
#include<fstream>
using namespace std;
void TestingStudentVoterClass()
{	
	//----------Testing Default Constructor-----------------
	cout<<"Creating StudentVoter x;\n";
	StudentVoter x;
	cout << "Testing Default constructor,\n"
		 << "Creating: StudentVoter x:\nPrinting out 'x':\n"
		 << x << "\nPress Enter to Continue...\n";
	cin.get();
	//----------Testing Constructor Function----------------
	StudentVoter a("Johnson",15,"123-45-6789",2.5,"Democratic Party");
	cout << "Testing constructor,\n"
		 <<"Creating: StudentVoter a(Johnson,15,123-45-6789,2.5,Democratic Party)\n"
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
		 <<"\nCreating StudentVoter b(a) and then outputing 'b':\n" << flush;
	StudentVoter b(a);
	cout << b;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//*///--------------------------------------------------
	//----------Testing Name Mutator---------------------
	StudentVoter c;
	cout << "\nCreating StudentVoter c:\n" << flush;
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
	//----------Testing Party Affiliation Mutator-------
	cout << "Part Affiation Mutator - Changing Party to Whig, c.partyAffiliation(whig);:";
	c.partyAffiliation("Whig");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n" << flush;
		//----------Testing GPA Mutator---------------------
	cout << "GPA Mutator - Changing GPA to 4.0, c.gpa(4.0);:";
	c.gpa(4.0);
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	/*----------Testing Write Function-----------------------
	cout<<"Testing Read Function\n";
	StudentVoter a("Thomas",23,"555-55-5555",0.1,"People's Party");
	cout<<"Created StudentVoter Object, printing info:\n";
	cout<<a;
	fstream fout;
	fout.open("Output.txt");
	cout<<"Printing object 'a' to 'Output.txt'\n";
	fout << a;
	fout.close();
	//*///-----------------------------------------------------
	/*----------Testing Read Function------------------------
	cout<<"Tesing Read Function\n";
	StudentVoter a("Mr.GenericName",00,"404",0.0,"NULL");
	cout<<"Created StudentVoter Object, printing info:\n";
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