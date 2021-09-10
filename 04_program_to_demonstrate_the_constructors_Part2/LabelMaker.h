//Name:Rujal Tuladhar
//Student_id: 154594188
// I have done this workshop on my own using only the code provide by my instructor
#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include "Label.h"

namespace sdds
{
    class LabelMaker
    {
        Label* m_labels;
        int m_noOfLabels;

    public:

        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif