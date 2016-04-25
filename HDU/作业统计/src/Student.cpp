#include "Student.h"

Student::Student()
{
}
Student::Student(char *ID){
    strcpy(this->m_ID,ID);
    this->m_count=0;
}

Student::~Student()
{
    //dtor
}
void Student::set_ID(char* ID)
{
    strcpy(this->m_ID,ID);
}
void Student::set_count(int count){
    this->m_count=count;
}
char* Student::get_ID(){
    return this->m_ID;
}
int Student::get_count(){
    return this->m_count;
}

void Student::add_count(){
    this->m_count+=1;
}
