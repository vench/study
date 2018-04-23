
#pragma once

#include <iostream>
#include "Node.h"

class List {
    
    Node Head;	// фиктивный элемент, который является признаком начала списка
    Node Tail;	// фиктивный элемент, который является признаком конца списка
    unsigned int m_size;	//количество элементов
    
public:
    List();
    List(const List& orig);
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
    bool Remove(Circle*);
    
    /**
     * удаление из списка всех элементов, данное которых совпадает со значением параметра. 
         Метод возвращает количество удаленных элементов.
     * @return 
     */
    int RemoveAll(Circle*);
    
    //
    int RemoveAll(Circle*, int);
     
    /**
     * Сделать список пустым
     * @return 
     */
    void Clear(); 
    
    
    friend std::ostream& operator<<(std::ostream&, const List&);
    
private:

}; 



//
std::ostream& operator<< (std::ostream&, const List&);
