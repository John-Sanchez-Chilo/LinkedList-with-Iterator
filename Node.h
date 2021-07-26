#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
using namespace std;
template<typename T>
class Node {    
    private:
        T value;
        Node *next;
    public:
        Node(T _value = 0 , Node<T>* _next = nullptr): 
            value(_value), next(_next){}

		T getValue() const;
        T* getValueMemory() const;
        void setValue(T);

		Node<T>* getNext() const;               
        void setNext(Node<T>*);

        void print();
        void deleteNextNodes();
        //friend ostream& operator<<<>(ostream& output,const Node<T> &out);

};

template<typename T>
void Node<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << value<< "-> ";
}

template<typename T>
T Node<T>::getValue() const {
    return value;
}

//tiene la debildiad q se crea un puntero innecesario
template<typename T>
T* Node<T>::getValueMemory() const {
    T tmp=value;
    T *ptr=&tmp;
    return ptr;
}

template<typename T>
void Node<T>::setValue(T _value){
    this->value = _value;
}

template<typename T>
Node<T>* Node<T>::getNext() const{
    return next;
}

template<typename T>
void Node<T>::setNext(Node<T> *_next){
    this->next = _next;
}

//eliminar los nodos siguientes a este
//invocalo en la cabeza para eliminar todo
template<typename T>
void Node<T>::deleteNextNodes(){
    if(next!=nullptr){
        next->deleteNextNodes();
    }
    delete this;
}

/*
template<typename T>
ostream& operator<<(ostream& output,const Node<T> &node){
    output<<node.value;
    return output;
}
*/
#endif