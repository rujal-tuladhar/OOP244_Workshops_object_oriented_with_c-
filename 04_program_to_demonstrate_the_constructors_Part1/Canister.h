//Name: Rujal Tuladhar
//I have done this workshop on my own by using only the codes provided by my proffesors and course material notes
//Student id: 154594188
#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H
#include <iostream>
namespace sdds {
    class Canister {
        char* m_contentName{};
        double m_diameter{}; // in centimeters
        double m_hieght{};   // in centimeters
        double m_contentVolume{};  // in CCs
        bool m_usable{};
        void setToDefault();
        void setName(const char* Cstr);
        bool isEmpty() const;
        bool hasSameContent(const Canister& C) const;
    public:
        Canister();
        Canister(const char* contentName);
        Canister(double height, double diameter,
            const char* contentName = nullptr);
        ~Canister();
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister&);
        double volume() const;
        std::ostream& display() const;
        double capacity() const;
        void clear();
    };
}

#endif // !SDDS_BOX_H