//MotorVehicle.h
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>

namespace sdds {

	class MotorVehicle {
	private:
		char m_plate[33];
		char m_address[65];
		int m_year;

	public:
		MotorVehicle();
		MotorVehicle(const char* plate, int year);

		void moveTo(const char* address);

		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os,const MotorVehicle& mv);
	std::istream& operator>>(std::istream& in, MotorVehicle& mv);

}
#endif