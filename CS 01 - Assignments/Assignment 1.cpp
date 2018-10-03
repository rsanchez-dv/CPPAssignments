/*
*	Programmer:	Roberto Sanchez
*	Due Date:	Mar. 20, 2012
*	Lab Section:	90102
*
Problem: 
	Develop a solution and write a C++ program to solve a math problem and display results in a grid.

Analysis: What do we need to do the job? (Specifications)
	1)	Set Constants to[D=5,E=3.7,F=9.5]
	2)	Get Variables(Double) to [x,y,z,]
	3)	Get Variables(Integer) to [var1,var2]
	4)	Get Variables(Strings) to [FullName]
	5)	Set Variables(Double) is [Result]
	6)	Formula is for Variables/Constants [x,y,z,D,E,F,Result] is Result={Squareroot(x-[y/Dz])}(x+Dx)^4-[E/Fy]
	7)	Set Precision for "Result" to 6 digits(0.xxxxxx)
	8)	Formula for Variables [var1,var2] is 
		a)var1+var2
		b)var1*var2
		c)var1%var2
		d)(var1+var2)^2
	9)	Set Precision for the results of [var1,var2] to 0 (x)
Design: How do get the job done?  (Algorithm)
	0)	Output
		a. Setw(80)<<right justification
			i.  Print"Roberto Sanchez"
			ii. Print"Computer Science 1"
			iii.Print"Programming Assignment #1"
	1)	Input
		0.	Print left justification
			i.	Prompt user for Full Name
			ii.	Prompt user for two integers separated by a space [var1,var2]
			iii.Prompt user for three real numbers[x,y,z]
	2)	Process
		a.	Run Formula for Variables [var1,var2]
			i.  var1+var2
			ii. var1*var2
			iii.var1%var2
			iv.(var1+var2)^2
		b.	Run Formula for Variables/Constants [x,y,z,D,E,F]
			i. Result={Squareroot(x-[y/Dz])}(x+Dx)^4-[E/Fy]
	3)	Output
		a) Right Alignment (In same Line)
			 i) setw(15) display "Number 1"
			ii) setw(15) display "Number 2"
			iii)setw(7) display "Sum"
			iv) setw(12) display "Product"
			v)  setw(15) display "Remainder"
			vi) setw(14) display "Squared Sum"
			vii) Nextline
		b) Right Alignment(In Same Line)
			i)  setw(15) display (var1)
			ii) setw(15) display (var2)
			iii)setw(7) display (var1+var2)
			iv) setw(12) display (var1*var2)
			v)  setw(15) display (var1%var2)
			vi) setw(14) display [(var1+var2)^2]
			vii) Nextline, Nextline
		c)Left Alignment (each their own line with one tab)
			i)   Display "x= " and 'x' value in scienitific notaion
			ii)  Display "y= " and 'y' value in scienitific notaion
			iii) Display "z= " and 'z' value in scienitific notaion
			iv) Nextline, Nextline
		d)Left Aligment (In same line with one tab)
			i)Display "The result of substituting x,y,z in to formula is: " 
			ii)Display 'Result' value with 6 digit precision
			iii) Nextline
		e)Setw(70) Fill with '='
			i)Nextline
		f)right alignment- setw(50)
			i)Display "Have a nice day "
			ii) Display FullName
*/
//   Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main ()
{
//DO NOT DELETE
	cout<<setw(80)<<right<<"Roberto Sanchez"<<setw(80)<<right<<"Computer Science 1"<<setw(80)<<right<<"Programming Assignment #1";
//Declaring Variables
	int  var1, var2;
	double sum_result, product_result, remainder_result, squaresum_result;
	int const D=5,E=3.7, F=9.5;
	double  x,y,z;
	double Result;
	string FullName;
//Input
	cout<<"\n\nEnter your full name: ";
		getline(cin,FullName);
	cout<<"Enter 2 integer numbers separated by a space: ";
		cin>> var1>> var2;
	cout<<"Enter 3 real numbers: ";
		cin>>x>>y>>z;
	cout<<endl;
//Calculations (Formulas)
		sum_result=var1+var2;
		product_result=var1*var2;
		remainder_result=var1%var2;
		squaresum_result= pow(sum_result,2);

		Result= sqrt(x-(y/(D*z)))*pow(x+(D*x),4)-(E/(F*y));
		
//Output
	cout<<setw(14)<<right<<"Number 1"<<setw(15)<<right<<"Number 2"<<setw(7)<<right<<"Sum"<<setw(12)<<right<<"Product"<<setw(15)<<right<<"Remainder"<<setw(14)<<right<<"Squared Sum"<<endl;
	cout<<setw(14)<<right<<var1<<setw(15)<<right<<var2<<setw(7)<<right<<sum_result<<setw(12)<<right<<product_result<<setw(15)<<right<<remainder_result<<setw(14)<<right<<squaresum_result<<endl;
	//"x,y,z" variables displayed
	cout<<endl;
	cout<<showpos<<scientific<<setw(9)<<"x= "<<x<<endl;
	cout<<showpos<<scientific<<setw(9)<<"y= "<<y<<endl;
	cout<<showpos<<scientific<<setw(9)<<"z= "<<z<<endl;
	cout<<endl<<endl;
	//RESULTS
	cout<<setw(6)<<" "<<"The result of substituting x, y, z into the formula is: "<<fixed<<noshowpos<<Result<<endl<<endl;
	cout<<setfill('=')<<setw(80)<<" " << setfill(' ')<<setw(80)<< left;
	cout<<setw(40)<<right<<"Have a nice day "<<FullName<<".\n";


	return 0;
}

