//BinaryTree.h

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "ListNode.h"
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

template <typename DataType>
class BinaryTree
{
private:
	
	ListNode<DataType> *root;

public:
	
	BinaryTree();
	~BinaryTree();
	void createByPreInOrder(vector<DataType> &, vector<DataType> &);
	void preOrderTraversal()const;
	void inOrderTraversal()const;
	void postOrderTraversal()const;
	void levelTraversal()const;
	bool isEmpty()const;
	int countNodes()const;
	int countLeaves()const;
	void delTree();
	int countHeight();
	int countWidth();
	void insertNode(DataType &);
	bool isMirrorTree(BinaryTree &);
	void copyBinaryTree(BinaryTree<DataType> &);
	BinaryTree& operator=(BinaryTree<DataType> &);
	
};

#endif
