#include <bits/stdc++.h>
using namespace std;

#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

// } Driver Code Ends
/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
void findPath(int m[MAX][MAX], int n, int x, int y, int visited[MAX][MAX],string c,string s,vector <string> &v){
    if(x>=0&&y>=0&&x<n&&y<n){
        if(m[x][y]==0||visited[x][y]==1)
            return;
        else if(m[x][y]==1){
            //cout<<"Visiting "<<x<<" and "<<y<<endl;
            s+=c;
            if(x==n-1&&y==n-1){
                //cout<<s<<endl;
                v.push_back(s);
                }
        }
    visited[x][y]=1;
    findPath(m,n,x-1,y,visited,"U",s,v); //UP
    findPath(m,n,x+1,y,visited,"D",s,v); //DOWN
    findPath(m,n,x,y+1,visited,"R",s,v); //RIGHT
    findPath(m,n,x,y-1,visited,"L",s,v); //LEFT
    visited[x][y]=0;
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    //path="";
    //foundPath=1;
    int visited[MAX][MAX];
    vector <string> v;
    memset(visited,0,MAX*MAX*sizeof(int));
    findPath(m,n,0,0,visited,"","",v);
    sort(v.begin(),v.end());
    return v;
}
