/*
*	Programmer:	Roberto Sanchez
*	Due Date:	June 7, 2012
*	Lab Section:	90102
*
Problem:
	Develop a program that will take a .txt file with names, id numbers, grades, and units of multiple students to 
	calculate each GPA and overall GPA of all students with a menu to add, remove, open a file, print, sort, and edit 
	information recorded

Analysis: What do we need to do the job? (Specifications)
	1) A .txt file with multiple Student's name (one per line)
	2) Next Line
		a) ID Number
		b) Letter Grade (A,B,C,D,F)
		c) Number of Units (1-5)
Design: How do get the job done?  (Algorithm)
	**Main Algorithm**
	create Struct Student
	    string Full Name
		  long ID
		   double GPA
		   double Total Units
		   double Total Points
		   char array - Grade [20]
		   int array - Units [20]
	Setup Menu with options of open, add, remove, print, edit, search, sort, and close
	set counter to zero
	set loop =1
	set prnt_loop =1
	set exit_loop=1
	array Student_List [20]
	
	Loop until loop =0
		Call- Main_Menu function

		Open:
			Call - Input_Output function
			Call - Process function
		Add:
			Call - Add function
		Remove:
			Call - Remove function
		Print:
			Call - Prnt_Menu function
		Edit:
			Call - Edit Function
		Sort:
			Call - Sort_Menu function
		Search:
			Call - Search_Results function
		Exit:
			Call - Exit_Menu
			loop=0
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
	
	Function Input_Output
	Parameters: Fin, fout, file_in, file_out (ifstream&, ofstream&, string&, string&)
	Returns file_in file_out fin fout through pasby reference
	Prompt user for input file
	Call Verify_File Function
	if true
	   open file
	   prompt for output file_in
	   open/creat output_file
	else
	  prompt "bad file"
	End of Input_output
	
	Function Calc_One_Stu
	Parameters: total_units, units,adden, Num_Grade (int &, int, double&, float)
	Returns: total_units and adden through passby reference
	  total_units += units
	  adden += (num_grade * units)
	End of Function
	
	Function Process
	Parameters:Student_List[], Total, fin, counter (Student, Overall&,ifstream, int)
	Returns: Total, fin, Counter, Student_List through passbay reference
	  declare as int: indx_grd, units, total_units to 0
	  set counter to 0
	  declare as double: adden,average_grade,overall_gpa, overall_grade, overall_units to 0
	  declare as char: grade
	  declare as float: Num_Grade
	    clean up fin
	    read student's name from file and set to Student_List[0].Full_Name
	    loop(!.fin.eof())
		read ID from file and set to STudent_List[0]
		make sure to reset adden and total_units for student to 0 each time each student is processed
		read grade from file
		if grade is '*' -> next exit loop and read next student
		else 
		  loop(grade !='*')
		      send grade to Student_List[counter].Grade[indx_grd] (counter and indx_grd starts at zero by default)
		      Call Assign_GPA Function
		      if Assign_GPA is 6
		      set grade value to 0 and unit to zero and skip to next grade
		      else
		      read unit and verify its between 0 and 5 if not between 0-5 ignore in calculation
		      send unit to Student_List[counter].Units[indx_grd](dispite its under 0 or over 5)
		      Call Cal_One_Stu Function
		      overall_units += units
		      indx_grd increment one
		      read next grade
		Call Cal_Student_GPA Function
		set indx_grd to Student_List[counter].indx_grd
		set total_units to Student_List[counter].Total_Units
		set average_grade to Student_List[counter].GPA
		
		reset indx_grd to 0
		clean up fin
		increment counter by one
		read next names from file_in
	 Set overall_units to Total.Total_Units 
	 calculate overall_grade = overall_gpa / overall_units
	 Set overall_grade to Total.Total_GPA
	 close input file
	 End of Function
	 
	 Function Output_Print_Page
	 Parameters: Student_List[], counter (Student. int)
	 Returns: NONE
	    loop(declar i =0, check i<counter, increment i by one if true if not end loop)
		print to screen "Name: " Student_List[i].Full_Name
		print to screen "ID: " Student_List[i].ID
		print to screen "GPA: " Student_List[i].GPA (show only two decimal places)
		print to screen "Units: " Student_List[i].Total_Units
		print line of '*'
	End of Function
	
	Function Grid_Print
	Parameter: VOID
	Return: NONE
	    Print  to screen "Student Name" - "ID#" - "Units" - "GPA"
	    Print to screen fill line "="
	End of Function
	
	Function Grid_Print_file
	Parameter: Fout (ofstream &)
	Return: Passby reference
	    Print to file "Student Name" - "ID#" - "Units" - "GPA"
	    Printfill line "="
	End of Functions
	
	Function Output_Print_Table
	Parameters: Student_List, counter (Student, int)
	Return: None
	    loop( declare i =0. if i<counter, increment i by one)
		print to screen Student_List[i].Full_Name
		Print to screen Student_List[i].ID
		print to screen Student_List[i].Total_Units
		print to screen Student_List[i].GPA
	(Each student in one line)
	End of Function
	
	Function Output_Print_file
	Parameters: Student_List, counter, fout (Student, int, ofstream&)
	Return: fout by passby reference
		    loop( declare i =0. if i<counter, increment i by one)
		print to screen Student_List[i].Full_Name
		Print to screen Student_List[i].ID
		print to screen Student_List[i].Total_Units
		print to screen Student_List[i].GPA
	(Each student in one line)
	End of Function
	
	Function End_Print
	Parameters: Student_List, Total, counter (Student, Overall, int)
	Return: None
	   Print to screen - fill line with '='
	   print to screen - "Group of " - counter - "Student Total " Total.Total_Units - Total.Total_GPA
	(Print in one line with spaces between total_units and total_GPA)
	End of Function
	
	Function End_Print_file
	Parameters: Student_List, Total, counter, fout (Student, Overall, int,ofstream&)
	Return: fout by passby reference
	   Print to file - fill line with '='
	   print to file - "Group of " - counter - "Student Total " Total.Total_Units - Total.Total_GPA
	(Print in one line with spaces between total_units and total_GPA)
	End of Function
	
	Function Prnt_Menu
	Parameters: Student_List, Total, fout, counter, file_out (Student, Total, ofstream, int, string)
	Return:fout by passby reference
	    set prnt_loop = 0
	    loop(prnt_loop =0)
		declare char prnt_ansr
		display submenu of options to print
		L -> print student info in page formate
		T -> print student info in table format
		F -> print table format to output file
		x -> Exit
		take response
		    L: Call Output_Print_Page Function
		    T: Call Grid_Print Function
		       Call Output_Print_Table Function
		       Call End_Print Function
		    F: Call Grid_Print_file Functions
		       Call Output_Print_file Function
		       Call End_Print_file Function
		    X: prnt_loop =0
	End of Function
	
	Function Menu
	Parameter: VOID
	Returns: NONE
	   Print to screen:
		'O' - Open an existing Student's file_in
		'A' - Add new person to list
		'R' - Remove a person from list
		'P' - Print LIst
		'E' - Edit info for one person
		'T' - Sort list
		'X' - Exit
	End of Function
	
	Function Save_file
	Parameter: Student_List. counter, fs (Student, int, ofstream&)
	Returns fs through passby reference
	    loop (int j =0, j< counter, increment j by one
		print to file (fs) - Student_List[j].Full_Name - nextline
		print to file - Student_List[j].ID - " "
		loop(int i = 0, i<20, increment i by one)
		    print to file Student_List[j].Grade[i] - " " - Student_List[j].Units[i]
		print '*'
	End of function
	
	Function Exit_Menu
	Parameters: exit_loop, loop, Student_List, counter, file_in (int&,int &, Student, int, string)
	returns: exit_loop and loop through passby reference
	    Loop(exit_loop =1)
		Promt user if they choose to save changes
		if yes open input file as output file (from input_output function)
		  call Save_file Function
		  exit_loop = 0, loop=0
		if no
		   exit_loop = 0. loop = 0
	End of Function
	
	Function Search
	Parameters: Student_list, counter (Student, int)
	Returns: integer i or integer -1
	  declare string: Name
	  Prompt for Last Name and First Name with a comma inbetween to search list
	  set response to Name
	      Loop(int i =0, i<counter, increment i by one)
		  compare Student_List[i].Full_Name with Name in an ifstatement
		  if found return i
	  if found nothing return -1
	End of Function
	
	Function Search_Results
	Parameter: Student_List, counter (Student, int)
	Returns: None
	   declare int i, loop = 1, size = 0, char ansr
	   loop(loop=1)
	      Call Search Function
	      set integer from Search to i
	      if i  =-1
		print to screen "student not found"
	      else
		print Student_List[i].Full_Name, Student_List[i].ID, Student_List[i].GPA, Student_List[i].Total_Units
		print all grades and units in Student_List[i] in a table
	  prompt "search again?"
	  if yes  - do nothing
	  if no - set loop = 0
	End of Function
	
	Function Zeros
	Parameters: Student_list (Student)
	Returns: Passby reference
	  loop( i =0, i<20, increment i by one
	      loop(j=0, j<20, increment j by one
		  Student_list[i].Grade[j] = '*'
		  Student_List[i].Units[j] =0
	End of Function
	
	Function Sort_Menu
	Parameters: Student_list, counter
	Returns: NONE
	    declare loop =1
	    loop(loop==1)
		print options for user 'N' - Sort Names, 'C'- Sort GPA, 'X' to Exit_Menu
		if selected N
		   call Sort_Name Function
		   prompt user to see print preview
		if selected C
		   Call Sort_GPA Function
		   Prompt User to see print Preview
		if selected x
		  loop = 0
	End of Function
	
	Function Edit
	Parameters: Student_list, counter, Total(Student_list[].int, Overall&)
	Returns Total through passby reference
	declare indx =0;size =0
	  Prompt for Student's Last and First Names
	  Find Student's Name by comparing Name received from user and comparing it to all students on list
	  set number of student as tab (Student_List[tab])
	  if found
	     prompt user with options: 'G' - Change Student's Grade, 'I' - Change Student's ID, 'X' - Exit
	     if selected G
	       Display all of that Student's Grades and Units
	       Prompt user which grade/unit to changes
	       set number user put as indx
	       lower indx by one (the grade/unit user choose)
	       Call Process_change Function
	       End Edit
	    if selected I
	      Prompt user for new ID
	      set Id to that student
	      End Edit
	End of Function
	
	Function Process_Change
	Parameters: Student_list, Total, counter, tab, size, indx (Student, Overall&, int, int, int, int)
	Return: Total through passby reference
	declare double adden =0, GPA =0, int total_units =0;
	  Call Verify_change
	  Loop(i=0, i<20, increment i by one)
	      temp adden = Student_List[tab].Grade[i] * Student_List[tab].Units
	      temp Total_Units += Student_List[tab].Units[i]
	      temp GPA =temp adden / temp Total_Units
	 Student_List[tab].GPA = temp GPA
	      Student_List[tab].adden = temp adden
	      Student_List[tab].Total_Units = temp Total_Units
	      Total.Total_units += temp Total_Units
	End of Function
	
	Function Verify_Change
	Parameter: Student_List, tab, size, indx (Student, int, int, int)
	Returns: Student_List through passby reference
	  Declare float Num_Grade =0, int i = 0
	  Prompt user for new grade
	    set new grade to Student_List[tab].Grade[indx]
	    Verify if Grade is valid (ONLY A.B,C,D, or F ~ everything else ignore in calculation along with it's acommpanied unit)
	    if good prompt user for new unit
	      set new unit to Student_List[tab].Units[indx]
	      Verify if unit is good (ONLY 0-5~ Everything else ignore in calculation along with it's accompanied grade)
	      exit function
	    if grade was bad then prompt user bad grade
	      exit function
	ENd of Function
	
	Function Sort_Name
	Parameters: Student_list, counter (Student, int)
	Returns: Student_list through passby reference
	  declare int min,i,j, long temp_id, double gpa,total_units, adden, int indx_grd, Units[20], char grade[20], string temp
	  loop(i=0, i<counter-1, incrementi by one)
	      min =i
	      loop(j=i+1, j<counter, increment j by one)
		 compare: Student_List[j].Full_Name < Student_List[Min].Full_Name
		 if true
		   set all of Student_List[j] data to temp variable declared in this function
		   set all of Student_List[Min] data to Student_List[j]
		   set all of temp variable data to Student_List[Min]
	End of Function
	
	Function Sort_GPA
	Parameters:Student_List, counter (Student, int)
	Returns: Student_list through passby reference
	  declare int min,i,j, long temp_id, double gpa,total_units, adden, int indx_grd, Units[20], char grade[20], string temp
	  declare bool flag = false
	  loop
	      loop(i = 0, i<counter, increment i by one)
		 compare: Student_List[i].GPA < Student_List[i+1].GPA
		 if true
		    set all of Student_List[i] data to temp variable declared in this function
		    set all of Student_List[i+1] data to Student_List[i]
		    set all of temp variable data to Student_List[i+1]
	End of Function
	
	Function Add
	Parameters:Student_List, counter, Total (Student,int&,Overall&)
	Returns: counter and Total through passby reference
	  Prompt for New student name
	  set to Student_List[counter].Full_Name
	  verify name doesn't exits
	  if it does
	    prompt that name exists
	  if it doesn't
	    prompt for new id
	    set to Student_List[counter].ID
	    loop until user inputs '*' or reach max 20 grades and units, i++ every loop
	      prompt for new grades
	      set to Student_List[counter].Grade[i]
	      prompt for new units
	      set to Student_list[counter].Units[i]
	    calculate new GPA and total Units for student
	
	End of Function
	
	Function Remove
	Parameter: Student_List, counter, Total (Student,int&,Overall&)
	Returns:Counter and Total through passby reference
	  Prompt for Student's Name
	  Search for Name
	  Prompt to confirm deletion
	  if no
	    exit function
	  if yeas
	    set name for that student to "zzzzzzzzzzzzzzzz"
	    set Gpa for that student to 999.999
	    set ID for that student to 00000000
	    set grades to '*'
	    set units to 0
	End of Function
	
	*/
	
