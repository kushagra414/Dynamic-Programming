#include<bits/stdc++.h>
using namespace std;
#define INF 1e7

//Floyd warshall Algorithm can be used to detect negative cycle in a graph as well as shortest distance
// using dynamic programming

struct Graph{
    int v;
    vector<vector<int>> adjList;
};

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest,int weight);
vector<vector<int>> floydWarshall(Graph *graph);

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y,w;
        cin>>v;
        Graph *graph = createGraph(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cin>>w;
                addNode(graph,i,j,w);
            }
        }
        vector<vector<int>>dist = floydWarshall(graph);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][j]==1e7)
                    cout<<"INF ";
                else
                    cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = vector<vector<int>>(totalVertices,
                                            vector<int>(totalVertices,INF));
    return graph;
}

void addNode(Graph *graph,int src,int dest,int weight){
    graph->adjList[src][dest] = weight;
}

vector<vector<int>> floydWarshall(Graph *graph){
    int n = graph->v;
    vector<vector<int>>dist = graph->adjList;
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];

    return dist;
}