//main.cpp

#include "configuration.h"
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

int main()
{
	bool flag; string filename;
	int x, y, number, x1, y1, turns;
	Configuration c1;
	cout << "This is a lifegame, so you should make sure you've already understand its rules.\n";
	cout << "Please input 0 or 1. The number 1 represents you will input data from keyboard, and number 2 from file.\n";
	cin >> flag;
	cout << "Please input the number of rows and columns of the board.\n";
	cin >> x >> y;
	c1.iniBoard(x, y);
	if(flag == 1)
	{
		cout << "Then please input the number of living cells.\n";
		cin >> number;
		cout << "and input the location of each cell.\n";
		while(number --)
		{
			cin >> x1 >> y1;
			c1.iniFromKeyboard(x1, y1);
		}
	}
	else
	{
		cout << "Please input the name of data file.\n";
		cin >> filename;
		c1.iniFromFile(filename);
	}
	
	cout << "How many turns do you want to see the changes?\n";
	cin >> turns;
	for(int i = 1; i <= turns; i ++)
	{
		cout << "turn " << i << ":\n";
		c1.boardUpdate();
		c1.boardPrint();
	}
	
	return 0;
}
