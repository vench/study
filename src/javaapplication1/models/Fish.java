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
public class Fish extends Animal {
    
    public Fish(String name) {
        super(name);
    }

    @Override
    public String moves() {
        return "swim";
    }

    @Override
    public String sound() {
         return "nothing";
    }

    
    
}
