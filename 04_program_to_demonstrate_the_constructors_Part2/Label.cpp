//Name:Rujal Tuladhar
//Student_id: 154594188
// I have done this workshop on my own using only the code provide by my instructor
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <iostream>
#include "cstring.h" 
#include "Label.h"
using namespace std;

namespace sdds
{
  
    
    Label::Label()
    {
        m_inside = new char[72];
        strCpy(m_inside, "");
        strCpy(m_boder, "+-+|+-+|");
    }

    Label::Label(const char* frameArg)
    {
      
        m_inside = new char[72];
        strCpy(m_inside, "");
        strCpy(m_boder, frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        m_inside = nullptr;
        m_boder[0]= 0;
        
        
        if (frameArg)
        {
            
            strCpy(m_boder, frameArg);
        }

        if (content)
        {
            m_inside = nullptr;
            int length = 0;
            if (strLen(content) > 70)
            {
                length = 72;
            }else
          
            {
                length = strLen(content);
            }
            delete[] m_inside;
            m_inside = new char [length + 1];
            strCpy(m_inside, content);
        }
    }

    Label:: ~Label()
    {
        delete[] m_inside;
        m_inside = nullptr;
        
    }

  
    void Label::readLabel()
    {
       
        fgets(m_inside, 72, stdin);
     
        m_inside[strLen(m_inside) - 1] = '\0';
    }

    ostream& Label::printLabel() const
    {
        if (strLen(m_inside) == 0 || strLen(m_boder) == 0)
        {
            return cout;
        }
     
        cout << m_boder[0] << string(strLen(m_inside) + 2, m_boder[1]) << m_boder[2] << endl;
        cout << m_boder[7] << string(strLen(m_inside) + 2, ' ') << m_boder[3] << endl;
        cout << m_boder[7] << " " << m_inside << " " << m_boder[3] << endl;
        cout << m_boder[7] << string(strLen(m_inside) + 2, ' ') << m_boder[3] << endl;
        cout << m_boder[6] << string(strLen(m_inside) + 2, m_boder[5]) << m_boder[4];
        return cout;
    }
}