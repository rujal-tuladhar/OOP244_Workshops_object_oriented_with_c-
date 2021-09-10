//name- Rujal Tuladhar 
//seneca id -154594188
//seneca email - rtuladhar@myseneca.ca
//I have done this assignment on my own using only the materials provided by my instructor.

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include<iostream>
#include"Shape.h"
namespace sdds
{
	class LblShape:public Shape
	{
		char* m_label = nullptr;

	protected:
	   const char* label() const;

	public:
		LblShape();
		LblShape(const char* value);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator = (const LblShape&) = delete;

		void getSpecs(std::istream& istr);


	};
}

#endif// !SDDS_LBLSHAPE_H
