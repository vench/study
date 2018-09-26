/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import javaapplication1.help.*;

/**
 *
 * @author vench
 */
public class Task2 extends AbTask {

    @Override
    public String getTitle() {
        return "Напишите следующую программу:\n" +
"1. Вводится с клавиатуры целое число\n" +
"2. В соответствии с введенным числом, строится двумерный массив целых чисел такого вида:\n" +
"Количество строчек и столбцов равно введенному числу. Для данной картинки = 6.\n" +
"Внимание! Верхний «треугольник» - это не неиспользующаяся часть прямоугольной матрицы. Его нет в принципе. То есть, например, элемент[0][1] не существует.\n" +
"3. Этот двумерный массив заполняется числами, вводящимися с клавиатуры.\n" +
"4. Массив распечатывается на экране\n" +
"5. Массив передается функции, которая находит элемент, наиболее близкий к 10.\n" +
"6. Программа выводит на экран индекс и значение найденного элемента.";
    }

    @Override
    public void run() { 
        System.out.println("Введите пожалуйста размер массива: ");
        int size = readInt();
        int[][] ar = new int[size][]; 
        for(int i = 0; i < size; i ++) {
            ar[i] = new int[i+1];
        }
         
        printArray(ar);
        
        System.out.println("Заполняем массив");
        //int len = (size*(size + 1)) / 2; 
        for(int i = 0; i < size; i ++) {
            for(int j = 0; j < ar[i].length; j ++) {
                System.out.printf("Вводим элемент для ar[%d][%d]\n", i, j);
                int val = readInt();
                ar[i][j] = val;
            }
        }    
        printArray(ar);
        
        //find
        find(ar, 10);
    }
    
    /**
     * 
     * @param ar
     * @param value 
     */
    private void find(int[][] ar, int value ) {
        SearchIndex2D index = new SearchIndex2D(value);
       
        for(int i = 0; i < ar.length; i ++) {
            for(int j = 0; j < ar[i].length; j ++) {  
                if(index.updateDiff( ar[i][j] )) {
                    index.setIndex(i, j);
                } 
            }
        } 
        
        System.out.printf("Ближнее значение к %d ar[%d][%d] = %d\n", 
                value, index.getI(), index.getJ(), index.getValue(ar));
    }
    
    /**
     * 
     * @param ar 
     */
    private void printArray(int[][] ar) {
        for(int i = 0; i < ar.length; i ++) {
            System.out.print("\n");
            for(int j = 0; j < ar[i].length; j ++) {
                System.out.printf("[%d]", ar[i][j]);
            }
        }
        System.out.print("\n");
    }
    
}
