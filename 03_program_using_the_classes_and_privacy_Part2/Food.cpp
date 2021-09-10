#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    void Food::setName(const char* name)

    {

        strCpy(m_name, name);
        m_name[30] = '\0';
    }

    void Food::setEmpty()
    {
      
        m_name[0] = '\0';
        m_number = 0;
        m_time = 0;


    }

    void Food::set(const char* item_name, int calories, int when)
    {
  
        if (calories < 0 || item_name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(item_name);
            m_number = calories;
            m_time = when;
        }
    }

    void Food::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(30);

            cout << left << setfill('.') << m_name << " | ";

            cout.width(4);
            cout << left << setfill(' ')<< right << m_number;

            cout << " | ";
            cout.width(10);
            if (m_time == 1)

                cout << left << "Breakfast";

            else if (m_time == 2)

                cout << left << "Lunch";

            else if (m_time == 3)

                cout << left << "Dinner";

            else if (m_time == 4)
                cout << left << "Snack";

            cout << setfill(' ') << right<< " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    bool Food::isValid() const
    {
       
        return m_time >= 1 && m_name[0] != '\0';
    }

    int Food::calorieNo() const

    {

        return m_number;
    }
}