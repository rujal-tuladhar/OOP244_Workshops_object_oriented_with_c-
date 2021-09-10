//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.

#define _CRT_SECURE_NO_WARNINGS
#include"Line.h"
#include<iomanip>
using namespace std;
namespace sdds
{

	Line::Line():LblShape()
	{
		
	}
	Line::Line(const char* value, int length) :LblShape(value)
	{
		m_length = length;
	}
	void Line::getSpecs(std::istream& is)
	{
		
		LblShape::getSpecs(is);

		is >> m_length;
		is.ignore();
	}
	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && label() != nullptr)
		{
			ostr << label() << endl;
			ostr << setw(m_length) << setfill('=') << '=';
		}

	}
	

}

