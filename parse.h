/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    O_MULT  = '*'
};


struct Stack{
	char m_ar[100];	//встроенный массив, который будем использовать как стек
	int m_i;	//индекс первого свободного элемента в стеке
};

struct StackX{
	int m_ar[100];	//встроенный массив, который будем использовать как стек
	int m_i;	//индекс первого свободного элемента в стеке
};


Stack* InitStack();// инициализация стека
bool push(Stack*s, const char c);// поместить новый элемент на верхушку стека
const char  pop(Stack*s);// извлечь элемент с верхушки стека
bool StackEmpty(Stack*s);// проверка – пуст ли стек

StackX* InitStackX();// инициализация стека
bool pushX(StackX*s, int c);// поместить новый элемент на верхушку стека
int  popX(StackX*s);// извлечь элемент с верхушки стека
bool StackEmptyX(StackX*s);// проверка – пуст ли стек


const char* makePolishEntry(const char* input); 
int evaluatePolishEntry(const char* input);
int evaluateMatch(int a, int b, char operation);

bool isInt( char c);
bool isOperation( char c);
bool isClosedBracket( char c);

int charToInt(char c); 

#endif /* PARSE_H */

