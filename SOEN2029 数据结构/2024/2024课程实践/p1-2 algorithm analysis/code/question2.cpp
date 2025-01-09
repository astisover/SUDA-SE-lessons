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
#include <chrono>

using namespace std;
using namespace chrono;

void RecursivePrint(int n)
{
	if(n > 1)
		RecursivePrint(n - 1);
	//cout << n << " ";
}

void ForPrint(int n)
{
	for(int i = 1; i <= n; i ++)
		continue;
		//cout << i << " ";
}

template<typename Function>
void testAlgorithm(Function f, int n) {
    auto start = high_resolution_clock::now();

    f(n);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Time taken: " << duration << " microseconds" << endl;
}

int main()
{
	int n;
	cin >> n;
	
	//ForPrint(n);
	//cout << endl;
	//RecursivePrint(n);
	
	testAlgorithm(ForPrint, n);
	testAlgorithm(RecursivePrint, n);
	
	return 0;
}
