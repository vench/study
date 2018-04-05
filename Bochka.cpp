#include "Bochka.h"
#include <iostream>

Bochka::Bochka() {
}

Bochka::Bochka(const Bochka& orig) {
}

Bochka::~Bochka() {
}

//
Bochka::Bochka(unsigned char weight,  float alcohol,  float water) {
    this->weight = weight;
    this->alcohol = alcohol;
    this->water = water;
};

//
  const float Bochka::getAlcohol() {
     return this->alcohol; 
 };

 //
 const float Bochka::getWater() {
    return this->water; 
 }
 
 //
 void Bochka::Pereliv(Bochka &b, unsigned int weight) {
     if(b.weight - weight < 0) {
         std::cout << "Bochka b Is Empty!!!" << "\n";
         return;
     }
     
     b.weight -= weight;
     float a = this->alcohol * this->weight + b.alcohol  * weight,
           w = this->water * this->weight + b.water * weight; 
     this->weight += weight;  
     
     this->alcohol = a / this->weight;
     this->water = w / this->weight;   
 };

 
 
 
 
 
 
 
 
 
 
