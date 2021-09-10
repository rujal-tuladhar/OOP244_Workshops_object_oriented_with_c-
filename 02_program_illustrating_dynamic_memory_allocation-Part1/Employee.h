//Name: Rujal Tuladhar

//Student id: 154594188
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#define DATAFILE "employees.csv"
namespace sdds
{
    struct Employee
    {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    void sort();

    bool load(Employee& emp);

    bool load();

    void display(Employee& emp);
    void display();
    void deallocateMemory();
}

#endif