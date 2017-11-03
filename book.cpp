/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "book.h"

const char *FILE_NAME  = "/home/vench/dev/books.db";



/**
 * 
 * @param pCard
 */
void addBook(CARD_INDEX *pCard) {
    printf("Add new Book!\n");
    
    
    BOOK *pb = new BOOK();
    printf("Enter author name[30 max]:\n");
    scanf("%s[^\n]%*c", &(*pb).author[0]); 
   
    fflush(stdin);
    printf("Enter book title[80 max]:\n");
    scanf("%s[^\n]%*c", &(*pb).name[0]);
    fflush(stdin); 
    
    printf("Enter year:\n"); 
    int y;
    scanf("%d[^\n]%*c", &y);
    pb->year = y;
  
    //TODO check year
    printf("Enter category (PROSE: 1, POESY: 2 , SCIENCE: 3):\n");
    int cat;
    scanf("%d[^\n]%*c", &cat);
    pb->category =  (eCategory)cat; 
    printf("Enter price:\n");
    scanf("%f[^\n]%*c", &(*pb).price); 
    
    addBook(pCard, pb); 
    showAllBook(pCard);
}

/**
 * 
 * @param pb
 */
void sortBOOK(CARD_INDEX *pCard) {
    printf("Sort book (Name: 1, Author: 2, Category: 3, Year: 4, Price: 5)#:\n");
     
    int type = 0;
    scanf("%d", &type);
    fflush(stdin); 
    printf("You enter: %d\n", type);   
    
    for(int i = 0; i < pCard->count; i ++ ) {
        for(int j = i + 1; j < pCard->count; j ++ ) {
            if(cmpBOOKByType(pCard->pB[i], pCard->pB[j], (eSortType)type) > 0) {
                BOOK *temp = pCard->pB[i];
                pCard->pB[i] = pCard->pB[j];
                pCard->pB[j] = temp;
                temp = NULL;
            }
        } 
    }
    showAllBook(pCard);
}

/**
 * 
 * @param pb1
 * @param pb2
 * @param type
 * @return 
 */
int cmpBOOKByType(BOOK *pb1, BOOK *pb2, eSortType type) {
    switch(type) {
        case SORT_BY_YEAR: 
            return pb1->year - pb2->year;
        case SORT_BY_PRICE:
            return (int)(pb1->price - pb2->price);
        case SORT_BY_CATEGORY:
            return (int)(pb1->category - pb2->category);
        case SORT_BY_TITLE:
            return strcmp(pb1->name, pb2->name);
        case SORT_BY_AUTHOR:
            return strcmp(pb1->author, pb2->author);
    }
    return 0;
}

 

/**
 * 
 * @param pCard
 * @param pb
 */
void addBook(CARD_INDEX *pCard, BOOK *pb) {
    if (pCard->count >= pCard->cap)  {
        //перераспределяем память   
        pCard->cap *= 2;
        BOOK **ppb = new BOOK*[pCard->cap];
        
        for(int i = 0; i < pCard->count; i ++) {
            ppb[i] = pCard->pB[i];
        }
        
        delete[] pCard->pB;
        pCard->pB = ppb; 
    }
    
    pCard->pB[pCard->count++] = pb;
}

/**
 * s
 */
void help() {
    printf("Wellcome to the Book list!\n");
    printf("List commands: \n");
    printf("Help: [%d]\n", C_HELP);
    printf("Show all books: [%d]\n", C_SHOW_ALL);
    printf("Add book: [%d]\n", C_ADD_NEW);
    printf("Remove book: [%d]\n", C_REMOVE);
    printf("Save to file: [%d]\n", C_FILE_SAVE);
    printf("Load from file: [%d]\n", C_FILE_LOAD);
    printf("Sort: [%d]\n", C_SORT);
    printf("Exit: [%d]\n", C_EXIT);
}

/**
 * 
 * @param pCard
 */ 
void showAllBook(CARD_INDEX *pCard) {
    const char* hl = "|---------------|---------------|---------------|---------------|---------------|---------------|\n";
    printf("Show All Book: count: %d; cap: %d\n", pCard->count, pCard->cap); 
    printf("%s", hl);
    printf("|\t#\t|\tName\t|\tAuthor\t|\tCateg\t|\tPrice\t|\tYear\t|\n");
    printf("%s", hl);
    
    for(int i = 0; i < pCard->count; i ++ ) {
        
        BOOK * pb = pCard->pB[i];
        printf("|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%4.2f\t|\t%hu\t|\n", 
            i, pb->name, pb->author, GetCategoryName(pb->category),  pb->price, pb->year);
        
        printf("%s", hl);
    }
}

/**
 * 
 * @param pCard
 */
void removeBook(CARD_INDEX *pCard) {
    printf("Enter book #:\n");
    int id = 0;
    scanf("%d", &id);
    fflush(stdin); 
    printf("You enter: %d\n", id);
    if (id && id < pCard->count) {
        delete pCard->pB[id];
        pCard->pB[id] = NULL;
        for(int i = id + 1; i < pCard->count; i ++ ) {
            pCard->pB[i - 1] = pCard->pB[i]; 
            pCard->pB[i] = NULL;
        }
        pCard->count --;
    } 
    
    showAllBook(pCard); 
}

/**
 * 
 * @param pCard
 */
void removeAllBook(CARD_INDEX *pCard) {
    if (pCard->count > 0) { 
        for(int i = 0; i < pCard->count; i ++ ) { 
            delete pCard->pB[i];
            pCard->pB[i] = NULL;
        }
        pCard->count = 0;
    } 
}

/**
 * 
 * @param pCard
 */
void saveBook(CARD_INDEX *pCard) {
    printf("Save Book\n"); 

   FILE * pFile = fopen (FILE_NAME, "wb");
   if (!pFile) {
       printf("Error open file: %s\n", FILE_NAME);
       return;
   }
       
   for(int i = 0; i < pCard->count; i ++ ) {
        BOOK * pb = pCard->pB[i];   
        fwrite(pb, sizeof(BOOK), 1, pFile);  
    }
   
   fclose (pFile); 
   pFile = NULL;
}

/**
 */
void loadBook(CARD_INDEX *pCard) {
    printf("Load book\n");
    //TODO free old data
    removeAllBook(pCard);
    FILE * pFile = fopen (FILE_NAME, "r");
    if (!pFile) {
       printf("Error open file : %s\n", FILE_NAME);
       return;
    }   
    
    int read;
     
    while(true) {
        BOOK *pb = new BOOK;         
        read = fread (pb , sizeof(BOOK), 1, pFile);
        if(!read) {
            delete pb;
            pb = NULL; 
            break;
        }
       // printBOOK(pb);
        addBook(pCard, pb); 
        pb = NULL; 
    } 
    
    fclose (pFile); 
   pFile = NULL; 
   showAllBook(pCard);
}

void printBOOK(BOOK *pb) {
    printf("BOOK{\n\tTitle: %s,\n\tCategory: %d,\n\tAuthor: %s,\n\tPrice: %4.2f,\n\tYear: %hu, \n}\n", 
            pb->name, pb->category, pb->author, pb->price, pb->year);
}


const char *GetCategoryName(eCategory c) {
    switch(c){
        case PROSE:
            return "PROSE";
        case POESY:
            return "POESY";
        case SCIENCE:
            return "SCIENCE";    
    }
    return "UNDEF";
}

 