

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
#include "exception.h"

using  namespace  std;

// 
// Array Constructor  
//
template <class ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(int length, int start_index) :
		m_length( length ), 
		m_start_index( start_index )
{

	if (length < 1)
	{
		
		throw Exception((char *) "Must have at least one element");
	}


	Array::m_array = new ELEMENT_TYPE[m_length];


	// 
	// Memory allocation check - exit if fails
	//
	if (!m_array)
	{
		throw Exception((char *) "Memory Allocation Error");
	}
	

}


//
// Copy Constructor
//
template <class ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(const Array &rhs) :
		m_length( rhs.m_length ),
		m_start_index( rhs.m_start_index ),
		m_array(new ELEMENT_TYPE[getLength()])
{
	// 
	// Memory allocation check - exit if fails
	//
	if (!m_array)
	{
		cout << "Error allocating memory" << endl;
		EXIT_FAILURE;
	}

	//
	// Populate new array
	//
	for (int idx = 0; idx < rhs.getLength(); ++idx)
	{
		m_array[idx] = rhs.m_array[idx];
	}


}




//
// Check that index for set or get is within the array bounds
//
template <class ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::checkBounds(int index) const
{
	if (index < m_start_index || index > m_length + m_start_index)
	{

		throw Exception((char *) "Out of Bounds");

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

	return m_array[index - m_start_index];

}

//
// Index operator read only const
//
template <class ELEMENT_TYPE>
const ELEMENT_TYPE &Array<ELEMENT_TYPE>::operator[](int index) const
{
	
	checkBounds(index);

	return m_array[index - m_start_index];

}