//Name: Rujal Tuladhar

//Student id: 154594188
#include <iostream>
#include <iomanip>
#include "cstring.h"

#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name)
    {
      
        strCpy(m_itemName, name);
        m_itemName[20] = '\0';
    }

    void Item::setEmpty()
    {
       
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = true;
    }

    void Item::set(const char* name, double price, bool taxed)
    {
     
        if (name == nullptr || price < 0.0 )
        {
            setEmpty();
        }else
        {
            strCpy(m_itemName, name);
            m_itemName[20] = '\0';
            m_price = price;
            m_taxed = taxed;
        }
    }

    double Item::price()const
    {

        return m_price;
    }

    double Item::tax() const
    {

        const double m_tax = 0.13;

        if (m_taxed == false)
        {
            return 0.0;
        }

        return m_tax * m_price;
    }

    bool Item::isValid() const
    {

        return m_itemName[0] != '\0';
    }

    void Item::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(20);
            cout << left << setfill('.') << m_itemName << " | ";
            cout.width(7);
            cout << left << setfill(' ')<< right << fixed << setprecision(2) << m_price<< " | ";

            if (m_taxed == true)
            {
                cout << "Yes";
            }else
            {
                cout << "No ";
            }
            cout << " |" << endl;
        }

        if (!isValid())
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

   



}