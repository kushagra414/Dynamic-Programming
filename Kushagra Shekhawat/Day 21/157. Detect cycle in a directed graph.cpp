// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/


void moveVertex(int vertex,unordered_set<int> &fromSet,
                unordered_set<int> &toSet){
                    fromSet.erase(vertex);
                    toSet.insert(vertex);
}

bool DFS(int vertex,vector<int> adj[],unordered_set<int> &whiteSet,
        unordered_set<int> &graySet,unordered_set<int> &blackSet){
            moveVertex(vertex,whiteSet,graySet);
            for(auto neighbour:adj[vertex]){
                if(blackSet.find(neighbour)!=blackSet.end())
                    continue;
                if(graySet.find(neighbour)!=graySet.end())
                    return true;
                if(DFS(neighbour,adj,whiteSet,graySet,blackSet))
                    return true;
            }
            moveVertex(vertex,graySet,blackSet);
            return false;
}



bool isCyclic(int v, vector<int> adj[])
{
    unordered_set<int>whiteSet,graySet,blackSet;
    for(int i=0;i<v;i++)
        whiteSet.insert(i);
    while(whiteSet.size()>0){
        int vertex = *whiteSet.begin();
        if(DFS(vertex,adj,whiteSet,graySet,blackSet))
            return true;
    }
    return false;
}



// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends