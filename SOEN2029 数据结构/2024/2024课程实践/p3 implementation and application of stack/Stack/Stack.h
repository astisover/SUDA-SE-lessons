//Stack.h

#ifndef STACK_H
#define STACK_H

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
struct ListNode
{
	Datatype val;
	ListNode* next;
	ListNode(): val(), next(nullptr) {}
	ListNode(Datatype x): val(x), next(nullptr) {}
};

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
