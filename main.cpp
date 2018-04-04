#include <iostream>
#include "myRect.h"
#include "myString.h" 

#define stop 

using namespace std;

int main()
{
    
    std::cout << "OK";
    

	//Задание 1.Объявление класса. Создание экземпляра класса.
	//Вызов методов класса. 
	//Откройте закладку Class View - (здесь Вы увидите имена методов и
	//данных - классов Rect и MyString)
	//Обратите внимание на пиктограммы слева от имен членов класса - они
	//обозначают спецификатор доступа к каждому члену класса.

	//Какой конструктор вызывается при создании экземпляра класса?
	{
                //Конструктор по умолчанию, без параметров
		Rect rect;
		stop
	}

	//1a. Объявите и определите конструктор с параметрами для
	//инициализации переменных класса. Создайте экземляры класса Rect
	//с помощью конструктора с параметрами. Если компилятор выдает
	//ошибку в предыдущем фрагменте, подумайте - чего ему не
	//хватает? Добейтесь отсутствия ошибок.
    
        //Если мы определим конструктор с параметрами но не определим конструкторв без 
        //(который сейчас генерится по умолчанию компилятором) то получим ошибку.
        // для устранения ошибки нужно перегрузить конструктор без параметрво
    
	//Выполняя задание с самого начала по шагам, определите:
	//в какой момент происходит вызов конструктора(какого?)?
    
    
        //
        {
            //Конутруктор с параметрами
            Rect rect(1,2,3,4); 
            
        }

	stop
	//1б. При конструировании объекта посредством конструктора без параметров
	//предусмотрите инициализацию переменных класса, например, нулем

        //добавил метод initialize который вызывается в констркторе
	

	//1в. Подумайте, как следует поступать в случае, когда пользователь задал
	//координаты следующим образом:

	Rect rrr(4,3,2,1);
	
	stop
	//1г. Объявите, определите и вызовите метод класса InflateRect(), 
	//который увеличивает размеры прямоугольника на заданные приращения
	//(раздвигая стороны от центра - каждую сторону на свое значение).
	//Подсказка: объявить и определить методы можно не только "вручную",
	//но и с помощью Wizard-a Class View. Для этого: откройте закладку
	//ClassView окна проекта, сделайте активным класс Rect и нажмите
	//правую кнопку мыши - в появившемся контекстном меню выберите
	//Add/Add Member Function... С помощью появившейся диалоговой панели
	//"дайте указания" Wizard-у как объявить и определить метод.

	
        rrr.InflateRect(10); 
        rrr.View();
	
	stop

	//Задание 2.Перегрузка конструкторов и методов класса.
	//Конструктор копирования.

	//2а.Объявите и определите конструктор копирования в классе Rect.
	//Выполняя задание по шагам, определите, какой
	//конструктор вызывается при создании r1,r2,r3 и r4?
	//Чему равны переменные созданных объектов?
		Rect r1; //Конструктор по умолчанию
		Rect r2(1,2,3,4); // Конструктор с параметрами
                
		Rect r3 = r1; //Конструктор копирования
		Rect r4(r2); // Конструктор копирования (функциональная запись)
		stop


  //2б. Объявите и определите в классе Rect метод InflateRect(),
	//который принимает два аргумента, по умолчанию равных 1, и 
	//раздвигает стороны прямоугольника на на заданные приращения.
	//Для каких объектов вызывается функция InflateRect()?
		r1.InflateRect(1,1);	//для объекта r1
		r2.InflateRect(2,2);    //для объекта r2
	//Какая из функций InflateRect() вызывается в каждом из трех случаев?
		r3.InflateRect(2,2,2,2); //Функция от 4-х аргументов
		r3.InflateRect(3,3); //Функция от 2-х аргументов
		r3.InflateRect(5);//Функция от 2-х аргументов (второй аргумент 1 - по умолчанию)
		r3.InflateRect();//функция от 2-х аргументов (по умолчанию 1, 1)
	stop/*
*/

	
	//Задание 3.Спецификаторы доступа. Инкапсуляция. 
	{
            Rect r;
	//Раскомментируйте следующую строку. Объясните ошибку
	//компилятора
/* ++++++++++++++++++++++++++++++++++++++++++++++++
 g++ -g   -c   -o build/main.o main.cpp
In file included from main.cpp:2:0:
myRect.h: In function ‘int main()’:
myRect.h:6:6: error: ‘int Rect::m_left’ is private
  int m_left, m_right, m_top, m_bottom;
      ^
main.cpp:115:25: error: within this context
 ++++++++++++++++++++++++++++++++++++++++++++++++
 * Обращение к приватному члену вне контекста класса
 */
            
            
           // int tmp = r.m_left;



	//Введите в класс Rect метод void SetAll(...),
	//который присваивают переменным класса передаваемые
	//значения. Вызовите созданный метод, проверьте корректность. 
            r.SetAll(10,100,10,100);
            r.View();

	//Введите в класс Rect парный метод GetAll(...),
	//который "достает" значения private-переменных класса.
	//Вызовите созданный метод, проверьте корректность. 
            int left, right, top, bottom;
            r.GetAll(left, right, top, bottom);    
            std::cout << "Left: " << left << "\n";    
            std::cout << "Right: " << right << "\n"; 
            std::cout << "Top: " << top << "\n"; 
            std::cout << "Bottom: " << bottom << "\n"; 

	stop
	}
/**/

	//Задание 4.Передача экземпляра класса в качестве параметра
	//функции. Возвращение объекта класса по значению. Поставив
	//остановы в конструкторе копирования или выполняя фрагмент
	//по шагам, определите: в какой момент происходит обращение
	//к конструктору копирования. 
	//Создайте глобальную функцию 
	// Rect BoundingRect(Rect, Rect);
	//которая принимает два объекта класса Rect по значению и
	//возвращает объект класса Rect, который является прямоугольником,
	//в который вписаны заданные прямоугольники. Как происходит
	//передача параметров и возвращение объекта класса?

	//Замечание*: хорошо было бы учесть тот факт, что прямоугольник
	//может оказаться "ненормализованным", то есть m_left>m_right или/и
	//m_top>m_bottom

	{

            //При передачи по значению объектов выхывается конструктор копирования
            //Создается новый объект с которым локально работает функция
            Rect r1(1,2,3,4), r2(5,60,7,80),r3;
            r3= BoundingRect(r1, r2);
            r3.View();
	stop
	
	//Задание 4а. Передача объектов по ссылке.
	//Создайте глобальную функцию BoundingRect2, которая выполняет ту же
	//задачу, принимая параметры по ссылке
	//Вызываются ли конструкторы при передаче параметров?
	
            //По ссылке не вызывается конструктор копирования    
            //Функция просто получает ссылку на уже существующий объект
            r4 = BoundingRect2(r1, r2);
            r4.View();
	stop
	}

/**/


	//Задание 5. Указатель на класс. Объявите и определите
	//явный деструктор класса. Поставьте остановы в 
	//конструкторе (конструкторах) и деструкторе. Определите: когда для
	//каждого из объектов вызывается конструктор, а когда - деструктор?
	{
		Rect r1; //Вызов конструктора
		Rect*	pR = new Rect(1,2,1,2);	 //Вызов конструктора 
		{
			Rect r2(r1);//Вызов конструктора (копирование)
			Rect arRect[2]; //Вызов 2-x конструкторов
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ; //вызов конструктора только при первой итерации
				Rect r4(*pR); //Вызов конструктора (копирование)
				Rect r5(i,i,i,i); //Вызов конструктора 
                                
                                //вызов деструкторов r4, r5
			}
                        //вызов деструкторов r3, r2
                        
		}
		delete pR; //Явно удаляем динамический объект, 
                //вызывается перед очисткой памяти деструктор
                
                
                //Конец облости видимости для r1 -вызывается его деструктор
		stop
	}
