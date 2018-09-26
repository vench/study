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
public class Task1 extends AbTask {
    
    /**
     * 
     * @return 
     */
    @Override
    public String getTitle() {
        return "Напишите программу, которая вводит три int числа, "
                + "сортирует их по возрастанию и выводит на экран. "
                + "\nИспользуйте не больше трёх простых if. "
                + "\nМассивы и прочие коллекции, а также else, &&, || и другие усложняющие конструкции не применять.";
    }
    
    @Override
    public void run() {
       int[] ar = new int[3];
       for(int i = 0; i < ar.length; i ++) {
           System.out.println("Введите пожалуйста число №" + i + ": ");
           ar[i] = readInt();
       }
       
       System.out.println("Вы ввели:"); 
       printArray(ar);
       sort(ar);
       System.out.println("После сортировки:"); 
       printArray(ar); 
    }
    
    
    private void printArray(int[] ar) {
       System.out.print("[");
       for(int i = 0; i < ar.length; i ++) {
           if(i > 0) {
               System.out.print(", ");
           }
           System.out.print(ar[i]);
       }
       System.out.print("]\n"); 
    }
    
    private void sort(int[] ar) {
        for(int i = 0; i < ar.length; i ++) {
            for(int j = i + 1; j < ar.length; j ++) {
                if(ar[i] > ar[j]) {
                    int tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp; 
                }
            }
        }
    }
    
    
}
