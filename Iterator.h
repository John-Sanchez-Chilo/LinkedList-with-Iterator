#ifndef __ITERATORLINKEDLIST_H__
#define __ITERATORLINKEDLIST_H__

#include "LinkedList.h"
//T es el tipo de dato q se recorre la lista enlazada es decir Node
//U es el objeto recorrido(lista)
//U=LinkedList<T>
//T deberia ser un int
//va dentro de linkedList<T>
template <typename T, typename U>
class IteratorLinkedList {
 public:
  IteratorLinkedList(U *p_data, bool reverse = false) : object(p_data) {
    //tmp = object->begin();
    node=object->m_data_.beginNode();
  }

  void First() {
    node=object->m_data_.beginNode();
  }

  void Next() {
    node=node->getNext();
  }

  bool IsDone() {
    return (node==nullptr);
    //return (node == object->m_data_.endNode());
  }

  T* Current() {//esto retorna un puntero al actual
    tmp=node->getValueMemory();
    
    return tmp;
  }

  T Currently(){
    
    return node->getValue();
  }

 private:
  U *object;//puntero al objeto recorrido U<T>
  T *tmp;//puntero recorredor puntero a Node
  Node<T> *node;
};

#endif