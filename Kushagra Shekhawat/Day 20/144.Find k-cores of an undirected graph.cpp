#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
};
Graph *createGraph(int totalVertices);
void addVertice(Graph *graph,int src,int dest);
void KCores(Graph *graph, int k);
void removeKCores(Graph *graph,int v);
void printGraph(Graph *graph);


int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,src,dest,k;
        cin>>v>>e;
        Graph *graph = createGraph(v);
        for(int i=0;i<e;i++) {
            cin>>src>>dest;   
            addVertice(graph,src,dest);
        }
        cin>>k;
        KCores(graph, k);
        printGraph(graph);
    }
    return 0;
}

Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new unordered_set<int>[totalVertices];
    return graph;
}

void addVertice(Graph *graph,int src,int dest){
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
}

void printGraph(Graph *graph){
    for(int i=0;i<graph->v;i++){
        unordered_set<int> vertices = graph->adjList[i];
        if(vertices.size()>0){
            cout<<i;
            for(auto vertex:vertices)
                cout<<"-> "<<vertex;
            cout<<endl;
            }
    }
}

void KCores(Graph *graph,int k){
    bool removedAllKCores=true;
    for(int i=0;i<graph->v;i++)
        if(graph->adjList[i].size()<k and graph->adjList[i].size()>0){
            removeKCores(graph,i);
            removedAllKCores=false;
            }
    if(!removedAllKCores)
        KCores(graph,k);
}

void removeKCores(Graph *graph,int v){
    unordered_set<int> vertices = graph->adjList[v];
    for(auto vertex:vertices){
        graph->adjList[vertex].erase(v);
    }
    graph->adjList[v].clear();
}