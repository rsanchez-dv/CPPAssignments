/*
	Programmer:	Roberto Sanchez
	Due Date:	May 08, 2012
	Lab Section:	90102

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std ;

//Functions Prototypes

// to provide a welcome message including the programmer's name
void Header(void) ;            
// To calculate an hourly paid worker and include over time (1.5 * regular pay for hours > 40)
float Salary(float Hours, float Pay_Rate);  
// Print the information for one employee to the monitor.
void Print_it(float Hours,float Pay_Rate,float Sal, float Tax_Rate, string Name);  
// Prompt user for name, hours workded and pay rate and send them back to the calling program
void Read(float &hour, float &Pay_R, string &name) ;
// To verify hours (0 - 60) and Pay rate (positive numbers less than 500) are valid.
bool Verify(float Hours, float Pay_Rate);  

int main ( void )
{
    float   Pay_Rate, Hours, Sal, Tax;
    const float  Tax_Rate= (float)0.09 ;
	string name;

	Header();
	cout<<"\n\n ****\t  Salary Report  \t*********\n";
	for(int i = 0 ; i < 6 ; i++){
		Read(Hours,Pay_Rate,name);		// actual parameter
		Sal = Salary(Hours,Pay_Rate);	// actual parameter
		Print_it(Hours,Pay_Rate,Sal, Tax_Rate,name);    // actual parameter
	}
	cout<<"\n\n\n**********\t End of report \t*****\n\n\n\n";
  return 0 ;
}

// Add the definition of functions described above here:
void Header(void)
{//Basic Printing
	cout<<setfill('*')<<setw(55)<<" " << setfill(' ')<<setw(50)<<endl;
	cout<<"Welcome to my Programming World - By: Roberto Sanchez\n";
	cout<<setfill('*')<<setw(55)<<" " << setfill(' ')<<setw(50);
}
void Read(float &hours, float &Pay_R, string &name) 
{//Reading incomming Hours, Pay Rate, and Name
	cout<<endl;
	cout<<"Enter Name: ";
		getline(cin, name);
	cout<<"Please enter hours worked: ";
		cin>>hours;
	if(!cin)
		hours = 0;
	cout<<"Please enter pay rate: ";
		cin>>Pay_R;
	if(!cin)
		Pay_R = 0;
	
	//clean  up
	cin.ignore(10,'\n');

}
bool Verify(float Hours, float Pay_Rate)
{//Verify if Hours and Pay Rate are valid
	if(Hours < 0 || Hours > 60 || Pay_Rate <0 || Pay_Rate >= 500)
	{
		return false;
	}
	else
		return true;
	
}
float Salary(float Hours, float Pay_Rate)
{//Process Salary
	float salary;
	if (Hours > 40)
	{	
		salary = Pay_Rate * 40;
		salary += 1.5 * Pay_Rate * (Hours - 40);
	}
    else
	{
		salary = Pay_Rate * Hours;
	
	}

	return (salary);

}
void Print_it(float Hours,float Pay_Rate,float Sal, float Tax_Rate, string Name)
{
	if(Verify(Hours, Pay_Rate))
	{
		cout<<endl;
		cout<<"\t"<<setw(20)<<left<<"Name"<<setw(1)<<left<<": "<<setw(10)<<Name<<endl;
		cout<<"\t"<<setw(20)<<left<<"Hours Worked"<<setw(1)<<left<<": "<<setw(10)<<Hours<<endl;
		cout<<"\t"<<setw(20)<<left<<"Wages per hours"<<fixed<<setprecision(2)<<setw(3)<<left<<": $"<<setw(10)<<Pay_Rate<<endl;
		cout<<"\t"<<setw(20)<<left<<"Gross Salary"<<fixed<<setprecision(2)<<setw(3)<<left<<": $"<<setw(10)<<Sal<<endl;
		cout<<"\t"<<setw(20)<<left<<"Taxes"<<fixed<<setprecision(2)<<setw(3)<<left<<": $"<<setw(10)<<Tax_Rate*Sal<<endl;
		cout<<"\t"<<setw(20)<<left<<"Net Salary"<<fixed<<setprecision(2)<<setw(3)<<left<<": $"<<setw(10)<<Sal-(Tax_Rate*Sal)<<endl;
	}
	else
	{
		cout<<"\n\t***AN ERROR HAS OCCURRED: INVALID HOURS/PAYRATE***\n";
		cout<<"\t\t***NO WORK HAS BEEN PROCESSED***\n";
	}

}
