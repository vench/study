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
public class Student extends AbPerson {
    
    private int age;

    public Student(String name) {
        super(name);
    }
    
    public Student(String name, int age) {
        super(name);
        this.age = age;
    }
    
    @Override
    public String listData() {
        return "Student: name " + name + ", age " + age;
    }
}
