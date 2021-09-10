#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
        
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        void setNumber(const int&);
        void setBalance(const double&);
        bool operator~() const;
        bool notValid() const;
        bool newNumber();
        Account& operator=(int number);
        Account& operator=(Account& account);
        Account& operator+=(double balance);
        Account& operator-=(double balance);
        Account& operator<<(Account& account);
        Account& operator>>(Account& account);
        friend double operator+(const Account& valA, const Account& valB);
        friend double operator+=(double& balance, const Account& account);
    };

}
#endif // SDDS_ACCOUNT_H_