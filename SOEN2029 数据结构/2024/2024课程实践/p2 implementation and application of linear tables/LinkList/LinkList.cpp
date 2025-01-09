//LinkList.cpp

#include "LinkList.h"
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

LinkList::~LinkList()
{
    ListNode* current = dummyHead;
    ListNode* temp;

    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
}

int LinkList::getIndex(int ind)const
{
	ListNode* p1 = dummyHead;
	
	while(ind --)
		p1 = p1->next;
		
	return p1->val;
}

int LinkList::searchNum(int num)const
{
	int count = 1;
	ListNode* p1 = dummyHead->next;
	
	while(p1->val != num)
	{
		p1 = p1->next;
		count ++;
	}
	
	return count;	
}

void LinkList::display()const
{
	ListNode* p1 = dummyHead;
	
	while(p1->next != nullptr && p1->next != dummyHead)
	{
		p1 = p1->next;
		cout << p1->val << " ";
	}
}



SingleLink::SingleLink()
{
	dummyHead = new ListNode(0);
	listlen = 0;
}

SingleLink::SingleLink(vector<int> &nums)
{
	dummyHead = new ListNode(0);
	listlen = 0;
	ListNode* p1 = dummyHead;
	
	for(int i = 0; i < nums.size(); i ++)
	{
		ListNode* temp = new ListNode(nums[i]);
		p1->next = temp;
		p1 = temp;
		listlen ++;
	}
}

void SingleLink::insert(int ind, int val)
{
	if(ind < 1 || ind > listlen + 1)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	ListNode* p1 = dummyHead;
	ListNode* temp = new ListNode(val);
	
	for(int i = 1; i < ind; i ++)
		p1 = p1->next;
		
	temp->next = p1->next;
	p1->next = temp;
	listlen ++;
	
	cout << "Inserted " << val << " at index " << ind << "." << endl;
}

void SingleLink::deleteByIndex(int ind)
{
	int index = ind;
	if(ind < 1 || ind > listlen)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(ind --)
	{
		p2 = p1;
		p1 = p1->next;
	}
		
	p2->next = p1->next;
	delete p1;
	listlen --;
	
	cout << "Deleted element at index " << index << "." << endl;
}

bool SingleLink::deleteByNum(int num)
{
	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(p1->next != nullptr)
	{
		p2 = p1;
		p1 = p1->next;
		if(p1->val == num)
		{
			p2->next = p1->next;
			listlen --;
			delete p1;
			return true;
		}
	}
	return false;
}




IterSingleLink::IterSingleLink()
{
	dummyHead = new ListNode(0);
	dummyHead->next = dummyHead;
	listlen = 0;
}

IterSingleLink::IterSingleLink(vector<int> &nums)
{
	dummyHead = new ListNode(0);
	listlen = 0;
	ListNode* p1 = dummyHead;
	
	for(int i = 0; i < nums.size(); i ++)
	{
		ListNode* temp = new ListNode(nums[i]);
		p1->next = temp;
		p1 = temp;
		listlen ++;
	}
}

void IterSingleLink::insert(int ind, int val)
{
	if(ind < 1 || ind > listlen + 1)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	ListNode* p1 = dummyHead;
	ListNode* temp = new ListNode(val);
	
	for(int i = 1; i < ind; i ++)
		p1 = p1->next;
		
	temp->next = p1->next;
	p1->next = temp;
	listlen ++;
	
	cout << "Inserted " << val << " at index " << ind << "." << endl;
}

void IterSingleLink::deleteByIndex(int ind)
{
	int index = ind;
	if(ind < 1 || ind > listlen)
	{
		cout << "Invalid index!" << endl;
		return;
	}

	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(ind --)
	{
		p2 = p1;
		p1 = p1->next;
	}
		
	p2->next = p1->next;
	delete p1;
	listlen --;
	
	cout << "Deleted element at index " << index << "." << endl;
}

bool IterSingleLink::deleteByNum(int num)
{
	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(p1->next != dummyHead)
	{
		p2 = p1;
		p1 = p1->next;
		if(p1->val == num)
		{
			p2->next = p1->next;
			listlen --;
			delete p1;
			return true;
			break;
		}
	}
	return false;
}




DoubleLink::DoubleLink()
{
	dummyHead = new ListNode(0);
	dummyHead->next = dummyTail;
	dummyTail->last = dummyHead;
	dummyTail = new ListNode(0);
	listlen = 0;
}

DoubleLink::DoubleLink(vector<int> &nums)
{
	dummyHead = new ListNode(0);
	listlen = 0;
	ListNode* p1 = dummyHead;
	
	for(int i = 0; i < nums.size(); i ++)
	{
		ListNode* temp = new ListNode(nums[i]);
		p1->next = temp;
		temp->last = p1;
		p1 = temp;
		listlen ++;
	}
}

void DoubleLink::insert(int ind, int val)
{
	if(ind < 1 || ind > listlen + 1)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	ListNode* p1 = dummyHead;
	ListNode* temp = new ListNode(val);
	
	for(int i = 1; i < ind; i ++)
		p1 = p1->next;
		
	temp->next = p1->next;
	p1->next->last = temp;
    p1->next = temp;
    temp->last = p1;
    listlen ++;
    
    cout << "Inserted " << val << " at index " << ind << "." << endl;
}

void DoubleLink::deleteByIndex(int ind)
{
	int index = ind;
	if(ind < 1 || ind > listlen)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(ind --)
	{
		p2 = p1;
		p1 = p1->next;
	}
		
	p2->next = p1->next;
	p1->next->last = p2;
	delete p1;
	listlen --;
	
	cout << "Deleted element at index " << index << "." << endl;
}

bool DoubleLink::deleteByNum(int num)
{
	ListNode* p1 = dummyHead;
	ListNode* p2;
	
	while(p1->next != nullptr)
	{
		p2 = p1;
		p1 = p1->next;
		if(p1->val == num)
		{
			p2->next = p1->next;
			p1->next->last = p2;
			listlen --;
			delete p1;
			return true;
			break;
		}
	}
	return false;
}
