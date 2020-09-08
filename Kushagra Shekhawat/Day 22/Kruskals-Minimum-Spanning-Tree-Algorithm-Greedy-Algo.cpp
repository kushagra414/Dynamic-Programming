#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v,e;
    vector<vector<int>> adjList;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices,int totalEdges);
void addNode(Graph *graph,int src,int dest,int weight);
void KruskalMst(Graph *graph);
void createSet(vector<int> &parent);
int findSet(vector<int> &parent, vector<int> &size, int a);
bool unionSet(vector<int> &parent, vector<int> &size,int a,int b);

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
        KruskalMst(graph);
    }
    return 0;
}
Graph *createGraph(int totalVertices,int totalEdges){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->e = totalEdges;
    graph->adjList = vector<vector<int>>(totalVertices,vector<int>(totalVertices,INT_MIN));
    return graph;
}

void addNode(Graph *graph,int src,int dest,int weight){
    graph->adjList[src][dest]=weight;
}

void KruskalMst(Graph *graph){
    //First Sort the edges according to their weight
    vector<pair<int,pair<int,int>>> edgeList(graph->e);
    int k=0;
    for(int i=0;i<graph->v;i++)
        for(int j=0;j<graph->v;j++)
            if(graph->adjList[i][j] != INT_MIN)
                edgeList[k++] = make_pair(graph->adjList[i][j],make_pair(i,j));
    
    sort(edgeList.begin(),edgeList.end());

    //Now create sets so that we can detect cycle
    vector<int> parent(graph->v),size(graph->v,0);
    createSet(parent);
    //Now take the shortest edge and check if this edge will form a cycle and if does not form a cycle.
    //Then add the edge to the mst
    for(int i=0;i<graph->e;i++){
        if(unionSet(parent,size,edgeList[i].second.first,edgeList[i].second.second))
            cout<<edgeList[i].second.first<<" --- "<<edgeList[i].second.second<<" = "<<edgeList[i].first<<endl;
    }
}

void createSet(vector<int> &parent){
    for(int i=0;i<parent.size();i++)
        parent[i]=i;
}
int findSet(vector<int> &parent, vector<int> &size, int a){
    if(a==parent[a])
        return a;
    return parent[a] = findSet(parent,size,parent[a]);
}
bool unionSet(vector<int> &parent, vector<int> &size,int a,int b){
    a = findSet(parent,size,a),b = findSet(parent,size,b);
    if(a==b)
        return false;
    else{
        if(size[a]<size[b])
            swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
        return true;
    }
}