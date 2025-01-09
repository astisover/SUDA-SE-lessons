//main.cpp

#include "Stack.h"
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

map<string, int> mymap = 
{
    {"+", 3}, {"-", 3},
    {"*", 4}, {"/", 4},
    {"(", 2}, {")", 2},
    {"#", 1}
};

double operation(double num1, double num2, const string &x)
{
    if (x == "+")
        return (num1 + num2);
    else if (x == "-")
        return (num1 - num2);
    else if (x == "*")
        return (num1 * num2);
    else
        return (num1 / num2);
}

void infixSolu(string &s)
{
    Stack<double> infNum;
    Stack<string> infOpe;
    infOpe.push("#");
    string temp = "";

    for (auto &x : s)
    {
        if (!mymap.count(string(1, x)))
            temp += x;
        else
        {
            if (temp != "")
            {
                infNum.push(stod(temp));
                temp = "";
            }

            string ope1 = string(1, x);
            string ope2 = infOpe.peek();

            while (ope1 != "#" || ope2 != "#") 
            {
                if (ope1 == "(") 
                {
                    infOpe.push(ope1);
                    break;
                } 
                else if (ope2 == "(" && ope1 == ")") 
                {
                    infOpe.pop();
                    break;
                } 
                else if (mymap[ope1] > mymap[ope2]) 
                {
                    infOpe.push(ope1);
                    break;
                } 
                else 
                {
                    double num2 = infNum.pop();
                    double num1 = infNum.pop();
                    infNum.push(operation(num1, num2, ope2));
                    infOpe.pop();
                    ope2 = infOpe.peek();
                }
            }
        } 
    }

    cout << infNum.pop() << endl;
}

void suffixSolu(string &s)
{
    Stack<double> sufNum;
    string temp = "";

    int x = 0;
    while (x < s.size())
    {
        while (!mymap.count(string(1, s[x])) && s[x] != '#')
        {
            if (s[x] != ' ')
            {
                temp += s[x];
            }
            else
            {
                sufNum.push(stod(temp));
                temp = "";
            }

            x++;
        }

        while (mymap.count(string(1, s[x])) || s[x] == ' ')
        {
            if (s[x] != ' ' && s[x] != '#')
            {
                double num2 = sufNum.pop();
                double num1 = sufNum.pop();
                sufNum.push(operation(num1, num2, string(1, s[x])));
            }

            x++;
        }   
    }

    cout << sufNum.pop() << endl;
}

void prefixSolu(string &s)
{
    vector<string> s1;
    stringstream ss(s);
    string temp;

    while (ss >> temp) {
        s1.push_back(temp);
    }

    Stack<double> prefNum;

    int x = s1.size() - 1;
    while (x >= 0)
    {
        while (x >= 0 && !mymap.count(s1[x]))
        {
            prefNum.push(stod(s1[x]));
            x --;
        }

        while (x >= 0 && mymap.count(s1[x]))
        {
            double num1 = prefNum.pop();
            double num2 = prefNum.pop();
            prefNum.push(operation(num1, num2, s1[x]));
            x --;
        } 
    }

    cout << prefNum.pop() << endl;
}

int main()
{
    string s;
    cout << "Please input the series:\n";
    getline(cin, s);
    string x;

    cout << "Which expression is it? (p: prefix, i: infix, s: suffix)\n";
    cin >> x;

    if (x == "i")    
        infixSolu(s);
        
    else if (x == "p")
        prefixSolu(s);
        
    else if (x == "s")
        suffixSolu(s);

    return 0;
}

