//Name: Rujal Tuladhar
//I have done this workshop on my own by using only the codes provided by my proffesors and course material notes
//Student id: 154594188
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  
#include "Canister.h"
using namespace std;
namespace sdds {
   
#define PI 3.14159265


    void Canister::setToDefault() 
    {
        m_contentName = nullptr;
        m_hieght = 13.0;
        m_contentVolume = 0.0;
        m_diameter = 10.0;
        m_usable = true;
    }


    bool Canister::isEmpty() const 
    { 
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C) const 
    {
        if (C.m_contentName != nullptr && m_contentName != nullptr)
        {
            int value = strCmp(m_contentName, C.m_contentName);
            return value == 0;
            
        }
        return false;
    }

    void Canister::setName(const char* Cstr) 
    {
        if (Cstr != nullptr && m_usable)
        {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister() 
    { setToDefault(); 
    }

    Canister::Canister(const char* contentName) 
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName)
    {
        setToDefault();
        if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30)
        {
            m_diameter = diameter;
            m_contentVolume = 0;
            m_hieght = height;
            setName(contentName);
            
        }
        else
        m_usable = false;
    }
    Canister::~Canister()
    { 
        delete[] m_contentName;
    }

    void Canister::clear() 
    { delete[] m_contentName;
      m_contentName = nullptr;
      m_contentVolume = 0.0;
      m_usable = true; 
    }

    double Canister::capacity() const 
    { 
        return PI * (m_hieght - .267) * m_diameter / 2 * m_diameter / 2; 
    
    }

    double Canister::volume() const
    {
        return m_contentVolume; 
    }

    Canister& Canister::setContent(const char* contentName) 
    
    {
        if (contentName == nullptr)
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if (!hasSameContent(contentName))
        {
            m_usable = false;
        }

        return *this;
    }

    Canister& Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0 && (quantity + volume()) <= capacity())
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C)
    {
        setContent(C.m_contentName);
        if (C.volume() > (capacity() - volume()))
        {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else 
        {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    ostream& Canister::display() const
    {
        cout << fixed << setprecision(1);
        cout << setw(7) << capacity() << "cc (" << m_hieght << "x" << m_diameter << ") Canister";

        if (m_usable == false) 
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr)
        {
            cout << " of " << setw(7) << volume() << "cc   " << m_contentName;
        }
        return cout;
    }

    


}