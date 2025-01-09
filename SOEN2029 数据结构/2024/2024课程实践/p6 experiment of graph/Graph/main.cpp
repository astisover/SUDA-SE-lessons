//main.cpp

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "Graph.h"
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

void ass1(ifstream &ifs)
{
    if(!ifs)
    {
        cerr << "Error: Failed to open the file 'graph1.txt'." << endl;
        return;
    }

    // 创建图
    Graph graph(ifs);

    int startNode;
    cout << "Enter the starting node for traversal: ";
    cin >> startNode;

    // 检查输入节点是否有效
    if(startNode < 0 || startNode >= MaxSize)
    {
        cerr << "Error: Invalid starting node! Please enter a valid node index (0-" << MaxSize - 1 << ")." << endl;
        return;
    }

    cout << "\nDepth First Search using adjacency matrix:" << endl;
    graph.adjMatrixDfs(startNode);

    cout << "\nBreadth First Search using adjacency list:" << endl;
    graph.adjLineBfs(startNode);
}

void ass2(ifstream &ifs)
{
	if(!ifs)
    {
        cerr << "Error: Failed to open the file 'graph2.txt'." << endl;
        return;
    }

    // 创建图
    Graph graph(ifs);
    
    int startNode, endNode;
    cout << "Enter the starting node and the ending node: ";
    cin >> startNode >> endNode;
    
    if(startNode < 0 || startNode >= MaxSize)
    {
        cerr << "Error: Invalid starting or ending node! Please enter a valid node index (0-" << MaxSize - 1 << ")." << endl;
        return;
    }
    
    graph.startToEnd(startNode, endNode);
}

int main()
{
    ifstream ifs1("graph1.txt");
    ass1(ifs1);
    
    ifstream ifs2("graph2.txt");
    ass2(ifs2);
    
    return 0;
}
