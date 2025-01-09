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

void maxSubArray1(vector<int> &nums, int n)
{
	int maxsum = 0, start = -1, end = -1;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			int tempsum = 0;
			for(int k = i; k <= j; k ++)
				tempsum += nums[k];
			if(tempsum > maxsum)
			{
				maxsum = tempsum;
				start = i;
				end = j;
			}	
		}
	}
	cout << maxsum << " ";
	
	if(end != -1)
		cout << start << "-" << end;
	cout << endl;	
}

void maxSubArray2(vector<int> &nums, int n)
{
	int maxsum = 0, start = -1, end = -1;
	for(int i = 0; i < n; i ++)
	{
		int tempsum = 0;
		for(int j = i; j < n; j ++)
		{
			tempsum += nums[j];
			if(tempsum > maxsum)
			{
				maxsum = tempsum;
				start = i;
				end = j;
			}
		}
	}
	cout << maxsum << " ";
	
	if(end != -1)
		cout << start << "-" << end;
	cout << endl;
}

void maxSubArray3(vector<int> &nums, int n)
{
	int maxsum = 0, tempsum = 0, start = 0, end = -1;
	for(int j = 0; j < n; j ++)
	{
		tempsum += nums[j];
		if(tempsum > maxsum)
		{
			maxsum = tempsum;
			end = j;
		}
		else if(tempsum < 0)
		{
			tempsum = 0;
			start = j + 1;
		}
	}
	cout << maxsum << " ";
	
	if(end != -1)
		cout << start << "-" << end;
	cout << endl;
}

void randNums(vector<int> &nums, int n)
{
	srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < n; ++i) 
	{
        int randomNumber = rand() % 201 - 100;
        nums.push_back(randomNumber);
        cout << randomNumber;

        if (i < n - 1) 
            cout << " ";
        else
        	cout << endl;
    }
}

int main()
{
	int n, num;
	vector<int> nums;
	cin >> n;
	randNums(nums, n);
	
	maxSubArray1(nums, n);
	maxSubArray2(nums, n);
	maxSubArray3(nums, n);
		 
	return 0;
}
