//BinaryTree.cpp

#include "BinaryTree.h"
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
#include <queue>

using namespace std;

template <typename DataType>
BinaryTree<DataType>::BinaryTree() : root(nullptr) {}

template <typename DataType>
BinaryTree<DataType>::~BinaryTree() 
{
    delTree();
}

template <typename DataType>
ListNode<DataType>* createByPreInOrderHelper(
	vector<DataType> &preOrder, int preStart, int preEnd,
	vector<DataType> &inOrder, int inStart, int inEnd,
	map<DataType, int> &mymap
)
{
	if(preStart > preEnd || inStart > inEnd)
		return nullptr;
	
	DataType rootValue = preOrder[preStart];
	
	int rootIndex = mymap[rootValue];
	int leftSize = rootIndex - inStart;
	
	ListNode<DataType>* root = new ListNode<DataType>(rootValue);
	
	root->left = createByPreInOrderHelper(
		preOrder, preStart + 1, preStart + leftSize,
		inOrder, inStart, rootIndex - 1,
		mymap
	);
	
	root->right = createByPreInOrderHelper(
		preOrder, preStart + 1 + leftSize, preEnd,
		inOrder, rootIndex + 1, inEnd, 
		mymap
	);
	
	return root;
}

template <typename DataType>
void BinaryTree<DataType>::createByPreInOrder(vector<DataType> &preOrder, vector<DataType> &inOrder)
{
	if(preOrder.size() == 0) 
	{
		root = nullptr;
		return;
	}
	
	map<DataType, int> mymap;
	for(int i = 0; i < inOrder.size(); i ++)
	{
		mymap[inOrder[i]] = i;
	}
	
	root = createByPreInOrderHelper(
		preOrder, 0, preOrder.size() - 1,
		inOrder, 0,  inOrder.size() - 1,
		mymap
	);
}

template <typename DataType>
void preOrderTraversalHelper(ListNode<DataType>* root)
{
	if(root == nullptr)
		return;
	
	cout << root->val << " ";
	preOrderTraversalHelper(root->left);
	preOrderTraversalHelper(root->right);
}

template <typename DataType>
void BinaryTree<DataType>::preOrderTraversal()const
{
	preOrderTraversalHelper(root);
}

template <typename DataType>
void inOrderTraversalHelper(ListNode<DataType>* root)
{
	if(root == nullptr)
		return;
	
	inOrderTraversalHelper(root->left);
	cout << root->val << " ";
	inOrderTraversalHelper(root->right);
}

template <typename DataType>
void BinaryTree<DataType>::inOrderTraversal()const
{
	inOrderTraversalHelper(root);
}

template <typename DataType>
void postOrderTraversalHelper(ListNode<DataType>* root)
{
	if(root == nullptr)
		return;
	
	postOrderTraversalHelper(root->left);
	postOrderTraversalHelper(root->right);
	cout << root->val << " ";
}

template <typename DataType>
void BinaryTree<DataType>::postOrderTraversal()const
{
	postOrderTraversalHelper(root);
}

template <typename DataType>
void BinaryTree<DataType>::levelTraversal()const
{
	queue<ListNode<DataType>*> myque;
	
	if(root != nullptr)
	{
		myque.push(root);
		cout << root->val << " ";
	}
	
	ListNode<DataType>* p;
	
	while(!myque.empty())
	{
		p = myque.front();
		myque.pop();
		
		if(p->left != nullptr)
		{
			cout << p->left->val << " ";
			myque.push(p->left);
		}
		
		if(p->right != nullptr)
		{
			cout << p->right->val << " ";
			myque.push(p->right);
		}
	}
}

template <typename DataType>
bool BinaryTree<DataType>::isEmpty()const
{
	return (root == nullptr);
}

