//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H



#include<iostream>
namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(std::ostream& ostr) const = 0;

		virtual void getSpecs(std::istream& istr)  = 0;

		virtual ~Shape()
		{};


	};

	std::ostream& operator<<(std::ostream& out, const Shape& obj);
	std::istream& operator>>(std::istream& in,  Shape& obj);



}



#endif // !SDDS_SHAPE_H