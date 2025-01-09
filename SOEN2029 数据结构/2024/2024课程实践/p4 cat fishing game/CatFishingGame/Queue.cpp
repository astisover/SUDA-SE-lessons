//Queue.cpp

#include "Queue.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

template <typename Datatype>
Queue<Datatype>::Queue() : front(nullptr), rear(nullptr) {}

template <typename Datatype>
void Queue<Datatype>::push(Datatype x)
{
    ListNode<Datatype>* temp = new ListNode<Datatype>(x);
    if (rear)
    {
        rear->next = temp;
    }
    
    else
    {
        front = temp; 
    }
    rear = temp; 
}

template <typename Datatype>
Datatype Queue<Datatype>::pop()
{
    if (front == nullptr)
    {
        cout << "Queue is empty!" << endl;
        return Datatype();
    }
    
    else
    {
        Datatype num = front->val;
        ListNode<Datatype>* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return num;
    }
}

template <typename Datatype>
Datatype Queue<Datatype>::peek() const
{
    if (front == nullptr)
    {
        cout << "Queue is empty!" << endl;
        return Datatype();
    }
    
    else
    {
        return front->val;
    }
}

template <typename Datatype>
bool Queue<Datatype>::isEmpty() const
{
    return (front == nullptr);
}

template <typename Datatype>
void Queue<Datatype>::printOut() const
{
    ListNode<Datatype>* pc = front;
    while (pc != nullptr)
    {
        cout << pc->val << " ";
        pc = pc->next;
    }
    cout << endl;
}


template class Queue<int>;
template class Queue<double>;
template class Queue<string>;