/**/
 
	//Задание 6.Конструктор + деструктор = функциональное
	// замыкание. Класс MyString
	// Посредством конструктора (конструкторов) и деструктора обеспечьте
	//корректные инициализацию и деактивацию объекта
	//C помощью остановов определите когда происходит
	//захват и освобождение памяти для строки-члена класса
	{
		MyString	str("It's my string!");
		//Создайте метод GetString(), который обеспечит доступ к хранящейся строке.
		//С помощью cout и метода GetString() распечатайте строку объекта str
		//Замечание: подумайте, как следует корректно реализовать метод GetString().
                std::cout << "GetString: " << str.GetString() << "\n";

		//...
	}
	stop
/**/

	//6a. Раскомментируйте следующий фрагмент. Подумайте - какие
	//неприятности Вас ожидают. Попробуйте исправить положение (как?)
		{
			MyString str1("The first string!");
			MyString str2 = str1;
                        
                        std::cout << "GetString: " << str1.GetString() << "\n";
                        std::cout << "GetString: " << str2.GetString() << "\n";
		}
		stop

	//6б. Реализуйте метод SetNewString, который будет заменять строку
	// на новую
        
                {
                    MyString str1("Change me!");
                    std::cout << "GetString: " << str1.GetString() << "\n";
                    
                    str1.SetNewString("New string!");
                    std::cout << "GetString: " << str1.GetString() << "\n";                   
                    
                }

