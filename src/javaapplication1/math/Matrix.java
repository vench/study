/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1.math;

import java.io.IOException;
import java.io.Writer;
import java.io.Reader;
import java.nio.CharBuffer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 */
public class Matrix {
    
    private double[] data;
    private int nRows;
    private int nCols;
    
    /**
     * 
     * @param nRows
     * @param nCols
     * @throws MatrixException 
     */
    public Matrix(int nRows, int nCols) throws MatrixException {
            if(nRows + nCols == 0) {
                throw new MatrixException("initData is empty");
            } 
            this.nRows = nRows;    
            this.nCols = nCols;
            this.data = new double[nRows * nCols]; 
    }
    
    /**
     * 
     * @param initData
     * @throws MatrixException 
     */
    public Matrix(double[][] initData) throws MatrixException {     
        this(initData.length, initData[0].length);    
        for(int i = 0; i < nRows; i ++) {
            System.arraycopy(initData[i], 0, this.data, i*nCols, nCols);
        }
    }
    
    /**
     * 
     * @param i
     * @param j
     * @param value 
     */
    public void set(int i, int j, double value) {
        this.data[i * nCols + j] = value; 
    }
    
    /**
     * 
     * @param i
     * @param j
     * @return 
     */
    public double get(int i, int j) {
        return this.data[i * nCols + j];
    }
    
    /**
     * add (сумма двух матриц). Можно складывать матрицы только одинакового размера. 
     * Сумма двух матриц дает матрицу. 
     * При попытке сложить матрицы разных размеров генерируется пользовательское exception;
     *      
     * @param m
     * @return 
     * @throws javaapplication1.math.MatrixException 
     */
    public Matrix add(Matrix m) throws MatrixException {
        try {
            if(m.nCols != this.nCols || m.nRows != this.nRows) {
                throw new MatrixException("Error matrix dimension");
            }
            Matrix n = this.clone();
            for(int i = 0; i < m.data.length; i ++) {
                n.data[i] += m.data[i];
            }
            return n;
        } catch (CloneNotSupportedException ex) {
            Logger.getLogger(Matrix.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }
    
    
    
    /**
     *  output – вывод матрицы на экран; 
     * @return 
     */
    public String output() {
        StringBuilder bf = new StringBuilder();
        bf.append("M: [");
        bf.append(nRows);
        bf.append("x");
        bf.append(nCols);
        bf.append("] (\n");
        for(int i = 0; i < nRows; i ++) {
            for(int j = 0; j < nCols; j ++) {
                bf.append(get(i, j));
                bf.append(" ");
            }
            bf.append("\n");
        }
        bf.append(")\n");
        return bf.toString();
    }
    
    /**
     * read (Читает матрицу из текстового файла); 
     * @param r
     * @return 
     * @throws java.io.IOException 
     */
    public static Matrix read(Reader r) throws IOException {
        CharBuffer cb = CharBuffer.allocate(18);
        StringBuilder bf = new StringBuilder();
        while(r.read(cb) > 0) {
            cb.flip();
            bf.append(cb);
        } 
        //TODO parse
        System.out.println(">>>"); 
        System.out.println(bf.toString());
        return null;
    }
    
    /**
     * write (Записывает матрицу в текстовый файл)
     * @param w
     * @throws java.io.IOException
     */
    public void write(Writer w) throws IOException {
        w.write(this.output());
    }
    
    /**
     * 
     * @param m
     * @return 
     */
    public boolean equal(Matrix m) {
        return false;
    }
    
    /**
     *
     * @return
     * @throws CloneNotSupportedException
     */
    @Override
    public Matrix clone() throws CloneNotSupportedException {
        try {
            Matrix m = new Matrix(nRows, nCols);
            System.arraycopy(data, 0, m.data, 0, data.length);
            return m;
        } catch (MatrixException ex) {
            Logger.getLogger(Matrix.class.getName()).log(Level.SEVERE, null, ex);
        }
        throw new CloneNotSupportedException("Error create Matrix");
    }
}
