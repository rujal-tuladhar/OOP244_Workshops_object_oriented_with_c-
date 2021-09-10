//Name: Rujal Tuladhar
//I have done this lab on myw own only using the notes provided by my profesors.
//Student id: 154594188

#include "cstring.h"
#include<iostream>
using namespace std;

namespace sdds
{

	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}

		des[i] = '\0';

	}

	void strnCpy(char* des, const char* src, int len)
	{
		int i;


		for (i = 0; i < len && src[i] != '\0'; i++)
		{
			des[i] = src[i];

		}
		if (i < len)
		{
			des[i] = '\0';
		}










	}

	int strCmp(const char* s1, const char* s2)
	{

		while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
		{
			s1++;
			s2++;
		}


		if (*s1 == *s2)
		{
			return 0;
		}
		else if (*s1 > * s2)
		{
			return 1;
		}
		else
		{
			return -1;
		}


	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i = 0;
		while (s1[i] != '\0' && s2[i] != '\0' && i < len)
		{
			if (s1[i] > s2[i])
			{
				return 1;
			}
			if (s2[i] < s2[i])
			{
				return -1;
			}

			i++;
		}

		if (i == len)
		{
			return 0;
		}

		return 1;




	}

	int strLen(const char* s)
	{
		int i = 0;

		while (*s != '\0')
		{
			i++;
			s++;
		}

		return i;
	}

	const char* strStr(const char* str1, const char* str2)
	{

		char* cp = (char*)str1;
		char* i, * j;
		if (!*str2)
			return((char*)str1);

		while (*cp)
		{
			i = cp;
			j = (char*)str2;
			while (*j && !(*i - *j))
				i++, j++;
			if (!*j)
				return(cp);
			cp++;
		}

		return(NULL);

	}

	void strCat(char* des, const char* src)
	{



		char* i = des;

		while (*i != '\0')
		{
			i++;
		}

		while (*src != '\0')
		{
			*i++ = *src++;
		}

		*i = '\0';

	}



}