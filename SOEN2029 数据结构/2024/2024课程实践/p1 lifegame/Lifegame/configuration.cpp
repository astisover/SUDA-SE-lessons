//configuration.cpp

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

vector<vector<int> > count1;

void Configuration::iniBoard(int x, int y)
{
	vector<vector<char> > board1(x + 2, vector<char>(y + 2, ' '));
	vector<vector<int> > temp(x + 2, vector<int>(y + 2, 0));
	
	count = temp;
	board = board1;
	count1 = count;	
}

void Configuration::iniFromKeyboard(int x, int y)
{
	board[x][y] = '*';
}

void Configuration::iniFromFile(string &filename)
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	char ct[5];
	while( ifs.getline(ct, 5) )
	{
		int x = int(ct[0]) - 48;
		int y = int(ct[2]) - 48;
		board[x][y] = '*';
	}
	ifs.close();
}

void Configuration::boardUpdate()
{	
	for(int i = 1; i <= board.size() - 2; i ++)
	{
		for(int j = 1; j <= board[0].size() - 2; j ++)
		{
			if(board[i][j] == '*')
			{
				count[i - 1][j - 1] ++;
				count[i - 1][j] ++;
				count[i - 1][j + 1] ++;
				count[i][j - 1] ++;
				count[i][j + 1] ++;
				count[i + 1][j - 1] ++;
				count[i + 1][j] ++;
				count[i + 1][j + 1] ++;
			}
		}
	}
	
	for(int i = 1; i <= board.size() - 2; i ++)
	{
		for(int j = 1; j <= board[0].size() - 2; j ++)
		{
			if(board[i][j] == '*')
			{
				if(count[i][j] != 2 && count[i][j] != 3)
					board[i][j] = ' ';
			}
			else
			{
				if(count[i][j] == 3)
					board[i][j] = '*';
			}
		}
	}
	count = count1;
}

void Configuration::boardPrint() const
{
	for(int i = 1; i <= board.size() - 2; i ++)
	{
		for(int j = 1; j <= board[0].size() - 2; j ++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}
