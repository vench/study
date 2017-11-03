

#include "other.h"

///////////////////////////////////////////////////


int val = 99;
 int &refVal = val;

//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1, ... )
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов


        int *pa = &arg1;
        int s = sizeof(int);
        pa += 7;
        while(*pa != 0) {
            
            number ++;
            std::cout << "Z arg #" << number << ", val = " << *pa   << "\n";
            pa += 2;
        } 

	//Печать числа элементов
        std::cout << "number = " << number << "\n";

}



void VarArgs2(int arg1,...) {
    
    va_list p;
    va_start(p, arg1);
    
    
    int val = arg1, number = 0;
    
    do {
        number ++;
        std::cout << "M: arg #" << number << ", val = " << val  << "\n";
        val = va_arg(p, int);
    } while(val != 0);
    
    std::cout << "number = " << number << "\n";
    va_end(p);
}

/**/


int IncByValue(int a) {
    a ++;
    return a;
}
void IncByPointer(int *a) {
    (*a) ++;
}
void IncByReference(int &a) {
    a ++;
}



void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}



int Min(int a[N][M]) {
    int *p = &a[0][0];
     return 1;//_Min((*p), N , M);
} 

int Min(int **pa, int rows, int cols) { 
    
    
    
    return _Min(pa, rows , cols);
}

int _Min(int **p, int rows , int cols) {
    int m = p[0][0];
    for(int i = 0; i < rows; i ++) {
        
        for(int j = 0; j < cols; j ++) {
            if(p[i][j] < m) {
                m = p[i][j];
            }
        } 
    }
    return m;
}



int MyStrCmp(const char* a, const char* b) {
   /* while(*a && *b && *a == *b)
    {a++;
    b++;
    }
    return *a - *b;
    //AAA\0
    //AAAA\0
    */
    int sa = 0, sb = 0;
    bool end;
    do {
        end = false;
        if(*a != '\0') {
            sa += *a;
            a ++;
            end = true;
        }
        if(*b != '\0') {
            sb += *b;
            b ++;
            end = true;
        }
    }while(end);
    
    return sa == sb ? 0 : (sa < sb ? -1 : 1);
}




int naturalSum(unsigned int n) {
    if(n == 0) {
        return 0;
    }
    return  n + naturalSum(n - 1);
}


int appendAr(int *&ar, int & size, int value) {
    
    for(int i = 0; i < size; i ++) {
        if(ar[i] == value) {
            return size;
        }
    }
    int size_new = size +1;
    
    int *ar_new = new int[size_new];
   // memcpy( ar_new, ar, size * sizeof(int) );
    for(int i = 0; i < size; i ++) {
        ar_new[i] = ar[i];
    }
 
    delete [] ar;
    ar = ar_new;
    
    ar_new[size++] = value;
    
    ar = ar_new; 
    
    return size_new;
}



int* MyMin(int *arNum, int const len) {
    int inx = 0;
    for(int i = 1; i < len; i ++) {
        if(arNum[inx] > arNum[i]) {
            inx = i;
        } 
    }
    return &arNum[inx];  
}


//
int DayOfYear(int day, int month, int year, int nDayTab[][12]) {
    
    int nDayTabIndex = isLeapYear(year) ? 1 : 0,
        dayOfYear = day
    ;
    
    
    
    for(int i = month- 2; i >= 0; i --) {
        dayOfYear += nDayTab[nDayTabIndex][i];
       // std::cout << "dayOfYear+: " <<  nDayTab[nDayTabIndex][i] << "\n";
    }
    
    return dayOfYear;
}


int* DayOfMonth(int dayOfYear, int year, int nDayTab[][12]) {//int &month, int &day
    int * res = new int[2];
    
    int nDayTabIndex = isLeapYear(year) ? 1 : 0,
            i = 0;
    
    while(nDayTab[nDayTabIndex][i] < dayOfYear) {
        dayOfYear -= nDayTab[nDayTabIndex][i];
        i ++;
    }
    
    res[0] = dayOfYear;
    res[1] = i + 1;
    
    
    return res;
}

bool isLeapYear (int y) {
    return (y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0));
}    