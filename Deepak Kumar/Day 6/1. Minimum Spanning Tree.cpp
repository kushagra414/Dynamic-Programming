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

#define pa pair<int,int>
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    bool visited[V];
    int value[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        value[i]=INT_MAX;
    }
    value[0]=0;
    priority_queue<pa,vector<pa>,greater<pa>> pq;
    pq.push(make_pair(value[0],0));
    int solution=0;
    for(int i=1;i<V;i++){
        pq.push(make_pair(INT_MAX,i));
    }
    while(!pq.empty()){
        pa temp=pq.top();
        pq.pop();
        int index=temp.second;
        if(visited[index]==false){
            visited[index]=true;
            solution=solution+value[index];
            for(int i=0;i<graph[index].size();i++){
                if(graph[index][i]!=INT_MAX && visited[i]==false && graph[index][i]<value[i]){
                    value[i]=graph[index][i];
                    pq.push(make_pair(value[i],i));
                }
            }
        }
    }
    return solution;
}
