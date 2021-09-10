//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include"LblShape.h"
namespace sdds
{
	class Rectangle :public LblShape
	{

		
		int m_width =0;
		int m_height =0;

	public:

		Rectangle();
		Rectangle(const char* value, int width, int height);
		void getSpecs(std::istream& obj);
		void draw(std::ostream& ostr) const;


	};



}



#endif // !SDDS_RECTANGLE_H
