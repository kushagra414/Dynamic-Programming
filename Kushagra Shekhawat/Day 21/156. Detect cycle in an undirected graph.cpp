// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

void makeSet(vector<int>&parent,vector<int>&size,int v){
    parent[v]=v;
    size[v]=0;
}

int findSet(vector<int>&parent,vector<int>&size,int v){
    if(parent[v]==v)
        return v;
    return (parent[v] = findSet(parent,size,parent[v]));
}

bool unionSets(vector<int>&parent,vector<int>&size,int a,int b){
    a = findSet(parent,size,a);
    b = findSet(parent,size,b);
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int v)
{
   vector<int>parent(v);
   vector<int>size(v);
   for(int i=0;i<v;i++)
        makeSet(parent,size,i);
    vector<vector<bool>>visitedEdge(v,vector<bool>(v,false));
    for(int i=0;i<v;i++)
        for(auto vertex:g[i])
            if(!visitedEdge[i][vertex] and !unionSets(parent,size,i,vertex))
                return true;
            else
                visitedEdge[i][vertex] = true,visitedEdge[vertex][i] = true;
    
    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends