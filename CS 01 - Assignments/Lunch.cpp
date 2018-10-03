// Program Lunch calculates the number of calories in a cheese sandwich. Each sandwich contains 
// 2 slices of bread, 3 slices of cheese, 4 pieces of pickles, and 2 grams of mayonnaise.
// Roberto Sanchez
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
//Constants
const int  BREAD = 63;//calories in a slice of bread
const int CHEESE = 106;//calories in a slice of cheese
const int MAYONNAISE = 49;//calories in 1 gram of mayonnaise
const int PICKLE = 25;//calories in a slice of pickle

//Variables for ingredients
string name;
int brd;
int chs;
int myns;
int pkls;

int brdcal;
int chscal;
int mynscal;
int pklscal;

int TotalCalories;

//Input
cout<<"\t\t\tWelcome to my Calorie Counter"<<endl;
cout<<"\nPlease enter your name? ";
	getline(cin,name);
cout<<"\nHi "<< name <<", please enter number of ingredients used on your sandwich."<<endl;
cout<<"\nPlease enter number of slices of bread used (0 if not used): ";
	cin>> brd;
cout<<"\nPlease enter number of slices of cheese used (0 if not used): ";
	cin>> chs;
cout<<"\nPlease enter amount of mayonnaise in grams used (0 if not used): ";
	cin>> myns;
cout<<"\nPlease enter number of pieces of pickle used (0 if not used): ";
	cin>> pkls;

//Formulas for caluculating Calories
	
	TotalCalories = brd*BREAD + chs*CHEESE + myns*MAYONNAISE + pkls*PICKLE;
		
	brdcal = brd*BREAD;
	chscal = chs*CHEESE;
	mynscal = myns*MAYONNAISE;
	pklscal = pkls*PICKLE;

//Output of calories per ingredient
	cout<<left;
cout<<"\tBread calories: "     <<brdcal<<endl
	<<"\tCheese calories: "    <<chscal<<endl
	<<"\tMayonnaise calories: "<<mynscal<<endl
	<<"\tPickle calories: "    <<pklscal<<endl<<endl
	<<"\tTotal calories: "     <<TotalCalories<<endl;

//Output
	cout<<endl;
	cout<< name <<",there were "<<TotalCalories<<" calories in your lunch yesterday."
		<<"\nWhat is for lunch today? Funny!!!"<<endl;
	

return 0;
}
