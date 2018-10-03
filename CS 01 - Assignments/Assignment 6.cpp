/*
*	Programmer:	Roberto Sanchez
*	Due Date:	May 20 , 2012
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
	**Main Algorithm**
	Call - Input_Output function
	Call - Grid_Print function
	Read first line for Name
		*LOOP*(Until eof)
			Read - Student ID
			Set TotalUnits and GPA to zero
			Read Grade
			if grade = '*' (skip following loop and set total units and GPA of that student to Zero)
				*LOOP*(Until '*')
				Call Assign_GPA function
				Verify it is either A,B,C,D,or F other wise IGNORE both current grade and following unit
				Read Unit
				Verify it is between 1-5 other wise IGNORE both previous grade and current unit
				If either GPA or Unit is bad then assign Units and GPA for that Student to zero
				add up all unit for all students
				Call Calc_One_Stu function
				Read Grade (Restart Loop)
			Call Calc_Student_GPA
			Call Output_Print
			Cleanup fin with ignore
			Read Name(Restart Loop)
			rise counter by one
	Calculate All STUDENT's GRADES
	Overall Grade = overall_GPA/Overall_units
	Call End_Print Function
	Close Input and Output files
	**END OF MAIN**

	Functon Verify_File
	Parameters: File_In (String)
	Returns: True or False through bool
	Open file
	Verify if file fails to open
		return false
	Otherwise return true
	End of Verify_File

	Function Assign_GPA
	Parameters: Grade (Char)
	Returns: Grade (Float)
	Verify if Grade is either A,B,C,D,or F otherwise return 6
	Set Number to Grade
		i) A = 4, B = 3, C = 2, D = 1, F = 0
	Return whatever number correspond with grade
	End of Assign_GPA

	Function Calc_Student_GPA
	Parameters: Sumofgrades, &Avg_GPA, Total_units, &overall GPA (ALL DOUBLE, Overall_GPA and Avg_GPA Passed by References)
	Returns: Avg_GPA and Overall_GPA
	if TotalUnits does NOT equal to zero
		Calculate Avg GPA =(Sumof grades/total units)
		Calculate OverallGPA += avg gpa *total units
	if total units does equal to zero
		avg = zero
	End of Cal_Student_GPA

	Function Grid_Print
	Parameters: Ofstream fout
	returns: N/A
	Print to screen "Student Name","ID","UNITS", "GPA" in one line
	Print to Output file as well
	Print solid '=' in next line
	Print to output file as well
	End of Grid_Print

	Function Output_Print
	Parameters: Student Name, Student ID, Total Units, Average grade, ofstream fout
	returns:N/A
	Print to screen and output file 
		Student Name, Student ID, Total Units, Average Grade
	End of Output_Print

	Function End_Print
	Parameters:counter (int), overall_units (double), overall_grade (double), fout (ofstream &)
	Print to screen and output file
		"Group of" counter " students total" overall units (tab) overall grade
	End of End_Print

	Function Input_Output
	Parameters:fin(Ifstream &), fout (Ofstream &), file_in(String), file out(String)
	Return: fin, fout
	Prompt for input file
	Call Verfiy_File function
	If Verify_File is false
		Display Error and terminate
	else
	open file
	prompt for output file
	verify if fail
	if fail
		display error and terminate
	End of Input_output

	Function Cal_One_Stu
	Parameters: total_units (Int &), units (int), adden (Double &), Num_Grade(float)
	Returns: Total_units, Adden through passby refrence
	Calculate total units += units
	Calculate adden (sumofgrade for other function) +=(Num_grade * units)
	End of Cal_One_Stu
*/
//   Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
float Assign_GPA (char);
bool Verify_File (string );
void Calc_One_Stu (int&, int, double&, float);  
void Read_Name (ifstream fin, string & Name, long & ID);
void Input_Output (ifstream &,ofstream&,  string, string);
void Calc_Student_GPA (double , double & , double , double & ) ;
void Grid_Print(ofstream &);
void Output_Print(string , long , float , float , ofstream &);
void End_Print (int,double,double , ofstream &);
int main (void)
{
	//Declaring Variables
	int units = 0;
	long student_id;
	int counter = 0;


	int total_units = 0;
	float Num_grade;
	double adden = 0;
	double average_grade = 0;
	double overall_gpa = 0;
	double overall_grade = 0;
	double student_gpa = 0;
	int overall_units = 0;
	bool Good_Grade = true;//filter out bad grades
	bool Good_Unit = true;//filter out bad units
	char grade = 0;
	ifstream fin;
	ofstream fout;

	string file_in;
	string file_out;
	string Student_Name;
																														//Class Header (DO NOT DELETE)
																														cout<<setw(80)<<right<<"Roberto Sanchez"<<setw(80)<<right<<"Computer Science 1"<<setw(80)<<right<<"Programming Assignment #6"<<endl;
//Input
		 Input_Output (fin,fout, file_in, file_out);
		 Grid_Print(fout);
		 getline(fin,Student_Name);		

		 while (!fin.eof())
		 {fin>>student_id;
				if(counter > 0)
					adden = 0, total_units = 0;
				fin>>grade;
				if (grade != '*')
					
				{
				while(grade!='*')// Loop for grade and units
				{
					Num_grade = Assign_GPA (grade);//Float Function
						if(Num_grade != 6)
							{
									fin>>units;
									if(!fin)
										 units = 0, Num_grade = 0;
											
									else if(units <  0 || units > 5)
										 units = 0, Num_grade =0 ;
							}
						else
							Num_grade =0, units = 0;
							//Process information
									//For this student
						Calc_One_Stu (total_units,units,adden,Num_grade);
									//For all Students Units
								    overall_units += units;
						fin>>grade;
				}
				}
				else
					adden= 0, total_units = 0;
				Calc_Student_GPA (adden, average_grade, total_units,overall_gpa);//void function to calculate GPA for one Student.
				Output_Print(Student_Name,student_id,total_units,average_grade,fout);																										
			fin.ignore(10,'\n');
			getline(fin,Student_Name);
			counter ++;
		 }
		 //Process ALL STUDENTS GRADES
				overall_grade = overall_gpa/overall_units;
				End_Print (counter,overall_units,overall_grade,fout);
			//Closing Files
			fout.close();
			fin.close();
		 return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////Functions/////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Verify_File (string file_in)
{	ifstream fin;
	fin.open(file_in.c_str());
	if(fin.fail())
		{	
			
		return false;
		}
	else
		return true;

}

float Assign_GPA (char grade)
{ 
	switch(grade)
	{        case 'a':
			 case 'A': return 4;
				               break;
			 case 'b':
			 case 'B': return 3;
			                   break;
			 case 'c':
			 case 'C': return 2;
							    break;
			 case 'd':
			 case 'D': return 1;
			 					break;
		     case 'e':
			 case 'E': return 6;
							    break;
			 case 'f':
			 case 'F': return 0;
								break;
			 default:  return 6;
								break;
	}
}
void Calc_Student_GPA (double sumofgrades, double & Avg_GPA, double Total_units, double & overall_gpa)
{
						if(Total_units !=0)
							{	
								Avg_GPA = ( sumofgrades / Total_units);
								overall_gpa += Avg_GPA * Total_units;
								}
						else
							Avg_GPA = 0;
}
void Grid_Print(ofstream &fout)
{
//OUTPUT GRID
cout<<setw(25)<<left<<"\n Student Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
cout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
fout<<setw(25)<<left<<"\n Student Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
fout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
}
void Output_Print(string Student_Name, long student_id, float total_units, float average_grade, ofstream &fout)
{
int a= (float)total_units;
//OUTPUT STUDENT NAME
cout<<setw(25)<<left<<Student_Name;
fout<<setw(25)<<left<<Student_Name;
						
//OUTPUT STUDENT ID
cout<<setw(12)<<left<<student_id;
fout<<setw(12)<<left<<student_id;
						
//OUTPUT UNITS
cout<<setw(10)<<left<<noshowpoint<<a;
fout<<setw(10)<<left<<noshowpoint<<a;
//OUTPUT GPA
cout<<setw(5)<<fixed<<setprecision(2)<<left<<average_grade<<endl;
fout<<setw(5)<<fixed<<setprecision(2)<<left<<average_grade<<endl;
}
void End_Print (int counter, double overall_units, double overall_grade, ofstream &fout)
{
	int a= (float)overall_units;
	//OUTPUT FOR FINAL GPA/units
				cout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(1)<< left<<endl;
				fout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(1)<< left<<endl;
				cout<<"Group of "<<counter<<" Students Total "<<fixed<<"\t     "<<a<<"\t       "<<fixed<<setprecision(2)<<overall_grade<<endl;
				fout<<"Group of "<<counter<<" Students Total "<<fixed<<"\t     "<<a<<"\t       "<<fixed<<setprecision(2)<<overall_grade<<endl;
																														
}
 void Input_Output (ifstream &fin,ofstream & fout,string file_in, string file_out)
 {
	 cout<<"Please enter input file name: ";
			getline(cin,file_in);
		 if(Verify_File(file_in) == false)//bool Function
				 {
					 cout<<"\n\t***AN ERROR OCCURRED: FILE COULD NOT BE OPENED***\n";
					 return;
		 }
		 else
			{   fin.open(file_in.c_str());
				cout<<"Please enter output file name: ";
					cin>>file_out;
				fout.open(file_out.c_str());
				if (fout.fail())
				{ 
					"\n\t***AN ERROR OCCURRED: FILE COULD NOT BE CREATED***\n";
					return;
				}
		 }
 }
 void Calc_One_Stu (int& total_units, int units, double & adden, float Num_grade) 
 {
	 total_units += units;
	 adden +=(Num_grade * units);
 }