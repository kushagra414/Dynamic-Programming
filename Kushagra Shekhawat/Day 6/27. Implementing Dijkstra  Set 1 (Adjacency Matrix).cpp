// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

typedef pair<int,int> DIPair; //Distance Index pair

vector <int> dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<int> distance(V,INT_MAX),parent(V,-1);
    vector<bool> inMst(V,false);
    priority_queue<DIPair,vector<DIPair>,greater<DIPair>> pq;
    pq.push(make_pair(0,src));
    distance[src]=0;
    parent[src] = NULL;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMst[u] = true;
        for(int v=0;v<V;v++){
            if(graph[u][v] != 0 and distance[v] > distance[u]+
            graph[u][v] and !inMst[v]){
                parent[v] = u;
                distance[v] = distance[u]+graph[u][v];
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    return distance;
}