#include "Bin.h"

 
//
int Bin::Show() {
    std::cout << "ShowBin: [" << 
            static_cast<unsigned int>(m_bin7) << 
            static_cast<unsigned int>(m_bin6) << 
            static_cast<unsigned int>(m_bin5) << 
            static_cast<unsigned int>(m_bin4) << 
            static_cast<unsigned int>(m_bin3) << 
            static_cast<unsigned int>(m_bin2) << 
            static_cast<unsigned int>(m_bin1) <<
            static_cast<unsigned int>(m_bin0) << 
            "]\n";
    return 0;
}

//выводим цифру в позиции
int Bin::ShowPos(int pos) {
    switch(pos){
        case 1:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin0) << "]\n";
            break;
        case 2:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin1) << "]\n";
            break;
        case 3:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin2) << "]\n";
            break;
        case 4:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin3) << "]\n";
            break;
        case 5:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin4) << "]\n";
            break;
        case 6:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin5) << "]\n";
            break;
        case 7:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin6) << "]\n";
            break;
        case 8:
            std::cout << "Bin::ShowPos(" << pos<< "): [" <<  static_cast<unsigned int>(m_bin7) << "]\n";
            break;
    }
    return 0;
}

//изменяем цифру в позиции
int Bin::Edit(int pos, int val) {
    switch(pos){
        case 1:
            m_bin0 = val; 
            break;
        case 2:
            m_bin1 = val; 
            break;
        case 3:
            m_bin2 = val;
            break;
        case 4:
            m_bin3 = val;
            break;
        case 5:
            m_bin4 = val;
            break;
        case 6:
            m_bin5 = val;
            break;
        case 7:
            m_bin6 = val;
            break;
        case 8:
            m_bin7 = val;
            break;
    }
    return 0;
}