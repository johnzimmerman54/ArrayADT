
/*
* CST 211 - Assignment 1
*
* Author : John Zimmerman
*
* File : exception.cpp
*
* ---
*
* Exception class implementation 
*
*/

#include "exception.h"


//
// Exception constructor
//
Exception::Exception (char * msg) 
{
	
	m_msg = 0;
	setMessage(msg);

}

//
// Copy constructor
//
Exception::Exception ( const Exception &rhs )
{
	
	setMessage(rhs.getMessage());

}
	

//
// Destructor
//
Exception::~Exception()
{

		delete[] m_msg;

}


//
// Get and Set Message for Exceptions
//

char * Exception::getMessage() const
{

	return m_msg;

}

void Exception::setMessage(char * msg)
{


	if (m_msg != 0)
	{
		delete[] m_msg;
	}

	
	int msglength = strlen(msg)+1;

	m_msg =	new char[msglength];

	memcpy(m_msg, msg, msglength);
	



}


















