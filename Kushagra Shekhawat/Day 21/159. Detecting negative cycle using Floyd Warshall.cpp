#include<bits/stdc++.h>
using namespace std;
#define INF 9999

//Floyd warshall Algorithm can be used to detect negative cycle in a graph as well as shortest distance
// using dynamic programming

struct Graph{
    int v,e;
    vector<pair<int,int>> *adjList;
};

Graph *createGraph(int totalVertices,int totalEdges);
void addNode(Graph *graph,int src,int dest,int weight);
bool floydWarshall(Graph *graph);

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
        cout<<floydWarshall(graph)<<endl;
    }
}

Graph *createGraph(int totalVertices,int totalEdges){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->e = totalEdges;
    graph->adjList = new vector<pair<int,int>>[totalVertices];
    return graph;
}

void addNode(Graph *graph,int src,int dest,int weight){
    graph->adjList[src].push_back(make_pair(dest,weight));
}

bool floydWarshall(Graph *graph){
    int n = graph->v;
    vector<vector<int>>dist(n,vector<int>(n,INF));
    for(int i=0;i<n;i++)
        dist[i][i] = 0;
    for(int i=0;i<n;i++)
        for(auto vertex:graph->adjList[i]){
            dist[i][vertex.first] = vertex.second;
        }
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];

    //If a vertex become negative that means there is a negative cycle
    for(int i=0;i<n;i++)
        if(dist[i][i]<0)
            return true;
    return false;
}