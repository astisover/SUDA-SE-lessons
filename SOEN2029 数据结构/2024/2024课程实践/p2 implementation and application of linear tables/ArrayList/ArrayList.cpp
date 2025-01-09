//ArrayList.cpp

#include "ArrayList.h"
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

UnOrderedArrayList::UnOrderedArrayList(int capacity)
{
	this->capacity = capacity;
	data = new int[capacity];
	size = 0;
}

UnOrderedArrayList::~UnOrderedArrayList()
{
	delete[] data;
}

bool UnOrderedArrayList::isEmpty()const
{
	return size == 0;
}

bool UnOrderedArrayList::isFull()const
{
	return size == capacity;
}

void UnOrderedArrayList::append(int val)
{
	if(isFull())
	{
		cout << "ArrayList is Full!" << endl;
		return;
	}
	
	data[size ++] = val;
}

void UnOrderedArrayList::insert(int ind, int val)
{
	if(ind < 0 || ind > size)
	{
		cout << "Invalid index!" << endl;
	}
	else if(isFull())
	{
		cout << "ArrayList is Full!" << endl;
	}
	else
	{
		for(int i = size + 1; i > ind; i --)
		{
			data[i] = data[i - 1];
		}
		
		data[ind] = val;
		size ++;
	}
}

void UnOrderedArrayList::replace(int ind, int val)
{
	if(ind < 0 || ind > size)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	
	data[ind] = val;
}

void UnOrderedArrayList::get(int ind)const
{
	if(ind < 0 || ind >= size)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	cout << data[ind] << endl;
	return;
}

void UnOrderedArrayList::display()const
{
	for(int i = 0; i < size; i ++)
		cout << data[i] << " ";
	cout << endl;
	return;
}

void UnOrderedArrayList::getSize()const
{
	cout << size << endl;
	return;
}
OrderedArrayList::OrderedArrayList(int capacity) : UnOrderedArrayList(capacity) {}

void OrderedArrayList::insertByValue(int val)
{
	if(isFull())
	{
		cout << "ArrayList is Full!" << endl;
		return;
	}
	
	int i = size - 1;
	while(i >= 0 && data[i] > val)
	{
		data[i + 1] = data[i];
		i --;
	}
	
	data[i + 1] = val;
	size ++;
}

void OrderedArrayList::insertByLocation(int ind, int val)
{

	insert(ind, val);
	sort(data, data + size);
}

void OrderedArrayList::replaceAndSort(int ind, int val)
{
	replace(ind, val);
	sort(data, data + size);
}
