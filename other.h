
//Прототипы используемых в данном задании функций:


#include <climits>
#include <string.h>
#include <iostream>

#include <cstdarg>

extern int &refVal;

int IncByValue(int a);
void IncByPointer(int *a);
void IncByReference(int &a); 

void Swap(int *a, int *b);
void Swap(int &a, int &b);


int const N = 2, M = 3;

int Min(int a[N][M]);
int Min(int **pa, int rows, int cols);
int _Min(int **p, int rows, int cols);


int MyStrCmp(const char* a, const char* b);


int naturalSum(unsigned int n);

/**
 * 
 * @param ar
 * @param size
 * @param value
 * @return  int new size
 */
int appendAr(int *&ar, int  &size, int value);


/**
 * 
 * @param arg1
 * @param ...
 */
void VarArgs(int arg1,...);

//m
/*
typedef char *va_list;

#define _INTSIZEOF(t) ((sizeof(t)+sizeof(int)-1) & ~(sizeof(int)-1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define va_argx(ap,t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))

#define va_end(ap) (ap = (va_list)0)

*/

void VarArgs2(int arg1,...);






//

int* MyMin(int *arNum, int const len);


//
int DayOfYear(int day, int month, int year, int nDayTab[][12]);
int* DayOfMonth(int dayOfYear, int year, int nDayTab[][12]); 
inline bool isLeapYear (int y);