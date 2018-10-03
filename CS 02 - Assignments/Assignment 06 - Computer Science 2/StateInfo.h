#ifndef __STATEINFO_H__
#define __STATEINFO_H__
#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
struct StateInfo{
	char name[15];
	int population;
	int area;
	int year;
	int order;
	char capital[15];
	char abbrev[3];
	int zip;
	void INITIALIZE(StateInfo);
};
typedef bool CompFunc(const StateInfo& p1, const StateInfo& p2);
void Print(StateInfo a[], int Size);
//Prints out entire array
//Precondition: None
//Postcondition: Prints a[] out
bool OpenRead(StateInfo a[],StateInfo& n,int& Size,int& i);
//Opens a .dat file and reads the data into the array a[]
//Precondition: None
//Postcondition: Either returns: True - File sucessfully opened
//								 or
//								 False - File did not sucessfully opened
bool NameLT(const StateInfo& p1, const StateInfo& p2);
//Compares if p1 name is less than p2 name
//Precondition:Names inside StateInfo Class
//Postcondition:Returns either:True - p1 is less than p2
//							   or
//							   False - p1 is not less than p2
bool NameLTE(const StateInfo& p1, const StateInfo& p2);
//Compares if p1 name is less or equal than p2 name
//Precondition:Names inside StateInfo Class
//Postcondition:Returns either:True - p1 is less or equal than p2
//							   or
//							   False - p1 is not less than or equal than p2
bool PopLTE(const  StateInfo& p1, const StateInfo& p2);
//Compares if p1 population is less than or equal than p2 population
//Precondition:Population inside StateInfo Class
//Postcondition:Returns either:True - p1 is less than or equal to p2
//							   or
//							   False - p1 is not less than or equal to p2
bool PopLT(const StateInfo& p1, const StateInfo& p2);
//Compares if p1 population is less than p2 population
//Precondition:Population inside StateInfo Class
//Postcondition:Returns either:True - p1 is less than p2
//							   or
//							   False - p1 is not less than p2
void HeapSort(StateInfo values[], int numValues, CompFunc LT, CompFunc LTE);
//Sorts through the array in alphabetical order (NAMES)
//Precondition:Values in the array, number of values
//Postcondition:Calls ReheapDown to finish sorting
void ReheapDown(StateInfo elements[], int root, int bottom, CompFunc LT, CompFunc LTE);
//Is called by HeapSort
//Precondition:
//Postcondition:
void SelectionSort(StateInfo a[], int na);
//Sorts through the array (By Population)
//Precondition:None
//Postcondition: Sorts population array in Decending order 
#endif