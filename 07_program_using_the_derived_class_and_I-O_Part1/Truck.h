#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle {
	private:
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);

		bool addCargo(double cargo);
		bool unloadCargo();

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const Truck& t);
	std::istream& operator>>(std::istream& in, Truck& t);

}

#endif