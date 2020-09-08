#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
};

typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
void DSF(Graph *graph, vector<bool>& visited, int v);
int findMotherNode(Graph *graph);

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
        cout<<"Mother Node: "<<findMotherNode(graph)<<endl;
    }
}

Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new unordered_set<int>[totalVertices];
    return graph;
}

void addNode(Graph *graph,int src,int dest){
    graph->adjList[src].insert(dest);
}

void DFS(Graph *graph, vector<bool>& visited,int v){
    visited[v] = true;
    unordered_set<int>vertices = graph->adjList[v];
    for(auto node:vertices)
    	if(!visited[node])
        	DFS(graph,visited,node);
}

int findMotherNode(Graph *graph){
    vector<bool>visited(graph->v);
    int v=0;
    for(int i=0;i<graph->v;i++){
        if(!visited[i]){
            DFS(graph,visited,i);
            v = i;
        }

    }
    fill(visited.begin(),visited.end(),false);
    DFS(graph,visited,v);
    for(auto vertex:visited)
        if(!vertex)
            return -1;
    return v;
}
