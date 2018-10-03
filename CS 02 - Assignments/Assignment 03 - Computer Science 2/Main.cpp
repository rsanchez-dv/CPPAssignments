/*
Student: Roberto Sanchez
Class:   Computer Science 2
Date:    Oct. 27, 2012
Due:     Oct. 29, 2012

Analysis: Create a linear, sorted list from movie information stored in a text file. Enable 
the user to manipulate the list through a menu
Class MovieType: Contains Movie data as private and functinos to display, compare, 
initilize, and read functions
Class SortedMovieList:Contains sorted movie array and size as private, contains functions to manipulate
the given array to add, remove, search, counts, and print all the data in private.
*/
#include<iostream>
#include<string>
#include<fstream>
#include "SortedMovieList.h"
#include "MovieType.h"
#include<iomanip>
using namespace std;
void doSearch( SortedMovieList& p);
void doRemove(SortedMovieList& p);
void doAdd(SortedMovieList& p);
void doCount( SortedMovieList& p);
void doSearchStars(SortedMovieList& p);
int main()
{	
	SortedMovieList p;
	ifstream fin;
	bool Loop=true,file_loop =false;
	char answer;
	do{
		string FILE_NAME;
		system("CLS");
		cout<<"  Welcome\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n (!) File Name >> 'Movie_Data.txt'";
		cout<<"\n    Please enter a file name to read from: ";
		cin>>FILE_NAME;
		fin.open(FILE_NAME.c_str());
		if(fin.fail())
		{
			cout<<"\t(!) Bad File Name, try again!\n";
			system("PAUSE");
			file_loop = true;
		}
		else
			file_loop = false;

	}while(file_loop);
	p.ReadAllMovieFromFile(fin);
	while(Loop)
	{	
		system("CLS");
		cout<<" "<<setw(50)<<" Main Menu"<<endl;
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n\n"<<"   MOVIE DATABASE\n\n";
		cout<<"\t[1] -------------------- View Movies in List\n";
		cout<<"\t[2] -------------------- Search a Movie's infomation\n";
		cout<<"\t[3] -------------------- Search Movies based on Stars\n";
		cout<<"\t[4] -------------------- Delete Movie from List\n";
		cout<<"\t[5] -------------------- Add Movie to List\n";
		cout<<"\t[6] -------------------- Count Movies in List\n";
		cout<<"\t[7] -------------------- Quit\n";
		cout<<"\t[Input]: ";
		cin>>answer;
		system("CLS");
		if(answer<'0' || answer>'7')
		{
			cout<<"  Main Menu >> Error Prompt\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n Answer not understood, try again!\n";
			system("PAUSE");
		}
		else
		{
			switch(answer)
			{
			case '1':
				cout<<"  Main Menu >> View\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				p.DisplayAll();
				system("PAUSE");
				break;
			case '2':
				doSearch(p);
				break;
			case '3':
				cout<<"  Main Menu >> Search 2\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				cout<<"Not finished yet...\n";
				system("PAUSE");
				break;
			case '4':
				doRemove(p);
				break;
			case '5':
				doAdd(p);
				break;
			case '6':
				doCount(p);
				break;
			case '7':
				cout<<"  Main Menu >> Terminating Program\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				cout<<"\n Ending Program, ALL CHANGED DATA WAS UNSAVED...\n ";
				cout<<endl;
				Loop = false;
				break;
			default: 
				cout<<"  Main Menu >> Error Prompt\n";
				cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
				cout<<"\n Answer not understood, try again!\n";
				system("PAUSE");
				break;
			}
		}
	}
	return 0;
}
/*
	/////////////Functions/////////////////
*/
void doSearch(SortedMovieList& p)
{
	char answer;
	MovieType temp;
	bool SearchLoop = false;
	cin.ignore(10,'\n');
	string title;
	do{
		system("CLS");
		cout<<"  Main Menu >> Search\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"\n Please enter a movie Title to search: ";
		getline(cin,title);
		temp.setkey(title);
		if(p.findAndRetrieve(temp))
			temp.Display();
		else
			cout<<"\t(!) Title Could not be found...\n";
		cout<<" (?) Do you want to look again?  [Y]-Yes/[N]-No";
		cout<<"\n     Response:";
		cin>>answer;
		if(answer == 'y'||answer == 'Y')
		{
			SearchLoop = true;
		}
		else 
		{
			if(answer =='n' ||answer == 'N')
				SearchLoop = false;
		}
		cin.ignore(10,'\n');
	}while(SearchLoop);
}
//---------------------------------------------------------------------------------------------
void doRemove(SortedMovieList& p)
{
	bool DeleteLoop;
	string title;
	char answer;
	MovieType q;
	cin.ignore(10,'\n');
	do{
		do{

			system("CLS");
			cout<<"  Main Menu >> Delete\n";
			cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
			cout<<"\n Please enter the Title of the movie you want to remove: ";
			getline(cin,title);
			q.setkey(title);
			if(!p.findAndRetrieve(q))
			{
				cout<<" (!) Title Could not be found...\n";
				system("PAUSE");
			}
		  }while(!p.findAndRetrieve(q));
		q.Display();
		cout<<"\n  (!) Delete this?  [Y]-Yes/[N]-No\n";
		cout<<"      Response: ";
		cin>>answer;
		if(answer == 'y'||answer == 'Y')
		{
			if(p.findAndRemove(q))
			{
				cout<<endl<<"\t(!) ["<<title<<"] has been deleted from list.\n";
			}
			else
				cout << "\n(?) The movie "<<title<<" is not on the list.\n";	
		}
		else 
			if(answer =='n' ||answer == 'N')
				DeleteLoop = false;

		cout<<"\n  (?) Do you want to remove another title?  [Y]-Yes/[N]-No";
		cout<<"\n      Response:";
		cin>>answer;
		if(answer == 'y'||answer == 'Y')
			DeleteLoop = true;
		else 
		{
			if(answer =='n' ||answer == 'N')
				DeleteLoop = false;
		}
	}while(DeleteLoop);
	cin.ignore(10,'\n');
}
//---------------------------------------------------------------------------------------------
void doAdd(SortedMovieList& p)
{
	bool AddLoop = false;
	MovieType Mov;
	char answer;
	string title,year, receipts, studio, stars;
	do{
		cin.ignore(10,'\n');
		system("CLS");
		cout<<"  Main Menu >> Add\n";
		cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
		cout<<"  Enter Movie Title:    ";
		getline(cin,title);
		cout<<"  Enter Movie Year:     ";
		cin>>year;
		cout<<"  Enter Movie Studio:   ";
		cin>>studio;
		cout<<"  Enter Movie Receipts: ";
		cin>>receipts;
		cin.ignore(10,'\n');
		cout<<" (!) Enter commas inbetween stars if more than 1 or 'None' if None";
		cout<<"\n  Enter Movie Stars:  ";
		getline(cin,stars);
		Mov.Initialize(title,year,receipts,studio,stars);
		Mov.Display();
		cout<<"\n (?) Is this Ok?  [Y]-Yes/[N]-No\n";
		cout<<"     Response: ";
		cin>>answer;
		if(answer == 'y'||answer == 'Y')
		{
			if(p.add(Mov))
			{
				cout<<"\n (!) "<<title<<" has been added to list\n";
			}
			else
				cout << "\n\t(?) The movie could not be created.\n";
		}
		else 
			if(answer =='n' ||answer == 'N')
			{
				cout<<"\n\t (!) Movie was not created.\n";
			}
		cout<<"\n (?) Do you want to add more:   [Y]-Yes/[N]-No\n";
		cout<<"      Response: ";
		cin>>answer;
		if(answer == 'y'||answer == 'Y')
			AddLoop = false;
		else 
		{
			if(answer =='n' ||answer == 'N')
				AddLoop = true;
		}

	}while(!AddLoop);
}
//---------------------------------------------------------------------------------------------
void doCount( SortedMovieList& p)
{
	cout<<"  Main Menu >> Count\n";
	cout<<setfill('-')<<setw(80)<<" " << setfill(' ')<<setw(1)<< left;
	cout<<endl<<" The Number of Movies Stored is: "<<p.GetMovieSize();
	cout<<endl;
	system("PAUSE");

}
//---------------------------------------------------------------------------------------------
void doSearchStars(SortedMovieList& p)
{
	string star;
	cout<<"Please enter stars to look up: ";
	getline(cin,star);

}
//---------------------------------------------------------------------------------------------