
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Node.h"
#include "Circle.h"

class List {
    
    Node Head;	// фиктивный элемент, который является признаком начала списка
    Node Tail;	// фиктивный элемент, который является признаком конца списка
    unsigned int m_size;	//количество элементов
    
public:
    List();
    List(const List& );
    List(const List&& );
    virtual ~List();
    
    /**
     * метод, который добавляет элемент в начало списка
     */
    void AddToHead(Circle*);
    
    /**
     * метод, который добавляет элемент в конец списка
     */
    void AddToTail(Circle*);
    
    /**
     * удаление из списка первого элемента, данное которого совпадает 
          со значением параметра. Если элемент найден и удален, метод возвращает true, 
           если элемента с таким значением в списке не было – false
     * @return 
     */
    bool Remove(const Circle*);
    
    /**
     * удаление из списка всех элементов, данное которых совпадает со значением параметра. 
         Метод возвращает количество удаленных элементов.
     * @return 
     */
    int RemoveAll(const Circle*);
    
    //
    int RemoveAll(const Circle*, int);
     
    /**
     * Сделать список пустым
     * @return 
     */
    void Clear(); 
    
    /**
     * 
     * @param 
     * @param 
     */
    void Swap(Node*, Node*);
    
    
    void SortBySquare();
    
    List& operator=(const List&);
    
    
    friend std::ostream& operator<<(std::ostream&, const List&); 
    friend void operator<<(List&, std::istream&);
    
private:
    void Copy(const List&);
   
}; 



//
std::ostream& operator<< (std::ostream&, const List&);
 
//
void operator<<(List&, std::istream&);