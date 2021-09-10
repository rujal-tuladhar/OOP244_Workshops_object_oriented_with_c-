#ifndef SDDS_SHIP_H__

#define SDDS_SHIP_H__

#include "Engine.h"

namespace sdds {


    const float MIN_STD_POWER = 90.111;

    const float  MAX_STD_POWER = 99.999;

    const int SIZE = 10;

    class Ship {



        Engine m_engines[SIZE];

        char m_type[TYPE_MAX_SIZE];

        int m_engCnt;



    private:


        float totalpower() const;


    public:

        Ship();

        Ship(const char* type, Engine* engine, int numberofEngines);



        explicit operator bool() const;

        void defaultconstrut();

        bool invaild() const;



        void display() const;


        Ship& operator+=(Engine engine);

        void set(const char* type, Engine* engine, int numofeng);



        bool operator<(double power) const;

        double power;


        friend bool operator<(double power, const Ship& theShip);



    };



    bool operator<(double power, const Ship& theShip);


}


#endif
