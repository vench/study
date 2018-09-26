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
public abstract class Animal { 
    
    protected String name;
    
     public Animal(String name) {
         this.name = name;
     }
     
     public abstract String moves();
     public abstract String sound();
     
     /**
      * 
      * @return 
      */
     public String output() {
         return "Animal{name:" + this.name + ", class: " +this.getClass().getName()+ "}";
     }
}
