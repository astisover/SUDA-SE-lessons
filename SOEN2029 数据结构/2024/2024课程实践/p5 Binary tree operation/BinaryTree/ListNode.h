//ListNode.h

#ifndef LISTNODE_H
#define LISTNODE_H

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

template <typename DataType>
struct ListNode
{
    DataType val;
    ListNode<DataType>* left;
	ListNode<DataType>* right;
    ListNode() : val(), left(nullptr), right(nullptr) {}
    ListNode(DataType x) : val(x), left(nullptr), right(nullptr) {}
};

#endif
