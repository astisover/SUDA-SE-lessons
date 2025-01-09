//ArrayList.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

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

class UnOrderedArrayList
{
protected:
	
	int* data;
	int capacity;
	int size;
	
public:
	
	UnOrderedArrayList(int capacity = 10);
	~UnOrderedArrayList();
	bool isEmpty()const;
	bool isFull()const;
	void append(int);
	void insert(int, int);
	void replace(int, int);
	void get(int)const;
	void display()const;
	void getSize()const;
};

class OrderedArrayList: public UnOrderedArrayList
{
public:
	
	OrderedArrayList(int capacity = 10);
	void insertByValue(int);
	void insertByLocation(int, int);
	void replaceAndSort(int, int);
};

#endif
