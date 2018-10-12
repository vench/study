/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author vench
 */
abstract public class AbPerson {
    
    protected String name;

    public AbPerson(String name) {
        this.name = name;
    }
    
    abstract public String listData();
    
    /**
     * 
     * @return 
     */
    public String toString() {
        return listData();
    }
}
