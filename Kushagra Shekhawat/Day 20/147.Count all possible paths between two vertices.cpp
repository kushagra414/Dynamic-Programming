#include<bits/stdc++.h>
using namespace std;

struct Graph{
     int v;
     unordered_set<int> *adjList;
};

Graph *createGraph(int v);
void addNode(Graph *graph,int src,int dest);
void countPaths(Graph *graph,int src,int dest, int &count);

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y,src,dest;
        cin>>v>>e;
        Graph *graph = createGraph(v);
        for(int i=0;i<e;i++){
            cin>>x>>y;
            addNode(graph,x,y);
        }
        cin>>src>>dest;
        int count = 0;
        countPaths(graph,src,dest,count);
        cout<<count<<endl;
    }
}

Graph *createGraph(int v){
    Graph *graph = new Graph;
    graph->v = v;
    graph->adjList = new unordered_set<int>[v];
    return graph;
}

void addNode(Graph *graph,int src,int dest){
    graph->adjList[src].insert(dest);
}

void countPaths(Graph *graph,int src,int dest,int &count){
    if(src==dest){
        count++;
        return;
    }
    for(auto vertex:graph->adjList[src]){
        countPaths(graph,vertex,dest,count);
    }
}