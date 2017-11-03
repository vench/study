

/* 
 * File:   book.h
 * Author: vench
 *
 * Created on 29 октября 2017 г., 19:07
 */


#ifndef BOOK_H

#define BOOK_H

extern const char *FILE_NAME;


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


enum eCategory{ 
    PROSE = 1, 
    POESY = 2, 
    SCIENCE = 3, 
    UNDEF 
};

enum eSortType {
    SORT_BY_TITLE = 1,
    SORT_BY_AUTHOR = 2,
    SORT_BY_CATEGORY = 3,
    SORT_BY_YEAR = 4,
    SORT_BY_PRICE = 5
};

enum  eCommands  {
    C_HELP      = 1,
    C_EXIT      = 10,
    C_SHOW_ALL  = 2,
    C_ADD_NEW   = 3,
    C_REMOVE    = 4,
    C_FILE_SAVE = 5,
    C_FILE_LOAD = 6,
    C_SORT = 7
};

const char *GetCategoryName(eCategory c);

struct BOOK
{
    char author[30];
    //автор
    char name[80];
    //название
    unsigned short year;
    //год издания
    float price;
    //цена
    eCategory category;
    //категория

};


struct CARD_INDEX
{
    BOOK **pB;
    int count;
    int cap;
};



void addBook(CARD_INDEX *pCard);
void addBook(CARD_INDEX *pCard, BOOK *pb);
void showAllBook(CARD_INDEX *pCard);
void removeBook(CARD_INDEX *pCard);
void removeAllBook(CARD_INDEX *pCard);
void saveBook(CARD_INDEX *pCard);
void loadBook(CARD_INDEX *pCard);
void printBOOK(BOOK *pb);
void sortBOOK(CARD_INDEX *pCard);
int cmpBOOKByType(BOOK *pb1, BOOK *pb2, eSortType type); 
void help();   


#endif /* BOOK_H */