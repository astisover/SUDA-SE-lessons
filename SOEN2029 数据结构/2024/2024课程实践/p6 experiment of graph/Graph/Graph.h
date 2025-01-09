//Graph.h

#ifndef GRAPH_H
#define GRAPH_H

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

const int MaxSize = 100;

struct EdgeNode
{
	int adjvex;
	EdgeNode *next;
	EdgeNode(int x): adjvex(x), next(nullptr) {}
};

class Graph
{
private:
	
	vector<EdgeNode*> vertex; 
	int edge[MaxSize][MaxSize];
    int vertexNum, edgeNum;
    void adjMatrixDfsHelper(int node, vector<int> &path, bool visited[]);
    void adjLineBfsHelper(int node);
    void startToEndHelper(int startNode, int endNode, vector<int> &path, vector<int> &shortestPath, bool visited[]);
    
public:
	
	Graph(ifstream &ifs);
	void adjMatrixDfs(int node);
	void adjLineBfs(int node);
	void startToEnd(int startNode, int endNode);

};

#endif
