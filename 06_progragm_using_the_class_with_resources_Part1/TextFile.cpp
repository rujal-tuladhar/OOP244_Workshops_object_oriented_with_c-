//Name: Rujal Tuladhar
//I have done this lab on my own only using the notes provided by my profesors.
//Student id: 154594188

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[lineValue == nullptr ? 0 : strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
       
        if (!isCopy)
        {
            delete[] m_filename;
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
            return;
        }
        m_filename = new char[ strLen(fname) + 3];
        string prefix = "C_";
        for (int i = 0; i < (int)strLen(fname); i++)
            prefix += (int)fname[i];
        strCpy(m_filename, prefix.c_str());
    }

    void TextFile::setNoOfLines() 
    {
        int counter = 0;
        string new_line;
        ifstream inst;
        inst.open(m_filename);
        
        while (getline(inst, new_line))
            counter++;

        inst.close();
        if (!counter) 
        {
            delete[] m_filename;
            m_filename = nullptr;
          
        }
        m_noOfLines = counter;
    }

    void TextFile::loadText() 
    {
       
        if (m_filename != nullptr)
        {
            string new_line;
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];
            ifstream inst;
            inst.open(m_filename);
            if (inst.is_open()) {
                
                for (int i = 0; i < (int)m_noOfLines; i++) {
                    getline(inst, new_line);
                    m_textLines[i] = new_line.c_str();
                }
            }
            inst.close();
        }
    }

    void TextFile::saveAs(const char* fileName) const 
    {
        if (fileName == nullptr) return;
        ofstream opn;
        opn.open(fileName);
        if (opn.is_open())
            for (int i = 0; i < (int)m_noOfLines; i++)
                opn << m_textLines[i] << '\n';
        opn.close();
    }

    TextFile::TextFile(unsigned int pageSize) 
    {
        m_pageSize = pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;
    }

    TextFile::TextFile(const char* filename, unsigned int pageSize) {
        m_pageSize = pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;
        
        if (filename != nullptr)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }



    TextFile::TextFile(const TextFile& obj)
    {
        m_pageSize = obj.m_pageSize;
        this->m_filename = nullptr;
        this->m_textLines = nullptr;
        this->m_noOfLines = 0;

        setFilename(obj.m_filename, true);
        obj.saveAs(m_filename);
        setNoOfLines();
        loadText();
    }

    TextFile& TextFile::operator=(const TextFile& obj) {
        if (this != &obj)
        {
            if (obj)
            {
                delete[] this->m_textLines;
                m_textLines = nullptr;
                obj.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile()
    {
        delete[] m_filename;
        delete[] m_textLines;
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    ostream& TextFile::view(ostream& ostr) const
    {
        if (!*this) return ostr;
        ostr << m_filename << endl;
        ostr.width(strLen(m_filename));
        ostr.fill('=');
        ostr << "" << endl;
        for (int i = 0; i <(int) m_noOfLines; i++)
        {
            if (!(i % m_pageSize) && i) 
            {
                ostr << "Hit ENTER to continue...";
                cin.get();
            }
            ostr << m_textLines[i].m_value << endl;
        }

        return ostr;
    }

   istream& TextFile::getFile(istream& istr)
   {
        string new_data;
        istr >> new_data;
        while (getchar() != '\n');
        setFilename(new_data.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned int index) const
    {
        if (m_textLines == nullptr)
        {
            return nullptr;
        }
        return m_textLines[index % m_noOfLines];
    }

    TextFile::operator bool() const
    {
        if (m_filename != nullptr)
        {
            return true;
        }
        else {
            return false;
        }
    
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
     return text.view(ostr);

    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        return text.getFile(istr);
        
    }
}