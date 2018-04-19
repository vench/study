

#include "MyData.h"

//
MyData::MyData() {}

//
MyData::MyData(Sex s, size_t age, const char* job, float sal) {
    //TODO
}
    
//
MyData::~MyData () {
    //TODO
}

//
MyData::MyData(const MyData& d) {
    //TODO
}

//
MyData & MyData::operator=(const MyData& d) {
    //TODO
    return *this;
}

//
MyData::MyData(MyData&& d) {
    //TODO
}

//
MyData& MyData::operator=(MyData&& d) {
    return *this;
}


//
std::ostream& operator<< (std::ostream& stream, const MyData& d) {
    //TODO
    // stream << "something";
    return stream;
}
