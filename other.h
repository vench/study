

#include <cmath>
#include <string.h>
#include <cstdio>
#include <iostream>



//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);

void SwapStr(void* p1, void* p2); 
int CmpStr(void* p1, void* p2);


//macth functions

enum MatchOperation {
    MINUS,
    PLUS,
    MUL,
    DIV,
    POW
};


double Match(double, double, MatchOperation);

double Sum(double, double); 
double Sub(double, double);
double Mul(double, double);
double Div(double, double);
double Pow(double, double);
double Default(double, double);


//
const char* GetString1();
const char* GetString2();


const int BOOK_MIN_YEAR = 1600;
const int BOOK_MAX_FIELD_LEN = 256; 

struct BOOK {
    float price; //цена
    int year; //год издания
    char title[BOOK_MAX_FIELD_LEN]; //заглавие
    char author[BOOK_MAX_FIELD_LEN]; //автор
    char category[BOOK_MAX_FIELD_LEN];//категория 
};

void printBOOK(BOOK &b);
void BookSetTitle(BOOK &b, const char *t);
void BookSetAuthor(BOOK &b, const char *t);
void BookSetCategory(BOOK &b, const char *t);
void fill(char (& s)[BOOK_MAX_FIELD_LEN] , const char *);
BOOK * makeBook();

extern BOOK globalBOOK;