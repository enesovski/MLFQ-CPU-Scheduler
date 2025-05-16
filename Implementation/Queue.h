#ifndef QUEUE_H
#define QUEUE_H

//Enes Ceran 
//ID: 22302324
//Section 1

#include "Node.h"

template <typename T>
class Queue
{
public:
    Queue();                                 
    ~Queue();                                  

    //copy - assignment
    Queue(const Queue& other);                 
    Queue& operator=(const Queue& other);      

    void enqueue(const T& item);   
    void dequeue();       
    void reEnqueue();   

    T& peek();          
    const T& peek() const;             
   
    bool isEmpty() const;
    int size() const;

    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

        void clear();

};

#endif 

#include "Queue.cpp"