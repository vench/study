#include "func.h"

//
void test(void) {
       
        std::cout << "Test..." << std::endl;
        /*
        float A[] = {
                2,0,0,0,0,0,0,1,3,
		9,2,1,0,0,0,0,1,3,
		1,0,2,1,0,0,0,1,3,
		1,0,2,1,0,0,0,1,2,
		0,0,0,1,5,0,0,1,1,
		0,0,0,7,6,3,0,1,1,
		0,0,0,0,0,7,3,1,5,
		0,0,0,0,0,7,2,1,6,
		0,0,0,7,0,0,7,1,7
                }; */
        /*float A[] = {
                3,      3,      -1, 2,
		4,      1,       3, 0,
		1,     -2,      -2, 5,
		1,     -2,      -1, 5
                };
        */
        float A[] = { 
                1,1,3,
                1,1,3,
                1,1,3,
                };
        int s= 3;
       std::cout << det(A, s) << " ok: "  << std::endl;
       
       
       M a(A, s,s);
       M z = a+2;
       std::cout << a[1][1] << " - "  << z.det()  <<  " " << std::endl;
       std::cout << "" << std::endl;
       rang(A, s, s);
}

//
void printSq(float *A, int n) {
        
        for(int i = 0; i < n; i ++) {
                std::cout << "\n";
                for(int j = 0; j < n; j ++) {
                        std::cout << A[i*n+j] << ", ";
                }
        }
        std::cout << "\n";
}


//
int rang(float *A, int n, int m) {
        int r = n < m ? m : n;
        for(int i = 1; i < n; i ++) {
                for(int j = 0; j < i; j ++) {
                        int index = i * m + j;
                        if(A [index] == 0) { // TODO ?
                                continue;
                        } 
                        float x = ZERO;
                        int z;
                        for(z = j; z < n; z ++) {
                                int ind = z * m + j;
                                if(z == i || A[ind] == 0) {
                                        continue;
                                }
                                x = - A[index] / A[ind];
                                break;
                        }
                        if (x != ZERO) {
                              for(int w = 0; w < m; w ++) {
                                        int ind = z * m + w;
                                        int ind1 = i * m + w;
                                        A[ind1] += x * A[ind];
                              }  
                             // std::cout  << "X: " << x  << std::endl;
                             // printSq(A, n);
                             r --;   
                        }
                }
              // 
              
        }
        
        
        
        
        return r;
}

//
float det1(float *A, int n) {
        if(n != 3) {
                return ZERO;
        }
        float p=ZERO,m = ZERO, pa,pm;
        int ia,im;
        for(int i = 0; i < n; i ++) {
                pa = ZERO;
                pm = ZERO;
                for(int j = 0; j < n; j ++) {
                        ia = j * n + ((j+i)%n);
                        im = j * n + ((n-1-j-i+n)%n); 
                        if(j == 0) {
                                pa = A[ia];
                                pm = -A[im];
                        } else {
                                pa *= A[ia];
                                pm *= A[im];
                        }                           
                }
                p += pa;
                m -= pm;
        }
        
        return p - m;
}

//
float det(float *A, int n) {
      //printSq(A, n)  ;
      if( n < 1) {
                return 0;
      } 
      if( n == 1) {
                return A[0];
      } 
      
      if(n == 2) {
               return A[0] * A[3] - A[1] * A[2];
      }
      
      int d = 0;
      for(int i = 0; i < n; i ++) {
        float s[(n-1)*(n-1)];
        int len = 0;
        for(int y = 1; y < n; y ++) { 
                for(int x = 0; x < n; x ++) {
                        if(i == x) {
                                continue;
                        }
                        s[len] = A[y*n+x];
                        len ++;
                }
        }  
        if((i & 0x01) > 0)     
                d -= A[i] * det(s, n-1);
        else 
                d += A[i] * det(s, n-1);        
      }
      
      
      return d;
} 
