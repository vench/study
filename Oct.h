#pragma once

#include <iostream>

class Oct {
    
     unsigned char m_oct0 : 3; //0-7 8 bit
     unsigned char m_oct1 : 3; //0-7 8 bit
     unsigned char m_oct2 : 2; //0-3 8 bit
    
public:
    int Show(); //выводим все двоичные цифры
    int ShowPos(int pos); //выводим цифру в позиции
    int Edit(int pos, int val); //изменяем цифру в позиции
    
    
    friend union Bytes;
private:

}; 

