// C++ Program to print 
// count of nodes 
// at given level. 
#include <iostream> 
#include <list> 

using namespace std; 

// This class represents 
// a directed graph 
// using adjacency 
// list representation 
class Graph { 
	// No. of vertices 
	int V; 

	// Pointer to an 
	// array containing 
	// adjacency lists 
	list<int>* adj; 

public: 
	// Constructor 
	Graph(int V); 

	// function to add 
	// an edge to graph 
	void addEdge(int v, int w); 

	// Returns count of nodes at 
	// level l from given source. 
	int BFS(int s, int l); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	// Add w to v’s list. 
	adj[v].push_back(w); 

	// Add v to w's list. 
	adj[w].push_back(v); 
} 

int Graph::BFS(int s, int l) 
{ 
	// Mark all the vertices 
	// as not visited 
	bool* visited = new bool[V]; 
	int level[V]; 

	for (int i = 0; i < V; i++) { 
		visited[i] = false; 
		level[i] = 0; 
	} 

	// Create a queue for BFS 
	list<int> queue; 

	// Mark the current node as 
	// visited and enqueue it 
	visited[s] = true; 
	queue.push_back(s); 
	level[s] = 0; 

	while (!queue.empty()) { 

		// Dequeue a vertex from 
		// queue and print it 
		s = queue.front(); 
		queue.pop_front(); 

		// Get all adjacent vertices 
		// of the dequeued vertex s. 
		// If a adjacent has not been 
		// visited, then mark it 
		// visited and enqueue it 
		for (auto i = adj[s].begin(); 
				i != adj[s].end(); ++i) { 
			if (!visited[*i]) { 

				// Setting the level 
				// of each node with 
				// an increment in the 
				// level of parent node 
				level[*i] = level[s] + 1; 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 

	int count = 0; 
	for (int i = 0; i < V; i++) 
		if (level[i] == l) 
			count++;	 
	return count; 
} 

// Driver program to test 
// methods of graph class 
int main() 
{ 
	// Create a graph given 
	// in the above diagram 
	Graph g(6); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 3); 
	g.addEdge(2, 4); 
	g.addEdge(2, 5); 

	int level = 2; 

	cout << g.BFS(0, level); 

	return 0; 
} 
