/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "parse.h"


StackX* InitStackX() {
    StackX *s = new StackX;
    s->m_i = 0;
    return s; 
}
bool pushX(StackX*s, int c) {
    if(sizeof(s->m_ar) / sizeof(int) > s->m_i) {
         s->m_ar[ s->m_i ++] = c;
         return true;
    } 
    return false;    
}

int  popX(StackX*s) {
    if(!StackEmptyX(s)) {
        return s->m_ar[ --  s->m_i ];
    }
    return 0;
}

bool StackEmptyX(StackX*s) {
    return s->m_i == 0;
}


/**
 * 
 * @return 
 */
Stack* InitStack() { 
    Stack *s = new Stack;
    s->m_i = 0;
    return s;
}

/**
 * 
 * @param s
 * @param c
 * @return 
 */
bool push(Stack*s, const char c) {
    if(sizeof(s->m_ar) / sizeof(char) > s->m_i) {
         s->m_ar[ s->m_i ++] = c;
         return true;
    } 
    return false;
}

/**
 * 
 * @param s
 * @return 
 */
const char  pop(Stack*s){
    if(!StackEmpty(s)) {
        return s->m_ar[ --  s->m_i ];
    }
    return '\0';
}         
               
/**
 * 
 * @param s
 * @return 
 */
bool StackEmpty(Stack*s) {
    return s->m_i == 0;
}


/**
 * 
 * @param input
 * @return 
 */
const char* makePolishEntry(const char* input) {
    Stack * sMain = InitStack();
    Stack * sSub = InitStack();
    int len = strlen(input);
    
    for(int i = 0; i < len; i ++) {
        const char c = input[i];
         
        if( isOperation(c) ) {
            //TODO check prioritet
            push(sSub, c); 
            
        } else if(isInt(c)) {
            push(sMain, c);
        } else if(isClosedBracket(c)) {
            push(sMain,  pop(sSub));
        }  
    }
    
    while(!StackEmpty(sSub)) {
        push(sMain,  pop(sSub));
    }
     
    char* out = new char[sMain->m_i];  
    strcpy(out, sMain->m_ar); 
     
    delete sMain;
    delete sSub;
    return out;
}

int evaluatePolishEntry(const char* input) { 
    StackX * sSub = InitStackX();
    int len = strlen(input);
    
    for(int i = 0; i < len; i ++) {
        const char c = input[i];
        
        if(isInt(c)) {
            pushX(sSub, charToInt(c));
        } else if(isOperation(c)) {
            int b = popX(sSub);
            int a = popX(sSub);
           
            pushX(sSub, evaluateMatch(a, b, c)); 
        }
    }   
    
    int out = popX(sSub);
     
    delete sSub;
     
    return out;
}



bool isInt(const char c) { 
    return (c >= '0' && c <= '9');
}

bool isOperation(const char c) {
    switch(c) {
        case O_PLUS:
        case O_MINUS:
        case O_DIV:
        case O_MULT:  
            return true; 
    }
    return false;
}

bool isClosedBracket(const char c) {
    return c == ')';
}


/**
 * 
 * @param a
 * @param b
 * @param operation
 * @return 
 */
int evaluateMatch(int a, int b, char operation) { 
    
    switch(operation) {
        case O_PLUS:
            return a + b;
        case O_MINUS:
            return a - b;
        case O_DIV:
            return b != 0 ? a / b : 0;
        case O_MULT:
            return a * b; 
    }
    return 0;
}


int charToInt(char c) {  
    if(c >= '0' && c <= '9') {
        return c - 48;
    }
    return 0;   
}

 