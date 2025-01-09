//main.cpp

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int dfs(int n, map<int, int> &numTable)
{
	if(!numTable.count(n))
	{
		numTable[n] = 0;
		for(int i = 1; i <= n / 2; i ++)
			numTable[n] += 1 + dfs(i, numTable);	
	}	
	return numTable[n];
}

int main()
{
	int n;
	cin >> n;
	map<int, int> numTable;
	cout << dfs(n, numTable) + 1;
	return 0;
}
