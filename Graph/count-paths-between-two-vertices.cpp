/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

class Graph
{
	int V;

	list<int> *adj;

public:
	Graph(int v)
	{
		V = v;
		adj = new list<int>[V];
	}

	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);		
	}

	void countPathsUtil(int s, int d, bool *visited, int *pathCount);
	int countPaths(int s, int d);
};

void Graph::countPathsUtil(int s, int d, bool *visited, int *pc)
{
	visited[s] = true;

	if (s == d)
		*pc = *pc + 1;
	else
	{
		list<int>::iterator it;
		for (it = adj[s].begin(); it != adj[s].end(); it++)
			if (!visited[*it])
				countPathsUtil(*it, d, visited, pc);
	}

	visited[s] = false;
}

int Graph::countPaths(int s, int d)
{
	bool *visited = new bool[V];
	memset(visited, false, sizeof(visited));

	int pathCount = 0;
	countPathsUtil(s, d, visited, &pathCount);
	
	return pathCount;
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
  
    int s = 2, d = 3; 
    cout << g.countPaths(s, d); 

	return 0;
}