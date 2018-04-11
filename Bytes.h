

#pragma once


#include "Bin.h"
#include "Oct.h"
#include "Hex.h"

union Bytes
{
    private:
        Bin m_bin;
        Oct m_oct;
        Hex m_hex;
        
        
        unsigned char m_dec;
    public:   
        Bytes(unsigned char byte) {  
            
            //TODO
            m_bin.m_bin0 = 0;
            m_bin.m_bin1 = 1; 
        } //конструктор
        
        ~Bytes(){}
        
        void ShowBin() { m_bin.Show(); } 
        void ShowDec() {   }
        void ShowChar() {  }
        void ShowHex() {}
        void ShowOct() {}
        
        void ShowBinPos(int pos) { 
            m_bin.ShowPos(pos); 
        }
};