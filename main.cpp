 // Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>

#include <iostream>
#include <algorithm>
#include <functional>
#include "libs"


using namespace std;

#define stop

int main(int argc, char* argv[])
{

	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	
    {
        std::stack<int> s;
        std::queue<int> q;
        std::priority_queue<int> pq;
        for (int i = 0; i < 3; i++) {
             q.push(i);
             pq.push(i);
             s.push(i);
        }
       
        stPrint(s);
        stPrint(q);
        stPrint(pq); 
       // return 0;
    }



	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
    {
        std::cout << "=======================" <<std::endl;
        std::vector<int> sv {1,2,3,4}; 
        std::reverse(sv.begin(), sv.end());
        std::stack<int> ss ({sv.rbegin(), sv.rend() }); 
        
        stPrint(sv);
        stPrint(ss); 
        //return 0;
    
    }


	
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	


    {
        std::queue<Point*, std::deque<Point*>> ppq;
        ppq.push(nullptr);
        ppq.push(nullptr); 
         
        ppq.front() = new Point(1,2); 
        ppq.back()  = new Point(1,2);
        
        stPrint(ppq);
         
        while(!ppq.empty()) {
            Point *pf = ppq.front();
            ppq.pop();
            if(pf) {
                delete pf;
            }    
        }
        
    }




	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


	

    {
        
        const char* ar[3] = {"abc", "mjv", "xwz"};
        std::priority_queue<const char*> pqc({ar, ar + 3});
        stPrint(pqc);
        //TODO b
    }


	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)


    {
        
        //в point необходимо определить operator<
        std::set<Point> sp;
        sp.insert(Point(1,2));
        sp.insert(Point(1,2));
        sp.insert(Point(10,10));
        std::cout << sp.size() << std::endl;
        itPrint(sp);
        
        //(*sp.begin()).setXY(2,2);    //Ошибка так как значение константа
        
        std::set<int> si1{1,2,3};
        std::set<int> si2{3,1,2};
        int ai[] = {2,3,4};
    
        si2.insert(ai, ai + 3);
        itPrint(si2); //множество хранит только уникальные значения
    }

    
    

    



	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	stop
        {
            std::map<const char*, int> mf;
            mf.insert(std::pair<const char*, int>("Иванов", 1000000));
            mf["Петров"] = 999999;
            mf["Иванова"] = 2000000;
             
            itPrint(mf);
            
            
            auto val = mf.find("Иванова");
            if(val != mf.end()) {
                mf["Петрова"] = (*val).second;
                mf.erase(val);                
            }            
            
            itPrint(mf);
        }

	
		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	
        {
            std::vector<std::string> vs = {"xyz", "Test 1", "Abc", "xyz", "My str", "test", "Abc", "Some", "Kate"};
            itPrint(vs);
            
            std::map<std::string, int> ms;
            
            for(auto s : vs) {
                auto it = ms.find(s);
                if(it != ms.end()) {
                    (*it).second += 1;
                } else {
                    ms[s] = 1;
                }
            } 
             
            std::vector<std::pair<std::string, int>> vs1(ms.begin(), ms.end());           
            std::sort(vs1.begin(), vs1.end(), 
                    [](const std::pair<std::string, int>& l, const std::pair<std::string, int>& r){
                return (r.first.compare(l.first) < 0);});           
          
            
            itPrint(ms);
            itPrint(vs1);
            return 0;
        }



		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
		
        {
            const char* words[] = {"Abba", "Alfa", "Beta", "Beauty", "test", "tor"};
            std::map<int, std::vector<int>> sm;
            char ch;
            for(int i = 0; i < sizeof(words) / sizeof(words[0]); i ++) {
                ch = words[i][0];
                auto it = sm.find(ch);
                if(it == sm.end()) {
                    std::vector<int> tmp {i};
                    sm[ch] = tmp;
                } else {
                    sm[ch].push_back(i);
                }
            }
            
            std::cout << "=======================" << std::endl;
            //itPrint(sm);
             auto it = sm.begin();
             while(it != sm.end()) {
                 
                 std::cout << "Char : " << static_cast<char>( (*it).first ) << " -";
                 auto second = (*it).second;
                 auto it2 = second.begin();
                 
                 while(it2 != second.end()) {
                     std::cout << " \"" << words[*it2] << "\"";
                     it2 ++;
                 }
                 
                 std::cout << std::endl;
                 
                 
                 it ++;
             }   
            
        }

		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
        {
            std::map<std::string, std::vector<std::string>> students {
                        
                        {"234", {"Иванов", "Иванова","Петров", "Сабинин", "Иванова"}},   
                        {"123", {"Путин", "Михалков", "Медведев"}}
            };
            
            
            auto it = students.begin();
            while(it != students.end()) {
                std::vector<std::string> *tmp = &(*it).second;
                std::sort (tmp->begin(), tmp->end(), 
                        [](std::string const &a, std::string const &b)->bool{ return a.compare(b) < 0;});
                it ++;
            }
            
            itPrint(students);
        }



	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

        {
            std::multimap<std::string, std::string> mp;
            mp.insert(
                std::make_pair<std::string, std::string>("hello", "привет")
            );
            mp.insert(
                std::make_pair<std::string, std::string>("strange", "чужой")
            );
            
            mp.insert(
                std::make_pair<std::string, std::string>("developer", "разработчик")
            );
            mp.insert(
                std::make_pair<std::string, std::string>("developer", "проявитель")
            );
            mp.insert(
                std::make_pair<std::string, std::string>("developer", "застройщик")
            ); 
            mp.insert(
                std::make_pair<std::string, std::string>("strange", "странный")
            );

            
            itPrint(mp);
            
            std::string findValue = "developer";  
            auto low = mp.lower_bound(findValue);
            auto upp = mp.upper_bound(findValue);
            
            std::cout << "=============== strange ================"  << std::endl;
            
            while(low != upp) {
                std::cout << "Val: " << (*low).second << std::endl;
                low ++;
            }
            
        }

  stop

	return 0;
}

