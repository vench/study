/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;


import javaapplication1.models.Employee;
import javaapplication1.models.EmployeePosition;

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
            new Employee("Женя", EmployeePosition.PROGRAMMER),
            new Employee("Аня", EmployeePosition.WORKER),
            new Employee("Юля", EmployeePosition.PROGRAMMER, 10000),
            new Employee("Петя", EmployeePosition.PROGRAMMER),
            new Employee("Дима", EmployeePosition.PROGRAMMER),
            new Employee("Гоша", EmployeePosition.WORKER),
            new Employee("Поля", EmployeePosition.PROGRAMMER),
            new Employee("Глаша", EmployeePosition.PROGRAMMER, 9000)
        }; 
    
        Employee.printArray(list);
    }
    
}
