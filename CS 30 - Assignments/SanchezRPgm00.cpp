/*
Name: Roberto Sanchez
Class: CSCI 30, Advanced Programming in C++
Section: 0124
Assignment Number: 00
File(s): SanchezRPgm1.cpp
Due Date: 02/??/2013
----------------------------------------------------------------------
I, Roberto Sanchez, pledge that this is my own independent work,
which conforms to generally accepted guidelines of academic honesty.
----------------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<afxwin.h>
#define new DEBUG_NEW
using namespace std;

int const dim1= 4, dim2 = 2, dim3 = 3;

bool Open(string& name, ifstream& fin);//Opens file
int main()
{
	//-------------------------Declarations
	double Matrix[dim1][dim2][dim3];
	string FileName;
	ifstream fin;
	ofstream fout;
	//-------------------------Allocating Memory
	double ***p3d = new double**[dim1];
	for(int i = 0; i < dim1; i++)
	{
		p3d[i] = new double*[dim2];
	}
	for(int i = 0; i < dim1; i++)
	{
		for(int p = 0; p < dim2; p++)
		{
			p3d[i][p] = new double[dim3];
		}
	}
	//-------------------------Opening / Reading File
	if(!Open(FileName,fin))
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < dim1; i++)
		{
			for(int j = 0; j<dim2; j++)
			{
				for(int k = 0; k<dim3; k++)
				{
					fin >> Matrix[i][j][k];
				}
			}
		}
	}
	//-------------------------Setting Up array
	for(int i = 0; i < dim1; i++)
	{
		for(int j = 0; j<dim2; j++)
		{
			for(int k = 0; k<dim3; k++)
			{
				p3d[i][j][k] = Matrix[i][j][k];
			}
		}
	}
	//-------------------------Printing Array
	
	int counter = 0, counter2 = 0;
	cout << '\n'<<fixed<<setprecision(3)<<right;
	//-----------------Regular Array
	for(int i = 0; i < dim1; i++)
	{

		cout<<"Data for matrix number "<<counter2<<".\n";
		for(int j = 0; j < dim2; j++)
		{
			for(int k = 0; k < dim3; k++)	
			{
				cout << setw(12) << Matrix[i][j][k];
			}
			cout << '\n';
		}
		counter2++;
	}
	cout<<"Hit enter to continue:\n";
	cin.get();
	cout<<"Data from the ""Pointer"" 3-D array.\n\n";
	//----------------- Pointer Array 
	for(int i = 0; i < dim1; i++)
	{

		cout<<"Data for matrix number "<<counter<<".\n";
		for(int j = 0; j < dim2; j++)
		{
			for(int k = 0; k < dim3; k++)	
			{
				cout << setw(12) << p3d[i][j][k];
			}
			cout << '\n';
		}
		counter++;
	}
	
	//-------------------------Printing To File
	fout.open("Output.txt");
	fout << '\n'<<fixed<<setprecision(3)<<right;
	//-----------------Regular Array
	for(int i = 0; i < dim1; i++)
	{

		fout<<"Data for matrix number "<<i+1<<".\n";
		for(int j = 0; j < dim2; j++)
		{
			for(int k = 0; k < dim3; k++)	
			{
				fout << setw(12) << Matrix[i][j][k];
			}
			fout << '\n';
		}
	}
	fout<<"Hit enter to continue:\n";
	fout<<"Data from the ""Pointer"" 3-D array.\n\n";
	//----------------- Pointer Array 
	for(int i = 0; i < dim1; i++)
	{

		fout<<"Data for matrix number "<<i+1<<".\n";
		for(int j = 0; j < dim2; j++)
		{
			for(int k = 0; k < dim3; k++)	
			{
				fout << setw(12) << p3d[i][j][k];
			}
			fout << '\n';
		}

	}
	fout.close();
	//-------------------------Deleting Array
	for(int i=0; i<dim1; i++)
	{
		for(int j = 0;j<dim2;j++)
		{
			delete p3d[i][j];
		}
		delete p3d[i];
	}
	delete [] p3d;
	//-----------------------END

	cout<<"\nHit enter to exit the program:\n";
	cout << "================================================================================";
	cin.get();
	return 0;
}
//___________________________________________________________________________
//              Functions
//___________________________________________________________________________
bool Open(string& File, ifstream& fin)
{
	cout << "================================================================================";
	cout << "Program to work with some three-dimensional arrays.\n\n"
		<< "Enter the name of the file containing the basic data: "<<flush;
	getline(cin,File);
	fin.open(File.c_str());
	if( fin.fail())
	{	
		cout<<" File could not be opened. Please check your file name! \n";
		return false ;
	}
	else
		return true;
}