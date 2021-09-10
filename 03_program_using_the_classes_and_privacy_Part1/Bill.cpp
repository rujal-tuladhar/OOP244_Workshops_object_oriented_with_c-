//Name: Rujal Tuladhar

//Student id: 154594188
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;

namespace sdds {


    void Bill::setEmpty()
    {
        m_items = nullptr;
        strCpy(m_title, "");
    }

    bool Bill::isValid() const
    {
        bool ok = true;
        ok = m_title[0] != '\0' && m_items != nullptr  ;
        for (int i = 0; ok == true && i < m_noOfItems; i++)
        {
            ok = ok && m_items[i].isValid();
        }

        return ok;
    }


    double Bill::totalTax() const
    {
        
        double tax = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            tax += m_items[i].tax();
        }

        return tax;
    }


    double Bill::totalPrice() const
    {
        double price = 0.0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            price += m_items[i].price();
        }

        return price;
    }

    void Bill::Title()const
    {
        cout << "+--------------------------------------+" << endl;

        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout << left << m_title<< " |" << endl;
        }else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalTax()<< " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalPrice() << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalTax() + totalPrice()<< " |" << endl;

        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

   
    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 1)
        {
            m_title[0] = '\0';
            m_noOfItems = 0;
            m_itemsAdded = 0;
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];

            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }

    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    { 
        delete[] m_items;
        m_title[0] = '\0';
    }

}