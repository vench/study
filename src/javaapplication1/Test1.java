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
public class Test1 implements java.lang.Cloneable {
    Object getCopy(Test1 obj) throws CloneNotSupportedException {
        if(obj != null && obj instanceof java.lang.Cloneable) {
            return obj.clone();
        }
        return null;
    }
}
