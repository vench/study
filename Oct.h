#pragma once

class Oct {
public:
    int Show(); //выводим все двоичные цифры
    int ShowPos(int pos); //выводим цифру в позиции
    int Edit(int pos, int val); //изменяем цифру в позиции
    
    
    friend union Bytes;
private:

}; 

