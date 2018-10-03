// |
// |		SortedMovieList Functions
// |--------------------------------------------------------------------
#include "SortedMovieList.h"  //header file 
#include <iostream>
#include <fstream>

int SortedMovieList::GetMovieSize()
{
		return ListSize;
}
//---------------------------------------------------------------------------------------------

SortedMovieList::SortedMovieList()
{
	ListSize = 0;
}
//---------------------------------------------------------------------------------------------

bool SortedMovieList::ReadAllMovieFromFile(ifstream &fin)
{
	MovieType MovieTemp;
	for(int i = 0; i<MAX_SIZE; i++)
	{
		if(MovieTemp.ReadOneMovieFromFile(fin))
		{	
			if(!add(MovieTemp))
			{
				cout<<"\n\tNo More Room to add\n";
				return false;
			}
		}
		else
			break;
	}
	return true;
}

//---------------------------------------------------------------------------------------------
void SortedMovieList::DisplayAll()const
{
	cout<<" Printing Stored List...\n";
	for(int j=0, p=1;j<ListSize;j++, p++)
	{
		items[j].Display();
		if(p == 3)
		{
			system("PAUSE");
			p=0;
		}
	}
	cout<<"\n (!) End of list\n";
}
//---------------------------------------------------------------------------------------------
bool SortedMovieList::remove(int index)
{
	if(index<0||index>= ListSize)
		return false;
	for(int pos = index;pos<ListSize-1;++pos)
		items[pos]=items[pos+1];
	ListSize--;

	return true;
}
//---------------------------------------------------------------------------------------------

bool SortedMovieList::findAndRemove(const ListItemType& itemToFind)
{
	int index=find(itemToFind);
	if(index>=0)
		return remove(index);
	else
		return false;
}
//---------------------------------------------------------------------------------------------
int SortedMovieList::find(const ListItemType& itemToFind)const
{
	int start = 0, end = ListSize-1;
	int midpoint;
	while( start <= end )
	{
		midpoint = ( start + end ) / 2;
		if(items[midpoint] > itemToFind)
		{
			end = midpoint-1;
		}
		else if( items[midpoint] < itemToFind)
		{
			start = midpoint+1;
		}
		else if (items[midpoint] == itemToFind)
		{
			return midpoint;
		}
	}
	return -1;
}
//---------------------------------------------------------------------------------------------
bool SortedMovieList::add(const ListItemType& newItem)
{
	int p;
	if( ListSize <  MAX_SIZE  )
	{
		for(p = 0; p < ListSize; p++ )
		{
			if( newItem < items[p] )
				break;
		}
		insert( p, newItem);
		return true;
	}
	return false;

}
//---------------------------------------------------------------------------------------------
bool SortedMovieList::insert(int index, ListItemType newItem)
{
	if(index<0||index>ListSize||ListSize==MAX_SIZE)
		return false;
	for(int pos=ListSize;pos>index;--pos)
		items[pos]=items[pos-1];
	items[index]=newItem;
	ListSize++;
	return true;
}
//---------------------------------------------------------------------------------------------
bool SortedMovieList::findAndRetrieve(ListItemType& itemToFind) const
{
	int index=find(itemToFind);
	if(index>=0)
		return retrieve(index,itemToFind);
	else
		return false;
}
//---------------------------------------------------------------------------------------------
bool SortedMovieList::retrieve(int index, ListItemType& dataItem)const
{
	if(index<0||index>=ListSize)
		return false;
	dataItem=items[index];
	return true;
}
//---------------------------------------------------------------------------------------------
