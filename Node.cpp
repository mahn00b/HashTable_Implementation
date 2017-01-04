#include "Student.h"
#include "Node.h"


template <typename T>
Node<T>::Node() { data = T(); next = NULL;}

template <typename T>
Node<T>::Node(T val){data = val; next = NULL;}
  
template <typename T>
Node<T>::~Node(){ }

template <typename T>
T Node<T>::getValue() { return data;}

template <typename T>
void Node<T>::setValue(T val) { data = val; }


template class Node<int>;
template class Node<Student>;