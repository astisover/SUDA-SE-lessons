//Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "ListNode.h"
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
class Queue
{
private:
	
    ListNode<Datatype>* front;
    ListNode<Datatype>* rear;

public:
	
    Queue();
    void push(Datatype);
    Datatype pop();
    Datatype peek() const;
    bool isEmpty() const;
    void printOut() const;
};

#endif

