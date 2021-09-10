//Name:Rujal Tuladhar
//Student_id: 154594188
// I have done this workshop on my own using only the code provide by my instructor

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>

#include <iostream>
#include "cstring.h" 
#include "LabelMaker.h"
using namespace std;

namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_noOfLabels = noOfLabels;

        m_labels = new Label[m_noOfLabels];
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;

        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << (i + 1) << endl;
            cout << "> ";
            m_labels[i].readLabel();
        }
    }

    LabelMaker::~LabelMaker()
    {
        delete[] m_labels;
        m_labels = nullptr;
    }

    void LabelMaker::printLabels()
    {
        
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel() << endl;
        }
    }


    
}