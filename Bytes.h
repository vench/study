

#pragma once


#include "Bin.h"
#include "Oct.h"
#include "Hex.h"
#include <iostream>

union Bytes
{
    private:
        Bin m_bin;
        Oct m_oct;
        Hex m_hex; 
        
        unsigned char m_dec;
    public:   
        Bytes(unsigned char byte) {   
            m_dec = byte; 
        }
        
        ~Bytes(){} 
        
        void ShowChar() { 
            std::cout << "ShowChar: [" << m_dec << "]\n";
        } 
        
        void ShowDec() {  
            std::cout << "ShowDec: [" << static_cast<unsigned int>(m_dec) << "]\n";
        } 
        
        void ShowBin() { m_bin.Show(); }  
        void ShowHex() { m_hex.Show(); }
        void ShowOct() { m_oct.Show(); }
        
        void ShowBinPos(int pos) { m_bin.ShowPos(pos); }        
        void ShowOctPos(int pos) { m_oct.ShowPos(pos); }        
        void ShowHexnPos(int pos) { m_hex.ShowPos(pos); }
        
        void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
        void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
        void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
        
        
};