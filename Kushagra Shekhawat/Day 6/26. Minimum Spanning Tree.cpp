// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

typedef pair<int,int> WIPair; //Weight Vertex Pair (3,A)
                              // weight 3 vertex A.

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<int> parent(V,-1),key(V,INT_MAX);
    vector<bool>inMst(V,false);
    priority_queue<WIPair,vector<WIPair>,greater<WIPair>>pq;
    int sum=0;
    key[0] = 0;
    pq.push(make_pair(0,0)); //Vertex 0 with weight 0.
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMst[u] = true;
        
        for(int v=0;v<V;v++){
            if(graph[u][v] != INT_MAX and key[v]>graph[u][v] and 
            inMst[v] == false){
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push(make_pair(key[v],v)); //Pushing Edge uv.
            }
        }
    }
    for(int i=0;i<V;i++){
        sum+=key[i];
    }
    return sum;
}
