#ifndef QUEUE_H
#define QUEUE_H

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

    //move
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;


    void enqueue(const T& item);   
    void dequeue();          

    T& peek();          
    const T& peek() const;             
   
    bool isEmpty() const;
    int size() const;

    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

        void clear();
        void swap(Queue& other) noexcept;   // <— new helper

};

#endif 
