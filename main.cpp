//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>

#include "MyString.h"
#include "Point.h"
#include "libs"


/* #pragma warning(disable: 4786) */


using namespace std;	

#define	  stop




//
int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	
        //Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

        {
            std::vector<int> vInt;
            std::cout  << "vInt.size() == 0 -> " << vInt.size() << std::endl;
        
      
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
 
            vInt.push_back(2);
            vInt.front()=1; // нет ссылки на первый элемент (если вектор пустой)
            
            std::cout  << "vInt.front() -> " << vInt.front() << std::endl;  //OK  
            

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
            for(int i =0; i< 10; i ++) {
                vInt.push_back(i);
                vectorInfo(vInt); 
            }

        }

	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	
        {
            std::vector<double> vDouble1(4);
           
            vectorInfo(vDouble1);
            //size( ): 4; capacity(): 4; max_size(): 2305843009213693951
            //все значение равны 0

        }

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

        {
             std::vector<MyString>  vMyString(5, MyString("A"));
             /*for(int i = 0; i < vMyString.size(); i ++) {
                 vMyString.at(i) = "A";
                 std::cout << "Val of " << i << " = " << vMyString[i] << std::endl;
             }*/
             
             vMyString[2] = "Some string";
             std::cout << "Value vMyString[2] = " << vMyString[2] << std::endl;
             
            // std::cout <<       vMyString[5] << std::endl; //; Segmentation fault;
             try {
                 std::cout <<       vMyString.at(5) << std::endl; //exception
             } catch(const std::exception &e ) {
                 std::cout << "Catch:\n\t " <<       e.what() << std::endl;
             }    
        }



	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
        {
             double dMas[7] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
             std::vector<double> vDouble3(dMas, dMas +  5);
             vectorInfo(vDouble3);
             vectorPrint(vDouble3);

            //вектор вещественных - vDouble4, который является копией элементов
            // [2,5) вектора vDouble3. 
             
            std::vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 5);
            vectorInfo(vDouble4);
            vectorPrint(vDouble4);
        }     



	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

        {
            std::vector<Point> vPoint1(3); // Point::Point() - конструктор по умолчанию
            std::vector<Point> vPoint2(5, Point(1,1)); 
            
            vectorPrint(vPoint2);
            //return 0;
        
        }

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{

	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*
            
            
             std::vector<Point*> vpPoint(5); //Если установить  new Point(1,1) то ссылка будет для всех 5 элементов
            
             for(int i = 0; i < vpPoint.size(); i ++ ) {
                vpPoint.at(i) = new Point(i,i);
             }
             /*std::vector<Point*> vpPoint{new Point(1,1),new Point(1,1),new Point(1,1),new Point(1,1),new Point(1,1)};
             */
             
             vectorPrint(vpPoint);
             
             //удалить память? 
             for(int i = 0; i < vpPoint.size(); i ++ ) {
                delete vpPoint.at(i);
             }
             vpPoint.clear();

	}//Какие дополнительные действия нужно предпринять для такого вектора?


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
		{
		size_t n=15;
		vector<int> v(n);
		v.resize(n/2);
                    if(v.capacity() == n) {
                        std::cout << " if(v.capacity() == n) -> true" << std::endl;
                    } else {
                        std::cout << " if(v.capacity() == n) -> false" << std::endl;
                    }//true?
                
                    //Всегда true - т.к. resize именно "режет" вектор, но не "отнимает" выделенную ему память
		}
		/**/

		
		{
		int n=10;
		size_t m=100;	
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) {
                        std::cout << " if(v.capacity() == m) -> true" << std::endl;
                    } else {
                        std::cout << " if(v.capacity() == m) -> false" << std::endl;
                    }//true?
		}
                
                //m >= n -> true
                //m <  n -> false
                //т.к. reserve переобпредеяет  capacity в большую сторону
                
		/**/

		
		{
		vector<int> v(3,5); //создаем вектор из 3х элеметов со значениями 5
               // vectorPrint(v);
		v.resize(4,10); //значения? //расширяем размер до 4 и новые инициализируем 10
               // vectorPrint(v);
		v.resize(5); //значения? //изменяем размер до 5, они инициализированны 0 (по умолчанию)
               // vectorPrint(v);
	
		}
		/**/

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
                {
                
                    std::vector<double> a;
                    a.reserve(5);
                    std::vector<double> b;
                    
                    for(int i =0; i < 5; i ++) {
                        a.push_back(0.1 * i);
                        b.push_back(0.1 * i);
                    }
                    
                    //веторы идентичные
                    //vectorPrint(a);
                    //vectorPrint(b);
                    //vectorInfo(a);
                    //vectorInfo(b);
                    //return 0;
                     
                    //
                    //!!! shrink_to_fit - Уменьшение емкости вектора.
                    //Для любого вектора из предыдущего задания требуется уменьшить емкость
                    //до size. 
                   // vectorInfo(a);
                    int size = 2;
                    a.resize(size);
                    a.shrink_to_fit(); //удаляет неиспользуемую память (которая зарезервированная)
                   // vectorInfo(a);
                }


	



	

	
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
        {
                  int ar[] = {11,2,4,3,5};
                  std::vector<std::vector<int>> vv(sizeof(ar) / sizeof(ar[0]));
                  
                  for(int i = 0; i < sizeof(ar) / sizeof(ar[0]); i ++) {
                      int val = ar[i]; 
                      vv.at(i).resize(val, val);
                  }
                  
                  vectorPrint(vv);
                 // return 0;
        }
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.


	
	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
         {
             std::vector<char> vChar2{'a', 'b', 'c'};
             vectorPrint(vChar2);
             char x = 'z';
             bool isset = false;
             
             for(std::vector<char>::iterator it = vChar2.begin(); it != vChar2.end(); ++it) {
                 if(*it == x) {
                     isset = true;
                     break;
                 }
             }
             /*
             for(int i = 0; i < vChar2.size(); i ++) {
                 if(vChar2.at(i) == x) {
                     isset = true;
                     break;
                 }
             }*/
             //TODO std::find(vector)
             if (!isset) { 
                 vChar2.insert(vChar2.begin(), x);
             } 
             
             vectorPrint(vChar2);
             
             int len = vChar2.size();
             for(int i = 0; i < len; i ++) {
                 vChar2.insert(vChar2.begin() + i * 2, 'W');
             }
             
             std::cout << "===================" << std::endl;
             vectorPrint(vChar2);
             
             //return 0;
         }       


