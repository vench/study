#pragma once

#include <iostream>

class Bin {
    
    unsigned char m_bin0 : 1;
    unsigned char m_bin1 : 1;
    unsigned char m_bin2 : 1;
    unsigned char m_bin3 : 1;
    unsigned char m_bin4 : 1;
    unsigned char m_bin5 : 1;
    unsigned char m_bin6 : 1;
    unsigned char m_bin7 : 1;
    unsigned char m_bin8 : 1;

public:
    
    
    int Show(); //выводим все двоичные цифры
    int ShowPos(int pos); //выводим цифру в позиции
    int Edit(int pos, int val); //изменяем цифру в позиции
    
    
    friend union Bytes;
    
private:

}; 

