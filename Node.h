#ifndef NODE_H
#define NODE_H


#include <stddef.h>

 
template <class T> class HashTable;
  


template <class T>
class Node {
  
  
  friend class HashTable<T>;

  T data;
  Node<T>* next;
  
  
  
public:
    
  Node();
  Node(T val);
  ~Node();
  T getValue();
  void setValue(T val);
 
  

};



#endif
