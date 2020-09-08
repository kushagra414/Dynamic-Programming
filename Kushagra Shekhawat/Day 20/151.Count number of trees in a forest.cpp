#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
int countTrees(Graph *graph);
void BFS(Graph *graph,vector<bool> &visited,int v);

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
        cout<<countTrees(graph)<<endl;
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

int countTrees(Graph *graph){
    vector<bool>visited(graph->v,false);
    int count=0;
    for(int i=0;i<graph->v;i++){
        if(!visited[i]){
            BFS(graph,visited,i);
            count++;
        }
    }
    return count;
}

void BFS(Graph *graph,vector<bool> &visited, int v){
    queue<int>q;
    q.push(v);
    visited[v]=true;
    while(!q.empty()){
        v = q.front();
        q.pop();
        unordered_set<int> vertices = graph->adjList[v];
        for(auto vertex:vertices){
            if(!visited[vertex]){
                q.push(vertex);
                visited[vertex]=true;
                }
        }
    }
}