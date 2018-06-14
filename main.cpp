 // Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>     // std::ostream_iterator

#include "Point.h"
#include "Rect.h"
#include "libs"

using namespace std;	

#define	  stop


int main(int argc, char* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию


	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.


	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
    
    {
        std::set<Point> sp { Point(1,2), Point(11,21), Point(122,222), Point(1333,2333)};        
        //itPrint(sp);        
        std::vector<Point> vp(sp.rbegin(), sp.rend());        
       // itPrint(vp);        
        
        std::ostream_iterator<Point> out_it (std::cout,", ");
        std::cout << "std::set<Point>" << std::endl;
        std::copy ( sp.begin(), sp.end(), out_it );
        std::cout << std::endl <<  "std::vector<Point>" << std::endl;
        std::copy ( vp.begin(), vp.end(), out_it );
        
        //std::back_inserter - нужен метод push_back 
        std::vector<Point> doner {Point(999,999), Point(888, 888)};
        std::copy ( doner.begin(), doner.end(), std::back_inserter(vp) ); //Добавим в конец
        std::cout << std::endl <<  "std::vector<Point>" << std::endl;
        std::copy ( vp.begin(), vp.end(), out_it );
        
        //std::front_inserter  - нужен метод push_front
        
        //std::inserter - нужен оператор insert
        std::copy ( doner.begin(), doner.end(), std::inserter(sp, std::next(sp.begin())) );
        std::cout << std::endl <<  "std::set<Point>" << std::endl;
        std::copy ( sp.begin(), sp.end(), out_it );
        
        std::copy ( doner.begin(), doner.end(), std::inserter(vp, std::next(vp.begin())) );
        std::cout << std::endl <<  "std::vector<Point>" << std::endl;
        std::copy ( vp.begin(), vp.end(), out_it );
        
        std::cout << std::endl;
    }



///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

    {
        std::vector<int> vi {1,2,3,4,5};
        std::for_each(vi.begin(), vi.end(), printValue<int>);
        std::for_each(vi.rbegin()+3, vi.rend(), printValue<int>);
        
        std::vector<Point> vp {Point(0,0), Point(1,1)};
        std::for_each(vp.begin(), vp.end(), printValue<Point>);
    
    }

	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

        {
        
            std::vector<Point> vp {Point(0,0), Point(1,1)};
            
            std::for_each(vp.begin(), vp.end(), PointChangeXY(100,100));
            std::cout << "Changed" << std::endl;
            std::for_each(vp.begin(), vp.end(), printValue<Point>);
        
        }


	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
        {
            Point find(1,1);
            std::vector<Point> vp {Point(0,0), Point(1,1),Point(10,10), Point(1,1),Point(20,20)};
            
            auto it = vp.begin();
            while(true) {
                it = std::find(it, vp.end(), find);
                if(it != vp.end()) {
                    printValue(*it);
                    it ++;
                } else {
                    break;
                }
            } ; 
        }


	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point? (operator <)
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	{
            std::cout << "=========== lp sort ===========" << std::endl;
            std::list<Point> lp {Point(10,20), Point(1,2),  Point(100,200)};
            //std::sort(lp.begin(), lp.end());
            lp.sort();
            std::for_each(lp.begin(), lp.end(), printValue<Point>);
            
            
            std::vector<Point> vp {Point(10,20), Point(1,2),  Point(100,200)};
            std::sort(vp.begin(), vp.end());
            std::for_each(vp.begin(), vp.end(), printValue<Point>);
            
        }



	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

        {
        
            std::vector<Point> lp{Point(10,20), Point(1,2),  Point(100,200), Point(-1,2)}; 
            std::cout << "=========== Find if ===========" << std::endl;
            auto it = lp.begin();
            while(true) {
                it = std::find_if(it, lp.end(), PointFindByMinMax(-10,10));
                if(it != lp.end()) {
                    printValue(*it);
                    it ++;
                } else {
                    break;
                }
            } ;
        }
        


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	{
            std::cout << "=========== Sort Rect ===========" << std::endl;
            
            std::vector<Rect> vr {Rect(0,4,0,4), Rect(0,10,0,10), Rect(10,16,10,16), Rect(2,10,2,10)};
            std::sort(vr.begin(), vr.end(), [](Rect &a, Rect &b ) -> bool {               
                return a.GetCenterXY() < b.GetCenterXY();
            });
            
            std::for_each(vr.begin(), vr.end(), printValue<Rect>);
        }






	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	



		stop
	}
        
	{ // map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	







	}

	


	return 0;
}

