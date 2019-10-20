/***********************************************************************************
	Author: Abhishek Singh
	Problem link/description:
***********************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

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

	void BFS(int src);
};

typedef vector <int> vi;

template <typename T>
void swap(T *a, T *b) { T t = *a; *a = *b; *b = t;}

void printVec(vi v){for(int i = 0; i < v.size(); i++) cout<<v[i]<<" "; cout<<endl;}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> q;

	q.push_back(s);
	visited[s] = true;

	list<int>::iterator it;

	while (!q.empty())
	{
		s = q.front();
		printf("%d ", s);
		q.pop_front();

		for (it = adj[s].begin(); it != adj[s].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push_back(*it);
			}
		}
	}
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 

	return 0;
}