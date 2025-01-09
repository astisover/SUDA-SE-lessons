//main.cpp

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

int sequentialSearch(vector<int> &list, int key, bool ordered)
{
	int count = 0;
	for(int i = 0; i < list.size(); i ++)
	{
		count ++;
		if(list[i] == key)
			return count;
		else if(ordered && list[i] > key)
			break;
	}
	return -count;
}

int binarySearchNonRecursive(vector<int> &list, int key)
{
	int count = 0, left = 0, right = list.size() - 1;
	while(left <= right)
	{
		count ++;
		int mid = (left + right) / 2;
		if(list[mid] > key)
			right = mid - 1;
		else if(list[mid] < key)
			left = mid + 1;
		else
			return count;
	}
	return -count;
}

int binarySearchRecursiveHelper(vector<int> &list, int key, int left, int right, int &count)
{
	if(left > right)
		return -count;
	
	count ++;
	int mid = (left + right) / 2;
	
	if(list[mid] > key)
		return binarySearchRecursiveHelper(list, key, left, mid - 1, count);
	else if(list[mid] < key)
		return binarySearchRecursiveHelper(list, key, mid + 1, right, count);
	else
		return count;
}

int binarySearchRecursive(vector<int> &list, int key)
{
	int count = 0;
	return binarySearchRecursiveHelper(list, key, 0, list.size() - 1, count);
}

void performanceTest(vector<int>& list, int m, bool ordered) 
{
    int key = list[rand() % list.size()]; // Randomly generate search target
    int comparisons = 0;

    // Sequential search test
    auto start = high_resolution_clock::now();
    for(int i = 0; i < m; i ++) 
	{
        comparisons += abs(sequentialSearch(list, key, ordered));
    }
    auto end = high_resolution_clock::now();
    cout << "Sequential search average comparisons: " << comparisons / (double)m << endl;
    cout << "Sequential search time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    if(ordered) 
	{
        // Non-recursive binary search test
        comparisons = 0;
        start = high_resolution_clock::now();
        for(int i = 0; i < m; i ++) 
		{
            comparisons += abs(binarySearchNonRecursive(list, key));
        }
        end = high_resolution_clock::now();
        cout << "Non-recursive binary search average comparisons: " << comparisons / (double)m << endl;
        cout << "Non-recursive binary search time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

        // Recursive binary search test
        comparisons = 0;
        start = high_resolution_clock::now();
        for(int i = 0; i < m; i ++) 
		{
            comparisons += abs(binarySearchRecursive(list, key));
        }
        end = high_resolution_clock::now();
        cout << "Recursive binary search average comparisons: " << comparisons / (double)m << endl;
        cout << "Recursive binary search time: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    }
}

int main() 
{
    int n, m;
    cout << "Enter the size of the list (n): ";
    cin >> n;
    cout << "Enter the number of searches (m): ";
    cin >> m;

    vector<int> list(n);
    for(int i = 0; i < n; ++i) 
	{
        list[i] = rand() % 100000; // Generate random integers between 0 and 99999
    }

    cout << "\nTesting unordered list:" << endl;
    performanceTest(list, m, false);

    sort(list.begin(), list.end());
    cout << "\nTesting ordered list:" << endl;
    performanceTest(list, m, true);

    return 0;
}

