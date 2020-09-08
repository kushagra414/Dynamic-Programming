// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

struct Graph{
    int v;
    unordered_set<int> *adjList;
    vector<bool>isPresent;
    vector<int>inDegree;
};
typedef struct Graph Graph;

Graph *createGraph(int totalVertices);
void addNode(Graph *graph,int src,int dest);
vector<int> topologicalSort(Graph *graph,int k);
void DFS(Graph *graph,vector<int> &visited,vector<int> &departure,int &time,int v);

string findOrder(string dict[], int n, int K) {
    Graph *graph = createGraph(26);
    int a = 'a';
    string s1,s2,result="";
    for(int i=0,j=1;i<n and j<n;i++,j++){
        s1 = dict[i],s2 = dict[j];
        for(int k=0;k<min(s2.length(),s1.length());k++){
            if(s1[k]!=s2[k]){
                addNode(graph,s1[k]-a,s2[k]-a);
                break;
            }
        }
    }
    vector<int>topSort = topologicalSort(graph,K);
    for(int i=0;i<K;i++){
        result += (char)(topSort[i]+a);
    }
    return result;
}

Graph *createGraph(int totalVertices){
    Graph *graph = new Graph;
    graph->v = totalVertices;
    graph->adjList = new unordered_set<int>[totalVertices];
    graph->isPresent = vector<bool>(totalVertices,false);
    graph->inDegree = vector<int>(totalVertices,0);
    return graph;
}

void addNode(Graph *graph,int src,int dest){
    graph->adjList[src].insert(dest);
    graph->isPresent[src]=true;
    graph->isPresent[dest]=true;
    graph->inDegree[dest]++;
}

vector<int> topologicalSort(Graph *graph,int k){
    vector<int>visited(graph->v,false),departure(k,-1);
    int time = -1;
    for(int i=0;i<graph->v;i++)
        if(!visited[i] and graph->isPresent[i])
            DFS(graph,visited,departure,time,i);

    reverse(departure.begin(),departure.end());
    return departure;
}

void DFS(Graph *graph,vector<int> &visited,vector<int> &departure,int &time,int v){
    visited[v]=true;
    for(auto vertex:graph->adjList[v])
        if(!visited[vertex])
            DFS(graph,visited,departure,time,vertex);
    
    departure[++time] = v;
}