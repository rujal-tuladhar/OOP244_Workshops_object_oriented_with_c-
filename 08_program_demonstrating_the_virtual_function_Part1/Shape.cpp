//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.


#include "Shape.h"


namespace sdds
{


	std::ostream& operator<<(std::ostream& out, const Shape& obj)
	{
	 obj.draw(out);
	 return out;
	}
	std::istream& operator>>(std::istream& in, Shape& obj)
	{
		obj.getSpecs(in);
		return in;
	}
	

	}