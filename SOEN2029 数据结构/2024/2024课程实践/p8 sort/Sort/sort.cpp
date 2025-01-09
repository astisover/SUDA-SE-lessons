//sort.cpp

#include "sort.h"
#include <iostream>
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
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

Sort::Sort(int r[], int n) : data(r), length(n) {}

void Sort::InsertSort(int &compareTimes, int &moveTimes)
{
	for(int i = 1; i < length; i ++)
	{
		int cur = data[i];
 		int pos = i;
 		
 		while(data[pos - 1] > cur && pos > 0)
 		{
 			moveTimes ++;
 			compareTimes ++;
 			data[pos] = data[pos - 1];
 			pos --;
		}
		
		if(pos > 0) compareTimes ++;
		data[pos] = cur;
	}
}

void Sort::ShellSort(int &compareTimes, int &moveTimes)
{
	for(int d = length / 2; d >= 1; d /= 2)
	{
		for(int i = d; i < length; i ++)
		{
			int cur = data[i];
			int loc = i;
			
			while(loc >= d && data[loc - d] > cur)
			{
				moveTimes ++;
 				compareTimes ++;
				data[loc] = data[loc - d];
				loc -= d;
			}
			
			if(loc >= d) compareTimes ++;
			data[loc] = cur;
		}
	}
}

void Sort::BubbleSort(int &compareTimes, int &moveTimes)
{
	for(int i = 0; i < length - 1; i ++)
	{
		for(int j = i; j < length - i - 1; j ++)
		{
			compareTimes ++;
			if(data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
				moveTimes ++;
			}
		}
	}
}

int Sort::Partition(int first, int last, int &compareTimes, int &moveTimes)
{
	int i = first, j = last;
	while(i < j)
	{
		while(i < j && data[i] <= data[j])
		{
			j --;
			compareTimes ++;
		} 	
		if(i < j)
		{
			swap(data[i], data[j]);
			moveTimes ++;
			i ++;
		}
			
		
		while(i < j && data[i] <= data[j])
		{
			compareTimes ++;
			i ++;
		}
			
		if(i < j)
		{
			swap(data[i], data[j]);
			moveTimes ++;
			j --;
		}	
	}
	return i;
}

void Sort::QuickSort(int first, int last, int &compareTimes, int &moveTimes)
{
	if(first >= last)
		return;
	
	int pivot = Partition(first, last, compareTimes, moveTimes);
	
	QuickSort(first, pivot - 1, compareTimes, moveTimes);
	QuickSort(pivot + 1, last, compareTimes, moveTimes);
} 

void Sort::SelectSort(int &compareTimes, int &moveTimes)
{
	for(int i = 0; i < length - 1; i ++)
	{
		int index = i;
		for(int j = i + 1; j < length; j ++)
		{
			compareTimes ++;
			if(data[j] < data[index])
				index = j;
		}
				
		if(index != i)
		{
			moveTimes ++;
			swap(data[index], data[i]);
			
		}
	}
}

void Sort::Sift(int k, int last, int &compareTimes, int &moveTimes)
{
	int i, j;
	i = k;
	j = 2 * i + 1; //这里指的是左孩子，因为数组下标是从0开始的 
	
	while(j <= last)
	{
		compareTimes ++;
		if(j < last && data[j] < data[j + 1])
		{
			j ++;
			compareTimes ++;
		}
			
		if(data[i] < data[j])
		{
			moveTimes ++;
			swap(data[i], data[j]);
			
			i = j;
			j = 2 * i + 1; 
			//堆是从后往前建立的，但前面如果发生了变化，也许会破坏之前的堆
			//所以要对这部分重新建堆 
		} 
		else
			break;
	}
}

void Sort::HeapSort(int &compareTimes, int &moveTimes)
{
	for(int i = ceil(length / 2) - 1; i >= 0; i --)
		Sift(i, length - 1, compareTimes, moveTimes);
		
	for(int i = 1; i < length; i ++)
	{
		swap(data[0], data[length - i]);
		moveTimes ++;
		Sift(0, length - i - 1, compareTimes, moveTimes);
	}
}

void Sort::Merge(int first, int mid, int last, int &compareTimes, int &moveTimes)
{
	int *newData = new int[length];
	int i = first, j = mid + 1, pos = first;
	
	while(i <= mid && j <= last)
	{
		if(data[i] < data[j])
		{
			if(pos != i)
				moveTimes ++;
			newData[pos ++] = data[i ++];
		}
		else
		{
			if(pos != j)
				moveTimes ++;
			newData[pos ++] = data[j ++];
		}
		compareTimes ++;
	}	
		
	while(i <= mid) newData[pos ++] = data[i ++];
	while(j <= last) newData[pos ++] = data[j ++];
	
	for(int i = first; i <= last; i ++)
	{
		data[i] = newData[i];
	}
		
	delete[] newData;
}

void Sort::MergeSort1(int first, int last, int &compareTimes, int &moveTimes)
{
	if(first >= last)
		return;
		
	int mid = (first + last) / 2;
	MergeSort1(first, mid, compareTimes, moveTimes);
	MergeSort1(mid + 1, last, compareTimes, moveTimes);
	
	Merge(first, mid, last, compareTimes, moveTimes);
}

int Sort::getLength()
{
	return length;
}

void Sort::Print()
{
	for(int i = 0; i < length; i ++)
		cout << data[i] << " ";
	cout << endl;
}
