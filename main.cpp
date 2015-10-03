
//
// CST 211 - Assignment #2 (test program)
//
// John Zimmerman
//
//
// File: main.cpp
//
// Test program for the Array and SafeArray classes.
//


#include  <math.h>
#include  <iostream>
#include  "arrayADT.cpp"

using  namespace  std;


//
// main() program
//
int  main()
{

	try
	{
		int elements = 25;
		int start = 0;
		int end = elements + start;

		Array<int> data(elements, start);
		
		int number = 1;
		for (int i = start; i < end; ++i)
		{
			data[i] = number;
			cout << data[i] << ' ';
			number++;
		}
		
		cout << endl << endl;

		//
		//Array<char> data2(15);
		//
		//char character = 90;
		//for (int i = 0; i < 15; i++)
		//{
		//	data2[i] = character;
		//	character++;
		//}
		//
		//cout << data2[0] << ',' << data2[1] << ',' << data2[2] << ',' << data2[3] << ',' << data2[14] << endl << endl;
		 

	}
	catch (int errCode)
	{

		switch (errCode)
		{
		case ERR_BAD_BOUNDS		: cout << "ERR_BAD_BOUNDS" << endl; break;
		case ERR_OUT_OF_BOUNDS	: cout << "ERR_OUT_OF_BOUNDS" << endl; break;
		case ERR_MEM_ALLOC		: cout << "ERR_MEM_ALLOC" << endl; break;
		default					: cout << "Undefined Error" << endl; break;


		}

	}

	return  0;
}

