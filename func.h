#pragma once
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdarg>
#include <math.h>


//
void test(void);
 
//
void printSq(float *A, int n);  
 
// 
float det(float *A, int n); 

//
float det1(float *A, int n);

//
int rang(float *A, int n);

//
class M {
        float *m;
        int cols, rows;
        
        class _row {
                float *m;
                int offset;       
         
         public:       
                float& operator[](int index) {
                        return m[offset + index];
                }
                
                friend M;
        };
        
        _row r;

public:        
        M(){
                m = nullptr;       
        }
        
        M(int size) : M(size, size){
        
        }
        
        M(const M& a)  : M(a.m, a.cols, a.rows) {}
        M( M&& a) {
                m = a.m;
                cols = a.cols;
                rows = a.rows;
        }
        
        M(int c, int r){
                this->cols = c;
                this->rows = r;
                m = new float[cols * rows];       
        } 
        
        M(float *m, int c, int r) : M(c, r) { 
                for(int i = 0; i < rows; i ++) {
                        for(int j = 0; j < cols; j ++) { 
                               this->m[i * cols + j] = m[i * cols + j]; 
                        }
                }
        }
        
        ~M(){
                r.m = nullptr;
                
                if(m) { 
                        delete[] m;
                        m = nullptr;
                }   
        }
        
        M operator *(int a) { 
                M C(*this);
                for(int i = 0; i < cols * rows; i ++) {
                        C.m[i] *= a; 
                }
                return C;
        }
        
        M operator +(int a) { 
                M C(*this);
                for(int i = 0; i < cols * rows; i ++) {
                        C.m[i] += a; 
                }
                return C;
        }
        
        M& operator =(const M& a) { 
                if(m) {
                        delete m;
                }
                cols = a.cols;
                rows = a.rows;
                m = new float(cols * rows); 
                for(int i = 0; i < rows; i ++) {
                        for(int j = 0; j < cols; j ++) {
                               this->m[i * cols + j] = m[i * cols + j];
                        }
                }
                return *this;
        }
        
        M& operator =(const M&& a) { 
                if(m) {
                        delete m;
                }
                m = a.m;
                cols = a.cols;
                rows = a.rows;
                return *this;
        } 
        
        _row& operator[](int index) {
                r.m = m;
                r.offset = index * cols;
                return r;
        }
        
        // methods
        bool isSqure() {
                return cols == rows;
        }
        
        float det() {
                if(!isSqure()) {
                        return 0.0;
                }
                
                return ::det(m, cols);
        }
        
        int rang() {
                if(!isSqure()) {
                        return 0.0;
                }
                
                return ::rang(m, cols);
        }
        
        M& T() {
                // TODO
                return *this;
        }
};

