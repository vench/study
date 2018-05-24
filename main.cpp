//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,

 
//#include <stdexcept>
#include <iostream>
#include "MyString.h"
#include "ArrayStack.h"
#include "ListStack.h"
#include "StackException.h"
#include "ArrayQueue.h"

#define stop __asm nop

#include "lib.h"

int main(int argc, char* argv[])
{
	


////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.
       
	int iX = 1, iY = -1;
	Swap(iX, iY);
        std::cout <<  "iX: " << iX << ", iY: "  << iY << "\n";

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
        std::cout <<  "dX: " << dX << ", dY: "  << dY << "\n";


	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
        //TODO
	Swap(str1, str2);
        std::cout <<  "str1: " << str1 << ", str2: "  << str2 << "\n";

/**/
/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]



        {
        
            ArrayStack<int> iStack(5);
            //throw
            try {
                iStack.push(10);
                iStack.push(102);
                iStack.push(110);
                iStack.push(1440);
                iStack.push(110);
                iStack.push(11);
            } catch(StackException e) {
               std::cout << "Exception: " <<  e.what() << std::endl;
            } 
            
            //readn value
            int n = iStack[2]; //=110
            std::cout << "int n = iStack[2] => "  << n << std::endl;
            
            while(!iStack.isEmpty()) { 
                std::cout << "iStack: " << iStack.pop() << std::endl;
            }
            
            //throw
            try {
                iStack.pop() ;
            } catch(StackException e) {
               std::cout << "Exception: " <<  e.what() << std::endl;
            }    
            
            
            //str
            ArrayStack<MyString> strStack(10); 
            strStack.push(MyString("test"));
            strStack.push(MyString("abc"));
            strStack.push(MyString("test2"));
            strStack.push(MyString("test3"));
            strStack.push(MyString("test4"));
            strStack.push(MyString("test5"));
            strStack.push(MyString("test6"));
            strStack.push(MyString("test7"));
            strStack.push(MyString("test8"));
            strStack.push(MyString("test9"));
            
            while(!strStack.isEmpty()) { 
                std::cout << "strStack: " << strStack.pop() << std::endl;
            }
            
        }




	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь


        {
            std::cout << "\n\n============\nList stack" << std::endl;
            ListStack<int> iStack;
            iStack.push(123);
            iStack.push(12324);
            iStack.push(1235);
            std::cout << "iStack.pop() == 1235; " << iStack.pop() << std::endl;
            //std::cout << "iStack.pop() == 12324; " << iStack.pop() << std::endl;
            
            while(!iStack.isEmpty()) { 
                std::cout << "iStack: " << iStack.pop() << std::endl;
            }
            
            iStack.push(1);
            iStack.push(2);
            iStack.push(3);
            iStack.push(4);
            iStack.push(5);
            
            ListStack<int> iStack2 = iStack;
            
            while(!iStack.isEmpty()) { 
                std::cout << "iStack: " << iStack.pop() << std::endl;
            }
            
            iStack2.reverse();
            
            while(!iStack2.isEmpty()) { 
                std::cout << "iStack2: " << iStack2.pop() << std::endl;
            }
        }



	//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
	//для хранения элементов использовался динамический массив.
	//При использовании массива следует учесть специфику очереди, то есть
	//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
	//=> должен быть организован кольцевой буфер
        
        {
        
            ArrayQueue<int> q(3);
            q.push(123);
            q.push(456);
            q.push(789);
            
            
            std::cout << "Pop() = 123; " << q.pop() << std::endl;
            
            q.push(7892);
            q.push(78921);
            
            while(!q.isEmpty()) { 
                std::cout << "q: " << q.pop() << std::endl;
            }
        }

	return 0;
}

