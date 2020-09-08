#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
    vector<int>inDegree;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
void topologicalSort(Graph *graph);
void DFS(Graph *graph,vector<int> &visited,vector<int> &departure,int &time,int v);

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y;
        cin>>v>>e;
        Graph *graph = createGraph(v);
        for(int i=0;i<e;i++){
            cin>>x>>y;
            addNode(graph,x,y);
        }
        topologicalSort(graph);
    }
    return 0;
}
Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new unordered_set<int>[totalVertices];
    graph->inDegree = vector<int>(totalVertices,0);
    return graph;
}

void addNode(Graph *graph,int src,int dest){
    graph->adjList[src].insert(dest);
    graph->inDegree[dest]++;
}

void topologicalSort(Graph *graph){
    vector<int>visited(graph->v,false),departure(graph->v,-1);
    int time = -1;
    for(int i=0;i<graph->v;i++)
        if(!visited[i])
            DFS(graph,visited,departure,time,i);

    reverse(departure.begin(),departure.end());
    for(auto vertex:departure)
        cout<<vertex<<" ";
    cout<<endl;
}

void DFS(Graph *graph,vector<int> &visited,vector<int> &departure,int &time,int v){
    visited[v]=true;
    for(auto vertex:graph->adjList[v])
        if(!visited[vertex])
            DFS(graph,visited,departure,time,vertex);
    
    departure[++time] = v;
}