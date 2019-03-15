/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modules;

import javax.ejb.Stateless;

/**
 *
 * @author vench
 */
@Stateless
public class HelloWorldBean implements IHelloWorld
{
    @Override
    public String sayHello(String name) {
        return String.format("Hello %s, welcome to EJB 3.1!", name);
    }
}