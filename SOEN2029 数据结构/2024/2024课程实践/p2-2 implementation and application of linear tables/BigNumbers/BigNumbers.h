//BigNumbers.h

#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

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

class BigNumbers
{
private:
	string num;

public:
	
	BigNumbers(const string&);
	BigNumbers operator+(const BigNumbers&)const;
	BigNumbers operator*(const BigNumbers&)const;
	friend ostream& operator<<(ostream&, const BigNumbers&);
	
};

#endif
