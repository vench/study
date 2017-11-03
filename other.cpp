
#include "other.h"

//#include "other.h"

///////////////////////////////////////////////////
BOOK globalBOOK;


void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
    int *t1 = reinterpret_cast<int*>(p1);
    int *t2 = reinterpret_cast<int*>(p2);
    
    int t = *t1;
    *t1 = *t2;
    *t2 = t;
    

}

int CmpInt(void* p1, void* p2)
{
	return *(reinterpret_cast<int*>(p1)) > *(reinterpret_cast<int*>(p2)) ? 1 : -1; 
}


void SwapDouble(void* p1, void* p2) {
    double *t1 = reinterpret_cast<double*>(p1);
    double *t2 = reinterpret_cast<double*>(p2);
    
    double t = *t1;
    *t1 = *t2;
    *t2 = t;  
}
int CmpDouble(void* p1, void* p2) {
    return *(reinterpret_cast<double*>(p1)) > *(reinterpret_cast<double*>(p2)) ? 1 : -1; 
}

void SwapStr(void* p1, void* p2) {
     const char** t1 = reinterpret_cast< const char** >(p1);
     const char** t2 = reinterpret_cast< const char** >(p2);
    
    
     //t1 = t2;
     //t2 = temp;
    /* 
      printf("%s\n", t1);
      printf("%s\n", t2);
      
    //const char *t = t1;
    //t1 = t2;
    //t2 = t; 
      
    const char *t1 = *(const char ** )p1;
    const char *t2 = *(const char ** )p2;
      */
     const char **t = t1;
     t1 = t2;
     t2 = t; 
     printf("X: %s\n", t1);
      printf("Y: %s\n", t2);
    
} 
int CmpStr(void* p1, void* p2) { 
    const char* t1 = reinterpret_cast< const char* >(p1);
     const char* t2 = reinterpret_cast< const char* >(p2);
    return strcmp(t1, t2) > 0 ? 1 : -1; 
}




//MATCH

double Match(double a, double b, MatchOperation op) {
    
    double (*func)(double, double);
    switch(op) {
        case PLUS:
            func = &Sum;
            break;
        case MINUS:
            func = &Sub;
            break;
        case DIV:
            func = &Div;
            break;
        case MUL:
            func = &Mul;
            break;
        case POW:
            func = &Pow;
            break;
        default:
            func = &Default;
            break;
    }
    
    return func(a, b);
}

double Sum(double a, double b) {
    return a + b;
}
double Sub(double a, double b) {
    return a - b;
}
double Mul(double a, double b) {
    return a * b;
}
double Div(double a, double b) {
    if(b == 0) {
        return 0; //TODO trow error
    }
    return a / b;
}
double Pow(double a, double b) {
    return pow(a, b); 
}
double Default(double a, double b) {
    return Sum(a, b);
}


//
const char* GetString1() {
    return "GetString1";
}
const char* GetString2() {
    return "GetString2";
}


void printBOOK(BOOK &b) {
    printf("BOOK{\n\tTitle: %s,\n\tCategory: %s,\n\tAuthor: %s,\n\tPrice: %4.2f,\n\tYear: %d, \n}\n", 
            b.title, b.category, b.author, b.price, b.year);
}

void BookSetTitle(BOOK &b, const char *t) {
    fill(b.title, t);
}

void BookSetAuthor(BOOK &b, const char *t) {
    fill(b.author, t);
}
void BookSetCategory(BOOK &b, const char *t) {
    fill(b.category, t);
}


void fill(char (& s)[BOOK_MAX_FIELD_LEN] , const char *t) {
    /*int n= 0;
    while (*t != '\0' && n < BOOK_MAX_FIELD_LEN) {
        s[n ++] = *t;
        t ++;
    }  */ 
    strncpy(&s[0], t, BOOK_MAX_FIELD_LEN);
}


BOOK * makeBook() {
   BOOK *b = new BOOK();
   printf("Enter author name:\n");
   scanf("%255[^\n]%*c", &(*b).author[0]);
   printf("Enter category:\n");
   scanf("%255[^\n]%*c", &(*b).category[0]);
   printf("Enter title:\n");
   scanf("%255[^\n]%*c", &(*b).title[0]);
   printf("Enter year:\n");
   scanf("%d", &(*b).year);
   if(b->year < BOOK_MIN_YEAR) {
       printf("Error: enter year\n");
       b->year = BOOK_MIN_YEAR;
   }
   printf("Enter price:\n");
   scanf("%f", &(*b).price);
   if(b->price < 0) {
       printf("Error: enter year\n");
       b->price = 0;
   }
   
   
   return b;
}
