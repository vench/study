#pragma once


#include <iostream>


class Hex { 
    
     unsigned char m_hex0 : 4; //0-7 8 bit
     unsigned char m_hex1 : 4; //0-7 8 bit 
    
public:
    int Show(); //выводим все двоичные цифры
    int ShowPos(int pos); //выводим цифру в позиции
    int Edit(int pos, int val); //изменяем цифру в позиции
    
    
    friend union Bytes;
private:

}; 

