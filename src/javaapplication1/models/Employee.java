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
public class Employee {
    
    
    private static int IdCounter = 0;
    
    int idNumber;
    String name;
    EmployeePosition position;
    int salary;

    /**
     * 
     * @param name
     * @param position
     * @param salary 
     */
    public Employee( String name, EmployeePosition position, int salary) {
        this.idNumber = ++ IdCounter;
        this.name = name;
        this.position = position;
        this.salary = salary;
    }
    
    /**
     * 
     * @param name 
     */
    public Employee( String name) {
        this(name, EmployeePosition.WORKER, 5000);
    }
    
    /**
     * 
     * @param name
     * @param position 
     */
    public Employee( String name, EmployeePosition position) {
         this(name, position, position == EmployeePosition.WORKER ? 5000 : 6000);        
    }
    
    
    @Override
    public String toString() {
        return "Employee{ID:"+idNumber+", Name: "+name+", Position: "+position.getName()+", Salary: "+salary+"}";
    }
    
    
    /**
     * 
     * @param list 
     */
    public static void printArray(Employee[] list) {
        int sum = 0;
        Employee max = null;
        for (Employee item : list) {
            System.out.println(item);
            sum += item.salary;
            
            if(max == null || max.salary < item.salary) {
                max = item;
            }
        }
        
        System.out.printf("Суммарная зарплата %d, должность(position): %s\n", sum, max.position.getName());
    }
}
