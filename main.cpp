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
    
    for(int i = 0; i < argc; i ++) { 
        if(strcmp(argv[i], "test") == 0) {
            return runTest(); 
        }
    } 
    
    const int len = 255;
    char s[len];
    
    printf("Enter matсh expression[max len %d]: \n", len); 
      
       
    while(true) { 
        
        fgets(s, len, stdin);   
        const char* pe = makePolishEntry(&s[0]); 
        printf("Polish Entry: %s\n", pe); 
        int r = evaluatePolishEntry(pe);
        printf("Evaluate: %d\n", r);
    } 
    
    return 0;
}




