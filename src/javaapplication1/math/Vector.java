/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1.math;

/**
 *
 * @author vench
 * 
 * Разработайте класс Vector. Вектор – это матрица из одной колонки, например: M4 and M7.
 * 
 */
public class Vector extends Matrix {
    
    public Vector(int size) throws MatrixException {
        super(size, 1);
    }
    
    public Vector(double[] ar) throws MatrixException {
        super(transpose(new double[][]{ar}));
    }
    
    public void set(int j, double value) {
        super.set(j, 0, value);
    }
    
    public double get(int j) {
        return super.get( j, 0);
    }
    
    /**
     * Возвращает длину вектора. Length=sqrt(a112+a212+a312+…+an12).
     * @return 
     */
    public double length() {
        double sum = 0.0;
        for(int i = 0; i < getCols(); i ++) {
            sum += get(i);
        }
        return Math.sqrt(sum);
    }
    
    /**
     * 
     * @param v
     * @return 
     */
    public double cos(Vector v) { 
        if(v.getCols() != getCols() || v.getRows() != getRows()) {
            return 0.0;
        }
        double p = 0.0, a = 0.0, b = 0.0;
        for(int i = 0; i < getRows(); i ++ ) {
            p += (get(i) * v.get(i));
            a += get(i) * get(i);
            b += v.get(i) * v.get(i);
        }
        
        return p / (Math.sqrt(a) * Math.sqrt(b));
    }
    
    /**
     * 
     * @param ar
     * @return 
     */
    public static double[][] transpose(double[][] ar) {
        int nRows = ar.length;
        int nCols = nRows > 0 ? ar[0].length : 0;
        double[][] m = new double[nCols][nRows];
        for(int i = 0; i < nRows; i ++) {
                for(int j = 0; j < nCols; j ++) {
                    m[j][i] = ar[i][j];
                }
        }
        return m;
    }
    
    /**
     * 
     * @param m
     * @return
     * @throws MatrixException 
     */
    public Vector matrixToVec(Matrix m) throws MatrixException {
        Vector v = new Vector(m.nRows * m.nCols);
        v.data = m.data;
        return v;
    }
    
    /**
     * 
     * @param m
     * @return
     * @throws MatrixException 
     */ 
    public Vector add(Vector m) throws MatrixException {
        return matrixToVec(super.add(m));
    }
    
}

