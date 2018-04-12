
#include "Oct.h"

#include <iostream>


//
int Oct::Show() {
    std::cout << "ShowOct: [0" << 
            static_cast<unsigned int>(m_oct2) << 
            static_cast<unsigned int>(m_oct1) << 
            static_cast<unsigned int>(m_oct0) <<  
            "]\n";
   
     return 0;
 }

//
int Oct::ShowPos(int pos) {
    
     switch(pos){
        case 1:
            std::cout << "Oct::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_oct0) << "]\n";
            break;
        case 2:
            std::cout << "Oct::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_oct1) << "]\n";
            break;
        case 3:
            std::cout << "Oct::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_oct2) << "]\n";
            break;
       }
       
    return 0;   
}

//
int Oct::Edit(int pos, int val) {
     switch(pos){
        case 1:
            m_oct0 = val;
            break;
        case 2:
            m_oct1 = val;
            break;
        case 3:
            m_oct2 = val;
            break;
       }
       
    return 0; 
}

