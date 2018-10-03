#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"StateInfo.h"
using namespace std;
const int Max_States = 50;
typedef bool CompFunc(const StateInfo& p1, const StateInfo& p2);
// Person Comparison Functions:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// name compare
void StateInfo::INITIALIZE(StateInfo n)
{
	name[15]= n.name[15];
	population=n.population;
	area=n.area;
	year=n.year;
	order=n.order;
	capital[15]=n.capital[15];
	abbrev[3]=n.abbrev[3];
	zip=n.zip;
}
//---------------------------------------------------------------------------------------------------------------------------------
void Print(StateInfo a[], int Size)
{

	cout<<left<<" "<<setw(16)<<"State Name:"<<setw(15)<<"Capital"<<setw(6)<<"Year"<<setw(12)<<"Population";
	cout<<setw(7)<<"Area"<<setw(6)<<"Zip"<<setw(6)<<"Order"<<"Abbrev"<<endl;
	cout<<"---------------------------------------------------------------------------\n";
	for(int j = 0,counter =0; j<Size; j++,counter++)
	{	
		if(counter ==10)
		{
			cout<<endl;
			cout<<left<<" "<<setw(16)<<"State Name:"<<setw(15)<<"Capital"<<setw(6)<<"Year"<<setw(12)<<"Population";
			cout<<setw(7)<<"Area"<<setw(6)<<"Zip"<<setw(6)<<"Order"<<"Abbrev"<<endl;
			cout<<"---------------------------------------------------------------------------\n";
			counter =0;
		}
		cout<<" "<<left<<setw(16)<<a[j].name<<setw(15)<<a[j].capital<<setw(6)<<a[j].year<<setw(12)<<a[j].population;
		cout<<setw(7)<<a[j].area<<setw(8)<<a[j].zip<<setw(6)<<a[j].order<<setw(6)<<a[j].abbrev<<endl;
	}
	cout<<"---------------------------------------------------------------------------\n";
}
//---------------------------------------------------------------------------------------------------------------------------------
bool OpenRead(StateInfo a[],StateInfo& n,int& Size,int& i)
{
	ifstream inBin;
	string name,name2[15];
	int pop,area,year,order,cap[15],ab[3];

	cout<<" Please enter Data File: ";
	cin>>name;
	inBin.open(name.c_str(),ios::binary);
	if( !inBin)
	{
		cout<<" File could not open\n";
		return false;
	}
	else
		cout<<" File Successfully opened\n";
	cout<<" Now Reading Data...\n";
	while(i < Max_States && inBin.read((char *)&n,Size))
	{
		a[i++]=n;
	}
	//while(i < Max_States && inBin.read((char *)&n,Size))
	//{

	//	a[i++] = new StateInfo(n);
	//}
	return true;
}
//---------------------------------------------------------------------------------------------------------------------------------
bool NameLT(const StateInfo& p1, const StateInfo& p2)
{
	return strcmp(p1.name,p2.name) < 0;
}
//---------------------------------------------------------------------------------------------------------------------------------

bool NameLTE(const StateInfo& p1, const StateInfo& p2)
{
	return strcmp(p1.name,p2.name) <= 0;
}
//---------------------------------------------------------------------------------------------------------------------------------
bool PopLT(const StateInfo& p1, const StateInfo& p2)
{
	return p1.population < p2.population;
}
//---------------------------------------------------------------------------------------------------------------------------------
bool PopLTE(const  StateInfo& p1, const StateInfo& p2)
{
	return p1.population <= p2.population;
}
//---------------------------------------------------------------------------------------------------------------------------------
void Swap(StateInfo& x,StateInfo& y)
{
	StateInfo temp = x;
	x = y;
	y = temp;
}
//---------------------------------------------------------------------------------------------------------------------------------
void HeapSort(StateInfo values[], int numValues, CompFunc LT, CompFunc LTE)
{
	int index;
	int step = 0;
	for (index = numValues/2 - 1; index >= 0; index--)
	{
		ReheapDown(values, index, numValues-1,LT,LTE);
	}
	step = 0;
	for (index = numValues-1; index >=1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index-1,LT,LTE);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void ReheapDown(StateInfo elements[], int root, int bottom, CompFunc LT, CompFunc LTE)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;// 
	rightChild = root*2+2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if ( LTE(elements[leftChild],elements[rightChild]) )
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if ( LT(elements[root],elements[maxChild]) )
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(elements, maxChild, bottom,LT,LTE);
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------
void SelectionSort(StateInfo a[], int na)
{
	int lowIndex;
	StateInfo temp;
	for(int i= 0;i<na-1; i++)
	{
		lowIndex=i;
		for(int j=i+1;j<na;j++)
			if(a[j].population>a[lowIndex].population)
				lowIndex =j;
		if(lowIndex != i)
		{
			temp = a[lowIndex];
			a[lowIndex]=a[i];
			a[i]=temp;
		}

	}
}