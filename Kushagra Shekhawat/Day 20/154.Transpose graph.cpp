#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
void TransposeGraph(Graph *graph);
void PrintGraph(Graph *graph);

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
        cout<<"Before Transpose"<<endl;
        PrintGraph(graph);
        cout<<"After Transpose"<<endl<<endl;
        TransposeGraph(graph);
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

void TransposeGraph(Graph *graph){
    Graph *transposeGraph = createGraph(graph->v);
    for(int i=0;i<graph->v;i++){
        unordered_set<int> vertices = graph->adjList[i];
        for(auto vertex:vertices){
            addNode(transposeGraph,vertex,i);
        }
    }
    PrintGraph(transposeGraph);
}
void PrintGraph(Graph *graph){
    for(int i=0;i<graph->v;i++){
        unordered_set<int> vertices = graph->adjList[i];
        cout<<i;
        for(auto vertex:vertices)
            cout<<"-> "<<vertex;
        cout<<endl;
    }
}