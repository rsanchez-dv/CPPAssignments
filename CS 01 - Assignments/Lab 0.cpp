//Example: setprecision, fixed, showpoint, setw, right and left
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	double x,y,z;
	string name = "John Smith";

	x= 15.67;
	y= 235.73;
	z= 9525.9864;

	cout << fixed << showpoint; 					
	cout << setprecision(2)<<"Setprecision(2) " ;		
	cout<<"x = "<<setw(12) <<x ;		
	cout<<" y = "<<setw(12) <<y ;				
	cout<<" z = "<<setw(12) <<z<<endl;		
	cout << setw(25)<<name << endl;


	return 0;
}
