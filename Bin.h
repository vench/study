#pragma once



class Bin {
    
    unsigned char m_bin0 : 1;
    unsigned char m_bin1 : 1;

public:
    
    
    int Show(); //выводим все двоичные цифры
    int ShowPos(int pos); //выводим цифру в позиции
    int Edit(int pos, int val); //изменяем цифру в позиции
    
    
    friend union Bytes;
    
private:

}; 

