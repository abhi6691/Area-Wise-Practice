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

	int countNodesAtLevel(int src, int level);
};

int Graph::countNodesAtLevel(int s, int l)
{
	vector<bool> visited(V, false);
	list<int> queue;

	vector<int> level(V, 0);
	queue.push_back(s);
	visited[s] = true;

	list<int>::iterator it;

	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();

		for (it = adj[s].begin(); it != adj[s].end(); it++)
		{
			if (!visited[*it])
			{
				queue.push_back(*it);
				visited[*it] = true;
				level[*it] = level[s] + 1;
			}
		}
	}

	int cnt = 0;
	for(int i = 0; i < V; i++)
		if (level[i] == l)
			cnt++;

	return cnt;
}

int main()
{
	freopen("D://inputf.in", "r", stdin);
	freopen("D://outputf.in", "w", stdout);

	Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 3; 
  
    cout << g.countNodesAtLevel(0, level); 

	return 0;
}