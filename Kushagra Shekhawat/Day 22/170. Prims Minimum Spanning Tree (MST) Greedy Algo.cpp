#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v,e;
    vector<vector<int>> adjList;
};
typedef pair<int,int> WIPair; //Weight Vertex Pair (3,A)
                              // weight 3 vertex A.

typedef struct Graph Graph;

Graph *createGraph(int totalVertices,int totalEdges);
void addNode(Graph *graph,int src,int dest,int weight);
int PrimsMST(Graph *graph);

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y,w;
        cin>>v>>e;
        Graph *graph = createGraph(v,e);
        for(int i=0;i<e;i++){
            cin>>x>>y>>w;
            addNode(graph,x,y,w);
        }
        cout<<"Min Sum in MST: "<<PrimsMST(graph)<<endl;
    }
    return 0;
}
Graph *createGraph(int totalVertices,int totalEdges){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->e = totalEdges;
    graph->adjList = vector<vector<int>>(totalVertices,vector<int>(totalVertices,INT_MAX));
    return graph;
}

void addNode(Graph *graph,int src,int dest,int weight){
    graph->adjList[src][dest]=weight;
    graph->adjList[dest][src]=weight;
}

int PrimsMST(Graph *graph){
    int V = graph->v;
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
            if(graph->adjList[u][v] != INT_MAX and key[v]>graph->adjList[u][v] and 
            inMst[v] == false){
                key[v] = graph->adjList[u][v];
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