///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
         {
            std::vector<char> vc {'q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3','3'};
            removePair(vc);
             std::cout << "===================" << std::endl;
            vectorPrint(vc);
            
           // return 0;
         }

	stop

///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 
        {
            std::vector<int> vb {7,1,0,0,0,0,1,1,1,2,7,1,99, 99, 0}; //1,2,7
           // vectorPrint(vb);            
            removeUnique(vb);//TODO unique
            std::cout << "===================" << std::endl;
            vectorPrint(vb); // {1,0,0,0,0,2,3,3,0,0,7}; 1,2,7
            return 0;
        }


	

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке
        {
            std::vector<int> src {1,2,3,4,5};
            
            //std::vector<int> dst(src);
            std::vector<int> dst(src.rbegin(), src.rend());
           // std::reverse(dst.begin(), dst.end()); //TODO
           // myReverse(dst.begin(), dst.end());
            std::cout << "===================" << std::endl;
            vectorPrint(dst);
            //return 0;
        }





///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
        {
            std::cout << "===================" << std::endl;
            std::list<Point> lp;
            lp.push_back(Point(1,1));
            lp.insert(lp.begin(), Point(2,2));
            lp.push_front(Point(3,3));
            
            listPrint(lp);
        }
	

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

        {
         
            std::vector<double> vd {1.0,2.0,3.0,4.0};
            itPrint(vd);
            
             
            std::list<bool> vb {1,0,1,0};
            itPrint(vb);
            
            
	//Сделайте любой из списков "реверсивным" - reverse()
            // std::reverse(vd.begin(), vd.end()); //TODO
            myReverse(vd.begin(), vd.end()); 
            itPrint(vd); 
           // return 0;


	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 
            
            
            std::list<Point> ptList1 {Point(12,10), Point(21,31)};
            
            std::vector<Point> ptPoint2 {Point(1,2), Point(15,17)};
            std::list<Point> ptList2(ptPoint2.begin(), ptPoint2.end());
            myReverse(ptList2.begin(), ptList2.end()); // TODO rbegin
            //std::reverse_copy ?
            itPrint(ptList2);
            
            
         


	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка //  operator<

            ptList2.sort();
            ptList1.sort();
            
            
            
	


	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.
            
            itPrint(ptList1);
            itPrint(ptList2);
            
            ptList2.merge(ptList1);
        
            itPrint(ptList1); //стал пустым
            itPrint(ptList2); // получил 2 элемента с учетом объей сортировки
            

	
	stop
                
                }
	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 


	//Исключение из списка подряд расположенных дублей - unique(). 
        
        
        {
            Point testPoint(33,31);
            std::list<Point> il {Point(12,-10),Point(12,10), Point(88,66), Point(21,31), Point(21,31),testPoint,testPoint};
            
            il.remove(testPoint);
            
            il.remove_if([](Point &p) -> bool { return p.getX() < 0 || p.getY() < 0; }); //remove 1
            itPrint(il);
            
            il.unique();
            
            itPrint(il);
        }

	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
                
        {
            
            std::vector<Point> pv {Point(1,1),Point(2,2),Point(3,3)};
            std::deque<Point> dPoint;
            dPoint.assign(pv.begin(), pv.end()); 
            
            itPrint(dPoint);
        }        



	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

        {
            std::deque<MyString> dStr;
            dStr.push_back(MyString("Abc"));
            dStr.push_front(MyString("aBC"));
            dStr.insert(dStr.end(), MyString("xyz"));
            dStr.push_front(MyString("test"));
            dStr.push_front(MyString("aTest"));
            
            itPrint(dStr);  
            /*
            auto it = dStr.begin();
            while(it != dStr.end()) {
                if((*it)[0] == 'A' || (*it)[0] == 'a') {
                    dStr.erase(it);
                }
                ++ it;
            }
            */
            dequeRemoveIF(dStr, [](MyString& s)->bool { return s[0] == 'A' || s[0] == 'a'; });
            itPrint(dStr);
        }


	return 0;
}