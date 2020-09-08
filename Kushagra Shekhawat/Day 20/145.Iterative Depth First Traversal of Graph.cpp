#include<bits/stdc++.h>
using namespace std;

struct Graph{
     int v;
     unordered_set<int> *adjList;
};

Graph *createGraph(int totalVertices);
void IterativeDFS(Graph *graph);
void addVertex(Graph *graph,int src, int dest);

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y;
        cin>>v>>e;
        Graph *graph = createGraph(v);
        for(int i=0;i<e;i++){
            cin>>x>>y;
            addVertex(graph,x,y);
        }
        IterativeDFS(graph);
    }
}

Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new unordered_set<int>[totalVertices];
    return graph;
}

void addVertex(Graph *graph,int src, int dest){
    graph->adjList[src].insert(dest);
    graph->adjList[dest].insert(src);
}

void IterativeDFS(Graph *graph){
    vector<bool>visited(graph->v,false);
    stack<int>s;
    int v;
    for(int i=0;i<graph->v;i++){
        if(!visited[i]){
            s.push(i);
            visited[i] = true;
            cout<<i<<" ";
        }
        while(!s.empty()){
            v = s.top();
            s.pop();
            unordered_set<int> vertices = graph->adjList[v];
            for(auto vertex:vertices)
                if(!visited[vertex]){
                    s.push(vertex);
                    visited[vertex] = true;
                    cout<<vertex<<" ";
                    }
        }
    }
}