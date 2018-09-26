/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1.models;

/**
 *
 * @author vench
 */
public enum EmployeePosition {
    WORKER("WORKER"),
    PROGRAMMER("PROGRAMMER");
    
    private final String name;
    
    private EmployeePosition(String name) {
        this.name = name;
    }
    
    /**
     * 
     * @return 
     */
    public String getName() {
        return this.name;
    }
    
    @Override
    public String toString() {
        return getName();
    }
}
