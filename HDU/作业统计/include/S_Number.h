#ifndef S_NUMBER_H
#define S_NUMBER_H
#include <iostream>
using namespace std;

class S_Number
{
    public:
        S_Number();
        virtual ~S_Number();
        int get_studentcount();
        void set_studentcount(int count);
        void add_studentcount(int count);
        void sub_studentcount(int count);
    protected:
    private:
        int m_studentcount;
};

#endif // S_NUMBER_H
