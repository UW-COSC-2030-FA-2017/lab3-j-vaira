// lab3.cpp : Defines the entry point for the console application.
//Jasmine Vaira
//2) We can detect overflow in this process by checking to see if the output of the function is negative. Since we are only summing positive integers, the output should
//ordinarily never be negative. Same for 3).
//4) We can detect overflow in the factorial process by checking to see if the output if infinity.
//6) The value should be zero if computations are exact, but due to rounding errors it isn't always, and is instead a very, very small value.

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
	float factorial = 1;
	for (long i = n; i > 0; i--)
	{
		factorial = factorial * i;
	}
	cout << n << "! is " << factorial << ".\n";
}

void doubleFactorial(long n)
{
	//compute the factorial of n integers
	double factorial = 1;
	for (long i = n; i > 0; i--)
	{
		factorial = factorial * i;
	}
	cout << n << "! is " << factorial << ".\n";
}

void floatRatio(float n)
{
	float sum = 0;
	for (float i = n; i > 0; i--)
	{
		sum = sum + (1 / n);
	}
	cout << "For " << n << ", there is an error of " << sum - 1 << ".\n";
}

void doubleRatio(double n)
{
	double sum = 0;
	for (double i = n; i > 0; i--)
	{
		sum = sum + (1 / n);
	}
	cout << "For " << n << ", there is an error of " << sum - 1 << ".\n";
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

	cout << endl;

	//testing limits of float
	floatFactorial(33);
	floatFactorial(34);
	floatFactorial(35); //this is where it overflows. I figured this out by running floatFactorial() through a loop. It's better than guessing.
	floatFactorial(36);

	cout << endl;

	//testing limits of double
	doubleFactorial(169);
	doubleFactorial(170);
	doubleFactorial(171); //overflow here. I ran this one through a loop like the last one to find the answer.
	doubleFactorial(172);

	cout << endl;

	//testing rounding error for float
	floatRatio(8);
	floatRatio(9);
	floatRatio(10); //this is where the rounding errors start. I ran it through a loop like the last one to find this. Some higher numbers do round right, most don't.
	floatRatio(11);

	cout << endl;

	//testing rounding error for double
	doubleRatio(4);
	doubleRatio(5);
	doubleRatio(6); //this is where the errors start. It's lower than for float, but that's because double holds more digits so has more potential for rounding error.
	doubleRatio(7);

	cout << endl;

	//testing float error again
	for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl; //the error occurs at the last pass through the loop. It should end at 4.2, but instead continues on and prints 4.4 as well. Because of the way float handles numbers, it rounds i down and thus runs through the loop one-too-many times.
	}

	cout << endl;
	
	//testing double error again
	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl; //double holds more, so doesn't round as many digits, and thus its accuracy is better in this case.
	}


	


	//according to the guys on stackoverflow IDEs that don't automatically wait so you can see your output and close immediately after running are stupid
	system("PAUSE");
	return 0;
}

