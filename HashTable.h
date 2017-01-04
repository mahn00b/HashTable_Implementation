#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

#include "Node.h"




template <class T> class Node;


template <typename T>
class HashTable {
  
  Node<T>** table;
  int hashFunction(T k);
  Node<T>* createNode(T val);
   
public:
  
  
  HashTable();
  ~HashTable();
  
 void insert(T val);
 void deleteNode(T val);
 Node<T>* search(T val);
 void printNodes();
  
  
  
  
  
  
};



#endif