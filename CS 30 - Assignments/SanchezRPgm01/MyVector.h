//---------------------------------------------------------------------------------------------------------
//		MyVector Header - Part of SanchezRPgm01.cpp
//---------------------------------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<afxwin.h>
using namespace std;
#define new DEBUG_NEW
#pragma once
template<class T> 
class MyVector
{
private:
	T* m_vctr;										            // Dynamic Array
	int m_size, m_capacity;								        // Size of Array(How many Items), Capacity 
	void expand();									            // Expands Vector if Full
public:
	MyVector();										            // Default Constructor
	MyVector(const MyVector & Temp);                            // Copy    Constructor
	~MyVector();									            // Destructor 
	T& operator[] (int index);			                        // Overloaded [] operator
	MyVector<T>& operator=(const MyVector<T>& Vctr_1);          // Overloaded = operator
	void insert(int index,const T& Item);                       // Inserts Item in array[index]
	void push_back(const T& Item);						        // Push_Back Item at end of array
	int  size()const;						                    // Returns Size of Array
	int  capacity()const;				                        // Returns Capacity of Array
};
//----------------------------------------------------------------
//                       MyVector Functions 
//----------------------------------------------------------------
template <class T>
MyVector<T>::MyVector()
{
	m_capacity = 3;								
	m_vctr = new T[m_capacity];					
	m_size = 0;										
}
//-----------------------------------------------------------------
template <class T>
MyVector<T>::MyVector(const MyVector<T>& Temp)
{
	m_capacity = Temp.m_capacity;
	m_vctr = new T[m_capacity];
	m_size = Temp.m_size;
	for(int i=0; i<m_size; i++)
		m_vctr[i] = Temp.m_vctr[i];
}
//-----------------------------------------------------------------
template <class T>
MyVector<T>::~MyVector()
{
	delete [] m_vctr;
}
//-----------------------------------------------------------------
template <class T>
T& MyVector<T>::operator[] (int index)
{
	if(index > m_size || index < 0)
	{
		cout << "\n (!) Error - Index must be within the Size of Array." << flush;
		cin.get();
		cin.get();
		exit(0);
	}
	else
		return m_vctr[index];
}
//-----------------------------------------------------------------
template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& Vctr_1)
{
	if( this != &Vctr_1)
	{
		delete [] m_vctr;
		m_size = Vctr_1.m_size;
		m_capacity = Vctr_1.m_capacity;
		m_vctr = new T[m_size];
		for(int i = 0; i < m_size; i++)
		{
			m_vctr[i] =Vctr_1.m_vctr[i];
		}
	}
	return *this;
}
//-----------------------------------------------------------------
template <class T>
void MyVector<T>::expand()
{
	T* OldArray = m_vctr;
	m_vctr = new T [m_capacity*2];
	for(int i=0; i< m_size;i++)
	{
		m_vctr[i] = OldArray[i];
	}
	m_capacity = m_capacity *2;
	delete [] OldArray;
}
//-----------------------------------------------------------------
template <class T>
void MyVector<T>::insert(int index, const T& Item)
{
	if(index > m_size)
	{
		cout<<" Error: Index is greater than size! Please choose an index within size!\n";
		cin.get();
		cin.get();
		exit (0);
	}
	if(m_size == m_capacity) 
	{
		expand();
		for(int pos=m_size;pos>index-1;--pos)
			m_vctr[pos] = m_vctr[pos-1];
		m_vctr[index] = Item;
		m_size++;
	}
	else if(index < m_size)
	{
		for(int pos=m_size;pos>index-1;--pos)
			m_vctr[pos] = m_vctr[pos-1];
		m_vctr[index] = Item;
		m_size++;
	}
	else
	{
		m_vctr[index] = Item;
		m_size++;
	}
}
//-----------------------------------------------------------------
template <class T>
void MyVector<T>::push_back(const T& Item)
{
	if(m_size == m_capacity)
	{
		expand();
		m_vctr[m_size] = Item;
		m_size++;
	}
	else
	{
		m_vctr[m_size] = Item;
		m_size++;
	}
}
//-----------------------------------------------------------------
template <class T>
int MyVector<T>::size() const
{
	return m_size;
}
//-----------------------------------------------------------------
template <class T>
int MyVector<T>::capacity() const
{
	return m_capacity;
}
//-----------------------------------------------------------------