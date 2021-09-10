//Name:Rujal Tuladhar
//Student_id: 154594188
// I have done this workshop on my own using only the code provide by my instructor
#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

namespace sdds
{
    class Label
    {
        char m_boder[9];
        char* m_inside;

    public:
    
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);

        ~Label();
        void readLabel();
        std::ostream& printLabel() const;
    };
}

#endif