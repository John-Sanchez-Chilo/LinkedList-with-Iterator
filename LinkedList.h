#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList {
    private:
        int size;
        Node<T> *head;
        friend std::ostream& operator << <>(std::ostream &,const LinkedList<T>&);
    public:

        LinkedList();
        explicit LinkedList(T);
        LinkedList(const LinkedList<T> &);//copy constructor
        LinkedList(LinkedList<T> &&);//move constructor
        LinkedList<T>& operator=(const LinkedList<T> &);//copy assigment
        LinkedList<T>& operator=(LinkedList<T> &&);//move assignment

        ~LinkedList();

        void insert(int);
        void insert(T,int);//funcionando
        void pushBack(T);

        void removeByValue(T);
        void removeByPosition(int);
        
        bool search(T value);


        void print();
        int getSize(){
            return size;
        }
        Node<T>* getHead()const{
            return head;
        }
        T* begin();
        Node<T>* beginNode();
        T* end();
        Node<T>* endNode();
        //T getElementByPosition(int); //no es necesario aun
        //friend std::ostream& operator <<<>(std::ostream &out,const LinkedList<T>& C);
        // operator <<
};


template <typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(T value) {
    this->size = 1;
    this->head = new Node<T>(value);
}

//destructor

template <typename T>
LinkedList<T>::~LinkedList() {
    /*
    cout<<"Destructor"<<endl;
    Node<T> *actual;
    while (head!=nullptr){
        actual = head->getNext();
        delete head;
        head = actual;
    }
    */
   //cout<<"Segundo destrcutor"<<endl;
   head->deleteNextNodes();
    //delete head;
}

//constructor copia
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &o) {
    this->size = 0;
    this->head = nullptr;
    Node<T>* tmp = o.head;
    /*while(tmp)
    {
        this->insert(tmp->getValue());
        tmp= tmp->getNext();
    }*/
    for(int i=0;i<o.size-1;i++){
        this->pushBack(tmp->getValue());
        tmp=tmp->getNext();
    }
    this->pushBack(tmp->getValue());
}

//move constructor
//el primeor debe recibir los atributos sel segundo y el segunod debe quedar vacio como si fuera uno nuevo
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> && rhs){
    //cout<<"Move construcot"<<endl;
    this->head=rhs.head;
    this->size=rhs.size;

    rhs.head=nullptr;
    rhs.size=0;
}

//copy assigment: duda se supone q ya tenemos una lista con ciertos elementos

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &rhs){
    //cout<<"Copu asisgmente has  been called"<<endl;
    //(*this->head)=(*rhs.head);
    //(this->size)=(rhs.size);
    //primer coppy assigment de menor a mayor
    /*
    Node<T> *tmp1=this->head;
    Node<T> *tmp2=rhs.head;
    for(int i=0;i<this->size;i++){
        tmp1->setValue(tmp2->getValue());
        tmp1= tmp1->getNext();
        tmp2= tmp2->getNext();
    }
    for(int i=0;i<rhs.size-this->size;i++){
        this->pushBack(tmp2->getValue());
        tmp2= tmp2->getNext();
    }
    (this->size)=(rhs.size);

    */
    //segundo coppy asigment
    this->head->deleteNextNodes();
    this->size=0;
    Node<T> *tmp=rhs.head;
    for(int i=0;i<rhs.size;i++){
        this->pushBack(tmp->getValue());
        tmp= tmp->getNext();
    }

    return *this;//
}

//move assigment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &&rhs){
    Node<T> *tmp=this->head;
    int tmpSize=this->size;
    this->head=rhs.head;
    this->size=rhs.size;

    rhs.head=tmp;
    rhs.size=tmpSize;
}

//for iterator
//devuelve un puntero a T
template <typename T>
T* LinkedList<T>::begin() {
    T *ptr=&(head->getValue());
    return ptr;
}

template<typename T>
T* LinkedList<T>::end() {
    Node<T> *tmp=head;
    for(int i=0;i<size-1;i++){
        tmp=tmp->getNext();
    }
    T* ptr=&(tmp->getValue());
    return ptr;
}

template<typename T>
Node<T>* LinkedList<T>::beginNode(){
    return head;
}

template<typename T>
Node<T>* LinkedList<T>::endNode(){
    Node<T> *tmp=head;
    for(int i=0;i<size-1;i++){
        tmp=tmp->getNext();
    }
    return tmp;
}

template <typename T>
void LinkedList<T>::insert(T value,int pos) {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *tmp = head;
    if(pos==0){
        head = newNode;
    } else {
        for(int i=0;i<pos-1;i++){
            tmp=(tmp->getNext());
        }
        newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);
    }
    size++;
}

template <typename T>
void LinkedList<T>::pushBack(T value){
    insert(value, size);
}


template <typename T>
void LinkedList<T>::removeByPosition(int posicion) {
    if(posicion<size){
        Node<T> *aux, *actual=head;
        if (posicion!=0){
            int i=0;
            while(i<posicion){
                aux = actual; actual = actual->getNext();
                i++;
            }
            aux -> setNext( actual->getNext() ); delete actual;
        }
        else{
            head = head -> getNext(); delete actual;
        }
        size--;
    }
}


template <typename T>
void LinkedList<T>::removeByValue(T value) {
    Node<T> *actual = head;
    int position=0;
    if(size != 0){
        while (actual!=nullptr){
            if ( value == actual->getValue() ){
                removeByPosition(position); break;
            }
            position++; actual = actual->getNext();
        }
    }
}

template <typename T>
bool LinkedList<T>::search(T value) {    
    Node<T> *tmp = head;
    
    while(tmp != nullptr ){
        if(tmp->getValue()==value){
            return true;
        }
        tmp = tmp->getNext();
    }    
    return false;
}



// Imprimir la Lista
template<typename T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;
    if (!head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->getNext()) cout << "NULL";
                temp = temp->getNext();
        }
  }
  cout << endl << endl;
}


// overload operator <<

template <typename T>
std::ostream& operator<<(std::ostream &out,const LinkedList<T>& c){
    Node<T>* actual = c.head; 
    out <<" [ ";
    while(actual!=nullptr){
        out<< actual->getValue();
        out<<"->";
        actual = actual->getNext();
    }
    out << "] ";
    return out;
}

#endif