#pragma once

class Bochka {
    unsigned int weight;
     float alcohol;
     float water;
    
    
public:
    Bochka();
    Bochka(unsigned char weight,  float alcohol,  float water);
    Bochka(const Bochka& orig);
    ~Bochka();
    const float getAlcohol();
    const float getWater();
    void Pereliv(Bochka &b, unsigned int weight);
private:

}; 

