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

template <typename Datatype>
struct ListNode
{
    Datatype val;
    ListNode* next;
    ListNode() : val(), next(nullptr) {}
    ListNode(Datatype x) : val(x), next(nullptr) {}
};

#endif

