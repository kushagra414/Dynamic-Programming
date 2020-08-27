// C++ program to check if two n-ary trees are 
// mirror. 
#include <bits/stdc++.h> 
using namespace std; 

// First vector stores all nodes and adjacent of every 
// node in a stack. 
// Second vector stores all nodes and adjacent of every 
// node in a queue. 
bool mirrorUtil(vector<stack<int> >& tree1, 
					vector<queue<int> >& tree2) 
{ 
	// Traversing each node in tree. 
	for (int i = 1; i < tree1.size(); ++i) { 
		stack<int>& s = tree1[i]; 
		queue<int>& q = tree2[i]; 

		// While stack is not empty && Queue is not empty 
		while (!s.empty() && !q.empty()) { 

			// checking top element of stack and front 
			// of queue. 
			if (s.top() != q.front()) 
				return false; 

			s.pop(); 
			q.pop(); 
		} 

		// If queue or stack is not empty, return false. 
		if (!s.empty() || !q.empty()) 
			return false; 
	} 

	return true; 
} 

// Returns true if given two trees are mirrors. 
// A tree is represented as two arrays to store 
// all tree edges. 
void areMirrors(int m, int n, int u1[], int v1[], 
							int u2[], int v2[]) 
{ 
	vector<stack<int> > tree1(m + 1); 
	vector<queue<int> > tree2(m + 1); 

	// Pushing node in the stack of first tree. 
	for (int i = 0; i < n; i++) 
		tree1[u1[i]].push(v1[i]);	 

	// Pushing node in the queue of second tree. 
	for (int i = 0; i < n; i++) 
		tree2[u2[i]].push(v2[i]); 
	

	mirrorUtil(tree1, tree2) ? (cout << "Yes" << endl) : 
							(cout << "No" << endl); 
} 

// Driver code 
int main() 
{ 
	int M = 3, N = 2; 

	int u1[] = { 1, 1 }; 
	int v1[] = { 2, 3 }; 

	int u2[] = { 1, 1 }; 
	int v2[] = { 3, 2 }; 

	areMirrors(M, N, u1, v1, u2, v2); 

	return 0; 
} 
