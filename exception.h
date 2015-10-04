
/*
* CST 211 - Assignment 1
*
* Author : John Zimmerman
*
* File : exception.h
*
* ---
*
* Exception class declaration and member variables 
*
*/

#ifndef  exception_H
#define  exception_H

#include  <iostream>
#include  <cstring>

class Exception
{

	friend std::ostream& operator <<(std::ostream& stream, const Exception& exception);

	public:
	//
	// Regular constructor
	//
	Exception ( char *msg );
	
	//
	// Copy constructor
	//
	Exception ( const Exception &rhs );

	//
	// Destructor
	//
	~Exception();

	
	//
	// Assignment operator
	//
	Exception &operator=(const char * &rhs);

	char * getMessage() const;

	void setMessage(char * msg);


private:

	char * m_msg;

};




#endif