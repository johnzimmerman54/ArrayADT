
/*
* CST 211 - Assignment 1
*
* Author : John Zimmerman
*
* File : arrayADT.h
*
* ---
*
* Array class and member variables 
*
*/

#ifndef  arrayADT_H
#define  arrayADT_H

#define  ERR_BAD_BOUNDS     1
#define  ERR_MEM_ALLOC      2
#define  ERR_OUT_OF_BOUNDS  3

#include "refCounter.h"


//
// Array Class
//
/*
* Constraints for the TYPE datatype for the Array<> template class:
*
*   datatype must supply a default constructor
*   datatype must support assignment
*   datatype must be copyable
*
*/
template <class ELEMENT_TYPE>
class Array
{

public:
	//
	// Regular constructor
	//
	Array ( int length, int start_index = 0 );
	

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
	int setStartIndex(int start_index)
			{ return m_start_index = start_index; }

	int setLength(int length)
			{ return m_length = length; }

	//
	// Inspector member functions
	//
	int		getStartIndex() const 
			{ return m_start_index; }

	int		upperBound() const 
			{ return m_start_index + m_length; }

	int		getLength() const
			{ return m_length; }

	int		size() const
			{ return getLength() * sizeof(ELEMENT_TYPE); }


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
