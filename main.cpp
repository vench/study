/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vench
 *
 * Created on 3 ноября 2017 г., 12:30
 */

#include <cstdlib>
#include <stdio.h>
#include "parse.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    printf("Enter matсh expression[max len 255]: \n"); 
    
    char s[255]; 
    while(true) {
        fgets(s, 255, stdin);   
        const char* pe = makePolishEntry(&s[0]); 
        printf("Polish Entry: %s\n", pe); 
        int r = evaluatePolishEntry(pe);
        printf("Evaluate: %d\n", r);
    } 
    
    return 0;
}




