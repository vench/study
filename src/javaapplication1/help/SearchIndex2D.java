/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1.help;

/**
 *
 * @author vench
 */
public class SearchIndex2D {
    private int i;
    private int j;
    private int val;
    private int diff;
    
    /**
     * 
     * @param val 
     */
    public SearchIndex2D(int val) {
        this.val = val;
        this.diff = Integer.MAX_VALUE;
    }
     
    
    /**
     * 
     * @param i
     * @param j 
     */
    public void setIndex(int i, int j) {
        this.i = i;
        this.j = j;
    }
    
    /**
     * 
     * @param ar
     * @return 
     */
    public int getValue(int[][] ar) {
        return ar[this.i][this.j];
    }
    
    /**
     * 
     * @param value
     * @return 
     */
    public boolean updateDiff(int value) {
        int d = Math.abs(value - this.val);
        if(this.diff > d) {
            this.diff = d;
            return true;
        }
        return false;
    }

    public int getI() {
        return i;
    }

    public void setI(int i) {
        this.i = i;
    }

    public int getJ() {
        return j;
    }

    public void setJ(int j) {
        this.j = j;
    }

    public int getVal() {
        return val;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public int getDiff() {
        return diff;
    }

    public void setDiff(int diff) {
        this.diff = diff;
    }
    
    
    
}
