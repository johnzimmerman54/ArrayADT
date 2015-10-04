
/*
* CST 211 - Assignment 1
*
* Author : John Zimmerman
*
* File : arrayADT.h
*
* ---
*
* Array class declarations and member variables 
*
*/

#ifndef  arrayADT_H
#define  arrayADT_H

#include "refCounter.h"


//
// Array Class
//
template <class ELEMENT_TYPE>
class Array
{

public:
	//
	// Regular constructor
	//
	Array ( int length, int start_index = 0 );
	
	//
	// Copy constructor
	//
	Array ( const Array &rhs );
	

	//
	// Destructor
	//
	~Array();


	//
	// Assignment operator
	//
	ELEMENT_TYPE &operator=(const ELEMENT_TYPE &rhs);

	void zeroreference();

	//
	// Index operator read + write
	//
	ELEMENT_TYPE &operator[](int index);

	//
	// Read only const index operator overload
	//
	const ELEMENT_TYPE &operator[](int index) const;

	//
	// Set Index and Set Length member functions
	//
	void	setStartIndex(int start_index)
			{ m_start_index = start_index; }

	void	setLength(int length)
			{ m_length = length; }

	//
	// Inspector member functions
	//
	int		getStartIndex() const 
			{ return m_start_index; }

	int		getLength() const
			{ return m_length - 1; }


private:
	//
	// Private member array vars
	//
	int				m_length;
	int				m_start_index;

	ELEMENT_TYPE	*m_array;

	RefCounter		m_refCounter;
	
	//
	// Check bounds of array
	//
	void checkBounds(int index) const;

};





#endif
