//BigNumbers.cpp

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

using namespace std;

BigNumbers::BigNumbers(const string &val) : num(val)
{
	while(num.size() > 1 && num[0] == '0')
		num.erase(0, 1);
}

BigNumbers BigNumbers::operator+(const BigNumbers& other)const
{
	string num1 = num;
	string num2 = other.num;
	string result;
	int carry = 0, sum = 0;
	
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	
	while(i >= 0 || j >= 0 || carry)
	{
		int digit1 = (i >= 0) ? num1[i --] - '0' : 0;
		int digit2 = (j >= 0) ? num2[j --] - '0' : 0;
		
		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result += sum % 10 + '0';
	}
	reverse(result.begin(), result.end());
	
	return BigNumbers(result);	
}

BigNumbers BigNumbers::operator*(const BigNumbers& other)const
{	
	string num1 = num;
	string num2 = other.num;
	vector<int> result(num1.size() + num2.size(), 0);
	
	for(int i = num2.size() - 1; i >= 0; i --)
	{
		for(int j = num1.size() - 1; j >= 0; j --)
		{
			int digit1 = num1[j] - '0';
			int digit2 = num2[i] - '0';
			int sum = digit1 * digit2 + result[i + j + 1];
			
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
	
	string product = "";
	for(int i : result)
		product += i + '0';

	return BigNumbers(product);
}

ostream& operator<<(ostream &os, const BigNumbers &bignum)
{
	os << bignum.num;
	return os;
}

