#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<cstring>

#include"Ship.h"

using namespace std;


namespace sdds {

    void Ship::defaultconstrut() {

        m_type[0] = '\0';

        m_engCnt = 0;


    }



    Ship::Ship() {

        defaultconstrut();

    }



    Ship::Ship(const char* type, Engine engine[], int numberofEngines) {

        if (strlen(type) <= TYPE_MAX_SIZE && numberofEngines > 0) {

            set(type, engine, numberofEngines);

        }

        else invaild();

    }



    void Ship::set(const char* type, Engine engine[], int numofeng) {

        strcpy(m_type, type);

        m_engCnt = numofeng;

        for (int i = 0; i < m_engCnt; i++) {

            m_engines[i] = engine[i];

        }

    }



    bool Ship::invaild()const {

        if (m_type && m_engCnt > 0) {

            return false;

        }

        else {

            return true;

        }

    }

    //

    Ship::operator bool() const

    {

        return m_type && m_type[0];

    }



    void Ship::display() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        if (!invaild()) {
            if (this->totalpower() < MAX_STD_POWER)
            {
                cout << m_type << " -  "<< totalpower()<<endl;

            }
            else
            {

                cout << m_type << " - " << totalpower() << endl;

            }

            

            for (int i = 0; i < m_engCnt; i++) {

                m_engines[i].display();



            }

        }

        else {

            cout << "No available data" << endl;




        }
        cout.unsetf(ios::fixed);
        cout.precision(6);

    }

    float Ship::totalpower() const

    {

        double pow = 0;

        for (int i = 0; i < m_engCnt; i++) {

            pow += m_engines[i].get() * 5;

        }

        return pow;

    }



    //4-5

    Ship& Ship::operator+=(Engine engine) {

        if (invaild()) {

            cout << "The object is not valid! Engine cannot be added!" << endl;



        }

        else {

            if (m_engCnt < 10) {

                m_engines[m_engCnt] = engine;

                m_engCnt++;

            }

        }

        return *this;

    }




    bool Ship::operator<(double power) const {//extra


        if (totalpower() < power) {


            return true;


        }


        else {


            return false;


        }


    }



    bool operator<(double power, const Ship& theShip) {


        if (power < theShip.totalpower()) {


            return true;


        }


        else {


            return false;


        }


    }

}