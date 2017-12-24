/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "parse.h"

/**
 * 
 * @return 
 */
StackX* InitStackX() {
    StackX *s = new StackX;
    s->m_i = 0;
    return s; 
}

/**
 * 
 * @param s
 * @param c
 * @return 
 */
bool pushX(StackX*s, int c) {
    if(sizeof(s->m_ar) / sizeof(int) > s->m_i) {
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
int  popX(StackX*s) {
    if(!StackEmptyX(s)) {
        return s->m_ar[ --  s->m_i ];
    }
    return 0;
}

/**
 * 
 * @param s
 * @return 
 */
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
const char SeeLast(Stack*s) {
    if(!StackEmpty(s)) {
        return s->m_ar[  s->m_i - 1];
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
 * @param o
 * @return 
 */
int getOperatorPriority(const char o) {
    switch(o) {
        case O_PLUS:
        case O_MINUS:
            return 1;
        case O_DIV:
            return 2;
        case O_MULT:  
            return 3; 
        case O_POW:
            return 4;
    }
    return 0;
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
    bool breakInt = false;
    
    for(int i = 0; i < len; i ++) {
        const char c = input[i];        
        
        if(isInt(c)) {
            push(sMain, c);
            breakInt = true;
            continue;
        } else if(breakInt) {
            breakInt = false;
            push(sMain, O_DELIMITER);
        }
         
        if(isOpenedBracket(c)) {
            push(sSub, c);
        } else if( isOperation(c) ) {   
            if(!StackEmpty(sSub) && getOperatorPriority(SeeLast(sSub)) > getOperatorPriority(c)) {  
                push(sMain, pop(sSub));
            } 
            push(sSub, c); 
            
        } else if(isClosedBracket(c)) { 
            while(!StackEmpty(sSub) && !isOpenedBracket(SeeLast(sSub))) {
                push(sMain,  pop(sSub));
            } 
        }   
    }
    
    while(!StackEmpty(sSub)) {
        char c = pop(sSub);
        if(!isOpenedBracket(c)) {
           push(sMain,  c); 
        } 
    }
     
    char* out = new char[sMain->m_i+1];  
    strcpy(out, sMain->m_ar); 
    out[sMain->m_i] = '\0'; 
    
    delete sMain;
    delete sSub;
    return out;
}

/**
 * 
 * @param s
 * @return 
 */
int StackReadIntX(StackX*s) {
    int v = 0, pos = 0;
    while(!StackEmptyX(s)) {
        v += pos > 0 ? intPow(popX(s), pos)  : popX(s);
        pos ++;
    }
    return v;
}

/**
 * 
 * @param input
 * @return 
 */
int evaluatePolishEntry(const char* input) { 
    StackX * sSub = InitStackX();
    StackX * sMain = InitStackX();
    int len = strlen(input);
    
    for(int i = 0; i < len; i ++) {
        const char c = input[i];
      
        if(isInt(c)) {
            pushX(sSub, charToInt(c));   
        } else if(isIntDelimiter(c)) { 
            pushX(sMain, StackReadIntX(sSub)); 
            
        } else if(isOperation(c)) {
             
            if(!StackEmptyX(sSub)) { 
                pushX(sMain, StackReadIntX(sSub)); 
            } 
            
            int b = popX(sMain);
            int a = popX(sMain); 
            pushX(sMain, evaluateMatch(a, b, c));  
        }
    }   
    
    int out = popX(sMain);
     
     delete sSub;
     delete sMain;
     
    return out;
}


/**
 * 
 * @param c
 * @return 
 */
bool isInt(const char c) { 
    return (c >= '0' && c <= '9');
}

/**
 * 
 * @param c
 * @return 
 */
bool isOperation(const char c) {
    switch(c) {
        case O_PLUS:
        case O_MINUS:
        case O_DIV:
        case O_MULT:  
        case O_POW:
            return true; 
    }
    return false;
}

/**
 * 
 * @param c
 * @return 
 */
bool isClosedBracket(const char c) {
    return c == ')';
}

/**
 * 
 * @param c
 * @return 
 */
bool isOpenedBracket(const char c) {
    return c == '(';
}

/**
 * 
 * @param c
 * @return 
 */
bool isIntDelimiter(char c) {
    return c == O_DELIMITER;
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
        case O_POW:
            int v = a;
            while(b -- > 1){
                v *= a;
            }
            return v;
    }
    return 0;
}

/**
 * 
 * @param c
 * @return 
 */
int charToInt(char c) {  
    if(c >= '0' && c <= '9') {
        return c - 48;
    }
    return 0;   
}

/**
 * 
 * @param i
 * @return 
 */
char intToChar(int i) {
    return (char)(i + 48);
} 

/**
 * 
 * @param i
 * @param p
 * @return 
 */
int intPow(int i, unsigned int p) {
    int n = i;
    while(p -- > 0) {
        n *= 10;
    }
    return n;
}




int runTest(){
    printf("Run Test\n-------------------\n");
    
    const int len = 5;
    STest* list = new STest[len]{
        {"1+2", 3},
        {"1+3", 4},
        {"2+2*2", 6},
        {"(2+2)*2", 8},
        {"3 + 4 * 2 / (3 - 1) ^ 2", 5}
    };
    
    for(int i = 0; i < len; i++) {
        const char* pe = makePolishEntry(list[i].expr); 
        printf("Polish Entry: %s\n", pe); 
        int r = evaluatePolishEntry(pe);
        printf("Evaluate: %d\n", r);
        printf("Result: %s\n\n", (list[i].result == r ? "Ok" : "Fail"));
        
    }
    
    delete[] list;
    
    return 0;
}