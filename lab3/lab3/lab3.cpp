// lab3.cpp : Defines the entry point for the console application.
//Jasmine Vaira
//2) We can detect overflow in this process by checking to see if the output of the function is negative. Since we are only summing positive integers, the output should
//ordinarily never be negative. Same for 3).

#include "stdafx.h"
#include <iostream>
using namespace std;

void sumShort(short n)
{
	//sum up n integers
	short sum = n;
	for (int i = n; i > 0; i--)
	{
		sum = sum + n - i;
	}
	//report the sum
	cout << "The sum of the first " << n << " integer(s) is " << sum << ".\n";
}

void sumLong(long n)
{
	//sum up n integers
	long sum = n;
	for (int i = n; i > 0; i--)
	{
		sum = sum + n - i;
	}
	//report the sum
	cout << "The sum of the first " << n << " integer(s) is " << sum << ".\n";
}

void floatFactorial(long n)
{
	//compute the factorial of n integers

}

int main()
{
	//testing upper limits of type short
	sumShort(254);
	sumShort(255);
	sumShort(256); //this is the value that's too big and causes underflow (overflow?) for the short value
	sumShort(257);

	cout << endl;

	//testing upper limits of type long
	sumLong(65534);
	sumLong(65535);
	sumLong(65536); //this is where it's too big for type long. I figured that since the last one broke at 256 and it was 2 bytes in size, type long, which is 4 bytes, would break at 256 squared
	sumLong(65537);

	//according to the guys on stackoverflow IDEs that don't automatically wait so you can see your output and close immediately after running are stupid
	system("PAUSE");
	return 0;
}

