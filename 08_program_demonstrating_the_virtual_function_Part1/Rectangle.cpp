//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.


#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include <iomanip>
#include <cstring>
using namespace std;

namespace sdds
{

	Rectangle::Rectangle():LblShape()
	{
	
	}
	Rectangle::Rectangle(const char* value, int width, int height) :LblShape(value)
	{
		m_height = height;
		m_width = width;

		int size = strlen(label());
		if (m_height < 3 || m_width < (size + 2))

		{
			m_height = 0;
			m_width = 0;
		}
		

	   




	}
	void Rectangle::getSpecs(std::istream& obj)
	{
		LblShape::getSpecs(obj);

		obj >> m_width;
		obj.ignore();
		obj >> m_height;
		obj.ignore();


	}
	void Rectangle::draw(std::ostream& ostr) const
	{
		if (m_width > 0 && m_height > 0) 
		{

			ostr << "+";
			ostr << setw((streamsize)m_width - 1) << setfill('-') << "+" << endl;

			ostr << "|" << setw((streamsize)m_width - 2) << left << setfill(' ') << label() << "|" << endl;

			for (int i = 0; i < m_height - 3; i++)
			{
				ostr << "|" << setw((streamsize)m_width - 1) << setfill(' ') << right << "|" << endl;
			}


			ostr << "+";
			ostr << setw((streamsize)m_width - 1) << setfill('-') << "+";
		}

	}



}