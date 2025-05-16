#ifndef QUEUE_CPP
#define QUEUE_CPP

//Enes Ceran 
//ID: 22302324
//Section 1

#include "Queue.h"
#include "Process.h"
#include <iostream>

using namespace std;

//DEFAULT CONSTRUCTOR
template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), length(0) {}

//DESTRUCTOR
template <typename T>
Queue<T>::~Queue() 
{
    clear();
} 

//COPY CONSTRUCTOR
template <typename T>
Queue<T>::Queue(const Queue& other) : head(nullptr), tail(nullptr), length(0)
{
    for (Node<T>* cur = other.head; cur != nullptr; cur = cur->next)
    {
        enqueue(cur->data);
    }

}

//ASSIGNMENT OPERATOR
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this == &other)          
        return *this;
    clear();              
    for (Node<T>* cur = other.head; cur != nullptr; cur = cur->next)
    {
        enqueue(cur->data);
    }

    return *this;
}


template <typename T>
void Queue<T>::enqueue(const T& item)
{
    Node<T>* node = new Node<T>(item);

    if(tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }

    length++;

}



template <typename T>
void Queue<T>::dequeue()
{
    if(isEmpty())
    {
        cout << "Error: Dequeue on empty queue" << endl;
        return;
    }

    Node<T>* dequeued = head;
    head = head -> next;

    if(head == nullptr)
    {
        tail = nullptr;
    }

    delete dequeued;
    length --;

}

template <typename T>
void Queue<T>::reEnqueue()
{
    if (isEmpty()) 
        return;     

    T item = peek();
    dequeue();
    enqueue(item);
}


template <typename T>
T& Queue<T>::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Peek on empty");
    }
    return head->data;

}

template <typename T>
const T& Queue<T>::peek() const
{
    if (isEmpty())
    {
        throw runtime_error("Peek on empty");
    }
    return head->data;

}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return length == 0;
}

template <typename T>
int Queue<T>::size() const
{
    return length;
}

template <typename T>
void Queue<T>::clear()
{
    while (head != nullptr)
    {
        Node<T>* next = head->next;
        delete head;
        head = next;
    }

    tail   = nullptr;
    length = 0;
}

#endif 
