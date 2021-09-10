#define _CRT_SECURE_NO_WARNINGS







#include <iostream>



#include "Engine.h"



#include "Ship.h"





using namespace std;





namespace sdds



{



	Engine::Engine() {



		defaultconstructore();



	}











	Engine::Engine(const char* t, double s) {





		if (strlen(t) < 1 && s < 0) {



			defaultconstructore();



		}



		else {



			setEng(t, s);



		}







	}







	void Engine::defaultconstructore() {





		m_type[0] = '\0';



		m_size = 0;



	}





	void Engine::setEng(const char* engtype, double sz) {



		if (engtype != nullptr && engtype[0] != '\0' && sz > 0) {





			strcpy(m_type, engtype);



			m_size = sz;



		}



		else {



			defaultconstructore();



		}



	}





	double Engine::get() const {



		return m_size;



	}







	void Engine::display() const {





		if (m_type != nullptr && m_type[0] != '\0' && m_size > 0) {





			cout << m_size << " liters - " << m_type << endl;





		}



	}



}