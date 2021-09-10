//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include"LblShape.h"
#include<iostream>



namespace sdds
{
	class Line:public LblShape
	{

	int m_length =0;

	public:
		Line();
		Line(const char* value, int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& ostr)const;




	};


}


#endif // !SDDS_LINE_H
