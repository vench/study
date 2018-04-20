

#include "MyData.h"

//
MyData::MyData() {
    this->sex = MyData::UNDEF;
}

//
MyData::MyData(Sex sex, size_t age, const char* job, float salary) { 
    this->sex = sex;
    this->m_age = age;
    this->m_job = job;
    this->m_salary = salary;
}
    
//
MyData::~MyData () {
    //TODO
}

//
MyData::MyData(const MyData& d) {
    this->sex = d.sex;
    this->m_age = d.m_age;
    this->m_job = d.m_job;
    this->m_salary = d.m_salary;
}

//
MyData & MyData::operator=(const MyData& d) {
    this->sex = d.sex;
    this->m_age = d.m_age;
    this->m_job = d.m_job;
    this->m_salary = d.m_salary;
    return *this;
}

//
MyData::MyData(MyData&& d) {
    this->sex = d.sex;
    this->m_age = d.m_age;
    this->m_job = d.m_job;
    this->m_salary = d.m_salary;
}

//
MyData& MyData::operator=(MyData&& d) {
    this->sex = d.sex;
    this->m_age = d.m_age;
    this->m_job = d.m_job;
    this->m_salary = d.m_salary;
    return *this;
}


//
std::ostream& operator<< (std::ostream& stream, const MyData& d) { 
    stream << "{Age: " << d.m_age << ", Sex: " << d.sex << ", Job: " << d.m_job << ", Salary: " << d.m_salary << "}";
    return stream;
}
