
#include "Pair.h"


//
Pair::Pair(const char *k, const MyData& d) {
    this->key = k;
    this->data = d;  
}
    
//
Pair::~Pair() {
    //TODO
}

//
Pair::Pair(const Pair& other) {
    this->key = other.key;
    this->data = other.data;
}

//
Pair& Pair::operator=(const Pair& other) {
    this->key = other.key;
    this->data = other.data;
    return *this;
}
   
//
Pair::Pair(Pair&& other) {
    this->key = other.key;
    this->data = other.data;
}

//
Pair& Pair::operator=(Pair&& other) {
    this->key = other.key;
    this->data = other.data;
    return *this;
}

//
bool Pair::operator==(const char *k) const { 
    MyString s = this->key; 
    return s.Compare(k);
}

//
std::ostream& operator<< (std::ostream& stream, const Pair& p) {
    stream << "Key: " << p.key << " => Data: "<< p.data;
    return stream;
}