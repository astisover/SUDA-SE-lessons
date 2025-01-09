//Graph.cpp

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

Graph::Graph(ifstream &ifs)
{
	string line;
	getline(ifs, line);
	istringstream ss(line);
	ss >> vertexNum >> edgeNum;
	
	while(getline(ifs, line))
	{
		ss.clear();
		ss.str(line);
		int pa, pb;
		ss >> pa >> pb;
		edge[pa][pb] = 1;
		edge[pb][pa] = 1;
	}
	
	for(int i = 0; i < vertexNum; i ++)
	{
		vertex.push_back(new EdgeNode(i));
		EdgeNode *p = vertex[i];
		for(int j = 0; j < vertexNum; j ++)
		{
			if(edge[i][j] == 1)
			{
				p->next = new EdgeNode(j);
				p = p->next; 
			}
		}	
	}
}

void Graph::adjMatrixDfsHelper(int node, vector<int> &path, bool visited[])
{
	if(visited[node])
		return;
	
	visited[node] = 1;
	path.push_back(node);
	
	if(path.size() == vertexNum)
	{
		for(int i = 0; i < vertexNum; i ++)
			cout << path[i] << " ";
		cout << endl;
	}
	
	for(int j = 0; j < vertexNum; j ++)
	{
		if(edge[node][j] == 1)
			adjMatrixDfsHelper(j, path, visited);
	}
	
	visited[node] = 0;
	path.pop_back();
}

void Graph::adjMatrixDfs(int node)
{
	bool visited[MaxSize] = {0};
	vector<int> path;
	adjMatrixDfsHelper(node, path, visited);
}

void Graph::adjLineBfsHelper(int node)
{
	queue<vector<bool> > v;
	queue<vector<int> > q;
	
	vector<int> path;
	path.push_back(node);
	
	vector<bool> visited(vertexNum, 0);
	visited[node] = 1;
	
	v.push(visited);
	q.push(path);
	
	while(!q.empty())
	{
		path = q.front();
		visited = v.front();
		
		q.pop();
		v.pop();
		
		if(path.size() == vertexNum)
		{
			for(int i = 0; i < vertexNum; i ++)
				cout << path[i] << " ";
			cout << endl;
			continue;
		}
		
		int lastNode = path.back();
		EdgeNode *p = vertex[lastNode]->next;
		while(p != nullptr)
		{
			if(visited[p->adjvex])
			{
				p = p->next;
				continue;
			}
			
			vector<bool> newVisited = visited;
			newVisited[p->adjvex] = 1;
			
			vector<int> newPath = path;
			newPath.push_back(p->adjvex);
			
			v.push(newVisited);
			q.push(newPath);
			
			p = p->next; 
		}	
	}	
}

void Graph::adjLineBfs(int node)
{
	adjLineBfsHelper(node);
}

void Graph::startToEndHelper(int startNode, int endNode, vector<int> &path, vector<int> &shortestPath, bool visited[])
{
	if(visited[startNode])
		return;
	
	visited[startNode] = 1;
	path.push_back(startNode);
	
	if(startNode == endNode)
	{
		for(int i = 0; i < path.size(); i ++)
			cout << path[i] << " ";
		cout << endl;
		
		if(path.size() < shortestPath.size())
			shortestPath = path;
			
		visited[startNode] = 0;
		path.pop_back();	
			
		return;
	}
	
	for(int j = 0; j < vertexNum; j ++)
	{
		if(edge[startNode][j] == 1)
			startToEndHelper(j, endNode, path, shortestPath, visited);
	}
	
	visited[startNode] = 0;
	path.pop_back();
}

void Graph::startToEnd(int startNode, int endNode)
{
	bool visited[MaxSize] = {0};
	vector<int> path;
	vector<int> shortestPath(vertexNum + 1, 0);
	
	cout << "\nThe paths are followings:" << endl;
	startToEndHelper(startNode, endNode, path, shortestPath, visited);
	
	if(shortestPath.size() <= vertexNum)
	{
		cout << "\nThe shortest path is:" << endl;
		for(int i = 0; i < shortestPath.size(); i ++)
			cout << shortestPath[i] << " ";
		cout << endl;
	}
}
