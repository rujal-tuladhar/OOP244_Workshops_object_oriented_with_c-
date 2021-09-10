

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

//#include <iostream>
#include <cstring>


namespace sdds
{

    const int TYPE_MAX_SIZE = 30;

    class Engine
    {
        double m_size;
        char m_type[TYPE_MAX_SIZE];



    public:
        //constructors
        Engine();
        Engine(const char* t, double s);

        void defaultconstructore();

        void setEng(const char* emngtype, double sz);

        double get() const;

        void display() const;

    };





}


#endif