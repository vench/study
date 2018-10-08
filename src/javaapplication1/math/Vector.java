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
        super(1, size);
    }
    
    public Vector(double[] ar) throws MatrixException {
        super(new double[][]{ar});
    }
    
    public void set(int j, double value) {
        super.set(0, j, value);
    }
    
    public double get(int j) {
        return super.get(0, j);
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
        for(int i = 0; i < getCols(); i ++ ) {
            p += (get(i) * v.get(i));
            a += get(i) * get(i);
            b += v.get(i) * v.get(i);
        }
        
        return p / (Math.sqrt(a) * Math.sqrt(b));
    }
}

