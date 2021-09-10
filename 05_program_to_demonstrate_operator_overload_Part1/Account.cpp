#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }
    //----
    Account::operator bool() const
    {
        bool value = false;
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0)
        {
            value = true;
        }
        return value;
    }

    Account::operator int() const
    {
        return m_number;
    }
    Account::operator double() const
    {
        return m_balance;
    }


    bool Account::operator~() const
    {
        bool value = false;
        {
            if( m_number == 0)
            {
                value = true;
            }
        
        }
        return value;
    }

    bool Account::notValid() const
    {
        bool value = false;

        if (m_number == -1 && !m_balance)
        {
            value = true;
        }
        return value;


    }
    bool Account::newNumber()
    {
        bool value = false;
        {
            if (m_number == 0)
            {
                value = true;
            }

        }
        return value;
    }

    Account& Account::operator=(int number)
    {
        if (newNumber())
        {
            if (number >= 10000 && number <= 99999)
                m_number = number;

            else
                setEmpty();
        }
        return *this;
    }

    void Account::setNumber(const int& number)
    {
        m_number = number;
    }
    void Account::setBalance(const double& balance)
    {
        m_balance = balance;
    }

    Account& Account::operator=(Account& account)
    {
        if (!newNumber() || account.notValid() || &account == this)
        { 
            return *this;
            
        }
        setNumber(int(account));
        setBalance(double(account));

        account.setBalance(0);
        account.setNumber(0);
        return *this;
    }

    Account& Account::operator+=(double balance)
    {
        if (balance < 0 || notValid())
        {
            return *this;
        }
        m_balance += balance;
        return *this;
    }

    Account& Account::operator-=(double balance)
    {
        if ( balance < 0 || balance > m_balance || notValid())

        {
            return *this;
        }
        m_balance -= balance;
        return *this;
    }


 

    Account& Account::operator<<(Account& account)
    {
        if (&account == this || notValid() || double(account) < 0)
        {
            return *this;
        }

        m_balance += double(account);
        account.setBalance(0);
        return *this;
    }

    Account& Account::operator>>(Account& account)
    {
        if (this == &account || notValid())
        {
            return *this;
        }

        account.setBalance(double(account) + m_balance);
        m_balance = 0;
        return *this;
    }


    double operator+(const Account& valA, const Account& valB)
    {
        if (valA.notValid() || valB.notValid())

        {

            return 0;
        }

        return double(valA) + double(valB);
    }



    double operator+=(double& balance, const Account& account)
    {
        if (account.notValid())
        {
            return balance;
        }
        return balance += double(account);
    }

}