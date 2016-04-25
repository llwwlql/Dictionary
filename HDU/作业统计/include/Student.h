#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
using namespace std;
class Student
{
    protected:
    private:
        char m_ID[20];
        int m_count;
    public:
        Student();
        Student(char* ID);
        virtual ~Student();
        void set_ID(char *ID);
        void set_count(int count);
        char* get_ID();
        int get_count();
        void add_count();
};

#endif // STUDENT_H
