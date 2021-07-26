#include <iostream>
#include "LinkedList.h"
#include "Iterator.h"
#include "Container.h"

class Data {
 public:
  Data(int a = 0) : m_data_(a) {}

  void set_data(int a) {
    m_data_ = a;
  }

  int data() {
    return m_data_;
  }

 private:
  int m_data_;
};

using namespace std;
int main(){
    //probando que los metodos funcionan
    
    LinkedList<int> lista(2);
    lista.insert(5,1);
    lista.print();
    lista.insert(3,2);
    lista.print();
    lista.insert(5,1);
    lista.print();
    lista.insert(5,1);
    lista.print();
    lista.insert(12,3);
    lista.pushBack(12);
    lista.print();
    lista.removeByValue(7);
    lista.print();
    lista.removeByValue(12);
    lista.print();
    lista.removeByValue(3);
    lista.print();
    lista.removeByPosition(0);
    lista.print();
    
    
    //probando constructor copia
    
    LinkedList<int> lista1;
    lista1.pushBack(1);
    lista1.pushBack(2);
    lista1.pushBack(3);
    lista1.print();
    
    LinkedList<int> lista2=lista1;
    
    lista2.print();
    lista2.pushBack(20);
    lista1.pushBack(10);
    lista1.print();
    lista2.print();
    

   //porbando dedstructo
   
    LinkedList<int> des1(14), des2(21);
    LinkedList<int> *desp1=new LinkedList<int>(14);
    desp1->pushBack(21);
    desp1->print();
    delete desp1;
    

    //probando assignacion de copia
    
    LinkedList<int> copia1(15), copia2(25);
    copia1.pushBack(20);
    copia1.pushBack(26);
    copia1.pushBack(30);
    copia2.pushBack(27);
    copia1.print();
    copia2.print();
    copia2=copia1;
    copia1.pushBack(12);
    copia2.pushBack(16);
    copia1.print();
    copia2.print();
    cout<<copia2;
    

    //probando el iterator ocn su container
    
    ContainerLinkedList<int> cont;
    for(int i=0;i<10;i++){
        cont.Add(i);
    }

    IteratorLinkedList<int,ContainerLinkedList<int>> *it=cont.CreateIterator();
    for(it->First(); !it->IsDone(); it->Next()){
        cout<<*it->Current() <<endl;
    }
    cout<<"Termine l primeor"<<endl;
    for(it->First(); !it->IsDone(); it->Next()){
        cout<<it->Currently() <<endl;
    }
    cout<<"Terine el segundo"<<endl;
    delete it;

    cout<<"ContainerLinkedList"<<endl;
    ContainerLinkedList<Data> cont2;
    Data a(100),b(1000),c(10000);
    cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);

    IteratorLinkedList<Data,ContainerLinkedList<Data>> *it2=cont2.CreateIterator();
    for(it2->First();!it2->IsDone();it2->Next()){
        cout<<it2->Currently().data()<<endl;
    }
    
    return 0;
}