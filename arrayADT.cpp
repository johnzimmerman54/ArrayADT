

/*
* CST 211 - Assignment 1
*
* Author : John Zimmerman
*
* File : arrayADT.cpp
*
* ---
*
* Array class implementation
*
*/

#include  <iostream>

#include "arrayADT.h"

using  namespace  std;

// 
// Array Constructor  
//
template <class ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(int length, int start_index) :
		m_length( length ), 
		m_start_index( start_index )
{

	if (length < start_index)
	{
		throw ERR_BAD_BOUNDS;
	}


	Array::m_array = new ELEMENT_TYPE[getLength()];


	// 
	// Memory allocation check - exit if fails
	//
	if (!m_array)
	{
		throw ERR_MEM_ALLOC;
	}
	

}


//
// Check that index for set or get is within the array bounds
//
template <class ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::checkBounds(int index) const
{
	if (index < getStartIndex() || index > upperBound())
	{

		throw ERR_OUT_OF_BOUNDS;

	}
}


template <class ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::zeroreference()
{

	if (m_refCounter.onlyInstance())
	{

		//
		// Deallocate the dynamic memory
		//
		delete[] m_array;

	}

}

template <class ELEMENT_TYPE>
Array<ELEMENT_TYPE>::~Array()
{

	//
	// If there are no copies left delete the memory allocation
	//
	zeroreference();

}


//
// Assignment operator
//
template <class ELEMENT_TYPE>
ELEMENT_TYPE &Array<ELEMENT_TYPE>::operator=(const ELEMENT_TYPE &rhs)
{

	if (this != &rhs)
	{

		this.zeroreference();

		//
		// assign RHS values to this object 
		//
		this = rhs;

	}

	return *this;

}

//
// Index operator read + write
//
template <class ELEMENT_TYPE>
ELEMENT_TYPE &Array<ELEMENT_TYPE>::operator[](int index)
{

	checkBounds(index);

	return m_array[index];

}

//
// Index operator read only const
//
template <class ELEMENT_TYPE>
const ELEMENT_TYPE &Array<ELEMENT_TYPE>::operator[](int index) const
{
	
	checkBounds(index);

	return m_array[index];

}
