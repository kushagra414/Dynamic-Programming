#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int n;
    int **matrix;
};

Graph *createGraph(int n);
void addNode(Graph *graph,int i, int j, int val);
void DFS(Graph *graph,vector<vector<bool>> &visited,int i, int j);
void printMinSources(Graph *graph);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        Graph *graph = createGraph(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                cin>>x;
                addNode(graph, i,j,x);
            }
            printMinSources(graph);

    }
}

Graph *createGraph(int n){
    Graph *graph = new Graph;
    graph->n = n;
    graph->matrix = new int*[n];
    for(int i=0;i<n;i++)
        graph->matrix[i] = new int[n];
    return graph;
}

void addNode(Graph *graph,int i, int j, int val){
    graph->matrix[i][j] = val;
}

void printMinSources(Graph *graph){
    vector<pair<int,pair<int,int>>> vertices;
    int n = graph->n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vertices.push_back(make_pair(graph->matrix[i][j],make_pair(i,j)));

    vector<vector<bool>>visited(n,vector<bool>(n,false));
    sort(vertices.begin(),vertices.end(),greater<pair<int,pair<int,int>>>());
    cout<<endl<<endl;
    for(int i=0;i<vertices.size();i++)
        if(!visited[vertices[i].second.first][vertices[i].second.second]){
            cout<<vertices[i].second.first<<" "<<vertices[i].second.second<<endl;
            DFS(graph,visited,vertices[i].second.first,vertices[i].second.second);
            }
}

void DFS(Graph *graph,vector<vector<bool>> &visited,int i, int j){
    visited[i][j]=true;

    if(j+1<graph->n and !visited[i][j+1] and graph->matrix[i][j]>=graph->matrix[i][j+1])
        DFS(graph,visited,i,j+1);
    if(i+1<graph->n and !visited[i+1][j] and graph->matrix[i][j]>=graph->matrix[i+1][j])
        DFS(graph,visited,i+1,j);
    if(i-1>=0 and !visited[i-1][j] and graph->matrix[i][j]>=graph->matrix[i-1][j])
        DFS(graph,visited,i-1,j);
    if(j-1>=0 and !visited[i][j-1] and graph->matrix[i][j]>=graph->matrix[i][j-1])
        DFS(graph,visited,i,j-1);
}