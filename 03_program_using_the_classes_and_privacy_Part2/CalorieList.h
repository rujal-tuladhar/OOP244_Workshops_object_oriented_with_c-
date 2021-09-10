//Name - Rujal Tuladhar
//Student_id- 154594188
//I am done this workshop on my own by using the code provided by my professor.
#ifndef _SDDS_CALORIELIST_H_
#define _SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList 
    {

        Food* m_foods;
        int m_size;
        int m_foodAdded;
        void setEmpty();
        bool isValid()const;
        int totals()const;
        void Title()const;
        void footer()const;
       


    public:

        bool add(const char* item_name, int calories, int when);
        void init(int size);
        void display()const;
        void deallocate();
    };
}
#endif
