/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;


import javaapplication1.models.*;

/**
 *
 * @author vench
 */
public class Task4 implements Task {

    @Override
    public String getTitle() {
       return "Напишите программу, создающую заданную иерархию классов и следующие экземпляры:\n" +
"- shark -eagle\n" +
"- whale - dog\n" +
"Также проверьте, как работают заданные функции. Продумайте, какие функции к каким классам отнести.\n" +
"Занесите этих животных в массив и проверьте полиморфизм и динамическое связывание.";
    }

    @Override
    public void run() {
        Animal[] list = {
            new Fish("shark"), 
            new Bird("eagle"), 
            new SeaMammal("whale"), 
            new TerreMammal("dog", "gaf") };
        
        for(Animal item : list) {
            System.out.println();
            System.out.println("\tOutput: " + item.output());
            System.out.println("\tMoves: " + item.moves());
            System.out.println("\tSound: " + item.sound());
        }
    }
    
}
