#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v,e;
    vector<pair<int,int>> *adjList;
};

Graph *createGraph(int totalVertices,int totalEdges);
void addNode(Graph *graph,int src,int dest,int weight);
bool findNegativeCycles(Graph *graph);
bool bellManFord(Graph *graph);

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
        cout<<bellManFord(graph)<<endl;
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

bool bellManFord(Graph *graph){
    //create a list of edges
    vector<int> weight(graph->v,INT_MAX);
    weight[0] = 0;
    //relaxation
    //Traverse all the edges of graph v-1 times to find the shortest path.
    for(int i=0;i<graph->v-1;i++){
        for(int j=0;j<graph->v;j++){
            for(auto edge:graph->adjList[j]){
                if(weight[j]!=INT_MAX and 
                   weight[edge.first]>weight[j]+edge.second){
                    weight[edge.first] = weight[j]+edge.second;
                }
            }
        }
    }
    
    //Check if the weight of the graphs are still decreasing.
    //If so then the graph contains a negative cycle
    for(int j=0;j<graph->v;j++){
        for(auto edge:graph->adjList[j]){
            if(weight[j]!=INT_MAX and 
               weight[edge.first]>weight[j]+edge.second){
                   return true;
            }
        }
    }
    return false;
}