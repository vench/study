#include "Hex.h"

 
//
int Hex::Show() {    
    
    std::cout << std::hex << "ShowHex: [0x" << 
            static_cast<unsigned int>(m_hex1) << 
            static_cast<unsigned int>(m_hex0) <<  
            "]" << std::endl;
   
     return 0;
};


//
 int Hex::ShowPos(int pos) {
      switch(pos){
        case 1:
            std::cout << std::hex << "Hex::ShowPos(" << pos<< "): [0x" <<  static_cast<unsigned int>(m_hex0) << "]\n";
            break;
        case 2:
            std::cout << std::hex << "Hex::ShowPos(" << pos<< "): [0x" <<  static_cast<unsigned int>(m_hex1) << "]\n";
            break; 
       }
       
     return 0;
 }
 
 //
 int Hex::Edit(int pos, int val) {
       switch(pos){
        case 1:
            m_hex0 = val;
            break;
        case 2:
            m_hex1 = val;
            break; 
       }
       
     return 0;
 }