/**/

	//6г. Создайте глобальную функцию, которая будет принимать любое
	//количество указателей на строки, а возвращать объект MyString,
	//в котором строка будет конкатенацией параметров
                
                {
                    const char *a ="The", *b = " first", *c = " string!";
                    MyString *s = CreateString(3, a, b, c);
                    std::cout << s->GetString() << "\n";
                    
                }

/**/


	//Задание 7.Массив объектов класса.
	{
	//Объявите и проинициализируйте массив ar из объектов
	// типа MyString. Например:
	//Как задать размерность? N=3
        const int N = 3;            
	MyString arstr[N] = {"Str 1", "Str 2", "Str 3"};
          
	//Проверка - печать строк-членов класса
        for (int i = 0; i < N; i ++) {
            std::cout << arstr[i].GetString() << "\n";
        }


	//Увеличьте размер массива, не изменяя список инициализаторов:
	//N=5???
        const int N1 = 5;            
	MyString arstr1[N1] = {"Str 1", "Str 2", "Str 3"};
          
	//Проверка - печать строк-членов класса
        for (int i = 0; i < N1; i ++) {
            std::cout << arstr1[i].GetString() << "\n";
        }
        
	//Объявите и проинициализируйте массив объектов	типа Rect.
        Rect rects[N] = {{1,1,1,1}, {2,2,3,3}, {4,4,6,9}}; //C++11
        for (int i = 0; i < N; i ++) {
            rects[i].View();
        }


	}
	stop
/**/

	//Задание 8.Массив указателей на объекты класса.
	{
	//Объявите и проинициализируйте массив arPtr из трех 
	//указателей на объекты типа MyString.
            const int N = 3;
            MyString *arPtr = new MyString[N]{"abc", "nlp", "xyz"};
	
	//Печать строк-членов класса
            for (int i = 0; i < N; i ++) {
                std::cout << arPtr[i].GetString() << "\n";
            }

            delete[] arPtr; 
	}
	stop
/**/
	//Задание 9.  Решите с помощью классов следующую задачу:
	//даны две бочки известного объема. В одной бочке в начальный момент
	//времени содержится спирт (96%), в другой – вода.
	//Кружкой емкостью 1л переливаем итеративно содержимое из одной бочки
	//в другую следующим способом: на каждой итерации
	//зачерпнули из первой бочки -> вылили во вторую
	//зачерпнули из второй бочки -> вылили в первую.
	//Требуется определить номер итерации, на которой концентрация спирта в
	//первой бочке станет меньше 50%.

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(концентрация спирта в бочке spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //или spirt.Pereliv(water, объем_кружки);
	//		water.Pereliv(spirt); // аналогично
	//		...

	//	}
    
    return 0;

}//end_main

