#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    unordered_set<int> *adjList;
    vector<int> inDegree;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
void findMaxEdges(Graph *graph);
vector<int> KahnAlgo(Graph *graph);


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
        findMaxEdges(graph);
        cout<<endl;
    }
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

void findMaxEdges(Graph *graph){
    vector<int>topSort = KahnAlgo(graph);
    int LDV,HDV; //lowerDegreeVertex and higherDegreeVertex
    for(int i=0;i<graph->v;i++)
        cout<<topSort[i]<<" ";
    cout<<endl;
    for(int i=0;i<graph->v;i++){
        LDV = topSort[i];
        for(int j=i+1;j<graph->v;j++){
            HDV = topSort[j];
            if(graph->adjList[LDV].find(HDV) == graph->adjList[LDV].end()){
                cout<<LDV<<"->"<<HDV<<" ";
            }
        }
    }
}

vector<int> KahnAlgo(Graph *graph){
    vector<bool> visited(graph->v,false);
    vector<int> topSort,inDegree = graph->inDegree;
    queue<int>q;
    int v;
    for(int i=0;i<graph->v;i++)
        if(inDegree[i]==0 and visited[i]==false){
            q.push(i);
            visited[i]=true;
        }
        while(!q.empty()){
            v = q.front();
            q.pop();
            visited[v]=true;
            topSort.push_back(v);
            for(auto vertex:graph->adjList[v]){
                inDegree[vertex]--;
                if(inDegree[vertex]==0)
                    q.push(vertex);
                }
        }
    return topSort;
}