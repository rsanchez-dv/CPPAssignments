//|
//|		Functions for MovieType
//|------------------------------------
#include"MovieType.h"
#include<iostream>
#include<string>
using namespace std;
//---------------------------------------------------------------------------------------------
MovieType::MovieType()
{
	m_title    = " ";
	m_year     = " ";
	m_receipts = " ";
	m_studio   = " ";
	m_stars    = " ";
}
//-----------------------------------------------------------------------------------------------------
void MovieType::Initialize(string title, string year, string receipts,string studio,string stars)
{
	m_title = title;
	m_year = year;
	m_receipts = receipts;
	m_studio = studio;
	m_stars=stars;
}
//---------------------------------------------------------------------------------------------------
bool MovieType::ReadOneMovieFromFile(ifstream &fin)
{
	string temp;
	m_studio= " ";
	m_stars=" ";
	int i=0;
	getline(fin,m_title);
	if(m_title == "***")
		return false;
	else
	{
		fin>>m_year;
		fin>>m_receipts;
		fin.ignore(3,'\n');
		getline(fin,temp);
		for(;i<=temp.length()-1;i++)
		{
			if(temp[i]!=',')
				m_studio+=temp[i];
			else 
				break;	
		}
		i+=2;//Skippipng over a space and comma

		for(int H = temp.length(); i < H ;i++)
		{
			m_stars+=temp[i];
		}
		if(	m_stars == " ")
			m_stars = "None";
		return true;
	}
}
//---------------------------------------------------------------------------------------------
void MovieType::Display()const
{
		cout<<" ________________________________________________________________\n";
		cout<<" Title:           "<<m_title<<endl;
		cout<<" Studio:         "<<m_studio<<endl;
		cout<<" Year:            "<<m_year<<endl;
		cout<<" Adjusted Gross:  $"<<m_receipts<<endl;
		cout<<" Stars:          "<<m_stars<<"\n\n";
}
//---------------------------------------------------------------------------------------------
int MovieType::CompareKeys(const MovieType& p2)const
{
	return(m_title.compare(p2.m_title));	
}
//---------------------------------------------------------------------------------------------
string MovieType::getkey()const
{
	return m_title;
}
//---------------------------------------------------------------------------------------------
void MovieType::setkey(string title)
{
	m_title = title;
}
//---------------------------------------------------------------------------------------------
bool MovieType::operator <(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp < temp2)
		return true;
	else
		return false;
	//return m_title<p2.m_title;
}

//---------------------------------------------------------------------------------------------
bool MovieType::operator >(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp > temp2)
		return true;
	else
		return false;
	//return m_title>p2.m_title;
}
//---------------------------------------------------------------------------------------------
bool MovieType::operator >=(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp >= temp2)
		return true;
	else
		return false;
	//return m_title>=p2.m_title;
}
//---------------------------------------------------------------------------------------------

bool MovieType::operator <=(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp <= temp2)
		return true;
	else
		return false;
	//return m_title<=p2.m_title;
}
//---------------------------------------------------------------------------------------------
bool MovieType::operator !=(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp != temp2)
		return true;
	else
		return false;
	//return m_title!=p2.m_title;
}
//---------------------------------------------------------------------------------------------
bool MovieType::operator ==(const MovieType& p2)const
{
	string temp;
	string temp2;
	temp=m_title;
	temp2=p2.m_title;
	for(int i=0;i<=m_title.length()-1;i++)
	{
		temp[i]=tolower(temp[i]);
	}
	for(int i=0;i<=p2.m_title.length()-1;i++)
	{
		temp2[i]=tolower(temp2[i]);
	}
	if(temp == temp2)
		return true;
	else
		return false;
}