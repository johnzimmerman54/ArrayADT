
//
// CST 211 - Assignment #2 (test program)
//
// John Zimmerman
//
//
// File: main.cpp
//
// Test driver
//

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
		
		int elements = 20;
		int start = -2;
		int end = elements + start;

		//
		// Array constructor
		//
		Array<int> data(elements, start);
		
		//
		// index operator overload
		//
		int n = 1;

		cout << "data" << endl;

		for (int i = start; i < end; ++i)
		{
			data[i] = n;
			cout << data[i] << ' ';
			n++;
		}
		cout << endl << endl;

		//
		// Array copy
		//
		Array<int> data2(data);

		//
		// assignment operator overload
		//
		Array<int> data3(data2);
		data3 = data;

		//
		// get start index
		//
		cout << "getStartIndex()" << endl;
		cout << data.getStartIndex() << endl;

		//
		// set start index
		//
		cout << "setStartIndex to 0" << endl;
		data2.setStartIndex(0);
		cout << data2.getStartIndex() << endl;

		//
		// get array length
		//
		cout << "getLength()" << endl;
		cout << data2.getLength() << endl;

		//
		// set array length
		//
		cout << "setLength to 10" << endl;
		data3.setLength(10);
		cout << data3.getLength() << endl;


	

		
		cout << endl << endl;

		cout << "data2" << endl;
		
		int c = -20;
		for (int i = 0; i < data2.getLength(); ++i)
		{
			data2[i] = c;
			cout << data2[i] << ' ';
			c++;
		}
		
		cout << endl << endl;

		cout << "data3" << endl;

		for (int i = start; i < data3.getLength(); ++i)
		{
			cout << data3[i] << ' ';
		}
		
		cout << endl << endl;
		

	}


	catch (const Exception &error)
	{

		cout << endl << endl << error.getMessage() << endl << endl;

	}

	return  0;
}