//  Implementation: Converting the algorithm to specific programming language. (C++ Code)
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
float Assign_GPA (char);
struct Student {
		string Full_Name;
		long ID;
		double GPA, Total_Units,adden;
		char Grade [20];
		int Units [20];
		int indx_grd;
};
struct Overall {
	int Total_Units;
	float Total_GPA;
};
bool Verify_File (string );
void Add (Student Student_List[], int &, Overall &);
void Calc_One_Stu (int&, int, double&, float);  
void Read_Name (ifstream fin, string & Name, long & ID);
void Input_Output (ifstream &,ofstream&,  string&, string&);
void Calc_Student_GPA (double , double & , double , double & ) ;
void Prnt_Menu(Student Student_List[],Overall, ofstream &,int,string);
void Process(Student Student_List[], Overall &Total, ifstream &fin, int &counter);
void End_Print_file (Student Student_List[],Overall Total,int counter,ofstream &fout);
void End_Print (Student Student_List[],Overall Total,int counter);
void Output_Print_Table_file(Student Student_List[],int counter,ofstream &fout);
void Output_Print_Table(Student Student_List[],int counter);
void Grid_Print_file(ofstream &fout);
void Grid_Print();
void Output_Print_Page(Student Student_List[],int counter);
void Menu();
void About();
void Sort_Menu(Student Student_List[], int);
void Sort_Name (Student Student_List[],int);
void Sort_GPA (Student Student_List[], int);
void Remove(Student Student_List[],int &,Overall &);
void Zeros(Student Student_List[]);
int Search (Student Student_List[],int , int );
void Search_Results(Student Student_List[],int);
void Verify_Change(Student Student_List[],int, int,int);
void Edit(Student Student_List[],int counter,Overall &Total);
void Exit_Menu(int &, int &, Student Student_List[], int ,string);
void Save_file(Student Student_List[],int ,int , ofstream &);
void Process_Change (Student Student_List[], Overall &Total,int counter,int tab, int size, int indx);

