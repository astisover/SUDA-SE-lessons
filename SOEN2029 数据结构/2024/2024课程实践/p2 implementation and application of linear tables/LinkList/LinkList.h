//LinkList.h

#ifndef LINKLIST_H
#define LINKLIST_H

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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode* last;
    ListNode(int x): val(x), next(nullptr), last(nullptr){}
};

class LinkList
{
public:
	
	ListNode* dummyHead;
	ListNode* dummyTail;
	int listlen;
	~LinkList();
	int getIndex(int)const;
	int searchNum(int)const;	
	void display()const;
	virtual void insert(int, int) = 0;
	virtual void deleteByIndex(int) = 0;
	virtual bool deleteByNum(int) = 0;
	
};

class SingleLink : public LinkList
{
public:
	
	SingleLink();
	SingleLink(vector<int>&);
	void insert(int, int) override;
	void deleteByIndex(int) override;
	bool deleteByNum(int) override;
	
};

class IterSingleLink : public LinkList
{
public:
	
	IterSingleLink();
	IterSingleLink(vector<int>&);
	void insert(int, int) override;
	void deleteByIndex(int) override;
	bool deleteByNum(int) override;
	
};

class DoubleLink : public LinkList
{
public:
	
	DoubleLink();
	DoubleLink(vector<int>&);
	void insert(int, int) override;
	void deleteByIndex(int) override;
	bool deleteByNum(int) override;
	
};

#endif
