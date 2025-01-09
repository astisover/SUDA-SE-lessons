//sort.h

#ifndef SORT_H
#define SORT_H

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

class Sort
{
private:
	
	int *data; 
    int length;	
	
    int Partition(int first, int last, int &compareTimes, int &moveTimes); 
    void Sift(int k, int last, int &compareTimes, int &moveTimes);           
    void Merge(int first1, int last1, int last2, int &compareTimes, int &moveTimes); 
    void MergePass(int h);                     

public:
	
	Sort(int r[], int n);
	void setSorter(int r[], int n);                    
    void InsertSort(int &compareTimes, int &moveTimes); 
    void ShellSort(int &compareTimes, int &moveTimes);  
    void BubbleSort(int &compareTimes, int &moveTimes);
    void SelectSort(int &compareTimes, int &moveTimes);                    
    void HeapSort(int &compareTimes, int &moveTimes);
	void QuickSort(int first, int last, int &compareTimes, int &moveTimes);                     
    void MergeSort1(int first, int last, int &compareTimes, int &moveTimes);
    void MergeSort2();   
	int getLength();                    
    void Print();  
	   
};
	
#endif
