//Stack.cpp

#include "Stack.h"
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
Stack<Datatype>::Stack()
{
	p = new ListNode<Datatype>();	
}

template <typename Datatype>
void Stack<Datatype>::push(Datatype x)const
{
	ListNode<Datatype>* temp = new ListNode<Datatype>(x);
	temp->next = p->next;
	p->next = temp;	
}

template <typename Datatype>
Datatype Stack<Datatype>::pop()
{
	if(p->next == nullptr)
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}
	else
	{
		Datatype num = p->next->val;
		ListNode<Datatype>* temp = p->next;
		p->next = p->next->next;
		delete temp;
		return num;
	}	
}

template <typename Datatype>
Datatype Stack<Datatype>::peek()const
{
	if(p->next == nullptr)
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}
	else
	{
		return p->next->val;
	}
}

template <typename Datatype>
bool Stack<Datatype>::isEmpty()const
{
	return (p->next == nullptr);
}

template <typename Datatype>
void Stack<Datatype>::printOut()const
{
	ListNode<Datatype>* pc = p->next;
	while(pc != nullptr)
	{
		cout << pc->val << " ";
		pc = pc->next;
	}
	cout << endl;
}

template class Stack<double>;
template class Stack<string>; 
