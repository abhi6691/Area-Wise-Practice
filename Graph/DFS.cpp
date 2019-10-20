/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
***********************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

class Graph
{
	int V;

	list<int> *adj;

	void DFSUtil(int s, bool *visited);
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

	void DFS(int s);
};

void Graph::DFSUtil(int s, bool *visited)
{
	visited[s] = true;
	printf("%d ",s);

	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
		if (!visited[*it])
			DFSUtil(*it, visited);
}

void Graph::DFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (!visited[i])
			DFSUtil(i, visited);
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	// Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 

	return 0;
}