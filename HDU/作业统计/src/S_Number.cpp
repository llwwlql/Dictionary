#include "S_Number.h"
S_Number::S_Number()
{
    this->m_studentcount=0;
    //ctor
}

S_Number::~S_Number()
{
    //dtor
}
int S_Number::get_studentcount(){
    return this->m_studentcount;
}
void S_Number::set_studentcount(int count){
    this->m_studentcount=count;
}
void S_Number::add_studentcount(int count){
    this->m_studentcount+=count;
}
void S_Number::sub_studentcount(int count)
{
    this->m_studentcount-=count;
}
