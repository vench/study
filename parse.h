/* 
 * File:   parse.h
 * Author: vench
 *
 * Created on 3 ноября 2017 г., 12:32
 */

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <string.h>

enum eOperation {
    O_PLUS  = '+',
    O_MINUS = '-',
    O_DIV   = '/',
    O_MULT  = '*',
    O_POW  = '^',
    O_DELIMITER = ' ',
};

struct Stack{
	char m_ar[100];	//встроенный массив, который будем использовать как стек
	int m_i;	//индекс первого свободного элемента в стеке
};

struct StackX{
	int m_ar[100];	//встроенный массив, который будем использовать как стек
	int m_i;	//индекс первого свободного элемента в стеке
};

struct STest {
    const char *expr;
    int result;
};


Stack* InitStack();// инициализация стека
void clear(Stack*s);// инициализация стека 
bool push(Stack*s, const char c);// поместить новый элемент на верхушку стека
const char  pop(Stack*s);// извлечь элемент с верхушки стека
bool StackEmpty(Stack*s);// проверка – пуст ли стек

StackX* InitStackX();// инициализация стека
bool pushX(StackX*s, int c);// поместить новый элемент на верхушку стека
int  popX(StackX*s);// извлечь элемент с верхушки стека
bool StackEmptyX(StackX*s);// проверка – пуст ли стек
int StackReadIntX(StackX*s);//читаем число
const char SeeLast(Stack*s);//смотрим последний символ
 
const char* makePolishEntry(const char* input); 
int evaluatePolishEntry(const char* input);
int evaluateMatch(int a, int b, char operation);

bool isInt( char c);//это число
bool isOperation( char c);//это оператор
bool isClosedBracket( char c);//закрытая скобка
bool isOpenedBracket(const char c);//открытая скобка
bool isIntDelimiter(char c);//это разрыв чисел

int charToInt(char c); //символ в число

char intToChar(int i); //

int intPow(int i, unsigned int p);//

int getOperatorPriority(const char o);//
int runTest();




#endif /* PARSE_H */

