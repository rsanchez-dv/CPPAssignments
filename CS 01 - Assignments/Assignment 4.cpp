/*
*	Programmer:	Roberto Sanchez
*	Due Date:	May 03, 2012
*	Lab Section:	90102
*
Problem:
	Develop a program that will take a .txt file with names, id numbers, grades, and units of multiple students to calculate each GPA and overall GPA of all students

Analysis: What do we need to do the job? (Specifications)
	1) A .txt file with multiple Student's name (one per line)
	2) Next Line
		a) ID Number
		b) Letter Grade (A,B,C,D,F)
		c) Number of Units (1-5)
Design: How do get the job done?  (Algorithm)
	1) INPUT
		a) Prompt User for location of .txt file 
			i)Verify that location is good if not terminate
		b) Prompt user for location of output file

	2) PROCESS
		a) [Loop until EOF]
			b) Take Student's name
			c) Take Student's ID Number
			d) [Loop until '*']
				e) Extract letter grade
					i) Verify it is either A,B,C,D,or F other wise IGNORE both current grade and following unit
				f) Convert Letter Grade to number 
					i) A = 4, B = 3, C = 2, D = 1, F = 0
				g) Take Unit number
					i) Verify it is between 1-5 other wise IGNORE both previous grade and current unit
				h) Process Average GPA of Student N 
					i) Average GPA = (grade 1 * units 1 + grade 2 * units 2 +...)/n 
					ii) 'n' stands for the TOTAL OF UNITS OVERALL the STUDENT has 
		b) Process OVERALL GPA of ALL STUDENTS by multiplying both GPA and units and adding them per student then dividing it by overall units
			i) OVERALL GPA = (units 1 * GPA 1 + units 2 * GPA 2... units n * GPA n)/ all units
	3) OUTPUT
		a) Display Name, ID#, Units, and Average GPA of all students in a grid
		b) At bottom display "The Average GPA for all entered grades is" OVERALL GPA
		c) Send Copy to OUTPUT file

*/
//   Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
int main ()
{
	//Declaring Variables
	int units = 0;
	int student_id;
	int GPA = 0;
	int counter = 0;

	int total_units = 0;
	double adden = 0;
	double average_grade = 0;
	double overall_gpa = 0;
	double overall_grade = 0;
	double student_gpa = 0;
	double overall_units = 0;
	
	char grade = 0;
	bool check_grade = false;
	bool check_units = false;

	ifstream fin;
	ofstream fout;

	string file_in;
	string file_out;
	string Student_Name;

	//DO NOT DELETE
	cout<<setw(80)<<right<<"Roberto Sanchez"<<setw(80)<<right<<"Computer Science 1"<<setw(80)<<right<<"Programming Assignment #4"<<endl;
	
	//Input
		cout<<"Please enter input file name: ";
			cin>>file_in;
		fin.open(file_in.c_str());
			if(fin.fail())
				{	cout<<"\n\t***AN ERROR OCCURRED: FILE COULD NOT BE OPENED***\n";
			return 0;
			}
			else
			{ 	cout<<"Please enter output file name: ";
					cin>>file_out;
				cout<<endl;
				fout.open(file_out.c_str());
				if(fout.fail())
				{	cout<<"\n\t***AN ERROR OCCURRED: FILE COULD NOT BE CREATED***\n";
					return 0;
				}
				// Loop for Student's Name
																					//OUTPUT GRID
																					cout<<setw(25)<<left<<"  Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
																					cout<<setfill('-')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
																					fout<<setw(25)<<left<<"  Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
																					fout<<setfill('-')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
				
				while (!fin.eof())
				{
					getline(fin,Student_Name);

																					//OUTPUT STUDENT NAME
																					cout<<setw(25)<<left<<Student_Name;
																					fout<<setw(25)<<left<<Student_Name;
																					fin>>student_id>>grade;
																					//OUTPUT STUDENT ID
																					cout<<setw(12)<<left<<student_id;
																					fout<<setw(12)<<left<<student_id;
						if(counter > 0)
							adden = 0, total_units = 0;
					
						while(grade!='*')// Loop for grade and units
						{
							switch(grade)
								{case 'a':
								 case 'A': GPA = 4, check_grade = true;
									       break;
								 case 'b':
								 case 'B': GPA = 3, check_grade = true;
										    break;
								 case 'c':
								 case 'C': GPA = 2, check_grade = true;
										     break;
								 case 'd':
								 case 'D': GPA = 1, check_grade = true;
			 							     break;
								 case 'e':
								 case 'E': check_grade = false;
									    	 break;
								 case 'f':
								 case 'F': GPA = 0,check_grade = true;
									       break;
								 default: check_grade = false;
										   break;
								}

							if(check_grade == true)
								{
									fin>>units;
									if(!fin)
										 check_units = false;
									else if(units >= 0 || units <= 5)
										 check_units = true;
										
								}
						    if(check_grade == false || check_units == false)//Let system ignore these 'bad' values
								 units = 0, GPA = 0;
							


								//Process information
									//For this student
									total_units += units;
									adden +=(GPA * units);
									//For Overall Students
								    overall_units += units;
							   
								

								
								// Cont. loop
								fin>>grade;

						}

						
						average_grade = (adden / total_units);
						overall_gpa += average_grade * total_units;
						
																							//OUTPUT UNITS
																							cout<<noshowpoint<<setw(10)<<left<<noshowpoint<<total_units;
																							fout<<noshowpoint<<setw(10)<<left<<noshowpoint<<total_units;
																							//OUTPUT GPA
																							cout<<setw(5)<<fixed<<setprecision(2)<<left<<average_grade<<endl;
																							fout<<setw(5)<<fixed<<setprecision(2)<<left<<average_grade<<endl;
						
						getline(fin,Student_Name);
						counter ++;
				}



				//Process ALL STUDENTS GRADES
				overall_grade = overall_gpa/overall_units;
																							//OUTPUT FOR FINAL GPA
																							cout<<setfill('-')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
																							fout<<setfill('-')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
																							cout<<"The average GPA for all entered grades is"<<fixed<<setprecision(2)<<overall_grade<<endl;
																							fout<<"The average GPA for all entered grades is"<<fixed<<setprecision(2)<<overall_grade<<endl;
			}

			return 0;
}