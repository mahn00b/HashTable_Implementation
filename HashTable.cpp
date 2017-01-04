#include "HashTable.h"
#include "Student.h"
#include <iostream>

template <typename T>
HashTable<T>::HashTable() {
  
  table = new Node<T>*[20];
  
  for(int i = 0; i < 20; i++)
    table[i] = NULL;
  
  
}



template <typename T>
HashTable<T>::~HashTable() {}

template <typename T>
Node<T>* createNode(T val) { 
  
  Node<T>* temp;
  temp -> data = val;
  return temp;
  
}
 

template <typename T>
int HashTable<T>::hashFunction(T k) {  return (k%20);  }


template <typename T>
void HashTable<T>::insert(T val) {
 
 Node<T> * temp = NULL; 
 temp = search(val); 
  
 if(temp == NULL){
  
   int index = hashFunction(val);
 
  
  Node<T>* row = table[index];
  Node<T>* value = new Node<T>(val);
  Node<T>* prev = NULL;
  
  if(row == NULL)
    table[index] = value;
  else{
  
    while(row -> next != NULL && row-> next -> data < val){
	    prev = row;
            row = row -> next;     
	
    }

    
    if(row ->data > value -> data) {
      value -> next = row;
      
      
      
      if(prev != NULL)	
	 prev ->next = value;
	else 
	  table[index] = value;

    } else {
    value -> next = row -> next;
    row -> next = value;

    }
  }
 
   
} else
  std::cout<<"\nValue is already in the table!\n";
   
  
}

template <typename T>
void HashTable<T>::deleteNode(T val) {
  
  Node<T>* temp = search(val);
  
  if(temp != NULL) {
    
    int index = hashFunction(val);
    temp = table[index];
    
    if(temp -> data == val)
      table[index] = temp -> next;
    else {
    
      
      while(temp -> next -> data != val)
	temp = temp -> next;
      
      Node<T>* dd = temp -> next;
      temp -> next = dd -> next;
      temp = dd;
    
    }
    
    delete temp;
    
    
  }
  
  
  
}






template <typename T>
Node<T>* HashTable<T>::search(T val) {
  
  int index = hashFunction(val);
  
  Node<T>* row = table[index];
  
  
  while(row != NULL && row -> data != val){
   
    if(row -> data != val){
	
      if(row -> next != NULL)
	  row = row -> next;
	else
	    return NULL;
   
      
    }
	
  }
	

  return row;
  
}




template <typename T>
void HashTable<T>::printNodes(){
  
  Node<T>* temp = NULL;
  
  
  for(int i = 0 ; i < 20; i++) {
    
    
    temp = table[i];
    
    while(temp != NULL) {
      
      std::cout<<"Key: "<< i << "  Value: " << temp -> data;
      
      temp = temp -> next;
      
      
    }
    
    
    
  }
  
  
  
}




template class HashTable<int>;
template class HashTable<Student>;