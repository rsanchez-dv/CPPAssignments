/*
Student: Roberto Sanchez
Class:   Computer Science 2
Date:    Oct. 1, 2012
Due:     Oct. 8, 2012

Analysis: This program is designed to add two integers together.
Structure BigInt: Contains an array that stores and array of numbers with MAX_DIGITS being the array index 
and an int storing the number of digits stored in the said array 

Bool ReadBigInt(istream& is=cin)
Purpose:Reads the string the user typed in and verifies it if its less than MAX_DIGIT
Precondition:NONE
PostCondition:Either
1. string is less than MAX_DIGIT and TRUE is returned; string is sent to StringToBigInt
or
2. string is greater than MAX_DIGIT and FALSE is returned

void PrintBigInt(ostream& os=cout)
Purpose: Prints the digits stored in BigIntClass
Precondition:Called by << operator with a BigInt
Postcondition:Prints digits out

bool AddBigInt(const BigInt& num1, const BigInt& num2, BigInt& sum)
Purpose: Checks whether num1 or num2 has more digits then use AddWithLongestFirst with first parameter being the one with the most digits
Precondition:num1,num2 must have digits stored
Postcondition: Either
1. AddWithLongestFirst returns true, return True
or
2. AddWithLongestFirst returns false, returns False

bool AddWithLongestFirst (const BigInt& longer, const BigInt& shorter, BigInt& sum)
Purpose: Adds the digits in arrays (longer/shorter) to each other and storing the sum in sum and verifing if sum is less than or equal to MAX_DIGIT
Precondition: longer and shorter contains valid digits
Postcondition:Either
1. sum is greater than MAX_DIGITS, return FALSE
or
2. sum is less than or equal to MAX_DIGITS, return TRUE

ostream& operator<<(ostream& os, const BigInt& num2)
Purpose:Sends BigInt (num2) to PrintBigInt Function
Precondition:num2 has digits
Postcondition: calls PrintBigInt and returns os

BigInt operator+(const BigInt& num1, const BigINt& num2, BigInt& sum)
Purpose: Adds two BigInts
Precondition: BigInts in num1 and num2 have digits
Postcondition: Calls AddBigInts function and Either
1. AddBigInts returns FALSE - throw OverFlowException
or
2. AddBigInts returns TRUE - return sum
void OverFlowException(const BigInt& num1,const BigInt& num2, char op)
Purpose: Determining overflow of sum
Precondition: AddBigInts in Operator + must fail
Postcondition: Prints out failed digits and print out "OVERFLOW!" in place of sum
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class BigInt
{
	friend ostream& operator<<(ostream&, const BigInt&);
	friend BigInt operator+(const BigInt&,const BigInt&);
	friend bool AddBigInts(const BigInt& num1, const BigInt& num2, BigInt& sum);
	friend bool AddWithLongestFirst(const BigInt& longer, const BigInt& shorter, BigInt& sum);

public:
	static const int MAX_DIGITS = 5;
	BigInt();
	BigInt(const string& goodstring);
	bool ReadBigInt(istream&);
	bool ExtractGoodString(const string&, string&);
	void PrintBigInt(ostream&)const;


private:
	int Digits[MAX_DIGITS];
	int numDigits;	
	void StringToBigInt(const string&);
};
class OverFlowException
{
public:
	BigInt m_num1,m_num2;
	char m_op;
	OverFlowException(const BigInt&, const BigInt&, char op);

};
int main()
{
	BigInt num1,num2,sum;
	bool loop=true,first_loop=true, second_loop = true, end_loop = true;
	char answer;

	cout<<" "<<setfill('-')<<setw(70)<<"\n";
	cout<<"| NOTE: The maximum number of digits is "<<num1.MAX_DIGITS<<endl;
	cout<<" "<<setfill('-')<<setw(70)<<"\n";
	while(loop== true)
	{
		do
		{
			cout<<" Enter first integer : ";
			if(!num1.ReadBigInt(cin))
			{
				first_loop = false;
			}
			else first_loop = true;
		}
		while(first_loop !=true);
		do
		{
			cout<<" Enter second integer: ";
			if(!num2.ReadBigInt(cin))
			{
				second_loop= false;
			}
			else second_loop = true;
		}
		while(second_loop !=true);
		try
		{
			sum=num1+num2;
			cout<<" The sum cased       : "<<sum<<endl;
		}
		catch(OverFlowException& num)
		{
			cout<<" "<<num.m_num1<<" "<<num.m_op<<" "<<num.m_num2<<" = OVERFLOW!"<<endl;
		}
		end_loop=true;
		while(end_loop)
		{
			cout<<" "<<setfill('-')<<setw(50)<<"\n";
			cout<<" (!) Do you want to add more numbers? (Y or N): ";
			cin>>answer;
			cin.ignore(50,'\n');
			cout<<" "<<setfill('-')<<setw(50)<<"\n";
			switch(answer)
			{
			case 'Y':
			case 'y': end_loop = false,loop =1; 
				break;
			case 'N':
			case 'n':cout<<" (*) Program terminated on request.\n"; end_loop = false;loop = 0;
				break;
			default: cout<<" (?) Answer is not recognized. [Y-Yes] [N-No]"; 
				break;
			}
		}
	}

	return 0;
}
/*//////////////////////////////////////
FUNCTIONS
*/															///////////////////////////////////////////
//---------------------------------------------------------------------------------
BigInt::BigInt()
{
	numDigits = 0;
}
//---------------------------------------------------------------------------------
BigInt::BigInt(const string& goodstring)
{	
	StringToBigInt(goodstring);
}
//---------------------------------------------------------------------------------
void BigInt::StringToBigInt(const string& s)
{	
	numDigits= s.length();
	for( int p = 0, i = s.length()-1; i>=0 ;i--,p++)
		Digits[p]=s[i]-'0';
}
//---------------------------------------------------------------------------------
bool BigInt::ExtractGoodString(const string& input, string& output)
{	
	int counter=0,tracer=0,k=0,i=0;
	bool trip = true;
	string temp;

	//temp=input;
	for(i=input.size()-1; i>=0; i--)
	{
		if(input[i]!= ' ')
		{
			trip=false;
			break;
		}
		else
		{
			tracer++;
		}

	}
	if(!trip)
	{
		temp.resize(input.size()-(input.size()-tracer));	//resize with tracer
	}
	else
		output=temp;//cleaned up version copied to output for 
	//checking valid ints and verifying spaces inbetween ints
	/*for(int j=0;j<=input.size()-1;j++)
	counter++;

	temp.resize(counter--);*/
	//counter =0;
	output=temp;
	temp+='\0';
	output+='\0';
	trip=true;//reset trip
	for( i=0,k=0; i<=temp.size()-1;i++,k++)
	{
		if(temp[i]!=' ')/////////////////////////////////////////CHANGE INPUT TO TEMP!!
		{
			if(input[i]>='0' && input[i]<='9')
			{
				output[k]=input[i];
				trip=false;
			}
			else
			{
				cout<<" (!) Illegal Character Found -> [ "<<input[i]<<" ]"<<" Please try again!\n";
				return false;
			}

		}
		else
			if(trip)
			{
				k--;
			}
			else if(temp[i]=='\0')
			{
				break;
			}
			else
			{
				cout<<" (!) Spaces Detected within Integer, Please try again!\n";
				return false;
			}
	}
	output+=' ';
	output[k]='\0';
	for(int j=0;output[j]!='\0';j++)
	{
		if(output[j]=='\0')
			break;
		else
		{
			counter++;
		}
	}
	output.resize(output.size()-(output.size()-counter));
	counter=0;
	return true;
}

