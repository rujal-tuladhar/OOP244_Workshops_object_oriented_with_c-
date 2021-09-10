//Name: Rujal Tuladhar

//Student id: 154594188
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	

	bool read(char name[]);
	bool read(int& m_empNo);
	bool read(double& m_salary);
}
#endif