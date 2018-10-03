/*
*	Programmer:	Roberto Sanchez
*	Due Date:	Mar. 29, 2012
*	Lab Section:	90102
*
Problem: 
	Develop a program that asks for the user's name, filing status, and salary to calculate his/her tax and net income.

Analysis: What do we need to do the job? (Specifications)
	1)	Get User’s full name [Full_Name]
	2)	Get User’s filing status ['S' -Single, 'J' –Joint]
		a) Verify if input is either Single or Joint - otherwise terminate
		b) Verify that program will accept lowercase 's' and 'j'
	3)	Get User’s taxable income ['Salary'] - set precision to 2
		a) Verify Salary is positive -if not-terminate program
	4)	Determine whether User will file under SINGLE TAXPAYERS or JOINT TAXPAYERS
	5)	If User files under SINGLE TAXPAYER
		a) If User’s salary is between $0-$1710, Computed_tax = 0, Tax_rate = 0, and Amount_Over = 0 
		b) If User’s salary is between $1710-$20930, Computed_tax = 87.00, Tax_rate = .03, Amount_Over = 1710
		c) If User’s salary is between $20930-$28790, Computed_tax = 742.40, Tax_rate = .08, Amount_Over = 20930
		d) If User's salary is between $28790- over, Computed_tax = 1449.60, Tax_rate = .11, Amount_Over = 28790
	6) If User files under JOINT TAXPAYERS
		a) If User’s salary is between $0-$3420, Computed_tax = 0, Tax_rate = 0, and Amount_Over = 0 
		b) If User’s salary is between $3420-$47120, Computed_tax = 330.00, Tax_rate = .04, Amount_Over = 3420
		c) If User’s salary is between $47120-$57580, Computed_tax = 1905.40, Tax_rate = .09, Amount_Over = 47120
		d) If User's salary is between $57580- over, Computed_tax = 2899.20, Tax_rate = .11, Amount_Over = 57580
	7)	Calculate  'tax' with {tax= computed_tax +(tax_rate (Salary - Amount_over))}	
	8)	Calculate 'Net_income' {salary – tax)
	9) Print Full_Name, filing status, income tax, and net income
Design: How do get the job done?  (Algorithm)
	1) Input
		a)Prompt User for FullName (string -"Full_Name")
		b)Prompt User for taxable annual income (Integer-"Salary")
			i)VERIFY input is a POSITIVE NUMBER if not prompt user of error and TERMINATE program
		c)Prompt User for filing status ('S' - for single user, 'J' for joint)
			i)VERIFY input is either 'S','s','J',or 'j' if not prompt user of error and TERMINATE program
	2) Process
		a)Determine whether User will file under SINGLE TAXPAYERS or JOINT TAXPAYERS
		  If User files under SINGLE TAXPAYER
		    a) If User’s salary is between $0-$1710, Computed_tax = 0, Tax_rate = 0, and Amount_Over = 0 
		    b) If User’s salary is between $1710-$20930, Computed_tax = 87.00, Tax_rate = .03, Amount_Over = 1710
		    c) If User’s salary is between $20930-$28790, Computed_tax = 742.40, Tax_rate = .08, Amount_Over = 20930
		    d) If User's salary is between $28790- over, Computed_tax = 1449.60, Tax_rate = .11, Amount_Over = 28790
	      If User files under JOINT TAXPAYERS
		    a) If User’s salary is between $0-$3420, Computed_tax = 0, Tax_rate = 0, and Amount_Over = 0 
		    b) If User’s salary is between $3420-$47120, Computed_tax = 330.00, Tax_rate = .04, Amount_Over = 3420
		    c) If User’s salary is between $47120-$57580, Computed_tax = 1905.40, Tax_rate = .09, Amount_Over = 47120
		    d) If User's salary is between $57580- over, Computed_tax = 2899.20, Tax_rate = .11, Amount_Over = 57580
		b) tax = computed tax +(tax_rate*(Salary - Amount_Over))
		c) Net_income = (salary - tax)
	3) Output
		a) Display entire line filled with '='
		b) Display "The income tax for 'Full_Name' based on 'filing status' is 'tax' and net income is 'Net_income'"
		c) Display entire line filled with '='
*/
//   Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main ()
{
	//DO NOT DELETE
	cout<<setw(80)<<right<<"Program Number 2"<<setw(80)<<right<<"Roberto Sanchez"<<setw(80)<<right<<"Computer Science 1";

	// Declaring Variables
	float Salary;
	float Tax;
	float Net_Income;

	int Computed_Tax;
	int Tax_rate;
	int Amount_Over;

	char filing_status;

	string Full_Name;

	//Input - Prompting User for Name, Filing status, and Salary
	cout<<setw(60)<<left<<"\nEnter your name:";
		getline(cin,Full_Name);
	cout<<setw(59)<<left<<"Enter your taxable annual income:"<<setw(1)<<'$';
		cin>>Salary;
		//Verify Salary for positive number and not a character or string
		if(!cin){
			cout<<endl;
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			cout<<" *         Please enter a NUMBER for your taxable annual income";
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			return 0;
		}
		else if (Salary <0){
			cout<<endl;
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			cout<<" *         Please enter a POSTIVE number for your taxable annual income";
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			return 0;
		}
	cout<<setw(60)<<left<<"Enter your filing status (Enter 'S' for single or 'J' for joint):";
		cin>>filing_status;
		
		//Verfiy Filing Status as 'j','J','s', or 'S'
		if(filing_status == 'S'|| filing_status == 's' )
			{if(Salary >= 0 && Salary <=1710)
				Computed_Tax = 0, Tax_rate =0, Amount_Over = 0;
			else if (Salary >1710 && Salary <= 20930)
				Computed_Tax =87.00,Tax_rate =.03, Amount_Over = 1710;
			else if (Salary >20930 && Salary <= 28790)
				Computed_Tax =742.40 ,Tax_rate =.08, Amount_Over = 20930;
			else if (Salary >28790)
				Computed_Tax =1449.60 ,Tax_rate =.11, Amount_Over =28790;}
		 else if (filing_status == 'J' || filing_status == 'j')
		    { if(Salary >= 0 && Salary <=3420)
				Computed_Tax = 0, Tax_rate =0, Amount_Over = 0;
		    else if (Salary >3420 && Salary <= 47120)
				Computed_Tax =330.00,Tax_rate =.04, Amount_Over = 3420;
			else if (Salary >47120 && Salary <= 57580)
			    Computed_Tax =1905.40 ,Tax_rate =.09, Amount_Over = 47120;
			else if (Salary >57580)
				Computed_Tax =2899.20 ,Tax_rate =.11, Amount_Over =57580;	}
		 else
			{
			cout<<endl;
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			cout<<" *       Please enter either 'S' for Single or 'J' for Joint on filing status";
			cout<<setfill('*')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			return 0;
			}
	
	//Calculations
			Tax= Computed_Tax +(Tax_rate *(Salary - Amount_Over));
			Net_Income = (Salary - Tax);
	//Output
			cout<<endl<<endl;
			cout<<setfill('=')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
			cout<<"The income tax for "<<Full_Name<<" based on ";
				if(filing_status == 'S'|| filing_status == 's' )
					cout<<"Single";
				else if (filing_status == 'J' || filing_status == 'j')
					cout<<"Joint";
				cout<<" filing is $"<<fixed<<setprecision(2)<<Tax<<" and net income is $"<<Net_Income<<endl;
			cout<<setfill('=')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;



	return 0;
	}