template <typename DataType>
int BinaryTree<DataType>::countNodes()const
{
	queue<ListNode<DataType>*> myque;
	int ans = 0;
	
	if(root != nullptr)
	{
		myque.push(root);
		ans ++;
	}
	
	ListNode<DataType>* p;
	
	
	while(!myque.empty())
	{
		p = myque.front();
		myque.pop();
		
		if(p->left != nullptr)
		{
			ans ++;
			myque.push(p->left);
		}
		
		if(p->right != nullptr)
		{
			ans ++;
			myque.push(p->right);
		}
	}
	
	return ans;
}

template <typename DataType>
void countLeavesHelper(ListNode<DataType>* root, int &ans)
{
	if(root != nullptr)
	{
		if(root->right == nullptr && root->left == nullptr)
			ans ++;
			
		countLeavesHelper(root->left, ans);
		countLeavesHelper(root->right, ans);
	}	
}

template <typename DataType>
int BinaryTree<DataType>::countLeaves()const
{
	int ans = 0;
	countLeavesHelper(root, ans);
	return ans;
}

template <typename DataType>
void delTreeHelper(ListNode<DataType>* root) 
{
    if(root == nullptr) 
		return;
		
    delTreeHelper(root->left);
    delTreeHelper(root->right);
    delete root;
}

template <typename DataType>
void BinaryTree<DataType>::delTree() 
{
    delTreeHelper(root);
    root = nullptr;
}

template <typename DataType>
int countHeightHelper(ListNode<DataType>* root)
{
	if (!root) 
		return 0;
    return 1 + max(countHeightHelper(root->left), countHeightHelper(root->right));
}

template <typename DataType>
int BinaryTree<DataType>::countHeight()
{
    return countHeightHelper(root);
}

template <typename DataType>
int BinaryTree<DataType>::countWidth()
{
	if(root == nullptr)
		return 0;
		
	queue<ListNode<DataType>*> myque;
	myque.push(root);
	int maxWidth = 0;
	
	while(!myque.empty())
	{
		int levelWidth = myque.size();
		maxWidth = max(maxWidth, levelWidth);
		
		for(int i = 0; i < levelWidth; i ++)
		{
			ListNode<DataType>* temp = myque.front();
			myque.pop();
			
			if (temp->left != nullptr) 
				myque.push(temp->left);
				
            if (temp->right != nullptr) 
				myque.push(temp->right);
		}
	}
	
	return maxWidth;
}

template <typename DataType>
void insertNodeHelper(ListNode<DataType>* &root, DataType &node)
{
	if(root == nullptr)
	{
		root = new ListNode<DataType>(node);
		return;
	}
	
	int leftHeight = countHeightHelper(root->left);
	int rightHeight = countHeightHelper(root->right);
	
	if(leftHeight <= rightHeight)
		insertNodeHelper(root->left, node);
		
	else
		insertNodeHelper(root->right, node);
}

template <typename DataType>
void BinaryTree<DataType>::insertNode(DataType &node)
{
	insertNodeHelper(root, node);
}

template <typename DataType>
bool isMirrorTreeHelper(ListNode<DataType>* root1, ListNode<DataType>* root2)
{
    if(!root1 && !root2)
    	return true;
    
    if(!root1 || !root2)
    	return false;
    
    return (root1->val == root2->val) &&
           isMirrorTreeHelper(root1->left, root2->right) &&
           isMirrorTreeHelper(root1->right, root2->left);
}

template <typename DataType>
bool BinaryTree<DataType>::isMirrorTree(BinaryTree &other)
{
    return isMirrorTreeHelper(root, other.root);
}

template <typename DataType>
ListNode<DataType>* copyTree(ListNode<DataType>* node) 
{
    if(node == nullptr) 
        return nullptr;

    ListNode<DataType>* newNode = new ListNode<DataType>(node->val);

    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

template <typename DataType>
void BinaryTree<DataType>::copyBinaryTree(BinaryTree<DataType> &other) 
{
    root = copyTree(other.root);
}

template <typename DataType>
BinaryTree<DataType>& BinaryTree<DataType>::operator=(BinaryTree<DataType> &other)
{
	if (this == &other)
        return *this;

    root = other.root;
    return *this;
}

template class BinaryTree<char>;
