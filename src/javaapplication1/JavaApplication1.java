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
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        //Task1 t = new Task1("https://yandex.ru/");
       // t.parse();
        Task2 t = new Task2();
        t.exec();
        
        /*
        if(args.length < 2) {
            System.out.println("Вы должны передать URL страницы");
            return;
        }
         new Task1(args[1]); */
    }
    
    
    
    
    
    
}
