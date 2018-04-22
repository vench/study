#include "Base.h"

//
Base::Base() { 
    this->count = 0;
    this->capacity = 10;//default capacity
    this->pBase = new Pair*[this->capacity]; 
}
    
//
Base::~Base() {   
    if(pBase) { 
        for(int i = 0; i < this->count; i ++) {
            delete this->pBase[i];
        }  
    }
    delete[] this->pBase;
    //std::cout << "Base::~Base\n";
}

//
Base::Base(const Base& bd) {
    this->count = bd.count;
    this->capacity = bd.count;
    //copy
    this->pBase = new Pair*[this->capacity];      
    //TODO копируем по ссылке, но можно и по значению
    for(int i = 0; i < this->count; i ++) {
        this->pBase[i] =  new Pair(*bd.pBase[i]); //bd.pBase[i];
    }     
}
   
//
Base& Base::operator=(const Base& bd) {
    this->count = bd.count;
    this->capacity = bd.count;
    //copy
    this->pBase = new Pair*[this->capacity];  
     //TODO копируем по ссылке, но можно и по значению
    for(int i = 0; i < this->count; i ++) {
        this->pBase[i] = new Pair(*bd.pBase[i]);// bd.pBase[i];
    } 
    return *this;
} 

//
Base::Base(Base&& bd) {
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pBase = bd.pBase;
    bd.pBase = nullptr;
}

//    
Base& Base::operator=(Base&& bd) {
   
    
    for(int i = 0; i < this->count; i ++) {
        delete this->pBase[i];
    }
    
     this->count = bd.count;
    this->capacity = bd.capacity;
    
    
    this->pBase = bd.pBase;
    
    
    
    
    bd.pBase = nullptr;
    return *this;
}
 
//
MyData& Base::operator[](const char * key) { 
    for (size_t i = 0; i < this->count; i++) {
        if (*this->pBase[i] == key)
            return (*this->pBase[i]).data;
    }
    
    if (this->count >= this->capacity) {
        //перераспределяем память 
        this->capacity *= 2;
        Pair **ppt = new Pair*[this->capacity];        
        for(int i = 0; i < this->count; i ++) {
            ppt[i] = this->pBase[i];
        }        
        delete[] this->pBase;
        this->pBase = ppt;        
    } 
     
    Pair *p = new Pair(key, MyData());
    this->pBase[this->count] = p; 
    count++; 
    
    return p->data;
}
    
//
int Base::deletePair(const char* key) {
    for (size_t i = 0; i < this->count; i++) {
        if (*this->pBase[i] == key) {
            delete this->pBase[i];
            this->count --;
            for (; i < this->count; i++) {
                this->pBase[i] = this->pBase[i + 1];
            }
            
            return 1;
        }
             
    }
    return 0;
}

//
std::ostream& operator<< (std::ostream& stream, const Base& b) {
    stream << "Base:\n";
    for(size_t i = 0; i < b.count; i ++) {
        stream << "n(" << (i+1) << "). " << *b.pBase[i] << "\n";
    }        
    
    return stream;
}