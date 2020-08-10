// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
#define pa pair<int,int>
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    bool visited[V]={false};
    vector<int> value(V,INT_MAX);
    value[src]=0;
    priority_queue<pa,vector<pa>,greater<pa>> pq;
    pq.push(make_pair(value[src],src));
    while(!pq.empty()){
        pa temp=pq.top();
        pq.pop();
        int index=temp.second;
        if(visited[index]==false){
            visited[index]=true;
        }
        for(int i=0;i<V;i++){
            if(g[index][i]!=0){
                int weight=g[index][i];
                if(value[i]>value[index]+weight){
                    value[i]=value[index]+weight;
                    pq.push(make_pair(value[i],i));
                }
            }
        }
    }
    return value;
}
