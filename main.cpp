 // Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


// #include <tchar.h>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "myRect.h"
#include "Bytes.h"

using namespace std;

#define	  stop 

int main(int argc, char* argv[])
{

        std::cout << "Ok\n";


	//Задание 1.Простое наследование.Аргументы конструктора,
	// передаваемые в базовый класс.

	//Создайте иерархию классов:
	//базовый класс Shape (который описывает любую фигуру)
	//и два производных класса Rect и Circle.
	//Подумайте: какие данные и методы нужно ввести в базовый
	//и производные классы (например, любую фигуру можно сделать
	//цветной => в базовом классе можно ввести переменную, которая
	//будет определять цвет фигуры.
	//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);

	//** только цвет
        {
            Circle c(0,0,10, Shape::BLUE);
            std::cout << c.getColor() << "\n";
	

            Rect r(0,0,10, 10, Shape::GREEN);
            std::cout << r.getColor() << "\n";
            
            //Конструктор - вначале вызов родителя, затем производного класса
            //деструкторы - вначале вызов производного класса, затем родителя
	}
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
	



	stop
//////////////////////////////////////////////////////////////////////

	//Задание 2.Виртуальные функции.
	//2а) Модифицируйте классы Shape,Rect и Circle:
	//добавьте в каждый класс public метод void WhereAmI().
	//Реализация каждой функции должна выводить сообщение 
	//следующего вида "Now I am in class Shape(Rect или Circle)".
	//Выполните приведенный фрагмент, объясните результат.

        {
        
        		Shape s;
		Rect r(0,0,10,10);
		Circle c;

	
		//Метод какого класса вызывается в следующих строчках???
		s.WhereAmI();	//	Now I am in class Shape
		r.WhereAmI();	//	Now I am in class Rect
		c.WhereAmI();	//	Now I am in class Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
                pShape->WhereAmI();	//	Now I am in class Shape
		pRect->WhereAmI();	//	Now I am in class Shape
		pCircle->WhereAmI(); //	Now I am in class Shape
//		stop


		//Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
   		Shape& rRect = r; //псевдоним r
   		Shape& rCircle = c; //псевдоним c
        	rShape.WhereAmI();	//вызов посредством rShape	Now I am in class Shape
                rRect.WhereAmI(); //Now I am in class Shape
                rCircle.WhereAmI(); //Now I am in class Shape
    		static_cast<Rect*>(&rRect)->WhereAmI();	//вызов посредством	rRect	Now I am in class Rect
    		static_cast<Circle*>(&rCircle)->WhereAmI(); //вызов посредством rCircle	Now I am in class Circle
		stop
        
        }
                
	//2б) Сделайте метод WhereAmI() виртуальным.
	//Снова выполните приведенный фрагмент, объясните разницу.

	{
            
            std::cout << "virtual";
 		Shape s;
		Rect r(0,0,10,10);
		Circle c;

	
		//Метод какого класса вызывается в следующих строчках???
		s.WhereAmI();	//	Now I am in class Shape
		r.WhereAmI();	//	Now I am in class Rect
		c.WhereAmI();	//	Now I am in class Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
                pShape->WhereAmI();	//	Now I am in class Shape
		pRect->WhereAmI();	//	Now I am in class Rect
		pCircle->WhereAmI(); //	Now I am in class Circle
//		stop


		//Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
   		Shape& rRect = r; //псевдоним r
   		Shape& rCircle = c; //псевдоним c
        	rShape.WhereAmI();	//вызов посредством rShape	Now I am in class Shape
                rRect.WhereAmI(); //Now I am in class Rect
                rCircle.WhereAmI(); //Now I am in class Circle
    		static_cast<Rect*>(&rRect)->WhereAmI();	//вызов посредством	rRect	Now I am in class Rect
    		static_cast<Circle*>(&rCircle)->WhereAmI(); //вызов посредством rCircle	Now I am in class Circle
		stop
                
                //Разница в том что CPP строит таблицу методов, виртуальные методы встают в начало и вызываются первыми
	}
        
        
/**/

//////////////////////////////////////////////////////////////////////

	//Задание 3.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.
        
        {
            std::cout << "Rect show destructor:\n";
            Rect r(10,10,100,100);
            
        }
        std::cout << "End Rect show destructor;\n";

        /*Rect show destructor:
Now I am in Rect's destructor!
Now I am in Shape's destructor!
End Rect show destructor;
*/
        
	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу.

	
	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

        {
                std::cout << "2 Rect show destructor:\n";
		Rect r(10,10,100,100);
        }        
        std::cout << "2 End Rect show destructor;\n";
        
        /* 2 Rect show destructor:
Now I am in Rect's destructor!
Now I am in Shape's destructor!
2 End Rect show destructor;
         * Разницы нет?!
*/
        {
            Rect r(10,10,100,100);
            Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
            
            for (int i = 0; i < 4; i ++) { 
                ar[i]->WhereAmI(); 
                delete ar[i];
            } 
            
            
            
             
            
            /*Now I am in class Shape 
Now I am in class Rect 
Now I am in class Circle 
Now I am in class Circle
*/
            
            
        }
		///Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//Вызовите для каждого элемента массива метод WhereAmI()
	

	stop
/**/


	//Задание 4*. В чем заключается отличие 1) и 2)
	{
            
            
            std::cout << "TODO!!!\n";
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//Попробуйте вызвать метод WhereAmI() для каждого элемента обоих массивов -
		//в чем заключается проблема???
                
                for(int i = 0; i < 10; i ++) {
                    (static_cast<Rect*>(pShapes) + i) ->WhereAmI(); //Now I am in class Shape *(если убрать слово virtual)
                    //Если не убирать, то будет Now I am in class Rect

                    pRects[i].WhereAmI();//Now I am in class Rect

                }
                //Причина в создании таблицы адресов функций, если метод объявлен вирутальный, и он реализован в 
                //потомке то он добавляется первым в табл методов, иначе берется объект метод родителя


		//Освободите динамически захваченную память
                delete[] pRects, pShapes;

	}

/**/

//////////////////////////////////////////////////////////////////////

	//Задание 5.Виртуальные функции и оператор разрешения области видимости. 

	{
		Rect r(0,0,10,10);
		Shape* p = &r;	
		p->WhereAmI();//Now I am in class Rect

		stop
	
		
		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmI()класса Shape
		p->Shape::WhereAmI(); //Now I am in class Shape 
	}
/**/

//////////////////////////////////////////////////////////////////////

	//Задание 6.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	{
		Rect r(0,0,0,0);
		Shape* p = &r;
		p->Inflate(5);
		Circle c;
		p = &c;
		p->Inflate(5);
                
                //В базовый класс Shape Inflate  добавил virtual void Inflate(int)
	}
/**/

//////////////////////////////////////////////////////////////////////

	//Задание 7.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;
        {
            Bytes byte(0x0b); // 0x0b - 11
            byte.ShowChar();
            byte.ShowDec();
          
            byte.ShowBin();
            byte.ShowOct();
            byte.ShowHex();
	
            
            byte.ShowBinPos(2);
            byte.ShowOctPos(1);
            byte.ShowHexnPos(1);
            
            //
            byte.EditBin(2, 0); //11 - 2
            byte.ShowDec();
            byte.ShowBin();
                        
            //
            byte.EditOct(2, 0); //9 - 8
            byte.ShowDec();
            byte.ShowOct();
            
            //
            byte.EditHex(2, 1);//1 + 16
            byte.ShowDec();
            byte.ShowHex();
        }

/**/


	
	return 0;
}//endmain


