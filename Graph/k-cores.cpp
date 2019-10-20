/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description: https://www.geeksforgeeks.org/find-k-cores-graph/
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

	bool DFSUtil(int src, vector<bool> &visited, vector<int> &vDeg, int k);

public:
	Graph(int v)
	{
		V = v;
		adj = new list<int>[V];
	}

	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);	
		adj[dest].push_back(src);	
	}

	void printKCores(int K);
};

bool Graph::DFSUtil(int s, vector<bool> &visited, vector<int> &vDeg, int k)
{
	visited[s] = true;

	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (vDeg[s] < k)
			vDeg[*it]--;

		if (!visited[*it])
		{
			if (DFSUtil(*it, visited, vDeg, k))
				vDeg[s]--;
		}
	}

	return (vDeg[s] < k);
}

void Graph::printKCores(int k)
{
	vector<bool> visited(V, false);
	vector<int> vDeg(V);

	int mindeg = numeric_limits<int>::max();
	int src;
	for (int i = 0; i < V; i++)
	{
		vDeg[i] = adj[i].size();
		if (vDeg[i] < mindeg)
		{
			mindeg = vDeg[i];
			src = i;
		}
	}

	DFSUtil(src, visited, vDeg, k);

	for (int i = 0; i < V; i++)
		if (!visited[i])
			DFSUtil(i, visited, vDeg, k);

	printf("K-Cores:\n");
	for (int i = 0; i < V; i++)
	{
		if (vDeg[i] >= k)
		{
			printf("[%d]", i);
			list<int>::iterator it;

			for (it = adj[i].begin(); it != adj[i].end(); it++)
			{
				if (vDeg[*it] >= k)
					printf("->%d", *it);
			}
			cout<<endl;
		}
	}
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printKCores(k); 
  
    cout << endl << endl; 
  
    Graph g2(13); 
    g2.addEdge(0, 1); 
    g2.addEdge(0, 2); 
    g2.addEdge(0, 3); 
    g2.addEdge(1, 4); 
    g2.addEdge(1, 5); 
    g2.addEdge(1, 6); 
    g2.addEdge(2, 7); 
    g2.addEdge(2, 8); 
    g2.addEdge(2, 9); 
    g2.addEdge(3, 10); 
    g2.addEdge(3, 11); 
    g2.addEdge(3, 12); 
    g2.printKCores(k);

	return 0;
}