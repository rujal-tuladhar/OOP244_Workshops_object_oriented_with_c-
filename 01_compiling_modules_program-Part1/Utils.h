#ifndef SDDS_Utils_h
#define SDDS_Utils_h

namespace sdds
{
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);





}

#endif