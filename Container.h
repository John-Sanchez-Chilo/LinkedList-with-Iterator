#ifndef __CONTAINERLINKEDLIST_H__
#define __CONTAINERLINKEDLIST_H__

#include "LinkedList.h"
#include "Iterator.h"

template <class T>
class ContainerLinkedList{
  friend class IteratorLinkedList<T, ContainerLinkedList>;

 public:
  void Add(T a) {
    m_data_.pushBack(a);
  }

  IteratorLinkedList<T, ContainerLinkedList> *CreateIterator() {
    return new IteratorLinkedList<T, ContainerLinkedList>(this);
  }

 private:
  LinkedList<T> m_data_;
};
#endif