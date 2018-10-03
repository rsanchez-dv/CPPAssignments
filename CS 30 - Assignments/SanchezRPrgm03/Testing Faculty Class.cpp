#include<iostream>
#include"Faculty.h"
#include"Person.h"
#include<string>
#include<fstream>
using namespace std;
void TestingFacultyClass()
{	
	//*//---------Creating some Degrees-----------------------
	string* degrees = new string[2];
	degrees[0] = "Mathematics";
	degrees[1]= "Physics";
	cout<<"Creating some degrees, Math and Physics\n";
	//*//---------Creating some Degrees-----------------------
	//----------Testing Default Constructor-----------------
	cout<<"Creating Faculty x;\n";
	Faculty x;
	cout << "Testing Default constructor,\n"
		 << "Creating: Faculty x:\nPrinting out 'x':\n"
		 << x << "\nPress Enter to Continue...\n";
	cin.get();
	//----------Testing Constructor Function----------------
	Faculty a("Johnson",15,"123-45-6789",2,degrees);
	cout << "Testing constructor,\n"
		 <<"Creating: Faculty a(Johnson,15,123-45-6789,degrees)\n"
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
	cout<<"Printing updated info\n";
	cin.get();
	cout<<a;
	//----------Testing Copy Constructor------------------
	cout << "Testing out Copy Constructor,"
		 <<"\nCreating Faculty b(a) and then outputing 'b':\n" << flush;
	Faculty b(a);
	cout << b;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//----------Testing = Operator-----------------------
	Faculty c;
	
	cout << "Created a new Faculty 'c',\nTesting = operator,";
	c = b;
	cout << "Print out 'c' after c = b:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
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
	//----------Testing Degrees Mutator-------------------------
	cout<<"Testing Degrees mutator, adding Mathematics, Physics. c.degrees(degree,2);";
	c.degrees(degrees,2);
	cout<<"\nUpdated 'c' object:\n"<<c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	//*///------------------------------------------------------
	/*----------Testing Write Function-----------------------
	cout<<"Testing Read Function\n";
	string* diplomas = new string[2];
	diplomas[0] = "English";
	diplomas[1]= "Art";
	cout<<"Creating some degrees, English and Art\n";
	Faculty a("Thomas",23,"555-55-5555",2,diplomas);
	cout<<"Created Person Object, printing info:\n";
	cout<<a;
	fstream fout;
	fout.open("Output.txt");
	cout<<"Printing object 'a' to 'Output.txt'\n";
	fout << a;
	fout.close();
	cout << "\nPress Enter to Exit...\n"<< flush;
	//*///-----------------------------------------------------
	/*----------Testing Read Function------------------------
	cout<<"Tesing Read Function\n";
	Faculty a("Mr.GenericName",00,"404",2,degrees);
	cout<<"Created Student Object, printing info:\n";
	cout<<a;
	fstream fin;
	fin.open("Output.txt");
	fin >> a;
	cout<<"\nReading Info from Readin.txt, Printing Updated info:\n";
	cout<<a;
	fin.close();
	cout << "\nPress Exit to Continue...\n"<< flush;
	//*///------------------------------------------------------
	//Destructors gets invoked.
}