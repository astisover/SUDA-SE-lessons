//configuration.h

#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

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

class Configuration
{
private:
	vector<vector<char> > board;
	vector<vector<int> > count;
public:
	void iniBoard(int, int);
	void iniFromFile(string&);
	void iniFromKeyboard(int, int);
	void boardUpdate();
	void boardPrint()const;	
};

#endif