//---------------------------------------------------------------------------------
bool BigInt::ReadBigInt(istream& is=cin)
{
	string s,k;
	getline(cin,s);
	s.c_str();
	if(ExtractGoodString(s,k))
	{
		if(k.length()> MAX_DIGITS)
		{	
			cout<<"The Number you entered is too big, try again!\n";
			return false;
		}
		else
		{
			StringToBigInt(k);
			return true;
		}
	}
	else
		return false;
}
//----------------------------------------------------------------------------------
void BigInt::PrintBigInt(ostream& os=cout)const
{
	for(int i =numDigits-1; i>=0; i--)
		os<<Digits[i];
}

//----------------------------------------------------------------------------------
ostream& operator<<(ostream& os, const BigInt& num2)
{
	num2.PrintBigInt(os);
	return os; 
}
//----------------------------------------------------------------------------------
BigInt operator+(const BigInt& num1,const BigInt& num2)
{
	BigInt sum;
	if(!AddBigInts(num1,num2,sum))
	{
		throw OverFlowException(num1,num2,'+') ;
	}
	else 
		return sum;


}
//---------------------------------------------------------------------------------
bool AddBigInts(const BigInt& num1, const BigInt& num2, BigInt& sum)
{

	if(num1.numDigits >= num2.numDigits)
		return(AddWithLongestFirst(num1,num2,sum));

	else
		return(AddWithLongestFirst(num2,num1,sum));
}
//---------------------------------------------------------------------------------
bool AddWithLongestFirst(const BigInt& longer, const BigInt& shorter, BigInt& sum)
{
	int carry = 0;
	int temp = 0;
	for(int i=0; i<shorter.numDigits; i++)
	{
		temp=longer.Digits[i]+shorter.Digits[i]+carry;
		if(temp>=10)
		{
			carry =1;
			sum.Digits[i]=temp-10;
		}
		else
		{
			carry =0;
			sum.Digits[i]= temp;
		}
	}
	for(int j=shorter.numDigits; j<=longer.numDigits-1;j++)
	{
		temp=longer.Digits[j]+carry;
		if(temp>=10)
		{
			carry=1;
			sum.Digits[j]=temp-10;
		}
		else
		{
			carry=0;
			sum.Digits[j]=temp;
		}
	}
	sum.numDigits=longer.numDigits;
	if(carry == 1 && sum.numDigits == sum.MAX_DIGITS)
		return false;
	else
	{ 
		if(carry == 1 && sum.numDigits != sum.MAX_DIGITS)
		{
			sum.Digits[sum.numDigits++] = 1;
			return true;
		}
		else
			return true;
	}
}
//---------------------------------------------------------------------------------------
OverFlowException::OverFlowException(const BigInt& num1, const BigInt& num2, char op)
{
	m_num1=num1;
	m_num2= num2;
	m_op=op;
}