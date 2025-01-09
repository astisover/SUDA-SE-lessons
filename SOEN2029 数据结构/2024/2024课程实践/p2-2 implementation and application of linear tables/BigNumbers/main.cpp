//main.cpp

#include "BigNumbers.h"
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void testFunc(string &bigint1, string &bigint2)
{
	BigNumbers num1(bigint1);
	BigNumbers num2(bigint2);
	
	cout << "The sum is: " << num1 + num2 << endl;
	cout << "The product is: " << num1 * num2 << endl;
	
	return;
}

BigNumbers dfs(int n, map<int, BigNumbers> &numTable)
{
	if(!numTable.count(n))
	{
		numTable[n] = BigNumbers("0");
		for(int i = 1; i <= n / 2; i ++)
			numTable[n] = numTable[n] + BigNumbers("1") + dfs(i, numTable);	
	}	
	return numTable[n];
}

int main(int argc, char** argv) 
{
	//string bigint1, bigint2;
	//cin >> bigint1 >> bigint2;
	
	//testFunc(bigint1, bigint2);
	
	int n;
	cin >> n;
	
	map<int, BigNumbers> numTable;
	
	cout << dfs(n, numTable) + BigNumbers("1");
	return 0;
}
