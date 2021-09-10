#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#include "MotorVehicle.h"
#include<string.h>

namespace sdds {

	MotorVehicle::MotorVehicle() {
		m_plate[0] = '\0';
		m_address[0] = '\0';
		m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* plate, int year) {
		//Transfer license plate info
		strncpy(m_plate, plate, 32);

		//Transfer Year
		m_year = year;

		//Set default address
		strcpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		//Compare addresses
		if (strcmp(m_address, address)) {
			//Format output, align to right and then left, change widths for each field
			
			std::cout  << "|" << std::right << std::setw(10) << m_plate << "| |" << 
				std::setw(20) << std::right << m_address << " --->--- "
				<< std::setw(20) << std::left << address << "|" << std::endl;


			//Transfer Address
			strncpy(m_address, address, 64);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const {
		//Output MotorVehicle Atrriubutes
		os << "| " << m_year << " | " << m_plate << " | " << m_address;

		//Return os to client
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		//Grab data from user, transfer into attributes
		std::cout << "Built year: ";
		in >> m_year;
		std::cout <<  "License plate: ";
		in >> m_plate;
		std::cout <<  "Current location: ";
		in >> m_address;

		return in;
	}

	std::ostream& operator<<(std::ostream& os,const MotorVehicle& mv) {
		//Call write function with ostream obj
		return mv.write(os);

		//return ostream obj
		
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& mv) {
		//call read function istream obj
		return mv.read(in);

		//return istream obj
		
	}

}