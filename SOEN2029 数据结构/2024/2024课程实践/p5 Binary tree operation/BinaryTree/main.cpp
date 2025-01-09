//main.cpp

#include "BinaryTree.h"
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

void printMenu()
{
    cout << "==== Binary Tree Operations ====" << endl;
    cout << "1. Build tree using preorder and inorder sequences" << endl;
    cout << "2. Preorder traversal (recursive)" << endl;
    cout << "3. Inorder traversal (recursive)" << endl;
    cout << "4. Postorder traversal (recursive)" << endl;
    cout << "5. Level order traversal" << endl;
    cout << "6. Count nodes" << endl;
    cout << "7. Count leaves" << endl;
    cout << "8. Count height" << endl;
    cout << "9. Count width" << endl;
    cout << "10. Insert a new node in the tree" << endl;
    cout << "11. Check if two trees are mirror images" << endl;
    cout << "12. Copy binary tree" << endl;
    cout << "13. Assign operator (=) for binary tree" << endl;
    cout << "14. Clear the tree" << endl;
    cout << "0. Exit" << endl;
    cout << "=================================" << endl;
}

int main()
{
    BinaryTree<char> tree1, tree2; // Create two trees
    vector<char> preorder, inorder; // To hold the sequences
    int choice;
    char nodeValue;

    while (true)
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: 
            {
                cout << "Enter the preorder sequence (no spaces): ";
                string preOrderStr;
                cin >> preOrderStr;
                preorder.clear();
                for (char ch : preOrderStr)
                {
                    preorder.push_back(ch);
                }

                cout << "Enter the inorder sequence (no spaces): ";
                string inOrderStr;
                cin >> inOrderStr;
                inorder.clear();
                for (char ch : inOrderStr)
                {
                    inorder.push_back(ch);
                }

                tree1.createByPreInOrder(preorder, inorder);
                cout << "Tree1 built successfully!" << endl;
            }
            break;

            case 2: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Preorder traversal: ";
                    tree1.preOrderTraversal();
                    cout << endl;
                }
            }
            break;

            case 3: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Inorder traversal: ";
                    tree1.inOrderTraversal();
                    cout << endl;
                }
            }
            break;

            case 4: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Postorder traversal: ";
                    tree1.postOrderTraversal();
                    cout << endl;
                }
            }
            break;

            case 5: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Level order traversal: ";
                    tree1.levelTraversal();
                    cout << endl;
                }
            }
            break;

            case 6: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Node count: " << tree1.countNodes() << endl;
                }
            }
            break;

            case 7: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Leaf count: " << tree1.countLeaves() << endl;
                }
            }
            break;

            case 8: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Tree1 height: " << tree1.countHeight() << endl;
                }
            }
            break;

            case 9: 
            {
                if (tree1.isEmpty())
                {
                    cout << "Tree1 is empty. Please build a tree first!" << endl;
                }
                else
                {
                    cout << "Tree1 width: " << tree1.countWidth() << endl;
                }
            }
            break;

            case 10: 
            {
                cout << "Enter the value of the node to insert: ";
                cin >> nodeValue;
                tree1.insertNode(nodeValue);
                cout << "Node inserted successfully!" << endl;
            }
            break;

            case 11: 
            {
                cout << "Enter the preorder sequence (no spaces): ";
                string preOrderStr1;
                cin >> preOrderStr1;
                preorder.clear();
                for (char ch : preOrderStr1)
                {
                    preorder.push_back(ch);
                }

                cout << "Enter the inorder sequence (no spaces): ";
                string inOrderStr1;
                cin >> inOrderStr1;
                inorder.clear();
                for (char ch : inOrderStr1)
                {
                    inorder.push_back(ch);
                }
				
                tree2.createByPreInOrder(preorder, inorder);
                cout << "Tree2 built successfully!" << endl;

                if (tree1.isMirrorTree(tree2))
                {
                    cout << "The trees are mirror images!" << endl;
                }
                else
                {
                    cout << "The trees are not mirror images!" << endl;
                }
            }
            break;

            case 12: 
            {
                tree2.copyBinaryTree(tree1); // Using overloaded assignment operator
                cout << "Tree2 copied from tree1!" << endl;
            }
            break;

            case 13: 
            {
                cout << "Assigning tree1 to tree2..." << endl;
                tree2 = tree1;
                cout << "Tree assigned successfully!" << endl;
            }
            break;

            case 14: 
            {
                tree1.delTree();
                cout << "Tree cleared!" << endl;
            }
            break;

            case 0: 
            {
                cout << "Exiting the program." << endl;
                return 0;
            }
            break;

            default: 
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        }

        cout << endl;
    }

    return 0;
}
