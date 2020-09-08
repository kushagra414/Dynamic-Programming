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
void findAllTopologicalSort(Graph *graph);
void findAllTopologicalSortUtil(Graph *graph,vector<int> &visited,vector<int> &result);

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
        findAllTopologicalSort(graph);
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

void findAllTopologicalSort(Graph *graph){
    vector<int>visited(graph->v,false),result;
    findAllTopologicalSortUtil(graph,visited,result);
}

void findAllTopologicalSortUtil(Graph *graph,vector<int> &visited,vector<int> &result){
    bool visitedCompleteGraph = true;
    for(int i=0;i<graph->v;i++){
        if(!visited[i] and graph->inDegree[i]==0){
            visited[i] = true;
            result.push_back(i);
            for(auto vertex:graph->adjList[i]){
                graph->inDegree[vertex]--;
            }
            findAllTopologicalSortUtil(graph,visited,result);
            visited[i]=false;
            result.erase(result.end()-1);
            for(auto vertex:graph->adjList[i])
                graph->inDegree[vertex]++;
            visitedCompleteGraph = false;
        }
    }
    if(visitedCompleteGraph){
        for(auto topSort:result)
            cout<<topSort<<" ";
        cout<<endl;
            }
}