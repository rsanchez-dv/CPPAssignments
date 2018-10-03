/*
	Student: Roberto Sanchez
	Class:   Computer Science 2
	Date:    Sept. 17, 2012
	Due:     Sept. 19, 2012

	Analysis: This program is designed to add two integers together.
	Structure BigInt: Contains an array that stores and array of numbers with MAX_DIGITS being the array index 
					  and an int storing the number of digits stored in the said array 

	Bool ReadBigInt(BigInt& num)
		Purpose:Reads the string the user typed in and verifies it if its less than MAX_DIGIT
		Precondition:NONE
		PostCondition:Either
			1. string is less than MAX_DIGIT and TRUE is returned; string is stored into num.digits and records number of digits into num.numdigits
				or
			2. num is greater than MAX_DIGIT and FALSE is returned

	void PrintBigInt(const BigInt& num)
		Purpose: Prints the digits stored in num
		Precondition:num has digits stored
		Postcondition:Prints digits out in num

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
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int MAX_DIGITS = 5;
struct BigInt{
 int Digits[MAX_DIGITS];
 int numDigits;
};
bool ReadBigInt (BigInt& num);
void PrintBigInt (const BigInt& num);
bool AddBigInt (const BigInt& num1, const BigInt& num2, BigInt& sum);
bool AddWithLongestFirst(const BigInt& longer, const BigInt& shorter, BigInt& sum);
int main ()
{	
	BigInt num1,num2,sum;
	bool loop=true,first_loop=true, second_loop = true;
	char answer;

	cout<<" "<<setfill('-')<<setw(70)<<"\n";
	cout<<"| NOTE: The maximum number of digits is "<<MAX_DIGITS<<endl;
	cout<<" "<<setfill('-')<<setw(70)<<"\n";
	while(loop== true){
		do{
			cout<<" Enter first integer : ";
			if(!ReadBigInt(num1))
			{
			cout<<" The number you entered is too big, try again!\n";
			first_loop = false;
		    }
			else first_loop = true;
		  }while(first_loop !=true);
		do{
			cout<<" Enter second integer: ";
			if(!ReadBigInt(num2))
			{
			cout<<" The number you entered is too big, try again!\n";
			second_loop= false;
		    }
			else second_loop = true;
		  }while(second_loop !=true);
		if(AddBigInt(num1,num2,sum))
		{
			cout<<" The sum is          "<<": ";
			PrintBigInt(sum);
		}
		else cout<<" The sum cased OVERFLOW!";
		cout<<"\n "<<setfill('-')<<setw(50)<<"\n";
		cout<<" (!) Do you want to add more numbers? (Y or N): ";
		cin>>answer;
		cin.ignore(50,'\n');
		cout<<" "<<setfill('-')<<setw(50)<<"\n";
		switch(answer){
			case 'Y':
			case 'y': loop =1; 
				break;
			case 'N':
			case 'n':cout<<" (*) Program terminated on request.\n"; loop =0;
				break;
			defaut: cout<<" (?) Answer is not recognized, Ending Program\n"; loop = 0;
				break;
					  }
	}
	return 0;
}
/*	
					////////////////////
		      Functions 
////////////////////
*/
bool ReadBigInt (BigInt& num)
{	
	string s;
	getline(cin,s);
	if(s.length()> MAX_DIGITS)
		return false;
	else
	{
		num.numDigits= s.length();
		for( int p = 0, i = s.length()-1; i>=0 ;i--,p++)
			num.Digits[p]=s[i]-'0';
		return true;
	}
}
void PrintBigInt (const BigInt& num)
{
	for(int i =num.numDigits-1; i>=0; i--)
		cout<<num.Digits[i];
}
bool AddBigInt (const BigInt& num1, const BigInt& num2, BigInt& sum)
{
	if(num1.numDigits >= num2.numDigits)
		return(AddWithLongestFirst(num1,num2,sum));
			
	else
		return(AddWithLongestFirst(num2,num1,sum));
		
}
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
	if(carry==1 && sum.numDigits==MAX_DIGITS)
		return false;
	else
	{ 
		if(carry==1 && sum.numDigits!= MAX_DIGITS){
			sum.Digits[sum.numDigits++]=1;
			return true;}
		else
			return true;
	}
}

