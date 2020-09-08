// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool BFS(int G[][MAX],vector<int> &colorVertex,int V,int start){
    queue<int>q;
    q.push(start);
    colorVertex[start] = 0;
    int v;
    while(!q.empty()){
        v = q.front();
        //Self Loop
        if(G[v][v]==1)
            return false;
        q.pop();
        for(int i=0;i<V;i++){
            if(colorVertex[i]==-1 and G[v][i]==1){
                q.push(i);
                colorVertex[i] = colorVertex[v]^1;
            }else if(G[v][i]==1 and colorVertex[i]==colorVertex[v]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int G[][MAX],int V)
{
    vector<int>colorVertex(V,-1);
    bool bipartite=true;
    for(int i=0;i<V;i++)
        if(colorVertex[i]==-1){
            bipartite = BFS(G,colorVertex,V,i);
            if(!bipartite)
                return false;
        }
    return true;
}