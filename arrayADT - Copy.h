
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
	Array ( int amax, int amin = 0 );
	
	//
	// Copy constructor
	//
	//Array ( const Array &rhs );

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
	// Inspector member functions
	//
	int		lowerBound() const 
			{ return m_amin; }

	int		upperBound() const 
			{ return m_amax; }


	int		numElements() const  
			{ return m_amax - m_amin + 1; }

	int		size() const
			{ return numElements() * sizeof(ELEMENT_TYPE); }


private:
	//
	// Private member array vars
	//
	int				m_amax;
	int				m_amin;

	ELEMENT_TYPE	*m_values;

	RefCounter		m_refCounter;
	
	//
	// Check bounds of array
	//
	void checkBounds(int index) const;

};





#endif
