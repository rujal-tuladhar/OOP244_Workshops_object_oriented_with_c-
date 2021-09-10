//Name - Rujal Tuladhar
//Student_id- 154594188
//I am done this workshop on my own by using the code provided by my professor.
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

    int CalorieList::totals() const
    {
        
        int total = 0;
        for (int i = 0; i < m_size; i++)
        {
            total += m_foods[i].calorieNo();
        }

        return total;
    }

    void CalorieList::Title() const

    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;

    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << right << totals()<< " | ";
            cout.width(12);
            cout << setfill(' ')<< " |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty()
  
    {
        m_foods = nullptr;
    }

    bool CalorieList::isValid() const
    {
        bool ok = true;
        ok = m_foods != nullptr;
        for (int i = 0; ok == true && i < m_size; i++)
        {
            ok = ok && m_foods[i].isValid();
        }

        return ok;
    }

    void CalorieList::init(int size)
    {
        if (size < 1)
        {
            m_foodAdded = 0;
            m_size = 0;
            
        }
        else
        {
            m_size = size;
            m_foodAdded = 0;
            m_foods = new Food[m_size];
            for (int i = 0; i < m_size; i++)
            m_foods[i].setEmpty();

        }

    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        if (m_foodAdded < m_size)
        {
            m_foods[m_foodAdded].set(item_name, calories, when);
            m_foodAdded++;
            return true;
        }

        return false;
    }

    void CalorieList::display() const
    {
        Title();

        for (int i = 0; i < m_size; i++)
        {
            m_foods[i].display();
        }
        footer();
    }

    void CalorieList::deallocate()
    {
        
        delete[] m_foods;
    }
}