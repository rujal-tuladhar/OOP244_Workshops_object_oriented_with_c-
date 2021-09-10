//Name - Rujal Tuladhar
//Student_id- 154594188
//I am done this workshop on my own by using the code provided by my professor.
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_name[30];
        int m_number;
        int m_time;
        void setName(const char* name);


    public:

        void setEmpty();
        void display()const;
        bool isValid()const;
        void set(const char* item_name, int calories, int when); 
        int calorieNo()const;
    };
}

#endif // !SDDS_SUBJECT_H
