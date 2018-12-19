#include "func.h"

//
void test(void) {
       
        std::cout << "Test..." << std::endl;
        
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
                };
        
    
       std::cout << det(A, 9) << " ok: "  << std::endl;
       
       int s= 9;
       M a(A, s,s);
      // M z = a+1;
       std::cout << a[1][0]  << std::endl;
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
int det(float *A, int n) {
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
