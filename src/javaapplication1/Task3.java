/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;


import javaapplication1.models.Employee; 

/**
 *
 * @author vench
 */
public class Task3 implements Task {

    @Override
    public String getTitle() {
        return "Напишите программу, которая создает массив из 10 Employees, "
                + "\nпередавая различное число параметров конструктору. "
                + "\nЗатем с помощью вызова статических функций класса Employee распечатывает всех Employees на экране, рассчитывает суммарную зарплату Employees и печатает position с наибольшей зарплатой";
    }

    @Override
    public void run() {
        
        Employee[] list = {
            new Employee("Вася"),
            new Employee("Инна"),
            new Employee("Женя", "PROGRAMMER"),
            new Employee("Аня", "WORKER"),
            new Employee("Юля", "PROGRAMMER", 10000),
            new Employee("Петя", "PROGRAMMER"),
            new Employee("Дима", "PROGRAMMER"),
            new Employee("Гоша", "WORKER"),
            new Employee("Поля", "PROGRAMMER"),
            new Employee("Глаша", "PROGRAMMER", 9000)
        }; 
    
        Employee.printArray(list);
    }
    
}
