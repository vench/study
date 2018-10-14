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
public class Teacher extends AbPerson {
    
    private String degree;
    
    public Teacher(String name) {
        super(name);
    }
    
    public Teacher(String name, String degree) {
        super(name);
        this.degree = degree;
    }
    
    @Override
    public String listData() {
        return "Teacher> name: " + name + ", degree: " + degree;
    }
}
