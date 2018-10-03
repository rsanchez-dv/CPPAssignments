/*
*	Programmer:	Roberto Sanchez
*	Due Date:	April 17, 2012
*	Lab Section:	90102
*
Problem:
	Develop a program that will caculate a unspecified number of grades for the student's GPA

Analysis: What do we need to do the job? (Specifications)
	1) Get STUDENT's Name
	2) Loop until STUDENT enter '*' to complete
		a) Get STUDENT for grade
			i) Verify STUDENT's grade is between A-F
		b) Get STUDENT for number of units
			i) Verify STUDENT's number of units is between 1-5
	3) Set point values for grades A = 4, B = 3,C = 2, D = 1, F = 0
	4) Caluculate average GPA by multiplying student's grades and number of units then adding
	   all of them together then  dividing it by the number of OVERALL UNITS
		a) Average GPA = (grade 1 * unit 1 + grade 2 * unit 2 +...)/ (TOTAL UNITS)
Design: How do get the job done?  (Algorithm)
	1) INPUT
		a) Prompt STUDENT for Full Name
		b) Repeat until STUDENT enter '*'
			i)  Prompt STUDENT for a grade or '*' to finish
				~) Verify STUDENT's grade is between 'A'-'F'
				~) Assign STUDENT's grade to > A = 4,B = 3,C = 2,D = 1,F = 0
			ii) Prompt STUDENT for number of units
				~) Verify STUDENT's number of units is between 1-5
	2) PROCESS
		a) Average GPA = (grade 1 * units 1 + grade 2 * units 2 +...)/n
			i) 'n' stands for the TOTAL OF UNITS OVERALL the STUDENT has entered
	3) OUTPUT
		a) Display "The GPA for 'STUDENT' is 'Average GPA'"
			i) Average GPA must have two decimals precision

*/
//   Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main ()
{
	//Declaring Variables
	double units = 0;
	double total_units = 0,adden = 0;
	double average_grade;
	double const a = 4, b = 3,c = 2,d = 1,f = 0;
	int GPA = 0;
	int check =0;
	int counter = 0;
	char grade = 0;
	string Student_Name;

	//Input
	cout<<"Enter Student's name: ";
		getline(cin,Student_Name);

	cout<<"\tEnter a grade or '*' to terminate: ";
		cin>>grade;
	while(grade != '*')
	{
		//***Verify grade is A-F***

		switch(grade)
			{case 'a':
			 case 'A': GPA = 4, check = 1;
				       break;
			 case 'b':
			 case 'B': GPA = 3, check = 1;
				       break;
			 case 'c':
			 case 'C': GPA = 2, check = 1;
			           break;
			 case 'd':
			 case 'D': GPA = 1, check = 1;
			 	       break;
             case 'e':
             case 'E': cout<<"\n\t\t***ERROR - GRADE MUST BE BETWEEN A-F***\n";
							check = 0;
                     
					   break;
			 case 'f':
			 case 'F': GPA = 0, check = 1;
				       break;
			 default:cout<<"\n\t\t***ERROR - GRADE MUST BE BETWEEN A-F***\n";
							check = 0;
					
						break;
			}

		if(check == 1)
		{
		cout<<"\tEnter number of units: ";
			cin>>units;
		//***Verfiy number of units are valid
				if(!cin)
				{cout<<"\n\t\t***ERROR - PLEASE ENTER THE NUMBER OF UNITS BETWEEN 1-5***\n";
				check = 0;
				}
				if(units < 0 || units > 5 )
				{	cout<<"\n\t\t***ERROR - PLEASE ENTER THE NUMBER OF UNITS BETWEEN 1-5***\n";
				check =0;	
				}
		}
	 if(check == 0)//Let system ignore these 'bad' values
		{ units = 0, GPA = 0;
		}
			
	
			//Process information
		total_units += units;
		adden +=(GPA * units);
				// Cont. loop
		cout<<"\n\tEnter a grade or '*' to terminate: ";
			cin>>grade;
			counter++;
	}

	if(counter == 0)
{		cout<<"\n***NO SCORES WERE ENTERED***\n";
	    cout<<"######################################\n";
		return 0;
}
	// Processing Input
	average_grade = (adden / total_units);

	//Output

	cout<<"\nThe GPA of "<<Student_Name<<" is "<<fixed<<setprecision(2)<<average_grade<<endl;
	cout<<"######################################\n";

	return 0;
}
