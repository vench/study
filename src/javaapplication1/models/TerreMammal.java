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
public class TerreMammal extends Mammal {

    public TerreMammal(String name, String sound) {
        super(name, sound);
    }
    
     public TerreMammal(String name) {
        super(name);
    }
    
    @Override
    public String moves() {
        return "run";
    } 
    
}
