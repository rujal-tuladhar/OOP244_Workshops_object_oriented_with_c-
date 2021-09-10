#define _CRT_SECURE_NO_WARNINGS

#include "Truck.h"
#include "MotorVehicle.h"
#include <iomanip>
#include <iostream>
#include <string.h>

namespace sdds {

	Truck::Truck(const char* plate, int year, double capacity, const char* address) : MotorVehicle(plate, year) {
		//Set base class attributes through default constructor

		//Set cargo attributes
		m_capacity = capacity;
		m_cargo = 0;

		//Set address via moveTo function
		MotorVehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo) {

		if (m_cargo >= m_capacity)
			return false;
		
		//Check if cargo can be added
		
		if (m_cargo+cargo > m_capacity)
		{
			m_cargo=m_capacity;
		}
		else if (m_cargo + cargo < m_capacity)
		{
			m_cargo += cargo;
		}
		return true;

		
	}

	bool Truck::unloadCargo() {
		bool unload = m_cargo > 0;
		m_cargo = 0;
		return unload;
	}

	std::istream& Truck::read(std::istream& in) {
		//Grab data from user, transfer into attributes
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> m_capacity;
		std::cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}


	std::ostream& Truck::write(std::ostream& os)const {
		//Call base class write;
		MotorVehicle::write(os);

		//Output truck attributes
		os << " | " << m_cargo << "/" << m_capacity;

		return os;
	}


	std::ostream& operator<<(std::ostream& os,const Truck& t) {
		//Call write function with ostream obj
		t.write(os);

		//Return ostream obj
		return os;
	}

	std::istream& operator>>(std::istream& in, Truck& t) {
		//Call read function with istream obj
		t.read(in);

		//Return istream obj
		return in;
	}

}