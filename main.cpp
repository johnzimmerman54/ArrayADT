
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


		int elements = 26;
		int start = -99;
		int end = elements + start;

		Array<char> data(elements, start);
		
		//int number = 1;
		char c = 97;

		for (int i = start; i < end; ++i)
		{
			data[i] = c;
			cout << data[i] << ' ';
			c++;
		}
		
		cout << endl << endl;

		Array<char> data2(data);


		data2.setStartIndex(3);
		data2.setLength(16);

		

		for (int i = 3; i < 16; ++i)
		{
			data2[i] = c;
			cout << data2[i] << ' ';
			c++;
		}
		
		cout << endl << endl;

		c = 97;

		for (int i = start; i < end; ++i)
		{
			data[i] = c;
			cout << data[i] << ' ';
			c++;
		}
		
		cout << endl << endl;

		//
		//Array<char> data2(26, -99);
		//
		//char character = 97;
		//for (int i = -99; i < 26; i++)
		//{
		//	data2[i] = character;
		//	cout << data2[i] << ' ';
		//	character++;
		//}
		//
		//cout << endl << endl;
		 

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

