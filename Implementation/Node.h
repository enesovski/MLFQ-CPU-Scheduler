#ifndef NODE_H
#define NODE_H

//Enes Ceran 
//ID: 22302324
//Section 1


template<typename T>
struct Node {

    T data;
    Node<T>* next;


    Node(const T& value)
      : data(value), next(nullptr)
    {}
};

#endif