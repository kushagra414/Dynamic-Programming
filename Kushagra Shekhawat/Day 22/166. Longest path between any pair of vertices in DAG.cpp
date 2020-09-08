#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int v;
    vector<pair<int,int>> *adjList;
    vector<int> inDegree;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest,int weight);
int findLongestPath(Graph *graph);
vector<int> KahnAlgo(Graph *graph);


int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e,x,y,w;
        cin>>v>>e;
        Graph *graph = createGraph(v);
        for(int i=0;i<e;i++){
            cin>>x>>y>>w;
            addNode(graph,x,y,w);
        }
        cout<<findLongestPath(graph)<<endl;
    }
}
Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new vector<pair<int,int>>[totalVertices];
    graph->inDegree = vector<int>(totalVertices,0);
    return graph;
}

void addNode(Graph *graph,int src,int dest,int weight){
    graph->adjList[src].push_back(make_pair(dest,weight));
    graph->inDegree[dest]++;
}

int findLongestPath(Graph *graph){
    vector<int> topSort = KahnAlgo(graph);
    vector<int> dp(graph->v,INT_MIN);
    for(auto vertex:topSort)
        if(graph->inDegree[vertex]==0)
            dp[vertex]=0;
    for(auto vertex:topSort){
        for(auto adjVertex:graph->adjList[vertex]){
            if(dp[adjVertex.first]<adjVertex.second+dp[vertex])
                dp[adjVertex.first] = adjVertex.second+dp[vertex];
        }
    }
    for(int i=0;i<graph->v;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return *max_element(dp.begin(),dp.end());
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
                inDegree[vertex.first]--;
                if(inDegree[vertex.first]==0)
                    q.push(vertex.first);
                }
        }
    return topSort;
}