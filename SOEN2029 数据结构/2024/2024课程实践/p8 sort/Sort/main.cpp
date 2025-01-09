//main.cpp

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

void createFile(const string& filename, int length, const string& order) 
{
    ofstream file(filename);
    vector<int> data(length);

    if (order == "ascending") 
    {
        for (int i = 0; i < length; i++) 
        {
            data[i] = i + 1;
        }
    }
    else if (order == "descending") 
    {
        for (int i = 0; i < length; i++) 
        {
            data[i] = length - i;
        }
    }
    else if (order == "random") 
    {
        srand(time(0));
        for (int i = 0; i < length; i++) 
        {
            data[i] = rand() % 10000;
        }
    }

    for (int i = 0; i < length; i++) 
    {
        file << data[i] << " ";
    }
    file.close();
}

vector<int> readFile(const string& filename) 
{
    ifstream file(filename);
    vector<int> data;
    int value;
    
    while(file >> value) 
        data.push_back(value);

    file.close();
    return data;
}

void sortAndTime1(Sort& sorter, void (Sort::*sortFunction)(int&, int&), const string& sortName) 
{
    int compareTimes = 0, moveTimes = 0;
    
    auto start = high_resolution_clock::now();
    
    (sorter.*sortFunction)(compareTimes, moveTimes);
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    
    cout << sortName << " took " << duration << " ms." << endl;
    cout << "Compare Times: " << compareTimes << ", Move Times: " << moveTimes << endl;
    cout << endl;
}

void sortAndTime2(Sort& sorter, void (Sort::*sortFunction)(int, int, int&, int&), const string& sortName)
{
    int compareTimes = 0, moveTimes = 0;

    auto start = high_resolution_clock::now();

    (sorter.*sortFunction)(0, sorter.getLength() - 1, compareTimes, moveTimes);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << sortName << " took " << duration << " ms." << endl;
    cout << "Compare Times: " << compareTimes << ", Move Times: " << moveTimes << endl;
    cout << endl;
}

int main() 
{
    // 创建测试数据文件
    createFile("ascending_20.txt", 20, "ascending");
    createFile("descending_20.txt", 20, "descending");
    createFile("random_20.txt", 20, "random");
    
    createFile("ascending_200.txt", 200, "ascending");
    createFile("descending_200.txt", 200, "descending");
    createFile("random_200.txt", 200, "random");
    
    createFile("ascending_2000.txt", 2000, "ascending");
    createFile("descending_2000.txt", 2000, "descending");
    createFile("random_2000.txt", 2000, "random");
    
    vector<int> data1, data2, data3, data4, data5, data6, data7;
    vector<string> filenames{"ascending_20.txt", "descending_20.txt", "random_20.txt",
                             "ascending_200.txt", "descending_200.txt", "random_200.txt",
                             "ascending_2000.txt", "descending_2000.txt", "random_2000.txt"};
    

    for(const string& filename : filenames) 
	{
	    cout << "Testing file: " << filename << endl;
	    cout << endl;
	    
	    ifstream file(filename);
	    vector<int> originalData;
	    int value;
	    
	    while(file >> value) 
	        originalData.push_back(value);
	
	    file.close();
	
	    data1 = originalData;
	    Sort sorter1(data1.data(), data1.size());
	    sortAndTime1(sorter1, &Sort::InsertSort, "InsertSort");
	
		data2 = originalData;
	    Sort sorter2(data2.data(), data2.size());
	    sortAndTime1(sorter2, &Sort::BubbleSort, "BubbleSort");
	
	    data3 = originalData;
	    Sort sorter3(data3.data(), data3.size());
	    sortAndTime1(sorter3, &Sort::SelectSort, "SelectSort");
	
	    data4 = originalData;
	    Sort sorter4(data4.data(), data4.size());
	    sortAndTime1(sorter4, &Sort::ShellSort, "ShellSort");
	
	    data5 = originalData;
	    Sort sorter5(data5.data(), data5.size());
	    sortAndTime1(sorter5, &Sort::HeapSort, "HeapSort");
	
	    data6 = originalData;
	    Sort sorter6(data6.data(), data6.size());
	    sortAndTime2(sorter6, &Sort::MergeSort1, "MergeSort1");
	
	    data7 = originalData;
	    Sort sorter7(data7.data(), data7.size());
	    sortAndTime2(sorter7, &Sort::QuickSort, "QuickSort");
	
	    cout << "---------------------------------" << endl;
	}
	
    return 0;
}

