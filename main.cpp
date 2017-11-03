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
    fgets(s, 255, stdin);  
   /* s[0] = '1';
    s[1] = '+';
    s[2] = '2'; */
    const char* pe1 = makePolishEntry(&s[0]);
    
    printf("Polish Entry: %s\n", pe1); 
    int r = evaluatePolishEntry(pe1);
    printf("Evaluate: %d\n", r);
    
    return 0;
}




