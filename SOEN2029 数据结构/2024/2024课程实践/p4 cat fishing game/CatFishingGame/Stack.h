//Stack.h

#ifndef STACK_H
#define STACK_H

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
class Stack
{
private:
	
	ListNode<Datatype>* p;

public:
	
	Stack();
	void push(Datatype)const;
	Datatype pop();
	Datatype peek()const;
	bool isEmpty()const;
	void printOut()const;
};

#endif
