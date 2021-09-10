//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.


#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include<cstring>
#include <iostream>


namespace sdds
{
	LblShape::LblShape()
	{
		
	}

	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape(const char* value)
	{
		delete[] m_label;
		m_label = new char[strlen(value) + 1];
		strcpy(m_label, value);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
		
		
	}

     void LblShape::getSpecs(std::istream& istr)
	{
		char value[100];
		
		
		istr.get(value, 100, ',');
		delete[] m_label;
		m_label = new char[strlen(value) + 1];
		strcpy(m_label, value);

		istr.ignore();
		

	}



}