int main ()
{
//Declaring Variables
	int loop =1,prnt_loop=1,exit_loop =1,counter = 0;
	char grade = 0,response;
	ifstream fin;
	ofstream fout;
	string file_in,file_out;
	Student Student_List [20];//Array for Students
	Overall Total;

	Zeros(Student_List);
	while(loop ==1)
	{	prnt_loop =1;//resetting print menu
		exit_loop =1;
		Menu();
		cin>>response;
		switch(response){
		case'O':
		case'o': 
			Input_Output (fin, fout, file_in,  file_out);
			Process(Student_List, Total, fin,counter);
			system("PAUSE");
		break;
		case'A':
		case'a': Add (Student_List,counter,Total);
			system("PAUSE");
				break;
		case'R':
		case'r': Remove(Student_List,counter,Total);
			break;
		case'P':
		case'p':
			Prnt_Menu(Student_List,Total,fout, counter,file_out);
			break;
		case'E':
		case'e': Edit (Student_List,counter,Total);
			break;
		case'S':
		case's':Search_Results(Student_List,counter);
			break;
		case'T':
		case't': Sort_Menu(Student_List,counter);
			break;
		case'*':
			About();
			break;
		case'X':
		case'x': 
			 Exit_Menu(exit_loop,loop,Student_List,counter, file_in);
			 break;			
		}
		
	}
	fout.close();
		 return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////Functions/////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

 void Input_Output (ifstream &fin,ofstream & fout,string &file_in, string &file_out)
 {		system("CLS");
			cout<<"  Main Menu >> Open File\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;		
	 cin.ignore(10,'\n');
			 cout<<"Please enter input file name: ";
			getline(cin,file_in);
		 if(Verify_File(file_in) == false)//bool Function
				 {
					 cout<<"\n\t"<<setfill('=')<<setw(70)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  File Could Not Be Opened";
					 cout<<"\n\t |\t(?) Name Input file as: (EXAMPLE.txt) or (C:\Data\EXAMPLE.txt)\n";
					 cout<<"\t"<<setfill('=')<<setw(70)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 return;
		 }
		 else
			{   fin.open(file_in.c_str());
					 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t + File Successfully opened "<<file_in<<"\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
				cout<<"Please enter output file name: ";
					cin>>file_out;
				fout.open(file_out.c_str());
				if (fout.fail())
				{ 
					cout<<"\n\t"<<setfill('=')<<setw(70)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  File Could Not Be Created";
					 cout<<"\n\t |\t(?) Name Output file as: (EXAMPLE.txt) or (C:\Data\EXAMPLE.txt)\n";
					 cout<<"\t"<<setfill('=')<<setw(70)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					return;
				}
				else
					 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t + Output File Successfully opened/created "<<file_out<<" \n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
		 }

 }
 void Calc_One_Stu (int& total_units, int units, double & adden, float Num_grade) 
 {
	 total_units += units;
	 adden +=(Num_grade * units);
 }
 void Process(Student Student_List[], Overall &Total, ifstream &fin, int &counter)
 { 
	 counter = 0;
     int indx_grd =0,units =0 ,total_units = 0;
	 double adden = 0,average_grade = 0,overall_gpa = 0,overall_grade = 0,overall_units =0;
	 char grade = 0;
	 float Num_grade;
     cin.ignore(10,'\n');




 		getline(fin,Student_List [0].Full_Name);//Receiving Student's FullName into Array
		while (!fin.eof())//Looping One Student
		{
			fin>>Student_List[counter].ID;//Receving Student's ID into Array
			if(counter > 0)
					adden = 0, total_units = 0;
			fin>>grade;
			if (grade != '*')
			{	
				while(grade!='*')// Loop for grade and units
					{	Student_List[counter].Grade[indx_grd] = grade;
						Num_grade = Assign_GPA (grade);//Float Function
						if(Num_grade != 6)
						{		fin>>units;
								if(!fin)
									 units = 0, Num_grade = 0;							
								else if(units <  0 || units > 5)
									 units = 0, Num_grade =0 ;
						}
						else
							Num_grade =0, units = 0;
						Student_List[counter].Units[indx_grd] = units;
						//Process information
							//For this student
							Calc_One_Stu (total_units,units,adden,Num_grade);
							//For all Students Units
							 overall_units += units;
							 indx_grd++;//Rise to next grade/unit array
						fin>>grade;
					}
			}
		else
			adden= 0, total_units = 0;
			Calc_Student_GPA (adden, average_grade, total_units,overall_gpa);//void function to calculate GPA for one Student.
			Student_List [counter].indx_grd = indx_grd;
			Student_List [counter].Total_Units= total_units;
			Student_List [counter].GPA = average_grade;
				
			indx_grd =0;
			fin.ignore(10,'\n');
			counter++;//Rise to next slot in Array 
			getline(fin,Student_List [counter].Full_Name);
	}
	//Process ALL STUDENTS GRADES
	Total.Total_Units=overall_units;
				overall_grade = overall_gpa/overall_units;
				Total.Total_GPA =overall_grade;
fin.close();
 }
 void Output_Print_Page(Student Student_List[],int counter)
 {	for(int i =0;i<counter;i++){
	 int a = Student_List[i].Total_Units;
	 cout<<left<<setw(10)<<"\n\tName:"<<left<<setw(60)<<Student_List[i].Full_Name;
	 cout<<left<<setw(10)<<"\n\tID:"<<left<<setw(60)<<Student_List[i].ID;
	 cout<<left<<setw(10)<<"\n\tGPA:"<<left<<setw(60)<<fixed<<setprecision(2)<<left<<Student_List[i].GPA;
	 cout<<left<<setw(10)<<"\n\tUnits:"<<left<<setw(60)<<a;
	 cout<<endl<<endl<<setfill('*')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left<<endl;}
 }
 void Grid_Print()
{
			//OUTPUT GRID
			cout<<setw(25)<<left<<"\n Student Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
			cout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
}
void Grid_Print_file(ofstream &fout)
{
			//OUTPUT GRID
			fout<<setw(25)<<left<<"\n Student Name"<<setw(12)<<left<<"ID #"<<setw(10)<<left<<"Units"<<setw(5)<<left<<"GPA\n";
			fout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(50)<< left<<endl;
}
void Output_Print_Table(Student Student_List[],int counter)
{	for(int i =0; i<counter; i++){
	int a= (float)Student_List[i].Total_Units;
			//OUTPUT STUDENT NAME
			cout<<setw(25)<<left<<Student_List[i].Full_Name;
						
				//OUTPUT STUDENT ID
			cout<<setw(12)<<left<<Student_List[i].ID;
						
			//OUTPUT UNITS
			cout<<setw(10)<<left<<noshowpoint<<a;
			//OUTPUT GPA
			cout<<setw(5)<<fixed<<setprecision(2)<<left<<Student_List[i].GPA<<endl;}
}
void Output_Print_Table_file(Student Student_List[],int counter,ofstream &fout)
{	for(int i =0; i<counter; i++){
	int a= (float)Student_List[i].Total_Units;
			//OUTPUT STUDENT NAME
			fout<<setw(25)<<left<<Student_List[i].Full_Name;
						
				//OUTPUT STUDENT ID
			fout<<setw(12)<<left<<Student_List[i].ID;
						
			//OUTPUT UNITS
			fout<<setw(10)<<left<<noshowpoint<<a;
			//OUTPUT GPA
			fout<<setw(5)<<fixed<<setprecision(2)<<left<<Student_List[i].GPA<<endl;}
}
void End_Print (Student Student_List[],Overall Total,int counter)
{	int a = Total.Total_Units;
			//OUTPUT FOR FINAL GPA/units
				cout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(1)<< left<<endl;
				cout<<"Group of "<<counter<<" Students Total "<<fixed<<"\t     "<<a<<"\t"<<fixed<<setprecision(2)<<Total.Total_GPA<<endl;																														
}
void End_Print_file (Student Student_List[],Overall Total,int counter,ofstream &fout)
{	int a = Total.Total_Units;
			//OUTPUT FOR FINAL GPA/units
				fout<<setfill('=')<<setw(50)<<" " << setfill(' ')<<setw(1)<< left<<endl;
				fout<<"Group of "<<counter<<" Students Total "<<fixed<<"\t     "<<a<<"\t"<<fixed<<setprecision(2)<<Total.Total_GPA<<endl;																														
}
 
 
 void Prnt_Menu(Student Student_List[],Overall Total, ofstream & fout,int counter, string file_out)
 {		int prnt_loop =1;
		while(prnt_loop ==1)
		  {	char prnt_ansr;
			system("CLS");
			cout<<"  Main Menu >> Print Sub-Menu\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n\n\t"<<"Print Sub-Menu\n\n";
			cout<<"\t[L] ----------------- Print Student's info in page format to Screen\n";
			cout<<"\t[T] ----------------- Print Student's info in table format to Screen\n";
			cout<<"\t[F] ----------------- Print in table format to file\n";
			cout<<"\t[X] ----------------- Return to Main Menu\n\t";
					cin>>prnt_ansr;
					system("CLS");
					switch(prnt_ansr){
						case'L':
						case'l':
							cout<<"  Main Menu >> Print Sub-Menu >> Print\n";
							cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
							Output_Print_Page(Student_List,counter);
							system("PAUSE");
							break;
						case'T':
						case't':
							cout<<"  Main Menu >> Print Sub-Menu >> Print\n";
							cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
							Grid_Print();
							Output_Print_Table(Student_List,counter);
							End_Print (Student_List,Total,counter);
							cout<<endl;
							system("PAUSE");
								break;
						case'F':
						case'f':
							cout<<"  Main Menu >> Print Sub-Menu >> Print\n";
							cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
							Grid_Print_file(fout);
							Output_Print_Table_file(Student_List,counter,fout);
							End_Print_file(Student_List,Total,counter,fout);
							cout<<"\t"<<setfill('*')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left;
							cout<<"\n\t *\tPrinted to >>> "<<file_out<<"\n";
							cout<<"\t"<<setfill('*')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left;
							cout<<endl;
							system("PAUSE");
							break;
						case'X':
						case'x':prnt_loop=0;
							break;
						default:
							break;
					}
			}
 }
 void Menu()
{
system("CLS");
			cout<<"  Main Menu\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n\n\t"<<"STUDENT DATABASE\n\n";
		cout<<"\t[O] -------------------- Open an existing student's file\n";
		cout<<"\t[A] -------------------- Add new person to the current list\n";
		cout<<"\t[R] -------------------- Remove a person from the current list\n";
		cout<<"\t[P] -------------------- Print List\n";
		cout<<"\t[E] -------------------- Edit info for 1 person\n";
		cout<<"\t[S] -------------------- Search\n";
		cout<<"\t[T] -------------------- Sort List\n";
		cout<<"\t[*] -------------------- About\n";
		cout<<"\t[X] -------------------- Exit\n\t";
 }
 void Save_file(Student Student_List[],int counter, ofstream &fs)
 {		int j=0;
			
			 for(int j=0;j<counter;j++){
				 fs<<Student_List[j].Full_Name<<endl;
				fs<<Student_List[j].ID<<" ";
				 for(int i=0; i<Student_List[j].indx_grd;i++)
					fs<<Student_List[j].Grade[i]<<" "<<Student_List[j].Units[i]<<" ";
				 fs<<"*"<<endl;
			}
			
 }
 
void Exit_Menu(int &exit_loop, int &loop, Student Student_List[], int counter,string file_in)
{			char response;
			ofstream fs;
		while(exit_loop ==1)
			{
				
			system("CLS");
			cout<<"  Main Menu >> Exit Prompt\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n\t(!) Would you like to save any changes made to "<<file_in<<" ?";
			cout<<"\n\t\t\t[Yes]/[No]/[Cancel]\n";
			cin>>response;
			system("CLS");
			switch(response)
				{case'Y':
				 case'y': 
					 cout<<"  Main Menu >> Exit Prompt >> SAVE\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			fs.open(file_in.c_str());
			Save_file( Student_List, counter,fs);
			cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t ! Changes Successfully Saved to "<<file_in;
					 cout<<"\n\t |\t + Have a nice day!\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 fs.close();
					 exit_loop =0, loop=0;
					 break;
				 case'N':
				 case'n': 
					 cout<<"  Main Menu >> Exit Prompt >> EXIT\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
					  cout<<"\n\t"<<setfill('=')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t! No changes were made\n";
					 cout<<"\t |\t+ Have a nice day!\n";
					 cout<<"\t"<<setfill('=')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 exit_loop =0,loop =0;
					 break;
				 case'C':
				 case'c': exit_loop =0,loop=1;
				 default: 
					 break;
			}
			}
}
void About()
{		int loop=1;
			char response;
		while(loop==1)
			{	system("CLS");
				 cout<<"  Main Menu >> About Sub-Menu\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n\n\t"<<"About Menu\n\n";
			cout<<"\t[+] ----------------- About Student Database\n";
			cout<<"\t[X] ----------------- Return to Main Menu\n\t";
			cin>>response;
			switch(response)
				{
				case'+': 
					system("CLS");
					cout<<"  Main Menu >> About Sub-Menu >> About\n";
					cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left<<endl;
					cout<<"       "<<setfill('*')<<setw(45)<<" " << setfill(' ')<<setw(1)<< left;
					cout<<"\n\t* Student Database v0.7"<<"\n\t* Programmed by: Roberto Sanchez\n"<<"\t* Built for calculting grades of students\n";
					cout<<"       "<<setfill('*')<<setw(45)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					system("PAUSE");
					loop=1;
					break;
				case'X':
				case'x':loop=0;
					break;
				default: 
					break;
			}
	}
}
int Search (Student Student_List[],int counter)
{ string Name;
	system("CLS");
	cin.ignore(10,'\n');
	cout<<"  Main Menu >> Search\n";
	cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
	cout<<"\t Enter Student's Last Name: ";
		getline(cin,Name);
	for(int i=0; i< counter;i++)
		if(Student_List[i].Full_Name==Name)
				 return i;		   		 
	return -1;
	    
}
void Search_Results(Student Student_List[],int counter)
{int i;	
int loop=1,size=0;
char ansr;
	loop=1;//resetting loop
	while(loop==1){
		size=0;
	i= Search (Student_List, counter);
	if(i ==-1)
		{			 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  Student Not Found";
					 cout<<"\n\t |\t(?) Names are Case Sensitive: (LastName, First Name)\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
	}
	else
		{	cout<<"\n\tStudent Found:\n";
			cout<<"\t"<<setfill('*')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left<<endl;	
			cout<<"\t * Name:\t"<<Student_List[i].Full_Name
			<<"\n\t * Student ID:\t"<<Student_List[i].ID<<"\n\t * GPA:\t\t"<<fixed<<setprecision(2)<<Student_List[i].GPA
			<<"\n\t * Units:\t"<<fixed<<setprecision(0)<<Student_List[i].Total_Units;
			
			cout<<"\n\t * \n\t * Grades for Student:";
			cout<<"\n\t * \t  Grade"<<"  Units";
			size =sizeof Student_List[i].Units/sizeof(int);
			for(int j=0, count =1;j<size;j++,count++)
				cout<<"\n\t * \t"<<count<<".  "<<setw(1)<<Student_List[i].Grade[j]<<"      "<<Student_List[i].Units[j];
			cout<<"\n\t"<<setfill('*')<<setw(40)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
	}
	cout<<"\tSearch Again?\n\t"<<"\t[Y]/[N]\n\t";
		cin>>ansr;
		switch(ansr)
		{
		case'Y':
		case'y': 
			break;
		case'N':
		case'n':loop =0;
			break;
		default:
			break;
		}
	}
}
void Zeros(Student Student_List[])
{
	for(int i=0; i<20;i++)
	{
		for(int j=0; j<20; j++)
			{Student_List[i].Grade[j]='*';
			Student_List[i].Units[j]=0;
		}
	}
}
void Sort_Menu(Student Student_List[], int counter)
{
	int loop=1;
	char response;

		while(loop==1)
			{	system("CLS");
				 cout<<"  Main Menu >> Sort Sub-Menu\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n\n\t"<<"Sort Sub-Menu\n\n";
			cout<<"\t[N] ----------------- Sort on Names (Alphabetical)\n";
			cout<<"\t[C] ----------------- Sort on GPA (Descending) \n";
			cout<<"\t[X] ----------------- Return to Main Menu\n\t";
			cin>>response;
			switch(response){	
				case'N':
				case'n': Sort_Name (Student_List,counter);
					system("CLS");
						cout<<"  Main Menu >> Sort Sub-Menu >> Sort Alphabetical\n";
						cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left<<endl;
						cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
						cout<<"\n\t |\t !  Sorting Complete";
						cout<<"\n\t |\t +  Preview in Print Option\n";
						cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					system("PAUSE");
					break;
				case'C':
				case'c': Sort_GPA (Student_List,counter);
					break;
				case'X':
				case'x': loop =0;
					break;
				default:
					break;
				
			}
		}
}
void Edit(Student Student_List[],int counter,Overall &Total)//FIXX
{		int loop=1,locator=0,tab=0,size=0,indx=0;
		char ansr;
		string Name;
		
		while(loop==1)
		{ system("CLS");
			
		cout<<"  Main Menu >> Edit Sub-Menu\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n\t"<<"Edit Sub-Menu\n";
		cout<<"\n\tPlease Enter Student's Last Name, First Name to Edit: ";
		cin.ignore(10,'\n');
		getline(cin,Name);
		for(int i=0; i< counter;i++){
			if(Student_List[i].Full_Name == Name)
				locator = 1,tab = i;}
		if(locator=0){
			cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  Student Not Found";
					 cout<<"\n\t |\t(?) Names are Case sensitive: (LastName, First Name)\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 loop=0;}
		else	{	cout<<"\n\t[G] ----------------- Change Student's Grades/Units\n";
				cout<<"\t[I] ----------------- Change Student's ID Number\n";
				cout<<"\t[X] ----------------- Return to Main Menu\n\t";
					cin>>ansr;
						switch (ansr)
						{	case'G':
							case'g':system("CLS");
								cout<<"  Main Menu >> Edit Sub-Menu >> Edit Grades/Units\n";
								cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
								cout<<"\n\t\t Grade"<<"  Units";
									size =sizeof Student_List[tab].Units/sizeof(int);
						for(int j=0, count =1;j<size;j++,count++)
							cout<<"\n\t \t"<<count<<".  "<<setw(1)<<Student_List[tab].Grade[j]<<"      "<<Student_List[tab].Units[j];
						cout<<"\n\n\tChoose Which grade of "<<Student_List[tab].Full_Name<<" should be edited?\n\t\t";
							cin>>indx;
							indx--;
							Process_Change (Student_List,Total,counter,tab, size,indx);
							
								loop =0;
								break;
							case'I':
							case'i':
								system("CLS");
								cout<<"  Main Menu >> Edit Sub-Menu >> Edit ID\n";
								cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
								cout<<"\n\tEnter New ID for "<<Student_List[tab].Full_Name<<": ";
									cin>>Student_List[tab].ID;
								cout<<Student_List[tab].Full_Name<<" new ID Number is "<<Student_List[tab].ID<<endl;
								system("PAUSE");
								loop =0;
								break;
							case'X':
							case'x': loop=0;
								break;
						}
			}

		}
}
void Process_Change (Student Student_List[], Overall &Total,int counter,int tab, int size, int indx)
{int total_units=0;
double adden=0,GPA=0;
	Verify_Change(Student_List,tab,size,indx);
	
	for(int i=0; i<size;i++){
		adden+= Student_List[tab].Grade[i]*Student_List[tab].Units[i];
		total_units += Student_List[tab].Units[i];
		GPA= adden/total_units;
	}
	Student_List[tab].GPA =GPA;
		Student_List[tab].adden =adden;
		Student_List[tab].Total_Units = total_units;
		Total.Total_Units += total_units;

					 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  Update Complete\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 system("PAUSE");

}
void Verify_Change(Student Student_List[], int tab, int size,int indx)
{	float Num_grade=0;
int	i=0;
Student_List[tab].Grade[indx]='*';
Student_List[tab].Units[indx] =0;
cout<<"\n\tEnter new Grade:\n\t\t";
cin>>Student_List[tab].Grade[indx];

			Num_grade = Assign_GPA (Student_List[tab].Grade[indx]);
			if(Num_grade !=6)
				{		cout<<"\n\tEnter new Unit:\n\t\t";
							cin>>Student_List[tab].Units[indx];

							 if(Student_List[tab].Units[indx] <  0 || Student_List[tab].Units[indx] > 5){
								 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
								 cout<<"\n\t |\t !  Invalid Unit";
								 cout<<"\n\t |\t(?) Units are between 0 and 5\n";
								 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
								 Student_List[tab].Units[indx] = '*',Student_List[tab].Grade[indx] =0 ;}
							 else
								 Student_List[tab].Units[indx] = '*'; Student_List[tab].Grade[indx] =0 ;
				}
			else{
				 cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !  Invalid Grade";
					 cout<<"\n\t |\t(?) Grades are either: 'A','B','C','D', or'F'\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
					 Student_List[tab].Grade[indx] ='*', Student_List[tab].Units[indx] = 0;}
}
void Sort_Name (Student Student_List[],int counter)
{
	int Min, i, j;
	long temp_id;
	double gpa,total_units, adden;
	int indx_grd, Units[20];
	char grade[20];
	string temp;

	for(i=0;i<counter-1;i++){
		Min=i;
			for(j=i+1;j<counter;j++){
			if(Student_List[j].Full_Name<Student_List[Min].Full_Name)
				Min=j;
			//Switch
			temp= Student_List[i].Full_Name;
			temp_id= Student_List[i].ID;
			gpa = Student_List[i].GPA;
			total_units= Student_List[i].Total_Units;
			adden= Student_List[i].adden;
			indx_grd= Student_List[i].indx_grd;
			for(int l=0;l<20;l++){
			grade[l]= Student_List[i].Grade[l];
			Units[l]= Student_List[i].Units[l];}
			//Switch 
				Student_List[i].Full_Name= Student_List[Min].Full_Name;
				Student_List[i].ID= Student_List[Min].ID;
				Student_List[i].GPA= Student_List[Min].GPA;
				Student_List[i].Total_Units= Student_List[Min].Total_Units;
				Student_List[i].adden = Student_List[Min].adden;
				Student_List[i].indx_grd =Student_List[Min].indx_grd;
				for(int l=0;l<20;l++){
				Student_List[i].Grade[l] =Student_List[Min].Grade[l];
				Student_List[i].Units[l] =Student_List[Min].Units[l];}
			//Switch
			Student_List[Min].Full_Name = temp;
			Student_List[Min].ID = temp_id;
			Student_List[Min].GPA =gpa;
			Student_List[Min].Total_Units=total_units;
			Student_List[Min].adden=adden;
			Student_List[Min].indx_grd=indx_grd;
			for(int l=0;l<20;l++){
			Student_List[Min].Grade[l]=grade[l];
			Student_List[Min].Units[l]=Units[l];}
			}
	}
	
}
void Sort_GPA (Student Student_List[], int counter)
{
	int Min = counter;
	long temp_id;
	double gpa,total_units, adden;
	int indx_grd, Units[20];
	char grade[20];
	string temp;
	bool flag;
	do{
	flag =false;
	counter--;
	for(int i=0;i<counter;i++){
		if(Student_List[i].GPA<Student_List[i+1].GPA){
			
			//Switch
			temp= Student_List[i].Full_Name;
			temp_id= Student_List[i].ID;
			gpa = Student_List[i].GPA;
			total_units= Student_List[i].Total_Units;
			adden= Student_List[i].adden;
			indx_grd= Student_List[i].indx_grd;
			for(int l=0;l<20;l++){
			grade[l]= Student_List[i].Grade[l];
			Units[l]= Student_List[i].Units[l];}
			//Switch 
				Student_List[i].Full_Name= Student_List[i+1].Full_Name;
				Student_List[i].ID= Student_List[i+1].ID;
				Student_List[i].GPA= Student_List[i+1].GPA;
				Student_List[i].Total_Units= Student_List[i+1].Total_Units;
				Student_List[i].adden = Student_List[i+1].adden;
				Student_List[i].indx_grd =Student_List[i+1].indx_grd;
				for(int l=0;l<20;l++){
				Student_List[i].Grade[l] =Student_List[i+1].Grade[l];
				Student_List[i].Units[l] =Student_List[i+1].Units[l];}
			//Switch
			Student_List[i+1].Full_Name = temp;
			Student_List[i+1].ID = temp_id;
			Student_List[i+1].GPA =gpa;
			Student_List[i+1].Total_Units=total_units;
			Student_List[i+1].adden=adden;
			Student_List[i+1].indx_grd=indx_grd;
			for(int l=0;l<20;l++){
			Student_List[i+1].Grade[l]=grade[l];
			Student_List[i+1].Units[l]=Units[l];}
			flag=true;
		}
	}
}while(flag);
	system("CLS");
		cout<<"  Main Menu >> Sort Sub-Menu >> Sort By GPA\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left<<endl;
	cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
	cout<<"\n\t |\t !  Sorting Complete";
	cout<<"\n\t |\t +  Preview in Print Option\n";
	cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
	system("PAUSE");
}
void Add (Student Student_List[], int &counter, Overall &Total)
{	string Name;
	char ansr;
	int loop =1;
	
		system("CLS");

	cout<<"  Main Menu >> Add\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
	while(loop==1){
	system("CLS");
		if(counter <20){
			cout<<"  Main Menu >> Add New Student"<<setw(45)<<right<<"Spaces Left: "<<20-counter<<endl;
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left<<endl;
			Student_List[counter].Full_Name =" ";
			Student_List[counter].ID = 00000000;
			Student_List[counter].Total_Units =0;
			Student_List[counter].adden=0;
			Student_List[counter].GPA=0.00;
			for(int i=0;i<20;i++){
			Student_List[counter].Grade[i]='*';
			Student_List[counter].Units[i] =0;}
			cout<<"\n\tPlease enter new Student's Name(Last Name, First Name): ";
				cin.ignore(10,'\n');
				getline(cin,Student_List[counter].Full_Name);
			cout<<"\n\tPlease enter new Student's ID (8 digits MAX): ";
				cin>>Student_List[counter].ID;
					if(Student_List[counter].ID >99999999){
						cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
						cout<<"\n\t |\t  !   Invalid ID";
						cout<<"\n\t |\t (?)  Must be MAX 9 digits\n";
						cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
							loop=0;
								counter--;}
					for(int j=0;j<20 ||ansr == '*' ;j++){
							cout<<"\tPlease enter a Grade : ";
								cin>>Student_List[counter].Grade[j];
							cout<<"\tPlease enter a Unit or '*' to stop: ";
								cin>>ansr;
								if(ansr =='*'){
									loop=0; Student_List[counter].Units[j]=0; break;}
								else
									ansr=Student_List[counter].Units[j];}
						loop=0;
						counter++;
		}
		else{
			cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
						cout<<"\n\t |\t  !   No More Spaces Available";
						cout<<"\n\t |\t (?)  Max 20 Students\n";
						cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
						loop =0;}
}
}
void Remove(Student Student_List[],int &counter,Overall &Total)
{	string Name;
	int locator =0,tab=0, loop =1;
	char ansr;
	system("CLS");

	cout<<"  Main Menu >> Remove\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		while(loop ==1){
		cout<<"\n\tPlease Enter Student's Last Name, First Name to Edit: ";
		cin.ignore(10,'\n');
		getline(cin,Name);
		for(int i=0; i< counter;i++){
			if(Student_List[i].Full_Name == Name)
				locator = 1,tab = i;}
		if(locator=1){
						cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
						cout<<"\n\t |\t  !  WARNING: Deleting Student will erase everthing\n\t\t\t attached to Student";
						cout<<"\n\t |\t (?) Grades, Units, ID, Name would be deleted\n";
						cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
						cout<<"\t\t\Continue?\n\t\t[Y]/[N]\n\t\t";
							cin>>ansr;
							switch(ansr){
							case'Y':
							case'y':Student_List[tab].Full_Name = "";
									Student_List[tab].GPA =999.999;
									Student_List[tab].ID = 00000000000;
									Student_List[tab].Total_Units =0;
									Student_List[tab].adden=0;
									for(int i=0;i<20;i++){
										Student_List[tab].Grade[i] = '*';
										Student_List[tab].Units[i] = 0;
									}
									Sort_Name (Student_List,counter);
										counter--;
									system("CLS");
									cout<<"  Main Menu >> Remove\n";
									cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
									cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
									cout<<"\n\t |\t !	Student DELETED\n";
									cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
									loop = 0;
									system("PAUSE");
								break;
							case'N':
							case'n': loop =0;
								break;
							default:
								loop=1;
							}

					 }
		else	{	
			cout<<"\n\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left;
					 cout<<"\n\t |\t !	Student not Found...";
					 cout<<"\n\t |\t(?) Names are Case sensitive: (LastName, First Name)\n";
					 cout<<"\t"<<setfill('=')<<setw(60)<<" " << setfill(' ')<<setw(1)<< left<<endl<<endl;
		loop=0;}
		}
}