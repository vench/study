#include "Base.h"

//
Base::Base() {
//TODO
}
    
//
Base::~Base() {
//TODO
}

//
Base::Base(const Base& bd) {
//TODO
}
   
//
Base& Base::operator=(const Base& bd) {
//оптимизированный!!!
    //TODO
    return *this;
} 

//
Base::Base(Base&& bd) {
//TODO
}

//    
Base& Base::operator=(Base&& bd) {
    //TODO
    return *this;
}
 
//
MyData& Base::operator[](const char * key) {
    //TODO
    for (size_t i = 0; i < this->count; i++) {
        if (this->pBase[i] == key)
            return this->pBase[i].data;
    }
    
    if (this->count >= this->capacity) {
        //перераспределяем память
        //TODO    
    }
    
    Pair p(key, MyData());
    this->pBase[this->count] = p;
    
    count++;
 
    return this->pBase[this->count - 1].data;
}
    
//
int Base::deletePair(const char* key) {
    //TODO
    return 0;
}

//
std::ostream& operator<< (std::ostream& stream, const Base& b) {
            //TODO
    // stream << "something";
    return stream;
}