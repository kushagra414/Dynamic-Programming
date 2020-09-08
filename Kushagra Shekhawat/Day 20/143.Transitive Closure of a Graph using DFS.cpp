
struct Graph{
    int v;
    unordered_set<int> *adjList;
};

Graph *createGraph(int totalVertex);
void addNode(Graph *graph,int src, int dest);
void findTrasitiveClosure(Graph *graph);
void DFS(Graph *graph,vector<bool> &visited,int v);
void printAdjList(Graph *graph);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int v,e;
	    bool x;
	    cin>>v;
	    Graph *graph = createGraph(v);
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            cin>>x;
	            if(x){
	                addNode(graph,i,j);
	                //cout<<"i: "<<i<<",j: "<<j<<", x: "<<x<<" ";
	            }
	        }
	    }
	    //printAdjList(graph);
	    findTrasitiveClosure(graph);
	    cout<<endl;
	}
	return 0;
}

Graph *createGraph(int totalVertex){
    Graph *graph = new Graph;
    graph->v = totalVertex;
    graph->adjList = new unordered_set<int>[totalVertex];
    return graph;
}

void addNode(Graph *graph,int src, int dest){
    graph->adjList[src].insert(dest);
}

void findTrasitiveClosure(Graph *graph){
    vector<bool>visited(graph->v,false);
    vector<vector<bool>>TrClosure(graph->v, vector<bool>(graph->v,false));
    for(int i=0;i<graph->v;i++){
        DFS(graph,visited,i);
        TrClosure[i] = visited;
        fill(visited.begin(),visited.end(),false);
    }
    for(int i=0;i<graph->v;i++)
        for(int j=0;j<graph->v;j++)
            cout<<TrClosure[i][j]<<" ";
}

void DFS(Graph *graph,vector<bool> &visited,int v){
    unordered_set<int>vertices = graph->adjList[v];
    visited[v]=true;
    for(auto vertex:vertices){
        if(!visited[vertex])
            DFS(graph,visited,vertex);
    }
}

void printAdjList(Graph *graph){
    for(int i=0;i<graph->v;i++){
        unordered_set<int> vertices = graph->adjList[i];
        cout<<i;
        for(auto vertex:vertices)
            cout<<"-> "<<vertex;
        cout<<endl;
    }
}