#include<iostream>
#include"Person.h"
#include<string>
using namespace std;

int main()
{	
	//Default Constructor
	cout<<"Creating Person x;\n";
	Person x;
	cout << "Testing Default constructor,\n"
		 << "Creating: Person x:\nPrinting out 'x':\n"
		 << x << "\nPress Enter to Continue...\n";
	cin.get();
	//Constructor
	Person a("Johnson",15,"123-45-6789");
	cout << "Testing constructor,\n"
		 <<"Creating: Person a(Johnson,15,123-45-6789)\n"
		 << "Press Enter to Continue...\n" << flush;
	cin.get();
	//Operator <<
	cout << "Testing << operator on object 'a': \n" 
		 << a <<"\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//Operator >>
	cout << "Testing >> operator on 'a':\n";
	cin >> a;
	cout << "Press Enter to Continue...\n"<< flush;
	cin.get();
	// Copy Constructor
	cout << "Testing out Copy Constructor,"
		 <<"\nCreating Person b(a) and then outputing 'b':\n" << flush;
	Person b(a);
	cout << b;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	// = Operator
	Person c;
	cout << "Created a new Person 'c',\nTesting = operator,";
	c = b;
	cout << "Print out 'c' after c = b:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//Name mutator
	cout << "Testing Mutators:\n"<<"Name Mutator -c.name(""Micheal""):";
	c.Name("Micheal");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//ssn mutator
	cout << "SSN Mutator - Changing SSN to 999-99-9999, c.ssn(999-99-9999);:";
	c.Ssn("999-99-9999");
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//Age mutator
	cout << "Age Mutator - Changing Age to 42, c.age(42);:";
	c.Age(42);
	cout << "\nUpdated 'c' object:\n" << c;
	cout << "\nPress Enter to Continue...\n"<< flush;
	cin.get();
	//Destructor Gets invoked after here
	return 0;
}